#include "multiRC.h"
#include "ui_multiRC.h"

mutiRCDialog::mutiRCDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mutiRCDialog)
{
    ui->setupUi(this);

    p_Timer = new QTimer();
    flag    = new int[5]{1,1,1,1,1};
    caliState = 0;
    ui->progressBar->setRange(-200,200);
    ui->progressBar_2->setRange(-200,200);
    ui->progressBar_3->setRange(-200,200);
    ui->progressBar_4->setRange(-200,200);
    ui->progressBar_5->setRange(-200,200);

    initButtonGroup();
    initCmdButtonGroup();
    connect(p_Timer, SIGNAL(timeout()),   this, SLOT(slot_rcCapTimerDisplay()));
}

mutiRCDialog::~mutiRCDialog()
{
    delete ui;
}

void mutiRCDialog::initButtonGroup()
{
    p_QButtongroupFlag = new QButtonGroup();
    p_QButtongroupFlag->addButton(ui->pushButton_switch,0);
    p_QButtongroupFlag->addButton(ui->pushButton_ele,1);
    p_QButtongroupFlag->addButton(ui->pushButton_ail,2);
    p_QButtongroupFlag->addButton(ui->pushButton_col,3);
    p_QButtongroupFlag->addButton(ui->pushButton_rud,4);    

    connect(p_QButtongroupFlag,SIGNAL(buttonClicked(int)),this,SLOT(slot_dirButtonClicked(int)));
}

void mutiRCDialog::initCmdButtonGroup()
{
    cmdButtonGroup = new QButtonGroup();
    cmdButtonGroup->addButton(ui->pushButton_rc_receiveset,0);
    cmdButtonGroup->addButton(ui->pushButton_rc_receiveask,1);
    cmdButtonGroup->addButton(ui->pushButton_rccali,2);
    connect(cmdButtonGroup,SIGNAL(buttonClicked(int)),this,SLOT(slot_CmdButtonGroup(int)));
}

void mutiRCDialog::slot_dirButtonClicked(int i)
{
    quint8  Data[2];
    flag[i] = -flag[i];
    Data[0] = i;  Data[1] = flag[i];

    switch(i){
    case 0:
        if(flag[i] == 1) ui->pushButton_switch->setText(tr("正向"));
        else             ui->pushButton_switch->setText(tr("反向"));
        break;
    case 1:
        if(flag[i] == 1) ui->pushButton_ele->setText(tr("正向"));
        else             ui->pushButton_ele->setText(tr("反向"));
        break;
    case 2:
        if(flag[i] == 1) ui->pushButton_ail->setText(tr("正向"));
            else             ui->pushButton_ail->setText(tr("反向"));
            break;
        case 3:
            if(flag[i] == 1) ui->pushButton_col->setText(tr("正向"));
            else             ui->pushButton_col->setText(tr("反向"));
            break;
        case 4:
            if(flag[i] == 1) ui->pushButton_rud->setText(tr("正向"));
            else             ui->pushButton_rud->setText(tr("反向"));
            break;
        default:break;
    }
    emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_DIRSET, Data, 2);
}

void mutiRCDialog::slot_CmdButtonGroup(int i)
{
    quint8 Data;

    switch(i){
    case 0:
        if(ui->radioButton_PWM->isChecked()) Data = 0;
        else if(ui->radioButton_STU->isChecked()) Data = 1;
        else if(ui->radioButton_DSM2->isChecked()) Data = 2;
        else if(ui->radioButton_S_BUS->isChecked()) Data = 3;
        else if(ui->radioButton_X_BUS->isChecked()) Data = 4;
        emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_RECEIVESET, &Data, 1);
        break;
    case 1:
        emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_RECEIVEASK, &Data, 0);
        break;
    case 2:
        if(caliState == 0)
        {
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CALISTART, &Data, 0);

        }
        if(caliState == 1)
        {
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CALIMID, &Data, 0);
         //   if (p_Timer) p_Timer->stop();
        }
        if(caliState == 2)
        {
            emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CALIEND, &Data, 0);
          //  if (p_Timer) p_Timer->stop();

        }
        break;
        default: break;
    }
}

void mutiRCDialog::slot_rcCapTimerDisplay()
{
    quint8 Data[1];
    emit signal_cmdOutput(1, UAV_COMP_ID_RC1, UAV_MSG_RC_CHDATA, Data, 0);
}

void mutiRCDialog::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tempI, tmpData[30];

    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];
            switch (echoMsg) {
            case UAV_MSG_RC_RECEIVESET:
            case UAV_MSG_RC_RECEIVEASK:
                tempI = frame_return_uint8_t(msg->payload,1);
                rcTypeEchoOk(tempI);
                break;
            case UAV_MSG_RC_CALISTART:
                caliState = 1;
                ui->pushButton_rccali->setText(tr("校准中位"));
                break;
            case UAV_MSG_RC_CALIMID:
                caliState = 2;
                ui->pushButton_rccali->setText(tr("校准完成"));
                break;
            case UAV_MSG_RC_CALIEND:
                caliState = 0;
                ui->pushButton_rccali->setText(tr("校准开始"));
                break;
            case UAV_MSG_RC_CHDATA:
                for (int idx=0; idx<20; idx++) tmpData[idx] = msg->payload[idx+1];
                rcRawDataEchoOk(tmpData);
                break;
            default:break;
            }
        break;
    default: break;
    }
}

void mutiRCDialog::rcTypeEchoOk(quint8 x)
{
    switch(x){
    case 0:ui->radioButton_PWM->setChecked(true);break;
    case 1:ui->radioButton_STU->setChecked(true);break;
    case 2:ui->radioButton_DSM2->setChecked(true);break;
    case 3:ui->radioButton_S_BUS->setChecked(true);break;
    case 4:ui->radioButton_X_BUS->setChecked(true);break;
    default:break;
    }
}

void mutiRCDialog::rcRawDataEchoOk(quint8 *data)
{
    float value=0;
    value = frame_return_float(data, 0);  ui->progressBar->setValue(value);
    value = frame_return_float(data, 4);  ui->progressBar_2->setValue(value);
    value = frame_return_float(data, 8);  ui->progressBar_3->setValue(value);
    value = frame_return_float(data, 12);  ui->progressBar_5->setValue(value);
    value = frame_return_float(data, 16);  ui->progressBar_4->setValue(value);
}

void mutiRCDialog::showEvent(QShowEvent * event)
{
    Q_UNUSED(event);
    p_Timer->start(200);
}

void mutiRCDialog::hideEvent(QHideEvent * event)
{
    Q_UNUSED(event);
    if(p_Timer) p_Timer->stop();
}
