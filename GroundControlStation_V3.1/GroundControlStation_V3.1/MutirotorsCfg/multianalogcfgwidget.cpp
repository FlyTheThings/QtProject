#include "multianalogcfgwidget.h"
#include "ui_multianalogcfgwidget.h"

multiAnalogCfgWidget::multiAnalogCfgWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multiAnalogCfgWidget)
{
    ui->setupUi(this);

    p_Timer = new QTimer(this);
    initButtonGroup();

    connect(p_Timer, SIGNAL(timeout()),   this, SLOT(slot_ADTimerDisplay()));
}

multiAnalogCfgWidget::~multiAnalogCfgWidget()
{
    delete ui;
}

void multiAnalogCfgWidget::initButtonGroup(void)
{
    p_QButtongroup = new QButtonGroup();

    p_QButtongroup->addButton(ui->pushButton_Set_CH0,0);
    p_QButtongroup->addButton(ui->pushButton_Ask_CH0,1);
    p_QButtongroup->addButton(ui->pushButton_Set_CH1,2);
    p_QButtongroup->addButton(ui->pushButton_Ask_CH1,3);
    p_QButtongroup->addButton(ui->pushButton_Set_CH2,4);
    p_QButtongroup->addButton(ui->pushButton_Ask_CH2,5);
    p_QButtongroup->addButton(ui->pushButton_Set_CH3,6);
    p_QButtongroup->addButton(ui->pushButton_Ask_CH3,7);

    connect(p_QButtongroup,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdButtonClicked(int)));
}

void multiAnalogCfgWidget::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    float  tmpF;
    quint8 index;
    qint32 tmpL;

    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];

            switch (msg->compid){
                case UAV_COMP_ID_FCC:
                    switch(echoMsg){
                       case UAV_MSG_FCC_ADSET:
                       case UAV_MSG_FCC_ADASK:
                            index = frame_return_uint8_t(msg->payload,1);
                            switch(index){
                             case 0x00:
                                tmpF = frame_return_float(msg->payload,2); ui->lineEdit_Ratio_CH0->setText(QString::number(tmpF,'f',4));
                                tmpF = frame_return_float(msg->payload,6); ui->lineEdit_Offset_CH0->setText(QString::number(tmpF,'f',4));
                             break;
                             case 0x01:
                                tmpF = frame_return_float(msg->payload,2); ui->lineEdit_Ratio_CH1->setText(QString::number(tmpF,'f',4));
                                tmpF = frame_return_float(msg->payload,6); ui->lineEdit_Offset_CH1->setText(QString::number(tmpF,'f',4));
                             break;
                             case 0x02:
                                tmpF = frame_return_float(msg->payload,2); ui->lineEdit_Ratio_CH2->setText(QString::number(tmpF,'f',4));
                                tmpF = frame_return_float(msg->payload,6); ui->lineEdit_Offset_CH2->setText(QString::number(tmpF,'f',4));
                             break;
                             case 0x03:
                                tmpF = frame_return_float(msg->payload,2); ui->lineEdit_Ratio_CH3->setText(QString::number(tmpF,'f',4));
                                tmpF = frame_return_float(msg->payload,6); ui->lineEdit_Offset_CH3->setText(QString::number(tmpF,'f',4));
                             break;
                             case 0xFF:
                                tmpL = frame_return_int32_t(msg->payload,2);  ui->lineEdit_Vol_CH0->setText(QString::number(tmpL*1e-3,'f',4));
                                tmpF = frame_return_float(msg->payload,6);    ui->lineEdit_Val_CH0->setText(QString::number(tmpF,'f',4));
                                tmpL = frame_return_int32_t(msg->payload,10); ui->lineEdit_Vol_CH1->setText(QString::number(tmpL*1e-3,'f',4));
                                tmpF = frame_return_float(msg->payload,14);   ui->lineEdit_Val_CH1->setText(QString::number(tmpF,'f',4));
                                tmpL = frame_return_int32_t(msg->payload,18); ui->lineEdit_Vol_CH2->setText(QString::number(tmpL*1e-3,'f',4));
                                tmpF = frame_return_float(msg->payload,22);   ui->lineEdit_Val_CH2->setText(QString::number(tmpF,'f',4));
                                tmpL = frame_return_int32_t(msg->payload,26); ui->lineEdit_Vol_CH3->setText(QString::number(tmpL*1e-3,'f',4));
                                tmpF = frame_return_float(msg->payload,30);   ui->lineEdit_Val_CH3->setText(QString::number(tmpF,'f',4));
                             break;
                            }

                            break;
                    }
            }
    }
}

void multiAnalogCfgWidget::slot_cmdButtonClicked(int ButtonID)
{
    quint8   Data[12];
    float    tmpF;
    quint8   index=0;

    switch(ButtonID){
    case 0:
        index=0;                                          frame_push_uint8_t(Data, 0, index);
        tmpF = ui->lineEdit_Ratio_CH0->text().toFloat();  frame_push_float(Data, 1, tmpF);
        tmpF = ui->lineEdit_Offset_CH0->text().toFloat(); frame_push_float(Data, 5, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADSET, Data, 9);
        break;
    case 1:
        index=0;  frame_push_uint8_t(Data, 0, index);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADASK, Data, 1);
        break;
    case 2:
        index=1;                                          frame_push_uint8_t(Data, 0, index);
        tmpF = ui->lineEdit_Ratio_CH1->text().toFloat();  frame_push_float(Data, 1, tmpF);
        tmpF = ui->lineEdit_Offset_CH1->text().toFloat(); frame_push_float(Data, 5, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADSET, Data, 9);
        break;
    case 3:
        index=1;  frame_push_uint8_t(Data, 0, index);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADASK, Data, 1);
        break;
    case 4:
        index=2;                                          frame_push_uint8_t(Data, 0, index);
        tmpF = ui->lineEdit_Ratio_CH2->text().toFloat();  frame_push_float(Data, 1, tmpF);
        tmpF = ui->lineEdit_Offset_CH2->text().toFloat(); frame_push_float(Data, 5, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADSET, Data, 9);
        break;
    case 5:
        index=2;  frame_push_uint8_t(Data, 0, index);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADASK, Data, 1);
        break;
    case 6:
        index=3;                                          frame_push_uint8_t(Data, 0, index);
        tmpF = ui->lineEdit_Ratio_CH3->text().toFloat();  frame_push_float(Data, 1, tmpF);
        tmpF = ui->lineEdit_Offset_CH3->text().toFloat(); frame_push_float(Data, 5, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADSET, Data, 9);
        break;
    case 7:
        index=3;  frame_push_uint8_t(Data, 0, index);
        emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADASK, Data, 1);
        break;
    default:  break;
    }
}

void multiAnalogCfgWidget::slot_ADTimerDisplay()
{
   quint8 Data[2];

   Data[0]=0xFF;
   emit signal_cmdOutput(1, UAV_COMP_ID_FCC, UAV_MSG_FCC_ADASK, Data, 1);
}

void multiAnalogCfgWidget::showEvent(QShowEvent * event)
{
    Q_UNUSED(event);
    p_Timer->start(500);
}

void multiAnalogCfgWidget::hideEvent(QHideEvent * event)
{
    Q_UNUSED(event);
    if(p_Timer) p_Timer->stop();
}
