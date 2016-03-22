#include "multicontrol.h"
#include "ui_multicontrol.h"
#include "QDebug"

multicontrol::multicontrol(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multicontrol)
{
    ui->setupUi(this);
    connect(ui->comboBox_control,SIGNAL(activated(int)),SLOT(selectcontrol(int)));

    initButtonGroupEle();
    initButtonGroupAil();
    initButtonGroupCol();
    initButtonGroupRud();
}

multicontrol::~multicontrol()
{
    delete ui;
}

void multicontrol::selectcontrol(int index)
{
    switch(index)
    {
    case 0:  ui->stackedWidget_3->setCurrentIndex(0);break;
    case 1:  ui->stackedWidget_3->setCurrentIndex(1);break;
    case 2:  ui->stackedWidget_3->setCurrentIndex(2);break;
    case 3:  ui->stackedWidget_3->setCurrentIndex(3);break;
    default: break;
    }
}

void multicontrol::initButtonGroupEle(void)
{
    p_QButtongroupEle = new QButtonGroup();

    p_QButtongroupEle->addButton(ui->pushButton_EleInnerLoopGainSet,0);
    p_QButtongroupEle->addButton(ui->pushButton_EleInnerLoopGainAsk,1);
    p_QButtongroupEle->addButton(ui->pushButton_EleOutLoopGainSet,2);
    p_QButtongroupEle->addButton(ui->pushButton_EleOutLoopGainAsk,3);
    p_QButtongroupEle->addButton(ui->pushButton_QPIDSET,4);
    p_QButtongroupEle->addButton(ui->pushButton_QPIDASK,5);
    p_QButtongroupEle->addButton(ui->pushButton_THETAPIDSET,6);
    p_QButtongroupEle->addButton(ui->pushButton_THETAPIDASK,7);
    p_QButtongroupEle->addButton(ui->pushButton_KXPIDSET,8);
    p_QButtongroupEle->addButton(ui->pushButton_KXPIDASK,9);
    p_QButtongroupEle->addButton(ui->pushButton_VXPIDSET,10);
    p_QButtongroupEle->addButton(ui->pushButton_VXPIDASK,11);
    p_QButtongroupEle->addButton(ui->pushButton_AXPIDSET,12);
    p_QButtongroupEle->addButton(ui->pushButton_AXPIDASK,13);
    p_QButtongroupEle->addButton(ui->pushButton_VXRANGESET,14);
    p_QButtongroupEle->addButton(ui->pushButton_VXRANGEASK,15);

    connect(p_QButtongroupEle,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdEleButtonClicked(int)));
}

void multicontrol::initButtonGroupAil(void)
{
    p_QButtongroupAil = new QButtonGroup();

    p_QButtongroupAil->addButton(ui->pushButton_AilInnerLoopGainSet,0);
    p_QButtongroupAil->addButton(ui->pushButton_AilInnerLoopGainAsk,1);
    p_QButtongroupAil->addButton(ui->pushButton_AilOutLoopGainSet,2);
    p_QButtongroupAil->addButton(ui->pushButton_AilOutLoopGainAsk,3);
    p_QButtongroupAil->addButton(ui->pushButton_PPIDSET,4);
    p_QButtongroupAil->addButton(ui->pushButton_PPIDASK,5);
    p_QButtongroupAil->addButton(ui->pushButton_PHIPIDSET,6);
    p_QButtongroupAil->addButton(ui->pushButton_PHIPIDASK,7);
    p_QButtongroupAil->addButton(ui->pushButton_KYPIDSET,8);
    p_QButtongroupAil->addButton(ui->pushButton_KYPIDASK,9);
    p_QButtongroupAil->addButton(ui->pushButton_VYPIDSET,10);
    p_QButtongroupAil->addButton(ui->pushButton_VYPIDASK,11);
    p_QButtongroupAil->addButton(ui->pushButton_AYPIDSET,12);
    p_QButtongroupAil->addButton(ui->pushButton_AYPIDASK,13);
    p_QButtongroupAil->addButton(ui->pushButton_VYRANGESET,14);
    p_QButtongroupAil->addButton(ui->pushButton_VYRANGEASK,15);

    connect(p_QButtongroupAil,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdAilButtonClicked(int)));
}

void multicontrol::initButtonGroupCol(void)
{
    p_QButtongroupCol = new QButtonGroup();

    p_QButtongroupCol->addButton(ui->pushButton_HPIDSET,0);
    p_QButtongroupCol->addButton(ui->pushButton_HPIDASK,1);
    p_QButtongroupCol->addButton(ui->pushButton_HDOTPIDSET,2);
    p_QButtongroupCol->addButton(ui->pushButton_HDOTPIDASK,3);
    p_QButtongroupCol->addButton(ui->pushButton_AZPIDSET,4);
    p_QButtongroupCol->addButton(ui->pushButton_AZPIDASK,5);
    p_QButtongroupCol->addButton(ui->pushButton_HDOTRANGESET,6);
    p_QButtongroupCol->addButton(ui->pushButton_HDOTRANGEASK,7);

    connect(p_QButtongroupCol,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdColButtonClicked(int)));
}

void multicontrol::initButtonGroupRud(void)
{
    p_QButtongroupRud = new QButtonGroup();

    p_QButtongroupRud->addButton(ui->pushButton_RPIDSET,0);
    p_QButtongroupRud->addButton(ui->pushButton_RPIDASK,1);
    p_QButtongroupRud->addButton(ui->pushButton_PSIPIDSET,2);
    p_QButtongroupRud->addButton(ui->pushButton_PSIPIDASK,3);
    p_QButtongroupRud->addButton(ui->pushButton_RRANGESET,4);
    p_QButtongroupRud->addButton(ui->pushButton_RRANGEASK,5);

    connect(p_QButtongroupRud,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdRudButtonClicked(int)));
}

void multicontrol::slot_cmdEleButtonClicked(int ButtonID)
{
    quint8   Data[12];
    float    tmpF;

    switch(ButtonID){
    case 0:
        tmpF = ui->doubleSpinBox_THETA2ELE->text().toFloat(); frame_push_float(Data, 0, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_THETA2ELESET, Data, 4);
        break;
    case 1:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_THETA2ELEASK, Data, 0);
        break;
    case 2:
        tmpF = ui->doubleSpinBox_VX2ELE->text().toFloat();  frame_push_float(Data, 0, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VX2ELESET, Data, 4);
        break;
    case 3:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VX2ELEASK, Data, 0);
        break;
    case 4:
        tmpF = ui->doubleSpinBox_QP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_QI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_QD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_QPIDSET, Data, 12);
        break;
    case 5:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_QPIDASK, Data, 0);
        break;
    case 6:
        tmpF = ui->doubleSpinBox_THETAP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_THETAI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_THETAD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_THETAPIDSET, Data, 12);
        break;
    case 7:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_THETAPIDASK, Data, 0);
        break;
    case 8:
        tmpF = ui->doubleSpinBox_KXP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_KXI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_KXD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_KXPIDSET, Data, 12);
        break;
    case 9:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_KXPIDASK, Data, 0);
        break;
    case 10:
        tmpF = ui->doubleSpinBox_VXP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_VXI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_VXD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VXPIDSET, Data, 12);
        break;
    case 11:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VXPIDASK, Data, 0);
        break;
    case 12:
        tmpF = ui->doubleSpinBox_AXP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_AXI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_AXD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_AXPIDSET, Data, 12);
        break;
    case 13:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_AXPIDASK, Data, 0);
        break;
    case 14:
        tmpF = ui->doubleSpinBox_VXRANGEMIN->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_VXRANGEMAX->text().toFloat(); frame_push_float(Data,4,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VXRANGESET, Data, 8);
        break;
    case 15:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VXRANGEASK, Data, 0);
        break;
    default:break;
    }
}

void multicontrol::slot_cmdAilButtonClicked(int ButtonID)
{
    quint8   Data[12];
    float    tmpF;

    switch(ButtonID){
    case 0:
        tmpF = ui->doubleSpinBox_PHI2AIL->text().toFloat(); frame_push_float(Data, 0, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PHI2AILSET, Data, 4);
        break;
    case 1:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PHI2AILASK, Data, 0);
        break;
    case 2:
        tmpF = ui->doubleSpinBox_VY2AIL->text().toFloat();  frame_push_float(Data, 0, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VY2AILSET, Data, 4);
        break;
    case 3:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VY2AILASK, Data, 0);
        break;
    case 4:
        tmpF = ui->doubleSpinBox_PP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_PI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_PD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PPIDSET, Data, 12);
        break;
    case 5:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PPIDASK, Data, 0);
        break;
    case 6:
        tmpF = ui->doubleSpinBox_PHIP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_PHII->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_PHID->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PHIPIDSET, Data, 12);
        break;
    case 7:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PHIPIDASK, Data, 0);
        break;
    case 8:
        tmpF = ui->doubleSpinBox_KYP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_KYI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_KYD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_KYPIDSET, Data, 12);
        break;
    case 9:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_KYPIDASK, Data, 0);
        break;
    case 10:
        tmpF = ui->doubleSpinBox_VYP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_VYI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_VYD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VYPIDSET, Data, 12);
        break;
    case 11:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VYPIDASK, Data, 0);
        break;
    case 12:
        tmpF = ui->doubleSpinBox_AYP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_AYI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_AYD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_AYPIDSET, Data, 12);
        break;
    case 13:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_AYPIDASK, Data, 0);
        break;
    case 14:
        tmpF = ui->doubleSpinBox_VYRANGEMIN->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_VYRANGEMAX->text().toFloat(); frame_push_float(Data,4,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VYRANGESET, Data, 8);
        break;
    case 15:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_VYRANGEASK, Data, 0);
        break;
    default:break;
    }
}

void multicontrol::slot_cmdColButtonClicked(int ButtonID)
{
    quint8   Data[12];
    float    tmpF;

    switch(ButtonID){
    case 0:
        tmpF = ui->doubleSpinBox_HP->text().toFloat(); frame_push_float(Data, 0, tmpF);
        tmpF = ui->doubleSpinBox_HI->text().toFloat(); frame_push_float(Data, 4, tmpF);
        tmpF = ui->doubleSpinBox_HD->text().toFloat(); frame_push_float(Data, 8, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_HPIDSET, Data, 12);
        break;
    case 1:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_HPIDASK, Data, 0);
        break;
    case 2:
        tmpF = ui->doubleSpinBox_HDOTP->text().toFloat();  frame_push_float(Data, 0, tmpF);
        tmpF = ui->doubleSpinBox_HDOTI->text().toFloat();  frame_push_float(Data, 4, tmpF);
        tmpF = ui->doubleSpinBox_HDOTD->text().toFloat();  frame_push_float(Data, 8, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_HDOTPIDSET, Data, 12);
        break;
    case 3:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_HDOTPIDASK, Data, 0);
        break;
    case 4:
        tmpF = ui->doubleSpinBox_AZP->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_AZI->text().toFloat(); frame_push_float(Data,4,tmpF);
        tmpF = ui->doubleSpinBox_AZD->text().toFloat(); frame_push_float(Data,8,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_AZPIDSET, Data, 12);
        break;
    case 5:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_AZPIDASK, Data, 0);
        break;
    case 6:
        tmpF = ui->doubleSpinBox_HDOTRANGEMIN->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_HDOTRANGEMAX->text().toFloat(); frame_push_float(Data,4,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_HDOTRANGESET, Data, 8);
        break;
    case 7:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_HDOTRANGEASK, Data, 0);
        break;
    default:break;
    }
}

void multicontrol::slot_cmdRudButtonClicked(int ButtonID)
{
    quint8   Data[12];
    float    tmpF;

    switch(ButtonID){
    case 0:
        tmpF = ui->doubleSpinBox_RP->text().toFloat(); frame_push_float(Data, 0, tmpF);
        tmpF = ui->doubleSpinBox_RI->text().toFloat(); frame_push_float(Data, 4, tmpF);
        tmpF = ui->doubleSpinBox_RD->text().toFloat(); frame_push_float(Data, 8, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_RPIDSET, Data, 12);
        break;
    case 1:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_RPIDASK, Data, 0);
        break;
    case 2:
        tmpF = ui->doubleSpinBox_PSIP->text().toFloat();  frame_push_float(Data, 0, tmpF);
        tmpF = ui->doubleSpinBox_PSII->text().toFloat();  frame_push_float(Data, 4, tmpF);
        tmpF = ui->doubleSpinBox_PSID->text().toFloat();  frame_push_float(Data, 8, tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PSIPIDSET, Data, 12);
        break;
    case 3:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_PSIPIDASK, Data, 0);
        break;
    case 4:
        tmpF = ui->doubleSpinBox_RRANGEMIN->text().toFloat(); frame_push_float(Data,0,tmpF);
        tmpF = ui->doubleSpinBox_RRANGEMAX->text().toFloat(); frame_push_float(Data,4,tmpF);
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_RRANGESET, Data, 8);
        break;
    case 5:
        Data[0] = 0x00;
        emit signal_cmdOutput(1, UAV_COMP_ID_CTRLCHANNAL, UMH_GNC_RRANGEASK, Data, 0);
        break;
     default:break;
    }
}

void multicontrol::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    float  tmpF;

    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];

            switch (msg->compid){
                case UAV_COMP_ID_CTRLCHANNAL:
                    switch(echoMsg){
                       case UMH_GNC_THETA2ELESET:
                       case UMH_GNC_THETA2ELEASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_THETA2ELE->setValue(tmpF);
                            break;
                       case UMH_GNC_VX2ELESET:
                       case UMH_GNC_VX2ELEASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_VX2ELE->setValue(tmpF);
                            break;
                       case UMH_GNC_QPIDSET:
                       case UMH_GNC_QPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_QP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_QI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_QD->setValue(tmpF);
                            break;
                       case UMH_GNC_THETAPIDSET:
                       case UMH_GNC_THETAPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_THETAP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_THETAI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_THETAD->setValue(tmpF);
                            break;
                       case UMH_GNC_KXPIDSET:
                       case UMH_GNC_KXPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_KXP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_KXI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_KXD->setValue(tmpF);
                            break;
                       case UMH_GNC_VXPIDSET:
                       case UMH_GNC_VXPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_VXP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_VXI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_VXD->setValue(tmpF);
                            break;
                       case UMH_GNC_AXPIDSET:
                       case UMH_GNC_AXPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_AXP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_AXI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_AXD->setValue(tmpF);
                            break;
                       case UMH_GNC_VXRANGESET:
                       case UMH_GNC_VXRANGEASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_VXRANGEMIN->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_VXRANGEMAX->setValue(tmpF);
                            break;

                       case UMH_GNC_PHI2AILSET:
                       case UMH_GNC_PHI2AILASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_PHI2AIL->setValue(tmpF);
                            break;
                       case UMH_GNC_VY2AILSET:
                       case UMH_GNC_VY2AILASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_VY2AIL->setValue(tmpF);
                            break;
                       case UMH_GNC_PPIDSET:
                       case UMH_GNC_PPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_PP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_PI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_PD->setValue(tmpF);
                            break;
                       case UMH_GNC_PHIPIDSET:
                       case UMH_GNC_PHIPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_PHIP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_PHII->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_PHID->setValue(tmpF);
                            break;
                       case UMH_GNC_KYPIDSET:
                       case UMH_GNC_KYPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_KYP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_KYI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_KYD->setValue(tmpF);
                            break;
                       case UMH_GNC_VYPIDSET:
                       case UMH_GNC_VYPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_VYP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_VYI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_VYD->setValue(tmpF);
                            break;
                       case UMH_GNC_AYPIDSET:
                       case UMH_GNC_AYPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_AYP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_AYI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_AYD->setValue(tmpF);
                            break;
                       case UMH_GNC_VYRANGESET:
                       case UMH_GNC_VYRANGEASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_VYRANGEMIN->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_VYRANGEMAX->setValue(tmpF);
                            break;

                       case UMH_GNC_HPIDSET:
                       case UMH_GNC_HPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_HP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_HI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_HD->setValue(tmpF);
                            break;
                       case UMH_GNC_HDOTPIDSET:
                       case UMH_GNC_HDOTPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_HDOTP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_HDOTI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_HDOTD->setValue(tmpF);
                            break;
                       case UMH_GNC_AZPIDSET:
                       case UMH_GNC_AZPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_AZP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_AZI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_AZD->setValue(tmpF);
                            break;
                       case UMH_GNC_HDOTRANGESET:
                       case UMH_GNC_HDOTRANGEASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_HDOTRANGEMIN->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_HDOTRANGEMAX->setValue(tmpF);
                            break;

                       case UMH_GNC_RPIDSET:
                       case UMH_GNC_RPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_RP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_RI->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_RD->setValue(tmpF);
                            break;
                       case UMH_GNC_PSIPIDSET:
                       case UMH_GNC_PSIPIDASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_PSIP->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_PSII->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 9);   ui->doubleSpinBox_PSID->setValue(tmpF);
                            break;
                       case UMH_GNC_RRANGESET:
                       case UMH_GNC_RRANGEASK:
                            tmpF = frame_return_float(msg->payload, 1);   ui->doubleSpinBox_RRANGEMIN->setValue(tmpF);
                            tmpF = frame_return_float(msg->payload, 5);   ui->doubleSpinBox_RRANGEMAX->setValue(tmpF);
                            break;
                    default:break;
                    }
                    break;
            default:break;
            }
    }
}
