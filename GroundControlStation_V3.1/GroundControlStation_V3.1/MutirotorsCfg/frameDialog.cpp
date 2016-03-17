#include "frameDialog.h"
#include "ui_framDialog.h"

frameDialog::frameDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frameDialog)
{
    ui->setupUi(this);

    initButtonGroup();
}

frameDialog::~frameDialog()
{
    delete ui;
    if(p_QButtongroup) delete p_QButtongroup;
}

void frameDialog::initButtonGroup()
{
    p_QButtongroup = new QButtonGroup();

    p_QButtongroup->addButton(ui->pushButton,0);
    p_QButtongroup->addButton(ui->pushButton_2,1);
    p_QButtongroup->addButton(ui->pushButton_3,2);
    p_QButtongroup->addButton(ui->pushButton_4,3);
    p_QButtongroup->addButton(ui->pushButton_5,4);
    p_QButtongroup->addButton(ui->pushButton_6,5);
    p_QButtongroup->addButton(ui->pushButton_7,6);
    p_QButtongroup->addButton(ui->pushButton_8,7);
    p_QButtongroup->addButton(ui->pushButton_9,8);
    p_QButtongroup->addButton(ui->pushButton_10,9);
    connect(p_QButtongroup,SIGNAL(buttonClicked(int)),this,SLOT(slot_cmdButtonClicked(int)));
}

void frameDialog::slot_cmdButtonClicked(int ButtonID)
{
    quint8 Data[1];
    switch(ButtonID){
    case 0:Data[0] = 0;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 1:Data[0] = 1;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 2:Data[0] = 2;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 3:Data[0] = 3;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 4:Data[0] = 4;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 5:Data[0] = 5;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 6:Data[0] = 6;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 7:Data[0] = 7;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 8:Data[0] = 8;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    case 9:Data[0] = 9;
        emit signal_cmdOutput(1, UAV_COMP_ID_ACS, UAV_MSG_ACS_TILTTYPESET, Data, 1);
        break;
    default:break;
    }
}

void frameDialog::echoMessagePacket(datalink_message_t *msg)
{
    quint8 echoMsg;
    quint8 tmpData;
    QString defaultStyle;
    QString newStyle;
    defaultStyle = "QPushButton:hover{background-color: rgb(255,160,200);}\
            QPushButton:focus{background-color: rgb(255,49,80);}\
            QPushButton{border-top-left-radius:10px;\
                        border-top-right-radius:10px;\
                        border-bottom-left-radius:10px;\
                        border-bottom-right-radius:10px;\
                        background-color: rgb(200,200,200)}";
    newStyle = "QPushButton{border-top-left-radius:10px;\
                        border-top-right-radius:10px;\
                        border-bottom-left-radius:10px;\
                        border-bottom-right-radius:10px;\
                        background-color: black}";
    switch (msg->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = msg->payload[0];
            switch (echoMsg) {
            case UAV_MSG_ACS_TILTTYPESET:
            case UAV_MSG_ACS_TILTTYPEASK:
                tmpData = msg->payload[1];
                ui->pushButton->setStyleSheet(defaultStyle);
                ui->pushButton_2->setStyleSheet(defaultStyle);
                ui->pushButton_3->setStyleSheet(defaultStyle);
                ui->pushButton_4->setStyleSheet(defaultStyle);
                ui->pushButton_5->setStyleSheet(defaultStyle);
                ui->pushButton_6->setStyleSheet(defaultStyle);
                ui->pushButton_7->setStyleSheet(defaultStyle);
                ui->pushButton_8->setStyleSheet(defaultStyle);
                ui->pushButton_9->setStyleSheet(defaultStyle);
                ui->pushButton_10->setStyleSheet(defaultStyle);
                switch(tmpData){
                case 0: ui->pushButton->setStyleSheet(newStyle);break;
                case 1: ui->pushButton_2->setStyleSheet(newStyle);break;
                case 2: ui->pushButton_3->setStyleSheet(newStyle);break;
                case 3: ui->pushButton_4->setStyleSheet(newStyle);break;
                case 4: ui->pushButton_5->setStyleSheet(newStyle);break;
                case 5: ui->pushButton_6->setStyleSheet(newStyle);break;
                case 6: ui->pushButton_7->setStyleSheet(newStyle);break;
                case 7: ui->pushButton_8->setStyleSheet(newStyle);break;
                case 8: ui->pushButton_9->setStyleSheet(newStyle);break;
                case 9: ui->pushButton_10->setStyleSheet(newStyle);break;
                default:break;
                }
                break;
            default:break;
            }
    }
}
