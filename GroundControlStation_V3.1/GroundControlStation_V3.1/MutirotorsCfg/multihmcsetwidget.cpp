#include "multihmcsetwidget.h"
#include "ui_multihmcsetwidget.h"

multiHMCsetWidget::multiHMCsetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multiHMCsetWidget)
{
    ui->setupUi(this);
    initButtonGroup();
}

multiHMCsetWidget::~multiHMCsetWidget()
{
    delete ui;
}

void   multiHMCsetWidget::initButtonGroup(void)
{
    p_QButtongroup = new QButtonGroup();

    p_QButtongroup->addButton(ui->pushButton_PSIOFFSET,0);
    p_QButtongroup->addButton(ui->pushButton_PSIOFFASK,1);
    p_QButtongroup->addButton(ui->pushButton_CALSTART,2);
    p_QButtongroup->addButton(ui->pushButton_CALEND,3);
    p_QButtongroup->addButton(ui->pushButton_CALSave,4);
    p_QButtongroup->addButton(ui->pushButton_CALSTOP,5);
    p_QButtongroup->addButton(ui->pushButton_CALASK,6);
    p_QButtongroup->addButton(ui->pushButton_HMCdir_Set,7);
    p_QButtongroup->addButton(ui->pushButton_HMCdir_Ask,8);

    connect(p_QButtongroup,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdButtonClicked(int)));
}

void  multiHMCsetWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    float  tmpF;
    quint8  tmpI;

    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];

            switch (msg->compid){
                case UAV_COMP_ID_HMR:
                    switch(echoMsg){
                       case UAV_MSG_HMR_PSIOFFSET:
                       case UAV_MSG_HMR_PSIOFFASK:
                            tmpF = frame_return_float(msg->payload,1);  ui->lineEdit_PSIOFF->setText(QString::number(tmpF));
                       break;
                       case UAV_MSG_HMR_CALSTART:    break;
                       case UAV_MSG_HMR_CALEND:
                       case UAV_MSG_HMR_CALSET:
                       case UAV_MSG_HMR_CALASK:
                            tmpF=frame_return_float(msg->payload,1);    ui->lineEdit_KX->setText(QString::number(tmpF));
                            tmpF=frame_return_float(msg->payload,5);    ui->lineEdit_KY->setText(QString::number(tmpF));
                            tmpF=frame_return_float(msg->payload,9);    ui->lineEdit_BX->setText(QString::number(tmpF));
                            tmpF=frame_return_float(msg->payload,13);   ui->lineEdit_BY->setText(QString::number(tmpF));
                        break;
                       case UAV_MSG_HMR_CALSTOP:     break;
                       case UAV_MSG_HMR_DIRSET:
                       case UAV_MSG_HMR_DIRASK:
                            tmpI=frame_return_uint8_t(msg->payload,1);  ui->comboBox_HMCDIR->setCurrentIndex(tmpI);
                        break;
                    }
            }
    }
}

void multiHMCsetWidget::slot_cmdButtonClicked(int ButtonID)
{
    quint8   Data[16];
    float    tmpF;
    quint8   tmpI;

    switch(ButtonID){
    case 0:
        tmpF = ui->lineEdit_PSIOFF->text().toFloat();     frame_push_float(Data,0,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_PSIOFFSET, Data, 4);
        break;
    case 1:
        Data[0]=0;
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_PSIOFFASK, Data, 0);
        break;
    case 2:
        Data[0]=0;
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALSTART, Data, 0);
        break;
    case 3:
        Data[0]=0;
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALEND, Data, 0);
        break;
    case 4:
        tmpF = ui->lineEdit_KX->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->lineEdit_KY->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->lineEdit_BX->text().toFloat(); frame_push_float(Data,8,tmpF);
        tmpF = ui->lineEdit_BY->text().toFloat(); frame_push_float(Data,12,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALSET, Data, 16);
        break;
    case 5:
        Data[0]=0;
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALSTOP, Data, 0);
        break;
    case 6:
        Data[0]=0;
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_CALASK, Data, 0);
        break;
    case 7:
        tmpI = ui->comboBox_HMCDIR->currentIndex();
        frame_push_uint8_t(Data,0,tmpI);
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_DIRSET, Data, 1);
        break;
    case 8:
        Data[0]=0;
        emit signal_cmdOutput(1, UAV_COMP_ID_HMR, UAV_MSG_HMR_DIRASK, Data, 0);
        break;
    default:  break;
    }
}
