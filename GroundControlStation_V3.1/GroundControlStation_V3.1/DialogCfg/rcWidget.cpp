#include "rcWidget.h"
#include "ui_rcWidget.h"

QRcWidget::QRcWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QRcWidget)
{
    ui->setupUi(this);
    
    initButtonGroup1();
    initButtonGroup2();

    ui->progressBar_cap1->setRange(-200,200);
    ui->progressBar_cap2->setRange(-200,200);
    ui->progressBar_cap3->setRange(-200,200);
    ui->progressBar_cap4->setRange(-200,200);
    ui->progressBar_cap5->setRange(-200,200);
    ui->progressBar_cap6->setRange(-200,200);
    ui->progressBar_cap7->setRange(-200,200);
    ui->progressBar_cap8->setRange(-200,200);
    ui->progressBar_cap9->setRange(-200,200);
    ui->progressBar_cap10->setRange(-200,200);
    
    p_Timer = new QTimer();
    connect(p_Timer, SIGNAL(timeout()),   this, SLOT(slot_rcCapTimerDisplay()));
}

QRcWidget::~QRcWidget()
{
    delete ui;
    if (p_QButtongroupFlag)  delete p_QButtongroupFlag;
    if (p_QButtongroupFlag1) delete p_QButtongroupFlag1;
    if (flag)                delete flag;
    if (p_Timer)             delete p_Timer;
}

void QRcWidget::initButtonGroup1()
{
    flag = new int[10];
    for(int i=0;i<10;i++) flag[i]=1;
    
    p_QButtongroupFlag = new QButtonGroup();
    p_QButtongroupFlag->addButton(ui->pushButton_switch,0);
    p_QButtongroupFlag->addButton(ui->pushButton_ele,   1);
    p_QButtongroupFlag->addButton(ui->pushButton_ail,   2);
    p_QButtongroupFlag->addButton(ui->pushButton_col,   3);
    p_QButtongroupFlag->addButton(ui->pushButton_rud,   4);
    p_QButtongroupFlag->addButton(ui->pushButton_oil,   5);
    p_QButtongroupFlag->addButton(ui->pushButton_en,    6);
    p_QButtongroupFlag->addButton(ui->pushButton_water, 7);
    p_QButtongroupFlag->addButton(ui->pushButton_flow,  8);
    p_QButtongroupFlag->addButton(ui->pushButton_rc10,  9);    
    connect(p_QButtongroupFlag,SIGNAL(buttonClicked(int)),this,SLOT(slot_dirButtonClicked(int)));
}

void QRcWidget::initButtonGroup2()
{ 
    p_QButtongroupFlag1 = new QButtonGroup();
    p_QButtongroupFlag1->addButton(ui->pushButton_rccali_start,  0);
    p_QButtongroupFlag1->addButton(ui->pushButton_rccali_mid,    1);
    p_QButtongroupFlag1->addButton(ui->pushButton_rccali_end,    2);
    p_QButtongroupFlag1->addButton(ui->pushButton_rcask,         3);
    p_QButtongroupFlag1->addButton(ui->pushButton_rc_receiveset, 4);
    p_QButtongroupFlag1->addButton(ui->pushButton_rc_receiveask, 5);    
    connect(p_QButtongroupFlag1,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdButtonClicked(int)));
}

void QRcWidget::slot_dirButtonClicked(int i)
{ 
    quint8  Data[2];
        
    flag[i] = -flag[i];
    Data[0] = i;  Data[1] = flag[i]; 

    switch(i){
    case 0:if(flag[i] == 1)
            ui->pushButton_switch->setText(tr("正向"));
           else
            ui->pushButton_switch->setText(tr("反向"));
           break;
    case 1:if(flag[i] == 1)
            ui->pushButton_ele->setText(tr("正向"));
           else
            ui->pushButton_ele->setText(tr("反向"));
           break;
    case 2:if(flag[i] == 1)
            ui->pushButton_ail->setText(tr("正向"));
           else
            ui->pushButton_ail->setText(tr("反向"));
           break;
    case 3:if(flag[i] == 1)
            ui->pushButton_col->setText(tr("正向"));
           else
            ui->pushButton_col->setText(tr("反向"));
           break;
    case 4:if(flag[i] == 1)
            ui->pushButton_rud->setText(tr("正向"));
           else
            ui->pushButton_rud->setText(tr("反向"));
           break;
    case 5:if(flag[i] == 1)
            ui->pushButton_oil->setText(tr("正向"));
           else
            ui->pushButton_oil->setText(tr("反向"));
           break;
    case 6:if(flag[i] == 1)
            ui->pushButton_en->setText(tr("正向"));
           else
            ui->pushButton_en->setText(tr("反向"));
           break;
    case 7:if(flag[i] == 1)
            ui->pushButton_water->setText(tr("正向"));
           else
            ui->pushButton_water->setText(tr("反向"));
           break;
    case 8:if(flag[i] == 1)
            ui->pushButton_flow->setText(tr("正向"));
           else
            ui->pushButton_flow->setText(tr("反向"));
           break;
    case 9:if(flag[i] == 1)
            ui->pushButton_rc10->setText(tr("正向"));
           else
            ui->pushButton_rc10->setText(tr("反向"));
           break;
    default:break;
    }

    emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_DIRSET, Data, 2);
}

void QRcWidget::slot_cmdButtonClicked(int ButtonID)
{ 
    quint8  Data[1];    
    
    switch(ButtonID) {
        case  0: //pushButton_rccali_start
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CALISTART, Data, 0); 
            break;
        case  1: //pushButton_rccali_mid 
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CALIMID, Data, 0);  
            break;
        case  2: //pushButton_rccali_end
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CALIEND, Data, 0);     
            if (p_Timer->isActive()) p_Timer->stop();
            break;
        case  3: //pushButton_rcask
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP1ASK, Data, 0); 
//            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP2ASK, Data, 0);
//            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP3ASK, Data, 0);
//            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP4ASK, Data, 0);
//            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP5ASK, Data, 0);
            break;
        case  4: //pushButton_rc_receiveset                                                         
            Data[0] = (quint8)ui->comboBox_captype->currentIndex();
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_RECEIVESET, Data, 1); 
            break;
        case  5: //pushButton_rc_receiveask 
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_RECEIVEASK, Data, 0);  
            break;
    }
}

void QRcWidget::slot_rcCapTimerDisplay()
{      
    quint8 Data[1];
    emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CHDATA, Data, 0);      
}

void QRcWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tempI, tmpData[64];
    
    switch (msg->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = msg->payload[0];	        
	        switch (echoMsg) {
                case UAV_MSG_REQU_SAVE:     break;
                case UAV_MSG_REQU_DEL:      break;
                case UAV_MSG_RC_RECEIVESET:
                case UAV_MSG_RC_RECEIVEASK:
                    tempI = frame_return_uint8_t(msg->payload,1);
                    rcTypeEchoOk(tempI);
                    break;
                case UAV_MSG_RC_CALISTART:  if(!p_Timer->isActive()) p_Timer->start(200);  break;
                case UAV_MSG_RC_CALIMID:    break;
                case UAV_MSG_RC_CALIEND:    break;
                case UAV_MSG_RC_DIRSET:     break;
                case UAV_MSG_RC_CAP1ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(1, tmpData);
                    break;
                case UAV_MSG_RC_CAP2ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(2, tmpData);
                    break;
                case UAV_MSG_RC_CAP3ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(3, tmpData);
                    break;
                case UAV_MSG_RC_CAP4ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(4, tmpData);
                    break;
                case UAV_MSG_RC_CAP5ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(5, tmpData);
                    break;
                case UAV_MSG_RC_CAP6ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(6, tmpData);
                    break;
                case UAV_MSG_RC_CAP7ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(7, tmpData);
                    break;
                case UAV_MSG_RC_CAP8ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(8, tmpData);
                    break;
                case UAV_MSG_RC_CAP9ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(9, tmpData);
                    break;
                case UAV_MSG_RC_CAP10ASK:
                    for (int idx=0; idx<13; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcCaliAskEchoOk(10, tmpData);
                    break;
                case UAV_MSG_RC_REQU:       break;
                case UAV_MSG_RC_CHDATA:
                    for (int idx=0; idx<40; idx++) tmpData[idx] = msg->payload[idx+1];
                    rcRawDataEchoOk(tmpData);
                    break;
                case UAV_MSG_RC_CAP:        break;	            
	            default:                    break;    
	        }
	        break;
        default: break;
	}
}


void QRcWidget::rcRawDataEchoOk(quint8 *data)
{
    float value=0;
    value = frame_return_float(data, 0);  ui->progressBar_cap1->setValue(value);
    value = frame_return_float(data, 4);  ui->progressBar_cap2->setValue(value);
    value = frame_return_float(data, 8);  ui->progressBar_cap3->setValue(value);
    value = frame_return_float(data, 12);  ui->progressBar_cap4->setValue(value);
    value = frame_return_float(data, 16);  ui->progressBar_cap5->setValue(value);
    value = frame_return_float(data,20);  ui->progressBar_cap6->setValue(value);
    value = frame_return_float(data,24);  ui->progressBar_cap7->setValue(value);
    value = frame_return_float(data,28);  ui->progressBar_cap8->setValue(value);
    value = frame_return_float(data,32);  ui->progressBar_cap9->setValue(value);
    value = frame_return_float(data,36);  ui->progressBar_cap10->setValue(value);
}

void QRcWidget::rcTypeEchoOk(quint8 x)
{
    ui->comboBox_captype->setFont(QFont("Times", 8, QFont::Bold));
    ui->comboBox_captype->setCurrentIndex(x);
}

void QRcWidget::rcCaliAskEchoOk(quint8 x, quint8 *data)
{
    quint8  Data[1];

    switch (x) {
        case 1:
            ui->lineEdit_cap1mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap1max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap1min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_switch->setText(tr("正向"));
            else                                 ui->pushButton_switch->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP2ASK, Data, 0);
            break;
        case 2:
            ui->lineEdit_cap2mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap2max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap2min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_ele->setText(tr("正向"));
            else                                 ui->pushButton_ele->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP3ASK, Data, 0);
            break;
        case 3:
            ui->lineEdit_cap3mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap3max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap3min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_ail->setText(tr("正向"));
            else                                 ui->pushButton_ail->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP4ASK, Data, 0);
            break;
        case 4:
            ui->lineEdit_cap4mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap4max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap4min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_col->setText(tr("正向"));
            else                                 ui->pushButton_col->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP5ASK, Data, 0);
            break;
        case 5:
            ui->lineEdit_cap5mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap5max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap5min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_rud->setText(tr("正向"));
            else                                 ui->pushButton_rud->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP6ASK, Data, 0);
            break;
        case 6:
            ui->lineEdit_cap6mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap6max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap6min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_oil->setText(tr("正向"));
            else                                 ui->pushButton_oil->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP7ASK, Data, 0);
            break;
        case 7:
            ui->lineEdit_cap7mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap7max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap7min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_en->setText(tr("正向"));
            else                                 ui->pushButton_en->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP8ASK, Data, 0);
            break;
        case 8:
            ui->lineEdit_cap8mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap8max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap8min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_water->setText(tr("正向"));
            else                                 ui->pushButton_water->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP9ASK, Data, 0);
            break;
        case 9:
            ui->lineEdit_cap9mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap9max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap9min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_flow->setText(tr("正向"));
            else                                 ui->pushButton_flow->setText(tr("反向"));
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CAP10ASK, Data, 0);
            break;
        case 10:
            ui->lineEdit_cap10mid->setText(QString::number(frame_return_float(data, 0)));
            ui->lineEdit_cap10max->setText(QString::number(frame_return_float(data, 4)));
            ui->lineEdit_cap10min->setText(QString::number(frame_return_float(data, 8)));
            if (frame_return_int8_t(data, 12)==1) ui->pushButton_rc10->setText(tr("正向"));
            else                                 ui->pushButton_rc10->setText(tr("反向"));
            break;
    }
}
