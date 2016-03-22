#include "installwidget.h"
#include "ui_installwidget.h"

QInstallWidget::QInstallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QInstallWidget)
{
    ui->setupUi(this);
    
    initButtonGroup();
}

QInstallWidget::~QInstallWidget()
{
    delete ui;
}

void QInstallWidget::initButtonGroup()
{
    QButtonGroup *buttongroup = new QButtonGroup(this);
    
    buttongroup->addButton(ui->pushButton__IMU_DIRSET_FRONT,  0);
    buttongroup->addButton(ui->pushButton__IMU_DIRSET_BEHIND, 1);
    buttongroup->addButton(ui->pushButton__IMU_DIRSET_LEFT,   2);
    buttongroup->addButton(ui->pushButton__IMU_DIRSET_RIGHT,  3);
    buttongroup->addButton(ui->pushButton__GPS_DIRSET_FRONT,  4);
    buttongroup->addButton(ui->pushButton__GPS_DIRSET_BEHIND, 5);
    buttongroup->addButton(ui->pushButton__GPS_DIRSET_LEFT,   6);
    buttongroup->addButton(ui->pushButton__GPS_DIRSET_RIGHT,  7);    
    buttongroup->addButton(ui->pushButton__GPS_POSASK,        8);
    buttongroup->addButton(ui->pushButton__GPS_POSSET,        9);
    buttongroup->addButton(ui->pushButton_IMU_POSASK,        10);
    buttongroup->addButton(ui->pushButton__IMU_POSSET,       11);      
    connect(buttongroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_buttonSelect(int)));
}

void QInstallWidget::slot_buttonSelect(int button)
{
    quint8  Data[6];
    QString textD;
    int     tmpI;
            
    switch(button) {
        case  0: //pushButton__IMU_DIRSET_FRONT                                                  
            Data[0] = 0x01;                                                         
            emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_DIRSET, Data, 1); 
            break;
        case  1: //pushButton__IMU_DIRSET_BEHIND
            Data[0] = 0x02;
            emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_DIRSET, Data, 1);
            break;
        case  2: //pushButton__IMU_DIRSET_LEFT
            Data[0] = 0x03;
            emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_DIRSET, Data, 1);
            break;
        case  3: //pushButton__IMU_DIRSET_RIGHT
            Data[0] = 0x04;
            emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_DIRSET, Data, 1);
            break;
        case  4: //pushButton__GPS_DIRSET_FRONT
            Data[0] = 0x01;
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_DIRSET, Data, 1);
            break;
        case  5: //pushButton__GPS_DIRSET_BEHIND
            Data[0] = 0x02;
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_DIRSET, Data, 1);
            break;
        case  6: //pushButton__GPS_DIRSET_LEFT
            Data[0] = 0x03;
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_DIRSET, Data, 1);
            break;
        case  7: //pushButton__GPS_DIRSET_RIGHT
            Data[0] = 0x04;
            emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_DIRSET, Data, 1);
            break;
        case  8: //pushButton__GPS_POSASK
            Data[0] = 0x00;
            emit signal_cmdOutput(1, UAV_COMP_ID_GPS, UAV_MSG_GPS_POSASK, Data, 0);
            break;
        case  9: //pushButton__GPS_POSSET
            textD = ui->lineEdit_GPS_POSSETX->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 0, tmpI);
            textD = ui->lineEdit_GPS_POSSETY->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 2, tmpI);
            textD = ui->lineEdit_GPS_POSSETZ->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 4, tmpI);
            emit signal_cmdOutput(1, UAV_COMP_ID_GPS, UAV_MSG_GPS_POSSET, Data, 6);
            break;
        case 10: //pushButton_IMU_POSASK
            Data[0] = 0x00;
            emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_POSASK, Data, 0);
            break;
        case 11: //pushButton__IMU_POSSET
            textD = ui->lineEdit__IMU_POSSETX->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 0, tmpI);
            textD = ui->lineEdit__IMU_POSSETY->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 2, tmpI);
            textD = ui->lineEdit__IMU_POSSETZ->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 4, tmpI);    
            emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_POSSET, Data, 6);
            break;
    }
}

void QInstallWidget::echoMessagePacket(datalink_message_t *msg)
{    
    quint8 echoMsg;
    int imuPosX,imuPosY,imuPosZ,PosX,PosY,PosZ;
    
    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];

            switch (msg->compid){
                case UAV_COMP_ID_IMU:
                    switch(echoMsg){
                        case UAV_MSG_REQU_SAVE:    break;
                        case UAV_MSG_REQU_DEL:     break;
                        case UAV_MSG_IMU_DIRSET:
                        case UAV_MSG_IMU_DIRASK:
                            //data_imu.dir  = frame_return_float(msg->payload, 1);
                            break;
                        case UAV_MSG_IMU_POSSET:
                        case UAV_MSG_IMU_POSASK:
                            imuPosX = frame_return_int16_t(msg->payload, 1);
                            imuPosY = frame_return_int16_t(msg->payload, 3);
                            imuPosZ = frame_return_int16_t(msg->payload, 5);
                            cmdImuPosAskEcho(imuPosX, imuPosY, imuPosZ);
                            break;
                        case UAV_MSG_IMU_REQU:     break;
                        case UAV_MSG_IMU_RAWDATA:  break;
                        case UAV_MSG_IMU_INFODATA: break;
                        default:                   break;
                    }
                    break;
                case UAV_COMP_ID_GPS:
                    switch (echoMsg){
                        case UAV_MSG_REQU_SAVE:     break;
                        case UAV_MSG_REQU_DEL:      break;
                        case UAV_MSG_GPS_POSSET:
                        case UAV_MSG_GPS_POSASK:
                            PosX = frame_return_int16_t(msg->payload, 1);
                            PosY = frame_return_int16_t(msg->payload, 3);
                            PosZ = frame_return_int16_t(msg->payload, 5);
                            cmdGpsPosAskEcho(PosX, PosY, PosZ);
                            break;
                        case UAV_MSG_GPS_REQU:      break;
                        case UAV_MSG_GPS_RAWDATA:   break;
                        case UAV_MSG_GPS_INFODATA:  break;
                        default:                    break;
                    }
                    break;
                default: break;
            }
            break;
        default: break;
    }
}

void QInstallWidget::cmdGpsPosAskEcho(int x, int y, int z)
{
    ui->lineEdit_GPS_POSSETX->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit_GPS_POSSETY->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit_GPS_POSSETZ->setFont(QFont("Times", 8, QFont::Bold));

    ui->lineEdit_GPS_POSSETX->setText(QString::number(x));
    ui->lineEdit_GPS_POSSETY->setText(QString::number(y));
    ui->lineEdit_GPS_POSSETZ->setText(QString::number(z));
}

void QInstallWidget::cmdImuPosAskEcho(int x, int y, int z)
{
    ui->lineEdit__IMU_POSSETX->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit__IMU_POSSETY->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit__IMU_POSSETZ->setFont(QFont("Times", 8, QFont::Bold));

    ui->lineEdit__IMU_POSSETX->setText(QString::number(x));
    ui->lineEdit__IMU_POSSETY->setText(QString::number(y));
    ui->lineEdit__IMU_POSSETZ->setText(QString::number(z));
}

