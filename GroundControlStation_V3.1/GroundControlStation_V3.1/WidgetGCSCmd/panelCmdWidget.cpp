#include "panelCmdWidget.h"
#include "ui_panelCmdWidget.h"

QPanelCmdWidget::QPanelCmdWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanelCmdWidget)
{
    ui->setupUi(this);

    initButtonGroup();                               //初始控制模式数组
    initCmdButton();                                 //初始化connect
    
    curCmd_str   = "";
    curCmd_seqid = 0;   curCmd_compid = 0;
    curCmd_len   = 0;   curCmd_msgid  = 0;
    isPermitSend = false;
    isSerialPort = false;
}

QPanelCmdWidget::~QPanelCmdWidget()
{
    delete ui;
    if (menu_flymix)                 delete menu_flymix;
    if (speedmixwidget) {
        speedmixwidget->close();     delete speedmixwidget;
    }    
    if (positionmixwidget) {
        positionmixwidget->close();  delete positionmixwidget;
    }    
    if (wpmixwidget) {
        wpmixwidget->close();        delete wpmixwidget;
    }
    if(p_cmdEchoTimer)               delete p_cmdEchoTimer;
}

void QPanelCmdWidget::initButtonGroup()
{
   CmdNum.insert(1, "复原");          CmdInfo.insert("复原",    "1");        CmdCode.insert("复原",    0x11);   
   CmdNum.insert(2, "发动机开");      CmdInfo.insert("发动机开","1") ;       CmdCode.insert("发动机开",0x12);   
   CmdNum.insert(3, "发动机关");      CmdInfo.insert("发动机关","1") ;       CmdCode.insert("发动机关",0x13);   
   CmdNum.insert(4, "裸飞");          CmdInfo.insert("裸飞",    "1") ;       CmdCode.insert("裸飞",    0x14);   
   CmdNum.insert(5, "增稳");          CmdInfo.insert("增稳",    "1") ;       CmdCode.insert("增稳",    0x15);   
   CmdNum.insert(6, "半自动");        CmdInfo.insert("半自动",  "1") ;       CmdCode.insert("半自动",  0x16);      
   CmdNum.insert(7, "全自动");        CmdInfo.insert("全自动",  "1") ;       CmdCode.insert("全自动",  0x17);      
   CmdNum.insert(8, "起飞准备");      CmdInfo.insert("起飞准备","1") ;       CmdCode.insert("起飞准备",0x18);         
   CmdNum.insert(9, "起飞");          CmdInfo.insert("起飞",    "1") ;       CmdCode.insert("起飞",    0x19);   
   CmdNum.insert(10,"着陆");          CmdInfo.insert("着陆",    "1") ;       CmdCode.insert("着陆",    0x1A);   
   CmdNum.insert(11,"悬停");          CmdInfo.insert("悬停",    "1") ;       CmdCode.insert("悬停",    0x1B);   
   CmdNum.insert(12,"返航");          CmdInfo.insert("返航",    "1") ;       CmdCode.insert("返航",    0x1C);   
   CmdNum.insert(13,"导航");          CmdInfo.insert("导航",    "1") ;       CmdCode.insert("导航",    0x1D);   
   CmdNum.insert(14,"放飞");          CmdInfo.insert("放飞",    "1") ;       CmdCode.insert("放飞",    0x1E);   
   CmdNum.insert(15,"激活");          CmdInfo.insert("激活",    "1") ;       CmdCode.insert("激活",    0x1F);

   CmdNum.insert(16,"纵向速度遥调");  CmdInfo.insert("纵向速度遥调","1") ;   mixCode.insert("纵向速度遥调",0x11);         
   CmdNum.insert(17,"横向速度遥调");  CmdInfo.insert("横向速度遥调","1") ;   mixCode.insert("横向速度遥调",0x12);         
   CmdNum.insert(18,"垂向速度遥调");  CmdInfo.insert("垂向速度遥调","1") ;   mixCode.insert("垂向速度遥调",0x13);         
   CmdNum.insert(19,"航向角遥调");    CmdInfo.insert("航向角遥调",  "1") ;   mixCode.insert("航向角遥调",  0x14);      
   CmdNum.insert(20,"纵向位置遥调");  CmdInfo.insert("纵向位置遥调","1") ;   mixCode.insert("纵向位置遥调",0x15);         
   CmdNum.insert(21,"横向位置遥调");  CmdInfo.insert("横向位置遥调","1") ;   mixCode.insert("横向位置遥调",0x16);         
   CmdNum.insert(22,"高度遥调");      CmdInfo.insert("高度遥调",    "1") ;   mixCode.insert("高度遥调",    0x17);   
   CmdNum.insert(23,"航点遥调");      CmdInfo.insert("航点遥调",    "1") ;   mixCode.insert("航点遥调",    0x18);   
   CmdNum.insert(24,"定点遥调");      CmdInfo.insert("定点遥调",    "1") ;   mixCode.insert("定点遥调",    0x19);   
                     
   CmdRange.insert("纵向速度遥调","-5.0-5.0");  CmdZoom.insert("纵向速度遥调",1.0);
   CmdRange.insert("横向速度遥调","-5.0-5.0");  CmdZoom.insert("横向速度遥调",1.0);
   CmdRange.insert("垂向速度遥调","-5.0-5.0");  CmdZoom.insert("垂向速度遥调",1.0);
   CmdRange.insert("航向角遥调",  "-5.0-5.0");  CmdZoom.insert("航向角遥调",  1.0);
   CmdRange.insert("纵向位置遥调","-5.0-5.0");  CmdZoom.insert("纵向位置遥调",1.0);
   CmdRange.insert("横向位置遥调","-5.0-5.0");  CmdZoom.insert("横向位置遥调",1.0);
   CmdRange.insert("高度遥调",    "-5.0-5.0");  CmdZoom.insert("高度遥调",    1.0);
   CmdRange.insert("航点遥调",    "-5.0-5.0");  CmdZoom.insert("航点遥调",    1.0);   
   CmdRange.insert("定点遥调",    "-5.0-5.0");  CmdZoom.insert("定点遥调",    1.0);
}

void QPanelCmdWidget::initCmdButton()
{
    QAction *action_zerofly = new QAction(tr("裸飞"),  this);
    QAction *action_addfly  = new QAction(tr("增稳"),  this);
    QAction *action_halfauto= new QAction(tr("半自动"),this);
    QAction *action_auto    = new QAction(tr("全自动"),this);
    QMenu   *menu_mode      = new QMenu(this);
    menu_mode->addSeparator();  menu_mode->addAction(action_zerofly);
    menu_mode->addSeparator();  menu_mode->addAction(action_addfly);
    menu_mode->addSeparator();  menu_mode->addAction(action_halfauto);
    menu_mode->addSeparator();  menu_mode->addAction(action_auto);
    ui->toolButton_mode->setMenu(menu_mode);    
    QActionGroup *group = new QActionGroup(this);
    group->addAction(action_zerofly);
    group->addAction(action_addfly);
    group->addAction(action_halfauto);
    group->addAction(action_auto);
    connect(group,SIGNAL(triggered(QAction*)),this,SLOT(slot_ActionSelected(QAction*)));    

    QAction *action_reset  = new QAction(tr("复原"),    this);
    QAction *action_ready  = new QAction(tr("起飞准备"),this);
    QAction *action_takeoff= new QAction(tr("起飞"),    this);
    QAction *action_navi   = new QAction(tr("导航"),    this);
    QAction *action_fly    = new QAction(tr("放飞"),    this);
    QAction *action_hover  = new QAction(tr("悬停"),    this);
    QAction *action_back   = new QAction(tr("返航"),    this);
    QAction *action_land   = new QAction(tr("着陆"),    this);
    QMenu *menu_flycmd     = new QMenu(this);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_reset);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_ready);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_takeoff);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_navi);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_fly);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_hover);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_back);
    menu_flycmd->addSeparator();  menu_flycmd->addAction(action_land);
    ui->toolButton_flycmd->setMenu(menu_flycmd);    
    QActionGroup *group_1 = new QActionGroup(this);
    group_1->addAction(action_reset);
    group_1->addAction(action_ready);
    group_1->addAction(action_takeoff);
    group_1->addAction(action_navi);
    group_1->addAction(action_fly);
    group_1->addAction(action_hover);
    group_1->addAction(action_back);
    group_1->addAction(action_land);
    connect(group_1,SIGNAL(triggered(QAction*)), this,SLOT(slot_ActionSelected(QAction*)));
    
    QAction *action_loc     = new QAction(tr("位置"),this);
    QAction *action_speed   = new QAction(tr("速度"),this);
    QAction *action_airline = new QAction(tr("航线"),this);
    menu_flymix             = new QMenu(this);
    menu_flymix->addSeparator();    menu_flymix->addAction(action_loc);
    menu_flymix->addSeparator();    menu_flymix->addAction(action_speed);
    menu_flymix->addSeparator();    menu_flymix->addAction(action_airline);
    menu_flymix->addSeparator();    menu_flymix->setSeparatorsCollapsible(false);
    ui->toolButton_flymix->setMenu(menu_flymix);
    QActionGroup *group_2 = new QActionGroup(this);
    group_2->addAction(action_speed);
    group_2->addAction(action_loc);
    group_2->addAction(action_airline);
    connect(group_2,SIGNAL(triggered(QAction*)),this, SLOT(slot_ActionSelected_2(QAction*)));

    QAction *action_engineopen = new QAction(tr("发动机开"),this);
    QAction *action_engineclose= new QAction(tr("发动机关"),this);
    QAction *action_blank_1    = new QAction(tr(""),this);
    QAction *action_blank_2    = new QAction(tr(""),this);
    QMenu *menu_device         = new QMenu(this);
    menu_device->addSeparator();    menu_device->addAction(action_blank_1);
    menu_device->addSeparator();    menu_device->addAction(action_blank_2);
    menu_device->addSeparator();    menu_device->addAction(action_engineopen);
    menu_device->addSeparator();    menu_device->addAction(action_engineclose);
    ui->toolButton_device->setMenu(menu_device);
    QActionGroup *group_3 = new QActionGroup(this);
    group_3->addAction(action_engineopen);
    group_3->addAction(action_engineclose);
    connect(group_3,SIGNAL(triggered(QAction*)),this,SLOT(slot_ActionSelected(QAction*)));
                
    ui->SendButton->setEnabled(false);    ui->cancelButton->setEnabled(false);
    connect(ui->SendButton,  SIGNAL(clicked()),    this,SLOT(slot_OkSendCmd()));
    connect(ui->cancelButton,SIGNAL(clicked()),    this,SLOT(slot_cancelSendCmd()));
    connect(ui->checkBox_c,  SIGNAL(clicked(bool)),this,SLOT(slot_enabledSendButton(bool)));

    speedmixwidget = new QSpeedCmdDialog(this);
    positionmixwidget = new QPositionCmdDialog(this);
    wpmixwidget = new QWaypointCmdDialog(this);
    connect(speedmixwidget,   SIGNAL(signal_sendSpeedCmd(int, quint8 *, quint8)),   this,SLOT(slot_ActionSelected_2PreSend(int, quint8 *, quint8)));
    connect(positionmixwidget,SIGNAL(signal_sendPositionCmd(int, quint8 *, quint8)),this,SLOT(slot_ActionSelected_2PreSend(int, quint8 *, quint8)));
    connect(wpmixwidget,      SIGNAL(signal_sendWaypointCmd(int, quint8 *, quint8)),this,SLOT(slot_ActionSelected_2PreSend(int, quint8 *, quint8)));

    p_cmdEchoTimer = new QTimer(this);
    connect(p_cmdEchoTimer,SIGNAL(timeout()),this,SLOT(slot_cmdEchoTimer()));
}

void QPanelCmdWidget::slot_ActionSelected_2(QAction *action_2)   //mixbuttongroup  slot
{
    if (isPermitSend==false)  return;
    QString textvalue = action_2->text();    
    if(textvalue=="速度") { speedmixwidget->show();    speedmixwidget->raise();    }
    if(textvalue=="位置") { positionmixwidget->show(); positionmixwidget->raise(); }
    if(textvalue=="航线") { wpmixwidget->show();       wpmixwidget->raise();       }
}

void QPanelCmdWidget::slot_ActionSelected(QAction *action)
{
    if (isPermitSend==false)  return;
    if (isSerialPort==false)  {
        QMessageBox::warning(this,"串口状态","未检测到串口开！");
        return;
    }
        
    QString textvalue = action->text();
    
    if (CmdCode.contains(textvalue)) {
        curCmd_str   = textvalue;
        //curCmd_seqid = 1;
        curCmd_compid = UAV_COMP_ID_CMDFLY;
        curCmd_len   = 0;    curCmd_msgid  = CmdCode[textvalue];
        
        QString  str1= QString("待发:%1(0x%2)")
                               .arg(textvalue)
                               .arg(QString::number(CmdCode[textvalue],16));
        ui->label->setText(str1);
        ui->cancelButton->setEnabled(true);
        ui->SendButton->setEnabled(true);
   }
}

void QPanelCmdWidget::slot_ActionSelected_2PreSend(int count, quint8 *cmdData, quint8 dataLen)
{
    if (isPermitSend==false)  return;
    if (isSerialPort==false)  {
        QMessageBox::warning(this,"串口状态","未检测到串口开！");
        return;
    }    
        
    if (CmdNum.contains(count)) {
        curCmd_str   = CmdNum[count];
       // curCmd_seqid = 1;
        curCmd_compid = UAV_COMP_ID_CMDMISSION;
        curCmd_len   = dataLen;  curCmd_msgid  = mixCode[CmdNum[count]];
        for (int idx=0; idx<dataLen; idx++) {
            curCmd_payload[idx] = *(cmdData+idx);
        }
        
        QString str1 = QString("待发:%1(0x%2)...")
                                        .arg(curCmd_str)
                                        .arg(QString::number(mixCode[CmdNum[count]],16));
        ui->label->setText(str1);
        ui->cancelButton->setEnabled(true);
        ui->SendButton->setEnabled(true);
    }    
}

void QPanelCmdWidget::slot_OkSendCmd()
{    
    if (CmdCode.contains(curCmd_str)||mixCode.contains(curCmd_str)) {    
        emit signal_cmdOutput(curCmd_seqid, curCmd_compid, curCmd_msgid, curCmd_payload, curCmd_len);
        
        ui->SendButton->setEnabled(false);
        ui->cancelButton->setEnabled(false);
    } 
}

void QPanelCmdWidget::slot_cancelSendCmd()
{
    curCmd_str   = "";
    //curCmd_seqid = 0;
    curCmd_compid = 0;
    curCmd_len   = 0;   curCmd_msgid  = 0;
    
    ui->label->setText("");
    ui->cancelButton->setEnabled(false);
    ui->SendButton->setEnabled(false);
}

void QPanelCmdWidget:: slot_enabledSendButton(bool flag)
{
    if (flag==true) isPermitSend = true;
    else {
        isPermitSend = false;
        slot_cancelSendCmd();
    }
}

void QPanelCmdWidget::isSerialPortOpen(bool flag)
{
    isSerialPort = flag;
}

void QPanelCmdWidget::slot_cmdEchoTimer(void)
{
    //curCmd_seqid = 1;
    curCmd_compid = UAV_COMP_ID_CMDMISSION;
    curCmd_len   = 0;        curCmd_msgid  = UAV_MSG_REQU_ECHO;
    emit signal_cmdOutput(curCmd_seqid, curCmd_compid, curCmd_msgid, curCmd_payload, curCmd_len);
}

void QPanelCmdWidget::slot_CmdMissionEchoOK(datalink_message_t *message)
{
    quint8 echoMsg;

    switch (message->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = message->payload[0];

            switch (message->compid){
                case UAV_COMP_ID_CMDMISSION:
                    if(echoMsg==UAV_MSG_REQU_ECHO) p_cmdEchoTimer->stop();
                    else{
                        slot_cmdEchoTimer();
                        p_cmdEchoTimer->start(500);
                    }
                break;
                default:  break;
            }
        break;
        default:  break;
    }
}


void QPanelCmdWidget::setbuttonstate(bool flag)
{
    ui->cancelButton->setEnabled(flag);
    ui->SendButton->setEnabled(flag);
}

void QPanelCmdWidget::set_acseqid(quint8 seqid)
{
    curCmd_seqid=seqid;
}
