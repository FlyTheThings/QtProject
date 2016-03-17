#include "serialportcommu.h"
#include "ui_serialportcommu.h"
#include <QDebug>

QSerialPortCommu::QSerialPortCommu(QWidget *parent) :
    QWidget(parent),
    cmdTimer(NULL),
    Play_Timer(NULL)
{
    hide();
    isTxMsgCmd = false;  isTxMsgSim = false;
    numRepeatSend = 0;   tickTimer = 0;
    memset(&tx_message_cmd, 0, sizeof(tx_message_cmd));
    memset(&tx_message_sim, 0, sizeof(tx_message_cmd));
    
    dataTimer.start(10, this);
    cmdTimer = new QTimer(this); 
    connect(cmdTimer,SIGNAL(timeout()), this,SLOT(slot_cmdEchoTimerMonitor()));

    filepos=0;
    Play_Timer = new QTimer(this);
    connect(Play_Timer,SIGNAL(timeout()),SLOT(slot_playback()));
}

QSerialPortCommu::~QSerialPortCommu()
{
    if (cmdTimer)  delete cmdTimer;
    if (dataTimer.isActive()) dataTimer.stop();
}

void QSerialPortCommu::enableSimuCommu(bool flag)
{
    isTxMsgSim = flag;
}    

void QSerialPortCommu::slot_protocol_receiveDataProcess()
{
    quint8 packet_buf;
    qint32 idx;
    quint8 decodeState, isSYSID;

    if (serialPort->isOpen()) {
        QByteArray portData = serialPort->readAll();

        for(idx=0;idx<portData.length();idx++){
            packet_buf= portData.at(idx);
            if(record==true)  savetofile(packet_buf);//记录数据

            decodeState = protocol_parse_char(packet_buf, &rx_message_link, &rx_msg_status_link);

            if (decodeState==1) {
                emit signal_setlight(4);

                isSYSID = protocol_parse_packet(&rx_message_link);
                if (isSYSID==1) isSYSID = 1;
            }
            //else emit signal_setlight(5);   //不合适!
        }
    }
}

void  QSerialPortCommu::protocol_parse_state_initialize(datalink_status_t* initStatus)
{
    if ((initStatus->parse_state <= DATALINK_PARSE_STATE_UNINIT) 
                                 || (initStatus->parse_state > DATALINK_PARSE_STATE_GOT_CRC1)) {
        initStatus->msg_received = 0;
        initStatus->parse_error = 0;
        initStatus->parse_state = DATALINK_PARSE_STATE_UNINIT;
        initStatus->packet_idx = 0;
        initStatus->packet_rx_drop_count = 0;
        initStatus->packet_rx_success_count = 0;
        initStatus->current_rx_seq = 0;
        initStatus->current_tx_seq = 0;
    }
}

quint8  QSerialPortCommu::protocol_parse_char(quint8 c, datalink_message_t* r_message, datalink_status_t* r_msg_status)
{
    datalink_message_t* rxmsg = &message_cur;    ///< The currently decoded message
    datalink_status_t* status = &status_cur;     ///< The current decode status

    protocol_parse_state_initialize(status);     // Initializes only once, values keep unchanged after first initialization
    status->msg_received = 0;

    switch (status->parse_state) {
        case DATALINK_PARSE_STATE_UNINIT:
        case DATALINK_PARSE_STATE_IDLE:
            if (c == DATALINK_STX1) {
                rxmsg->magic1 = c;
                status->parse_state = DATALINK_PARSE_STATE_GOT_STX1;
            }
            break;
        case DATALINK_PARSE_STATE_GOT_STX1:
            if (c == DATALINK_STX2) {
                rxmsg->magic2 = c;
                status->parse_state = DATALINK_PARSE_STATE_GOT_STX2;
                protocol_start_checksum(rxmsg);
            }
            else {
                if (c == DATALINK_STX1) {
                    rxmsg->magic1 = c;
                    status->parse_state = DATALINK_PARSE_STATE_GOT_STX1;
                }
                else  status->parse_state = DATALINK_PARSE_STATE_IDLE;
            }
            break;
        case DATALINK_PARSE_STATE_GOT_STX2:
            //if(c < DATALINK_MAX_PAYLOAD_LEN) {                            //防止错误帧导致数据溢出（有无必要？）
                rxmsg->len = c;
                status->packet_idx = 0;
                protocol_update_checksum(rxmsg, c);
                status->parse_state = DATALINK_PARSE_STATE_GOT_LENGTH;
            /*}
            else {
                status->parse_error++;
                status->msg_received = 0;
                status->parse_state = DATALINK_PARSE_STATE_IDLE;

                if (c == DATALINK_STX1)	{
                    rxmsg->magic1 = c;
                    status->parse_state = DATALINK_PARSE_STATE_GOT_STX1;
                }
            }*/
            break;
        case DATALINK_PARSE_STATE_GOT_LENGTH:
            rxmsg->seq = c;
            protocol_update_checksum(rxmsg, c);
            status->parse_state = DATALINK_PARSE_STATE_GOT_SEQ;
            break;
        case DATALINK_PARSE_STATE_GOT_SEQ:
            rxmsg->sysid = c;
            protocol_update_checksum(rxmsg, c);
            status->parse_state = DATALINK_PARSE_STATE_GOT_SYSID;
            break;
        case DATALINK_PARSE_STATE_GOT_SYSID:
            rxmsg->compid = c;
            protocol_update_checksum(rxmsg, c);
            status->parse_state = DATALINK_PARSE_STATE_GOT_COMPID;
            break;
        case DATALINK_PARSE_STATE_GOT_COMPID:

            rxmsg->msgid = c;
            protocol_update_checksum(rxmsg, c);

            if (rxmsg->len == 0) status->parse_state = DATALINK_PARSE_STATE_GOT_PAYLOAD;
            else                 status->parse_state = DATALINK_PARSE_STATE_GOT_MSGID;
            break;
        case DATALINK_PARSE_STATE_GOT_MSGID:
            rxmsg->payload[status->packet_idx++] = c;
            protocol_update_checksum(rxmsg, c);

            if (status->packet_idx == rxmsg->len) {
                status->parse_state = DATALINK_PARSE_STATE_GOT_PAYLOAD;
            }
            break;
        case DATALINK_PARSE_STATE_GOT_PAYLOAD:
            if (c != rxmsg->ck_a) {                  // Check first checksum byte
                status->parse_error++;

                status->msg_received = 0;
                status->parse_state = DATALINK_PARSE_STATE_IDLE;

                if (c == DATALINK_STX1)	{
                    rxmsg->magic1 = c;
                    status->parse_state = DATALINK_PARSE_STATE_GOT_STX1;
                }
            }
            else {
                status->parse_state = DATALINK_PARSE_STATE_GOT_CRC1;
            }
            break;
        case DATALINK_PARSE_STATE_GOT_CRC1:
            if (c != rxmsg->ck_b) {                  // Check second checksum byte
                status->parse_error++;
                status->msg_received = 0;
                status->parse_state = DATALINK_PARSE_STATE_IDLE;

                if (c == DATALINK_STX1)	{
                    rxmsg->magic1 = c;
                    status->parse_state = DATALINK_PARSE_STATE_GOT_STX1;
                }
            }
            else {
                status->msg_received = 1;          // Successfully got message
                status->parse_state = DATALINK_PARSE_STATE_IDLE;
                if ( r_message != NULL ) {
                    memcpy(r_message, rxmsg, sizeof(datalink_message_t));
                }
            }
            break;
    }

    if (status->msg_received == 1) {

        status->current_rx_seq = rxmsg->seq;

        if (status->packet_rx_success_count == 0) status->packet_rx_drop_count = 0;
        status->packet_rx_success_count++;
    }

    r_msg_status->current_rx_seq = status->current_rx_seq+1;

    r_msg_status->packet_rx_success_count = status->packet_rx_success_count;
    if (status->parse_error>0) {
        ++(status->packet_rx_drop_count);
        r_msg_status->packet_rx_drop_count = status->packet_rx_drop_count;
    }
    status->parse_error = 0;

    return status->msg_received;
}

quint8  QSerialPortCommu::protocol_parse_packet (datalink_message_t* r_message)
{
    quint8 isOK=false;

    switch (r_message->compid) {
    qDebug()<<"minghaosb3"<<r_message->compid;
        case UAV_COMP_ID_SYSENABLE:  isOK = dataProtocol->msg_compID_sysEnable(r_message);  break;
        case UAV_COMP_ID_SYSINFO:    isOK = dataProtocol->msg_compID_sysInfo(r_message);    break;
        case UAV_COMP_ID_HELIINFO:   isOK = dataProtocol->msg_compID_heliCFG(r_message);    break;
        case UAV_COMP_ID_WAYPOINT:   isOK = dataProtocol->msg_compID_wayPoint(r_message);   break;             
        case UAV_COMP_ID_CTRLCHANNAL:isOK = dataProtocol->msg_compID_ctrlChannel(r_message);break;
        case UAV_COMP_ID_CMDFLY:     isOK = dataProtocol->msg_compID_cmdFly(r_message);     break;        
        case UAV_COMP_ID_CMDMISSION: isOK = dataProtocol->msg_compID_cmdMission(r_message); break;           
        case UAV_COMP_ID_CMDTEST:    isOK = dataProtocol->msg_compID_cmdTest(r_message);    break;
        case UAV_COMP_ID_FILE:       isOK = dataProtocol->msg_compID_fileTrans(r_message);  break;
        case UAV_COMP_ID_FCC:        isOK = dataProtocol->msg_compID_FCC(r_message);        break;
        case UAV_COMP_ID_IMU:        isOK = dataProtocol->msg_compID_sensorIMU(r_message);  break;
        case UAV_COMP_ID_GPS:        isOK = dataProtocol->msg_compID_sensorGPS(r_message);  break;
        case UAV_COMP_ID_HMR:        isOK = dataProtocol->msg_compID_sensorHMR(r_message);  break;
        case UAV_COMP_ID_ACS:	     isOK = dataProtocol->msg_compID_ACS(r_message);        break;
        case UAV_COMP_ID_RC1:        isOK = dataProtocol->msg_compID_RC(r_message);         break;
        case UAV_COMP_ID_RECORD:     isOK = dataProtocol->msg_compID_auxRecoder(r_message); break;
        case UAV_COMP_ID_POWERSYS:   isOK = dataProtocol->msg_compID_auxPower(r_message);   break;
        case UAV_COMP_ID_ENGINE:     isOK = dataProtocol->msg_compID_auxEngine(r_message);  break;
        case UAV_COMP_ID_SPRAY:      isOK = dataProtocol->msg_compID_auxSpray(r_message);   break;
        case UAV_COMP_ID_CAMERA:     isOK = dataProtocol->msg_compID_auxCamera(r_message);  break;
        case UAV_COMP_ID_SIM:        isOK = dataProtocol->msg_compID_simMode(r_message);    break;
        case UAV_COMP_ID_SCENE:	     isOK = dataProtocol->msg_compID_simScene(r_message);   break;
        case UAV_COMP_ID_IAP:        isOK = dataProtocol->msg_compID_IAP(r_message);        break;
        case UAV_COMP_SIM_SELFTEST:  isOK = false;                                          break;
        default:                     isOK = false;                                          break;
    }

    return (isOK);
}

void QSerialPortCommu::setSerialPort(QSerialPort *comPort)
{
    serialPort = comPort;
    connect(serialPort,SIGNAL(readyRead()), this,SLOT(slot_protocol_receiveDataProcess()));
}

void QSerialPortCommu::setSerialProtocol(QDataProtocol *comProtocol)
{
    dataProtocol = comProtocol;
}

void  QSerialPortCommu::slot_protocol_send_packet(quint8 seqid, quint8 compid, quint8 msgid, const quint8 *packet, quint8 length)
{
    quint16  checksum;
    quint8   buf[7];
    quint8   sysid=0;

    foreach (quint8 id, dataProtocol->Id2num.keys()) {
       qDebug()<<"minghaosb4"<<sysid<<"  "<<id<<"  "<<dataProtocol->Id2num[id];
       if(seqid== dataProtocol->Id2num[id])
       {
           sysid=id;
           qDebug()<<"minghaosb2"<<sysid<<"  "<<id;
       }
    }

    if(sysid!=0)
    {
        tx_message_cmd.magic1 = DATALINK_STX1;   tx_message_cmd.magic2 = DATALINK_STX2;
        tx_message_cmd.len    = length;
        tx_message_cmd.seq    = 0x00;
        tx_message_cmd.sysid  = sysid;
        tx_message_cmd.compid = compid;
        tx_message_cmd.msgid  = msgid;
        memcpy(tx_message_cmd.payload, packet, length);
        
        buf[0] = DATALINK_STX1;  buf[1] = DATALINK_STX2;
        buf[2] = length;         buf[3] = 0x00;
        buf[4] = sysid;          buf[5] = compid;
        buf[6] = msgid;

        checksum = crc_calculate((const quint8*)&buf[2], 5);
        crc_accumulate_buffer(&checksum, packet, length);
        tx_message_cmd.ck_a = (quint8)(checksum & 0xFF);
        tx_message_cmd.ck_b = (quint8)(checksum >> 8);

        isTxMsgCmd = true;                                   //启动发送和回报监控
        numRepeatSend = 3;
    }
}

void  QSerialPortCommu::slot_protocol_send_packetSim(quint8 sysid, quint8 compid, quint8 msgid, const quint8 *packet, quint8 length)
{
    quint16    checksum;
    quint8     buf[7];

    tx_message_sim.magic1 = DATALINK_STX1;   tx_message_sim.magic2 = DATALINK_STX2;
    tx_message_sim.len    = length;
    tx_message_sim.seq    = 0x00;
    tx_message_sim.sysid  = sysid;
    tx_message_sim.compid = compid; 
    tx_message_sim.msgid  = msgid;    
    memcpy(tx_message_sim.payload, packet, length);    
        
    buf[0] = DATALINK_STX1;  buf[1] = DATALINK_STX2;
    buf[2] = length;         buf[3] = 0x00;
    buf[4] = sysid;          buf[5] = compid;
    buf[6] = msgid;

    checksum = crc_calculate((const quint8*)&buf[2], 5);
    crc_accumulate_buffer(&checksum, packet, length);
    tx_message_sim.ck_a = (quint8)(checksum & 0xFF);
    tx_message_sim.ck_b = (quint8)(checksum >> 8);
}

void  QSerialPortCommu::protocol_send_packet(datalink_message_t tx_message, bool isEcho)
{
    quint8  buf[255], idx;
    QByteArray data;
    
    buf[0] = tx_message.magic1;  buf[1] = tx_message.magic2;
    buf[2] = tx_message.len;
    buf[3] = tx_message.seq;
    buf[4] = tx_message.sysid;
    buf[5] = tx_message.compid;
    buf[6] = tx_message.msgid;
    
    for(idx=7;idx<(tx_message.len+7);idx++)  buf[idx]=tx_message.payload[idx-7];
    buf[tx_message.len+7]=tx_message.ck_a;
    buf[tx_message.len+8]=tx_message.ck_b;
    
    data = QByteArray((const char *)buf,(tx_message.len+9));
    if (serialPort->isOpen()) {        
        if (serialPort->write(data)==-1) {            
            serialPort->close();
            QMessageBox::warning(this,"串口状态","数据发送失败,串口关闭！");
        }
        else {
            if (isEcho==true) {
                cmdTimer->start(1000);
    
                QString  str1= QString("已发指令：%1-0x%2(0x%3)")
                                       .arg(QString::number(tx_message.sysid))  
                                       .arg(QString::number(tx_message.compid,16))
                                       .arg(QString::number(tx_message.msgid,16));
                emit signal_setPrintText(str1,QColor(255,0,0));                
                dataProtocol->setCurrentSendMsg(tx_message_cmd);   //数据发送成功,告诉协议示例当前发送数据
            }
        }
    }
    else  QMessageBox::warning(this,"串口状态","未检测到串口开！");
}

void  QSerialPortCommu::slot_echoSendSuccess()
{
    cmdTimer->stop();                                        //发送成功,停止监控 
    QString str1= QString("发送成功：%1-0x%2(0x%3)")
                           .arg(QString::number(tx_message_cmd.sysid))  
                           .arg(QString::number(tx_message_cmd.compid,16))
                           .arg(QString::number(tx_message_cmd.msgid,16));                           
    emit signal_setPrintText(str1,QColor(0,255,0));          //发布成功    
    emit signal_setsendbutton(true);                     
                                                             //...其它处理：发送按钮有效!
    memset(&tx_message_cmd, 0, sizeof(tx_message_cmd));      //清空发送数据
    dataProtocol->setCurrentSendMsg(tx_message_cmd);         //告诉协议示例
}
 
void  QSerialPortCommu::slot_cmdEchoTimerMonitor()
{
    numRepeatSend--;
    if (numRepeatSend==0) {
        cmdTimer->stop();                                    //发送失败,停止监控  
        QString str1= QString("发送失败：%1-0x%2(0x%3)")
                           .arg(QString::number(tx_message_cmd.sysid))  
                           .arg(QString::number(tx_message_cmd.compid,16))
                           .arg(QString::number(tx_message_cmd.msgid,16));                  
        emit signal_setPrintText(str1,QColor(0,0,255));      //发布失败           
        emit signal_setsendbutton(false);                  
                                                             //...其它处理：发送按钮有效!
        memset(&tx_message_cmd, 0, sizeof(tx_message_cmd));  //清空发送数据
        dataProtocol->setCurrentSendMsg(tx_message_cmd);     //告诉协议示例
        
        QMessageBox::warning(this,"error","未收到回报！");   //tmp used
    }
    else {
        isTxMsgCmd = true;        
    }
}

void  QSerialPortCommu::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == dataTimer.timerId()) {
        tickTimer++;    tickTimer = tickTimer%100;     // tickTimer=10ms
        
        switch (tickTimer%2) {
            case 0:  
                if (isTxMsgCmd==true) {
                    protocol_send_packet(tx_message_cmd, true);    isTxMsgCmd = false;
                }
                break;
            case 1:  
                if (isTxMsgSim==true) {
                    protocol_send_packet(tx_message_sim, false);
                }
                break;
        }        
    } else {
        QWidget::timerEvent(event);
    }
}

void QSerialPortCommu::slot_playback()
{   
    quint8 byte16[16];
    quint8 decodeState, isSYSID;
    QDataStream in(&file);
    
    if (((filepos==0||filepos>0)&&filepos<filelength)&&!in.atEnd()) {
        file.seek(filepos);
        
        if (speed>1||speed==1) {
            for (int i=0;i<speed;i++) {
                in>>byte16[i];
            }
            for (int i=0;i<speed;i++) {
                decodeState = protocol_parse_char(byte16[i], &rx_message_link, &rx_msg_status_link);
                if (decodeState==1) isSYSID = protocol_parse_packet(&rx_message_link);
                isSYSID = isSYSID;
            }

            filepos = filepos+speed;
        }
    }
}

void QSerialPortCommu::savetofile(const quint8 &a)
{
    QDataStream out(&file);
    out<<a;
}

void QSerialPortCommu::record_open()
{
    QString fileName = "recorddata.dat";
    file.setFileName(fileName);
    
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }
    record=true;
}

void QSerialPortCommu::record_close()
{
    record=false;
    file.close();
}

void QSerialPortCommu::playback_open()
{
    filepos=0;

    QString filename1 = "recorddata.dat";
    file.setFileName(filename1);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this, tr("Warning"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(filename1)
                             .arg(file.errorString()));
        return;
    }
    filelength=file.size();
    speed=1;
}

void QSerialPortCommu::slot_setprogeess(int val)
{
    float pos=val/100.0;
    filepos=pos*file.size();
}
