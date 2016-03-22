#include "multiInstall.h"
#include "ui_multiInstall.h"

multiInstallDialog::multiInstallDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multiInstallDialog)
{
    ui->setupUi(this);
    initButtonGroup();
}

multiInstallDialog::~multiInstallDialog()
{
    delete ui;
    if(p_QButtongroup) delete p_QButtongroup;
}

void multiInstallDialog::initButtonGroup()
{
    p_QButtongroup = new QButtonGroup();

    p_QButtongroup->addButton(ui->pushButton__IMU_POSSET,0);
    p_QButtongroup->addButton(ui->pushButton_IMU_POSASK,1);
    p_QButtongroup->addButton(ui->pushButton__GPS_POSSET,2);
    p_QButtongroup->addButton(ui->pushButton__GPS_POSASK,3);

    connect(p_QButtongroup,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdButtonClicked(int)));
}

void multiInstallDialog::slot_cmdButtonClicked(int ButtonID)
{
    quint8  Data[6];
    QString textD;
    int     tmpI;

    switch(ButtonID){
    case 0:
        textD = ui->lineEdit__IMU_POSSETX->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 0, tmpI);
        textD = ui->lineEdit__IMU_POSSETY->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 2, tmpI);
        textD = ui->lineEdit__IMU_POSSETZ->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 4, tmpI);
        emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_POSSET, Data, 6);
        break;
    case 1:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_IMU, UAV_MSG_IMU_POSASK, Data, 0);
        break;
    case 2:
        textD = ui->lineEdit_GPS_POSSETX->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 0, tmpI);
        textD = ui->lineEdit_GPS_POSSETY->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 2, tmpI);
        textD = ui->lineEdit_GPS_POSSETZ->text();  tmpI = textD.toInt(); frame_push_int16_t(Data, 4, tmpI);
        emit signal_cmdOutput(1, UAV_COMP_ID_GPS, UAV_MSG_GPS_POSSET, Data, 6);
        break;
    case 3:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_GPS, UAV_MSG_GPS_POSASK, Data, 0);
        break;
    default:break;
    }
}

void multiInstallDialog::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    int imuPosX,imuPosY,imuPosZ,PosX,PosY,PosZ;

    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];

            switch (msg->compid){
                case UAV_COMP_ID_IMU:
                    switch(echoMsg){
                    case UAV_MSG_IMU_POSSET:
                    case UAV_MSG_IMU_POSASK:
                        imuPosX = frame_return_int16_t(msg->payload, 1);
                        imuPosY = frame_return_int16_t(msg->payload, 3);
                        imuPosZ = frame_return_int16_t(msg->payload, 5);
                        cmdImuPosAskEcho(imuPosX, imuPosY, imuPosZ);
                        break;
                    default:break;
                    }
                    break;
                 case UAV_COMP_ID_GPS:
                     switch (echoMsg){
                     case UAV_MSG_GPS_POSSET:
                     case UAV_MSG_GPS_POSASK:
                         PosX = frame_return_int16_t(msg->payload, 1);
                         PosY = frame_return_int16_t(msg->payload, 3);
                         PosZ = frame_return_int16_t(msg->payload, 5);
                         cmdGpsPosAskEcho(PosX, PosY, PosZ);
                         break;
                     default:break;
                     }
                     break;
            default:break;
            }
    }
}

void multiInstallDialog::cmdImuPosAskEcho(int x, int y, int z)
{
    ui->lineEdit__IMU_POSSETX->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit__IMU_POSSETY->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit__IMU_POSSETZ->setFont(QFont("Times", 8, QFont::Bold));

    ui->lineEdit__IMU_POSSETX->setText(QString::number(x));
    ui->lineEdit__IMU_POSSETY->setText(QString::number(y));
    ui->lineEdit__IMU_POSSETZ->setText(QString::number(z));
}

void multiInstallDialog::cmdGpsPosAskEcho(int x, int y, int z)
{
    ui->lineEdit_GPS_POSSETX->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit_GPS_POSSETY->setFont(QFont("Times", 8, QFont::Bold));
    ui->lineEdit_GPS_POSSETZ->setFont(QFont("Times", 8, QFont::Bold));

    ui->lineEdit_GPS_POSSETX->setText(QString::number(x));
    ui->lineEdit_GPS_POSSETY->setText(QString::number(y));
    ui->lineEdit_GPS_POSSETZ->setText(QString::number(z));
}





















