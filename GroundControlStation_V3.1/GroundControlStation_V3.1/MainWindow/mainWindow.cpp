#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    p_menuToolbar(NULL),
    p_statusToolbar(NULL),
    p_serialPort(NULL),
    p_realTimer(NULL),
    m_activeNumofUAS(1)
{
    ui->setupUi(this);                 //初始化gui
    active_seqid=0;
    initCentralWidget();               //窗口小部件初始化
    initToolBar();                     //初始化菜单和工具条
    initChildDialog();                 //初始化子窗口
    
    initCommunitcation();              //初始化串口和网络
    initSignal2Slot();                 //初始化消息与槽的映射
      
    showMaximized();                   //窗口显示最大化
}

MainWindow::~MainWindow()
{
                            delete ui;
    if(p_menuToolbar)       delete p_menuToolbar;
    if(p_statusToolbar)     delete p_statusToolbar;
    if(p_serialPort)        delete p_serialPort;
    if(p_serialConfigDlg)   delete p_serialConfigDlg;
    if(p_serialPortCommu)   delete p_serialPortCommu;
    if(p_udpConfigDlg)      delete p_udpConfigDlg;
    if(p_udpPortCommu)      delete p_udpPortCommu;
    if(p_dataProtocol)      delete p_dataProtocol;
    if(p_firmwarwUpdate)    delete p_firmwarwUpdate;
    if(p_waypointDesignDlg) delete p_waypointDesignDlg;
    if(p_configureDlg)      delete p_configureDlg;
    if(p_multiCenterDialog) delete p_multiCenterDialog;
}

void MainWindow::initCentralWidget()
{
    p_centralStack = new QStackedWidget(this);                   //主窗口
    p_centralStack->lower();
    setCentralWidget(p_centralStack);
    setWindowTitle("GCS");
    
    p_mapCentralStack = new QStackedWidget();
    p_mapWidget       = new QPanelMap2DWidget();                 //主窗口小部件创建
    p_localPicture  =   new QPanellocalmapWidget();
    p_mapCentralStack->addWidget(p_mapWidget);
    p_mapCentralStack->addWidget(p_localPicture);
    p_mapCentralStack->setCurrentWidget(p_mapWidget);    
    
    p_plotWidget       = new QPanelPlotWidget(p_centralStack);
    p_FPDWidget        = new QPanelFPDWidget;
    p_UASWidget        = new QPanelUASWidget;
    p_dataFrameWidget  = new QPanelDataFrameWidget();
    p_textBrowserWidget= new QTextBrowser();
    p_cmdWidget        = new QPanelCmdWidget();
   
    p_mapCentralStack->lower();                                  //主窗口小部件属性设置
    p_plotWidget->lower();   
    p_textBrowserWidget->setStyleSheet(QString("background-color: rgb(255, 255, 255);"));
    p_textBrowserWidget->setMinimumHeight(0);
    QWidget     *center     = new QWidget(this);                 //主窗口小部件布局    
    QGridLayout *mainlayout = new QGridLayout();
    QGridLayout *rightlayout= new QGridLayout();
    QGridLayout *leftlayout = new QGridLayout();
    
    p_centralStack->addWidget(center);
        center->setContentsMargins(0,0,0,0);
    mainlayout->setContentsMargins(0,0,0,0);
    leftlayout->setContentsMargins(0,0,0,0);
    mainlayout->setSpacing(0);
    mainlayout->setColumnStretch(0,3);
    mainlayout->setColumnStretch(1,0.9); 
    leftlayout->setRowStretch(0,0.67);

    center->setLayout(mainlayout);
     mainlayout->addLayout(leftlayout,0,0);
     mainlayout->addLayout(rightlayout,0,1);
     leftlayout->addWidget(p_mapCentralStack);
     leftlayout->addWidget(p_plotWidget);
    rightlayout->addWidget(p_FPDWidget,0,0);
    rightlayout->addWidget(p_UASWidget,1,0);
    rightlayout->addWidget(p_dataFrameWidget,2,0);
    rightlayout->addWidget(p_textBrowserWidget,3,0);
    rightlayout->addWidget(p_cmdWidget,4,0);

    p_mapbutton = new QPushButton(p_centralStack);
    p_mapbutton->resize(14,30);
    p_mapbutton->setText("<");
    p_mapbutton->raise();
    p_mapbutton->hide();

    p_rightwidget = new QPushButton(p_centralStack);
    p_rightwidget->resize(15,35);
    p_rightwidget->setStyleSheet(QString("background-color: rgb(255, 255, 255);font-size:25px;"));
    p_rightwidget->setText(">");
    p_rightwidget->raise();
    
    p_centralStack->setCurrentIndex(0);        //初始主窗口
    p_plotWidget->hide();                      //窗口小部件显示状态
    p_plotWidget->showControlPlot(false);
    p_plotWidget->showVoltagePlot(false);
    p_plotWidget->showControlPlot(false);
}

void MainWindow::initToolBar()
{
    QToolBar *toolbar_1 = new QToolBar();      //菜单工具条
    p_menuToolbar = new QMenuToolbarWidget();
    toolbar_1->addWidget(p_menuToolbar);    toolbar_1->setMinimumHeight(25);    
    p_menuToolbar->setCheckMenu(1,1,false); p_menuToolbar->setEnableMenu(1,1,true); isHeliCfg = false;
    p_menuToolbar->setCheckMenu(1,2,false); p_menuToolbar->setEnableMenu(1,2,true); isMutiCfg = false;
    p_menuToolbar->setCheckMenu(1,3,false); p_menuToolbar->setEnableMenu(1,3,true);   
    p_menuToolbar->setCheckMenu(1,4,false); p_menuToolbar->setEnableMenu(1,4,true);    
    p_menuToolbar->setCheckMenu(1,5,false); p_menuToolbar->setEnableMenu(1,5,true); 
    isRecordData = false;
    isReplayData = false;
    
    p_menuToolbar->setEnableMenu(2,1,true); p_menuToolbar->setEnableMenu(2,2,false); p_menuToolbar->setEnableMenu(2,3,false);
    p_menuToolbar->setEnableMenu(2,4,false);p_menuToolbar->setEnableMenu(2,5,false); p_menuToolbar->setEnableMenu(2,6,false);
    isOpenCom = false;
    
    p_menuToolbar->setEnableMenu(3,1,false);
    p_menuToolbar->setEnableMenu(3,2,false);
    p_menuToolbar->setEnableMenu(3,3,false);
    p_menuToolbar->setEnableMenu(3,4,false);
    p_menuToolbar->setEnableMenu(3,5,false);
    p_menuToolbar->setEnableMenu(3,6,false);
    p_menuToolbar->setEnableMenu(3,7,false);
    
    p_menuToolbar->setEnableMenu(4,1,true); p_menuToolbar->setEnableMenu(4,2,false);
    isLoadWP = false;
    
    p_menuToolbar->setEnableMenu(5,1,false); p_menuToolbar->setEnableMenu(5,2,true); p_menuToolbar->setEnableMenu(5,3,true);
    p_menuToolbar->setCheckMenu(5,1,true);   p_menuToolbar->setCheckMenu(5,2,false); p_menuToolbar->setCheckMenu(5,3,false);
    m_mapMode = 1;
    
    QToolBar *toolbar_2 = new QToolBar();      //状态工具条
    p_statusToolbar = new QStatusToolbarWidget();
    toolbar_2->addWidget(p_statusToolbar);    toolbar_2->setMinimumHeight(25);       
    this->addToolBar(toolbar_1);
    this->addToolBar(toolbar_2);         
    p_statusToolbar->displayUavFlyStatus(0);
    p_statusToolbar->displayUavActiveNumber(0,0);
    p_statusToolbar->displayGcsRunMode(0);
    
    p_maptoolbar= new QMaptoolbar(this);       //地图工具条
    p_maptoolbar->raise();

    m_runMode = 0;
}

void MainWindow::initCommunitcation()
{
    p_dataProtocol    = new QDataProtocol(this);
    p_serialPort      = new QSerialPort(this);
    p_serialConfigDlg = new QSerialSettingsDialog(this);    
    p_serialPortCommu = new QSerialPortCommu(this);
    
    p_serialPortCommu->setSerialPort(p_serialPort);
    p_serialPortCommu->enableSimuCommu(false);
    p_serialPortCommu->setSerialProtocol(p_dataProtocol);   
    p_dataFrameWidget->setSerialProtocol(p_dataProtocol);

    p_udpPortCommu = new QUdpCommu;
    p_udpPortCommu->setUdpProtocol(p_dataProtocol);
    p_udpConfigDlg = new QUdpPortSettingDialog(this);
    p_udpConfigDlg->hide();

    connect(p_udpPortCommu,SIGNAL(signal_sim(float*,quint8)),p_dataFrameWidget,SLOT(slot_sim(float*,quint8)));
}

void MainWindow::initChildDialog()
{    
    p_realTimer = new QTimer();
    p_realTimer->start(100);
        
    p_configureDlg = new QDialogConfigure(this);
    p_configureDlg->hide();

    p_multiCenterDialog = NULL;
    
    p_waypointDesignDlg = new QWaypointDialog(this);
    p_waypointDesignDlg->setmapwidget(p_mapWidget);
    p_waypointDesignDlg->hide();
            
    p_firmwarwUpdate = new QFirmwareUpdateDialog(this);
    p_firmwarwUpdate->hide();  

    p_recordDlg=new QRecordDialog(this);
}

void MainWindow::initSignal2Slot() 
{        
    connect(p_menuToolbar,    SIGNAL(signal_menu_action(quint8, quint8)), this, SLOT(slot_menu_action(quint8, quint8)));
    connect(p_rightwidget,    SIGNAL(clicked()),                          this, SLOT(slot_hideRightWidget()));
    connect(p_mapbutton,      SIGNAL(clicked()),                          this, SLOT(slot_hideMapToolbarButton()));    
    connect(p_maptoolbar,     SIGNAL(signal_hideToolbar()),               this, SLOT(slot_showMapToolbarButton()));   
    connect(p_maptoolbar,     SIGNAL(signal_TOJavaScript(int)),           this, SLOT(slot_MaptoolTOJava(int)));
    connect(p_mapWidget,      SIGNAL(signal_addToJava()),                 this, SLOT(slot_addToJava()));
    connect(p_plotWidget,     SIGNAL(signal_checkFailMenu(int)),          this, SLOT(slot_checkWindowsMenu(int)));    
    connect(p_realTimer,      SIGNAL(timeout()),                          this, SLOT(slot_RealtimeDisplay()));
    connect(p_serialPortCommu,SIGNAL(signal_setPrintText(QString,QColor)),this, SLOT(slot_setPrintText(QString,QColor)));
    connect(p_serialPortCommu,SIGNAL(signal_setlight(int))               ,this, SLOT(slot_setlight(int)));
    connect(p_serialPortCommu,SIGNAL(signal_setsendbutton(bool))         ,this, SLOT(slot_setsendbutton(bool)));

    connect(p_dataProtocol,SIGNAL(signal_echoSuccess()),                                p_serialPortCommu,  SLOT(slot_echoSendSuccess()));
    connect(p_dataProtocol,SIGNAL(signal_echoMessagePacket(datalink_message_t *,bool)), p_configureDlg,     SLOT(slot_echoMessagePacket(datalink_message_t *,bool)));
    connect(p_dataProtocol,SIGNAL(signal_waypointCmdEchoOK(quint8,WayPoint_Struc_t)),   p_waypointDesignDlg,SIGNAL(signal_waypointCmdEchoOK(quint8,WayPoint_Struc_t)));
    connect(p_dataProtocol,SIGNAL(signal_IAPCmdEchoOk(quint8, quint8 *, quint8)),       p_firmwarwUpdate,   SLOT(slot_IAPCmdEchoOk(quint8, quint8 *, quint8)));
    connect(p_dataProtocol,SIGNAL(signal_simFCC2Model(quint8 *, quint8)),               p_udpPortCommu,     SLOT(slot_fccData2UdpSend(quint8 *, quint8)));
    connect(p_dataProtocol,SIGNAL(signal_enableCmdEchoOK(quint8)),                      this,               SLOT(slot_enableCmdEchoOK(quint8)));
    connect(p_dataProtocol,SIGNAL(signal_setacseqid(quint8)),this,SLOT(slot_setactiveseqid(quint8)));
    connect(p_dataProtocol,SIGNAL(signal_CmdMissionEchoOK(datalink_message_t*)),        p_cmdWidget,        SLOT(slot_CmdMissionEchoOK(datalink_message_t*)));
                   
    connect(p_cmdWidget,        SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_configureDlg,     SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_waypointDesignDlg,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_firmwarwUpdate,   SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_UASWidget,        SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_udpPortCommu,     SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packetSim(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(this,               SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8))); 
    
    connect(p_recordDlg,        SIGNAL(signal_sliderchanged(int)),                                    p_serialPortCommu,SLOT(slot_setprogeess(int)));
    connect(p_recordDlg,        SIGNAL(signal_setplayback(int)),                                      this,SLOT(slot_playbackset(int)));
}

void MainWindow::slot_menu_action(quint8 pID, quint8 cID)
{
    quint8 Data[1];
    
    switch(pID) {
        case 1: //File
            switch(cID) {
                case 1: //heli
                    if (p_menuToolbar->isMenuChecked(1,1)) {
                        p_menuToolbar->setCheckMenu(1,1,true);  p_menuToolbar->setEnableMenu(1,1,false);
                        p_menuToolbar->setCheckMenu(1,2,false); p_menuToolbar->setEnableMenu(1,2,true);
                        isHeliCfg = true;   isMutiCfg = false;
                        p_statusToolbar->displayUavActiveNumber(1,1);
                    }
                    break;
                case 2: //rotor
                    if (p_menuToolbar->isMenuChecked(1,2)) {
                        p_menuToolbar->setCheckMenu(1,1,false); p_menuToolbar->setEnableMenu(1,1,true); 
                        p_menuToolbar->setCheckMenu(1,2,true);  p_menuToolbar->setEnableMenu(1,2,false);  
                        isMutiCfg = true;   isHeliCfg = false;  
                        p_statusToolbar->displayUavActiveNumber(2,1);
                    }
                    break;
                case 3: //test
                    if (p_serialPort->isOpen()==false)  {
                        QMessageBox::warning(this,"串口状态","未检测到串口开！");
                        p_menuToolbar->setCheckMenu(1,3,false);
                        break;
                    }
                    if (p_menuToolbar->isMenuChecked(1,3)) {
                        Data[0] = 2;  emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_SYSMODE, Data, 1);
                        p_menuToolbar->setCheckMenu(1,4,false);
                        p_menuToolbar->setCheckMenu(1,5,false);
                    }
                    break;
                case 4: //sim
                    if (p_serialPort->isOpen()==false)  {
                        QMessageBox::warning(this,"串口状态","未检测到串口开！");
                        p_menuToolbar->setCheckMenu(1,4,false);
                        break;
                    }
                    if (p_menuToolbar->isMenuChecked(1,4)) {
                        Data[0] = 3;  emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_SYSMODE, Data, 1); 
                        p_menuToolbar->setCheckMenu(1,3,false);
                        p_menuToolbar->setCheckMenu(1,5,false);
                    }                   
                    break;
                case 5: //fly
                    if (p_serialPort->isOpen()==false)  {
                        QMessageBox::warning(this,"串口状态","未检测到串口开！");
                        p_menuToolbar->setCheckMenu(1,5,false);
                        break;
                    }
                    if (p_menuToolbar->isMenuChecked(1,5)) {
                        Data[0] = 1;  emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_SYSMODE, Data, 1);
                        p_menuToolbar->setCheckMenu(1,3,false);
                        p_menuToolbar->setCheckMenu(1,4,false);
                    }                 
                    break;
                case 6: //record data
                    if (p_menuToolbar->isMenuChecked(1,6)) {
                        p_menuToolbar->setCheckMenu(1,6,true);   isRecordData = true;  p_serialPortCommu->record_open();
                        p_menuToolbar->setEnableMenu(1,7,false); isReplayData = false;
                    }
                    else {
                        p_menuToolbar->setCheckMenu(1,6,false);  isRecordData = false; p_serialPortCommu->record_close();
                        p_menuToolbar->setEnableMenu(1,7,true);  isReplayData = false;
                    }
                    break;
                case 7: //replay data
                    if (p_menuToolbar->isMenuChecked(1,7)) {
                        p_menuToolbar->setCheckMenu(1,7,true);   isReplayData = true; p_serialPortCommu->playback_open();p_recordDlg->show();
                        p_menuToolbar->setEnableMenu(1,6,false); isRecordData = false;
                    }
                    else {
                        p_menuToolbar->setCheckMenu(1,7,false);  isReplayData = false;
                        p_menuToolbar->setEnableMenu(1,6,true);  isRecordData = false;
                    }
                    break;
                case 8: close(); break;
            }            
            break;
        case 2: //communication
            switch(cID) {
                case 1: p_serialConfigDlg->show();
                        p_menuToolbar->setEnableMenu(2,1,true);
                        p_menuToolbar->setEnableMenu(2,2,true);  p_menuToolbar->setCheckMenu(2,2,false);
                        p_menuToolbar->setEnableMenu(2,3,false); p_menuToolbar->setCheckMenu(2,3,false);
                        break;
                case 2: //serial open
                    if (true==openSerialPort()) {                                    
                        p_statusToolbar->displaylight(3);
                        p_menuToolbar->setEnableMenu(2,1,false);
                        p_menuToolbar->setEnableMenu(2,2,false); p_menuToolbar->setCheckMenu(2,2,true);
                        p_menuToolbar->setEnableMenu(2,3,true);  p_menuToolbar->setCheckMenu(2,3,false);                        
                        p_cmdWidget->isSerialPortOpen(true);
                        isOpenCom = true;
                        
                        if (m_runMode==2) {
                            p_menuToolbar->setEnableMenu(3,1,true);    
                        }
                    }
                    else {                                         
                        p_statusToolbar->displaylight(1);
                        p_menuToolbar->setEnableMenu(2,1,true);
                        p_menuToolbar->setEnableMenu(2,2,true);  p_menuToolbar->setCheckMenu(2,2,false);
                        p_menuToolbar->setEnableMenu(2,3,false); p_menuToolbar->setCheckMenu(2,3,false);                        
                        p_cmdWidget->isSerialPortOpen(false);
                        isOpenCom = false;
                        
                        p_menuToolbar->setEnableMenu(3,1,false);
                        p_menuToolbar->setEnableMenu(3,2,false);
                        p_menuToolbar->setEnableMenu(3,3,false);
                        p_menuToolbar->setEnableMenu(3,4,false);
                        p_menuToolbar->setEnableMenu(3,6,false);
                        p_menuToolbar->setEnableMenu(3,7,false); 
                    }                         
                    break;
                case 3: //serial close
                    if (p_menuToolbar->isMenuChecked(2,3)) {                    
                        closeSerialPort();
                        p_statusToolbar->displaylight(1);
                        p_menuToolbar->setEnableMenu(2,1,true);
                        p_menuToolbar->setEnableMenu(2,2,true);  p_menuToolbar->setCheckMenu(2,2,false); 
                        p_menuToolbar->setEnableMenu(2,3,false); p_menuToolbar->setCheckMenu(2,3,true);                        
                        p_cmdWidget->isSerialPortOpen(false);     
                        isOpenCom = false;      
                        
                        p_menuToolbar->setEnableMenu(3,1,false);
                        p_menuToolbar->setEnableMenu(3,2,false);
                        p_menuToolbar->setEnableMenu(3,3,false);
                        p_menuToolbar->setEnableMenu(3,4,false);
                        p_menuToolbar->setEnableMenu(3,6,false);
                        p_menuToolbar->setEnableMenu(3,7,false);             
                    }                         
                    break;
                case 4: p_udpConfigDlg->show(); 
                        p_menuToolbar->setEnableMenu(2,4,false);
                        p_menuToolbar->setEnableMenu(2,5,true);  p_menuToolbar->setCheckMenu(2,5,false);
                        p_menuToolbar->setEnableMenu(2,6,false); p_menuToolbar->setCheckMenu(2,6,false);
                        break;
                case 5: //udp open
                    if (true==openUdpPort()) {
                        p_menuToolbar->setEnableMenu(2,4,false);
                        p_menuToolbar->setEnableMenu(2,5,false); p_menuToolbar->setCheckMenu(2,5,true);
                        p_menuToolbar->setEnableMenu(2,6,true);  p_menuToolbar->setCheckMenu(2,6,false);
                    }
                    else {
                        p_menuToolbar->setEnableMenu(2,4,true);
                        p_menuToolbar->setEnableMenu(2,5,false); p_menuToolbar->setCheckMenu(2,5,false); 
                        p_menuToolbar->setEnableMenu(2,6,false); p_menuToolbar->setCheckMenu(2,6,false);  
                    }
                    break;
                case 6: //udp close
                    if (p_menuToolbar->isMenuChecked(2,6)) {                    
                        closeUdpPort();
   
                        p_menuToolbar->setEnableMenu(2,4,true);
                        p_menuToolbar->setEnableMenu(2,5,true);  p_menuToolbar->setCheckMenu(2,5,false); 
                        p_menuToolbar->setEnableMenu(2,6,false); p_menuToolbar->setCheckMenu(2,6,true);                        
                    }                         
                    break;
            }            
            break;
        case 3: //configure            
            switch(cID) {
                case 1: Data[0] = 1; emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_PARAM, Data, 1); break;
                case 2: Data[0] = 2; emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_PARAM, Data, 1); break;
                case 3: Data[0] = 3; emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_PARAM, Data, 1); break;
                case 4: Data[0] = 4; emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_PARAM, Data, 1); break;
                case 5: //参数配置对话框
                    if(isHeliCfg) {
                        if(p_multiCenterDialog) {
                            delete p_multiCenterDialog; 
                            p_multiCenterDialog = NULL;
                        }
                        p_configureDlg->show();
                        p_dataProtocol->cfgType = true;
                    }
                    else {
                        if(isMutiCfg) {                            
                            if(p_configureDlg) p_configureDlg->hide();
                            if(!p_multiCenterDialog){
                                p_multiCenterDialog = new multiCenterDialog(this);
                            }
                            p_multiCenterDialog->show();
                            p_dataProtocol->cfgType = false;
                            connect(p_dataProtocol,SIGNAL(signal_echoMessagePacket(datalink_message_t*,bool)),p_multiCenterDialog,    SLOT(slot_echoMessagePacket(datalink_message_t*,bool)));
                            connect(p_multiCenterDialog,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), p_serialPortCommu,SLOT(slot_protocol_send_packet(quint8,quint8,quint8,const quint8 *,quint8)));
                        }
                    }
                    break;
                case 6: Data[0] = 5; emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_PARAM, Data, 1);break;
                case 7:
                        if(QMessageBox::information(NULL, "删除数据", "确认删除配置参数？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::No) return;
                        Data[0] = 6; emit signal_cmdOutput(1, UAV_COMP_ID_SYSENABLE, UAV_MSG_SET_PARAM, Data, 1);break;
            }            
            break;
        case 4: //waypoint
            switch(cID) {
                case 1: //load waypoint
                    if (true==openWaypointLoad()) {
                        p_menuToolbar->setEnableMenu(4,1,false); p_menuToolbar->setCheckMenu(4,1,true);  isLoadWP = true;
                        p_menuToolbar->setEnableMenu(4,2,true);  p_menuToolbar->setCheckMenu(4,2,false);   
                    }
                    else {
                        p_menuToolbar->setEnableMenu(4,1,true);  p_menuToolbar->setCheckMenu(4,1,false); isLoadWP = false;
                        p_menuToolbar->setEnableMenu(4,2,false); p_menuToolbar->setCheckMenu(4,2,false);   
                    }
                    break;
                case 2: //clear waypoint
                    if (p_menuToolbar->isMenuChecked(4,2)) {
                        p_menuToolbar->setEnableMenu(4,1,true);  p_menuToolbar->setCheckMenu(4,1,false); isLoadWP = false;
                        p_menuToolbar->setEnableMenu(4,2,false); p_menuToolbar->setCheckMenu(4,2,false);  
                        p_mapWidget->TOJavaScript(QString("clear_frame();"));
                    }
                    break;
                case 3: p_waypointDesignDlg->show();break;                
            }            
            break;
        case 5: //windows
            switch(cID) {
                case  1: //baidu
                    if (p_menuToolbar->isMenuChecked(5,1)) {  
                        p_mapCentralStack->setCurrentWidget(p_mapWidget);
                        p_mapbutton->show();   p_maptoolbar->hidebutton(true);
                        
                        p_menuToolbar->setCheckMenu(5,1,true);  p_menuToolbar->setEnableMenu(5,1,false); m_mapMode = 1;  
                        p_menuToolbar->setCheckMenu(5,2,false); p_menuToolbar->setEnableMenu(5,2,true);     
                        p_menuToolbar->setCheckMenu(5,3,false); p_menuToolbar->setEnableMenu(5,3,true);
                    }                  
                    break;
                case  2: //google 
                    if (p_menuToolbar->isMenuChecked(5,2)) {                        
                        p_menuToolbar->setCheckMenu(5,1,false); p_menuToolbar->setEnableMenu(5,1,true); 
                        p_menuToolbar->setCheckMenu(5,2,true);  p_menuToolbar->setEnableMenu(5,2,false);m_mapMode = 2;       
                        p_menuToolbar->setCheckMenu(5,3,false); p_menuToolbar->setEnableMenu(5,3,true);
                    }      
                    break;
                case  3: //picture 
                    if (p_menuToolbar->isMenuChecked(5,3)) {                        
                        p_mapCentralStack->setCurrentWidget(p_localPicture);
                        p_maptoolbar->hidebutton(false);
                        
                        p_menuToolbar->setCheckMenu(5,1,false); p_menuToolbar->setEnableMenu(5,1,true); 
                        p_menuToolbar->setCheckMenu(5,2,false); p_menuToolbar->setEnableMenu(5,2,true);       
                        p_menuToolbar->setCheckMenu(5,3,true);  p_menuToolbar->setEnableMenu(5,3,false);m_mapMode = 3;
                    } 
                    break;    
                case  4:  p_plotWidget->show(); 
                          p_plotWidget->showHeightPlot(true);   break;
                case  5:  p_plotWidget->show(); 
                          p_plotWidget->showVoltagePlot(true);  break;
                case  6:  p_plotWidget->show(); 
                          p_plotWidget->showControlPlot(true);  break;
                case  7:  p_plotWidget->showHeightPlot(false);  break;
                case  8:  p_plotWidget->showVoltagePlot(false); break;
                case  9:  p_plotWidget->showControlPlot(false); break;
                case 10:  p_plotWidget->hide();                 break;
            }       
            break;
        case 6: //help
            switch(cID) {
                case 1: QMessageBox::about(this, "Test","slot_helpApp");break;
                case 2: 
                    if (m_runMode==2) openFirmwareUpdate();
                    else  QMessageBox::about(this, "Warning","请在<测试模式>下进行固件升级！");  
                    break;
                case 3: QMessageBox::about(this, "Test","slot_helpAbout");break;                
            }            
            break;
    }
}

void MainWindow::slot_enableCmdEchoOK(quint8 idx)
{
    switch (idx) {
        case 1:   //echo飞行模式
            if (p_menuToolbar->isMenuChecked(1,5)) {                        
                p_menuToolbar->setCheckMenu(1,3,false); p_menuToolbar->setEnableMenu(1,3,true);  
                p_menuToolbar->setCheckMenu(1,4,false); p_menuToolbar->setEnableMenu(1,4,true);     
                p_menuToolbar->setCheckMenu(1,5,true);  p_menuToolbar->setEnableMenu(1,5,false); m_runMode = 1;
                p_statusToolbar->displayGcsRunMode(1);
                p_serialPortCommu->enableSimuCommu(false);
                
                p_menuToolbar->setEnableMenu(2,4,false);
                p_menuToolbar->setEnableMenu(2,5,false); p_menuToolbar->setCheckMenu(2,5,false); 
                p_menuToolbar->setEnableMenu(2,6,false); p_menuToolbar->setCheckMenu(2,6,false); 
                                        
                p_menuToolbar->setEnableMenu(3,1,false);
                p_menuToolbar->setEnableMenu(3,2,false);
                p_menuToolbar->setEnableMenu(3,3,false);
                p_menuToolbar->setEnableMenu(3,4,false);
                p_menuToolbar->setEnableMenu(3,5,false);
                p_menuToolbar->setEnableMenu(3,6,false);
                p_menuToolbar->setEnableMenu(3,7,false);
            }
            break;
        case 2:   //echo测试模式
            if (p_menuToolbar->isMenuChecked(1,3)) {                        
                p_menuToolbar->setCheckMenu(1,3,true);  p_menuToolbar->setEnableMenu(1,3,false); m_runMode = 2;
                p_menuToolbar->setCheckMenu(1,4,false); p_menuToolbar->setEnableMenu(1,4,true);    
                p_menuToolbar->setCheckMenu(1,5,false); p_menuToolbar->setEnableMenu(1,5,true);
                p_statusToolbar->displayGcsRunMode(2);
                p_serialPortCommu->enableSimuCommu(false);
                
                p_menuToolbar->setEnableMenu(2,4,false);
                p_menuToolbar->setEnableMenu(2,5,false); p_menuToolbar->setCheckMenu(2,5,false); 
                p_menuToolbar->setEnableMenu(2,6,false); p_menuToolbar->setCheckMenu(2,6,false); 
                
                p_menuToolbar->setEnableMenu(3,5,true);
                if (isOpenCom==true) {
                    p_menuToolbar->setEnableMenu(3,1,true);
                }
                else {                        
                    p_menuToolbar->setEnableMenu(3,1,false);
                    p_menuToolbar->setEnableMenu(3,2,false);
                    p_menuToolbar->setEnableMenu(3,3,false);
                    p_menuToolbar->setEnableMenu(3,4,false);                         
                    p_menuToolbar->setEnableMenu(3,6,false);
                    p_menuToolbar->setEnableMenu(3,7,false);
                } 
            }            
            break;
        case 3:   //echo仿真模式
            if (p_menuToolbar->isMenuChecked(1,4)) {                        
                p_menuToolbar->setCheckMenu(1,3,false); p_menuToolbar->setEnableMenu(1,3,true);  
                p_menuToolbar->setCheckMenu(1,4,true);  p_menuToolbar->setEnableMenu(1,4,false); m_runMode = 3;
                p_menuToolbar->setCheckMenu(1,5,false); p_menuToolbar->setEnableMenu(1,5,true);
                p_statusToolbar->displayGcsRunMode(3);
                p_serialPortCommu->enableSimuCommu(true);
                
                p_menuToolbar->setEnableMenu(2,4,true);
                p_menuToolbar->setEnableMenu(2,5,false); p_menuToolbar->setCheckMenu(2,5,false); 
                p_menuToolbar->setEnableMenu(2,6,false); p_menuToolbar->setCheckMenu(2,6,false); 
                                        
                p_menuToolbar->setEnableMenu(3,1,false);
                p_menuToolbar->setEnableMenu(3,2,false);
                p_menuToolbar->setEnableMenu(3,3,false);
                p_menuToolbar->setEnableMenu(3,4,false);
                p_menuToolbar->setEnableMenu(3,5,false);
                p_menuToolbar->setEnableMenu(3,6,false);
                p_menuToolbar->setEnableMenu(3,7,false);
            }            
            break;
        case 4:  //echo查询使能开
            p_menuToolbar->setEnableMenu(3,1,false);  p_menuToolbar->setEnableMenu(3,2,true);
            p_menuToolbar->setEnableMenu(3,3,true);   p_menuToolbar->setEnableMenu(3,4,false);
            break;
        case 5:  //echo查询使能关 
            p_menuToolbar->setEnableMenu(3,1,true);   p_menuToolbar->setEnableMenu(3,2,false);
            p_menuToolbar->setEnableMenu(3,3,false);  p_menuToolbar->setEnableMenu(3,4,false);
            p_menuToolbar->setEnableMenu(3,5,false);
            p_menuToolbar->setEnableMenu(3,6,false);  p_menuToolbar->setEnableMenu(3,7,false);
            break;
        case 6:  //echo设置使能开 
            p_menuToolbar->setEnableMenu(3,3,false);  p_menuToolbar->setEnableMenu(3,4,true);
            p_menuToolbar->setEnableMenu(3,5,true);   
            p_menuToolbar->setEnableMenu(3,6,true);   p_menuToolbar->setEnableMenu(3,7,true);            
            break;
        case 7:  //echo设置使能关 
            p_menuToolbar->setEnableMenu(3,3,true);   p_menuToolbar->setEnableMenu(3,4,false);
            p_menuToolbar->setEnableMenu(3,5,false);
            p_menuToolbar->setEnableMenu(3,6,false);  p_menuToolbar->setEnableMenu(3,7,false);
            break;
        case 8:  //echo保存所有数据 
            p_menuToolbar->setEnableMenu(3,1,true);  p_menuToolbar->setEnableMenu(3,2,false);
            p_menuToolbar->setEnableMenu(3,3,false);  p_menuToolbar->setEnableMenu(3,4,false);
            p_menuToolbar->setEnableMenu(3,5,false);
            p_menuToolbar->setEnableMenu(3,6,false);  p_menuToolbar->setEnableMenu(3,7,false);
            break;
        case 9:  //echo删除所有数据 
            p_menuToolbar->setEnableMenu(3,1,true);   p_menuToolbar->setEnableMenu(3,2,false);
            p_menuToolbar->setEnableMenu(3,3,false);  p_menuToolbar->setEnableMenu(3,4,false);
            p_menuToolbar->setEnableMenu(3,5,false);
            p_menuToolbar->setEnableMenu(3,6,false);  p_menuToolbar->setEnableMenu(3,7,false);
            break;
    }
}
    
bool MainWindow::openSerialPort()
{
    QSerialSettingsDialog::Settings p = p_serialConfigDlg->settings();

    p_serialPort->setPortName(p.name);
    if (p_serialPort->open(QIODevice::ReadWrite)) {
        if (p_serialPort->setBaudRate(p.baudRate)
                && p_serialPort->setDataBits(p.dataBits)
                && p_serialPort->setParity(p.parity)
                && p_serialPort->setStopBits(p.stopBits)
                && p_serialPort->setFlowControl(p.flowControl)) {
            
            return (true);            
        } else {
            p_serialPort->close();
            QMessageBox::critical(this, tr("Error"), p_serialPort->errorString());
                
            return (false);
        }
    } else {
        QMessageBox::critical(this, tr("Error"), p_serialPort->errorString());
        return (false);
    }
}

void MainWindow::closeSerialPort()
{
    p_serialPort->close();
    p_serialPortCommu->enableSimuCommu(false);
}

void MainWindow::slot_SerialPortHandleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), p_serialPort->errorString());

        closeSerialPort();
    }
}

bool MainWindow::openUdpPort()
{
    QUdpPortSettingDialog::Settings p = p_udpConfigDlg->settings();

    if (false==(p_udpPortCommu->setUdpPort(p))) {         
        QMessageBox::about(this, "error","ERRORR");   
        return (false);       
    }
    else return (true);
}

void MainWindow::closeUdpPort()
{
    p_udpPortCommu->closeUdpPort();
}

bool MainWindow::openWaypointLoad()
{
    QString line;
    QStringList fields;
    QVector<double> wplon;
    QVector<double> wplat;
    double *lon = new double[50];
    double *lat = new double[50];
    int     i=0, count=0, tmpI;
    bool    flag;
    
    QFile *m_pFileData = new QFile(this);

    QStringList    fileNameList;
    QString        filename;
    QFileDialog   *filedlg=new QFileDialog(this);
    filedlg->resize(240,320);                        //设置显示的大小
    filedlg->setWindowTitle(tr("打开航线文件"));     //设置文件保存对话框的标题
    filedlg->setAcceptMode(QFileDialog::AcceptOpen); //设置文件对话框为打开模式
    filedlg->setFileMode(QFileDialog::ExistingFile); //设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
    filedlg->setViewMode(QFileDialog::Detail);

    if ( filedlg->exec() == QDialog::Accepted )      //如果成功的执行
    {
       fileNameList = filedlg->selectedFiles();      //返回文件列表的名称
       filename = fileNameList[0];                   //取第一个文件名
    }
    else{flag=false; return flag;}


    if (!filename.isNull()) {  
        m_pFileData->setFileName(filename);
        if (m_pFileData->open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(m_pFileData);
            while (!in.atEnd()) {
                line = in.readLine();
                if (!line.isEmpty()) {
                     fields = line.split(',');
                     tmpI   = fields.takeFirst().toInt();   tmpI = tmpI;
                     tmpI   = fields.takeFirst().toInt();
                     lon[i] = fields.takeFirst().toDouble();
                     lat[i] = fields.takeFirst().toDouble();
                }
                i++;  count=i;
            } 
            p_mapWidget->TOJavaScript(QString("clear_frame();"));
            
            i=0;
            while(i<count) {
                p_mapWidget->TOJavaScript(QString("setframepath(%1,%2);")
                                          .arg(lon[i],0,'g',12)
                                          .arg(lat[i],0,'g',12)); 
                i++;
            }
            i=0;
            p_mapWidget->TOJavaScript(QString("frame_center();"));
            p_mapWidget->TOJavaScript(QString("addlabel();"));
            p_maptoolbar->actionset();
            for (i=0;i<count;i++) {
                wplon << lon[i];
                wplat << lat[i];
            }
            p_localPicture->setWPData(wplon, wplat);
            p_localPicture->MaptoolTOJava(1);
            
            flag = true;
        }
        else {
            QMessageBox::critical(this,tr("error"),tr("File error!"));
            flag = false;
        }
        
        m_pFileData->close();
    }
    else {
        QMessageBox::critical(this,tr("错误"),tr("文件打开失败！"));
        flag = false;
    }
    
    delete m_pFileData;
    return (flag);
}

void MainWindow::slot_checkWindowsMenu(int idx)
{
    switch (idx) {
        case 1: p_menuToolbar->setCheckMenu(5,4,false);  break;
        case 2: p_menuToolbar->setCheckMenu(5,5,false);  break;
        case 3: p_menuToolbar->setCheckMenu(5,6,false);  break;
    }
}

void MainWindow::slot_hideRightWidget()
{
    p_mapbutton->move(this->width()-p_mapbutton->width(), p_mapWidget->y()+p_mapWidget->height()-p_mapbutton->height());
    p_maptoolbar->move(p_mapWidget->width()-p_maptoolbar->width(), p_mapCentralStack->y()+p_mapWidget->height()-p_mapbutton->height()+30);
    
    if (p_rightwidget->text()==">") {
        p_FPDWidget->hide();       p_UASWidget->hide();
        p_dataFrameWidget->hide(); p_textBrowserWidget->hide(); p_cmdWidget->hide();
        p_rightwidget->setText("<");
        p_rightwidget->move(this->width()-p_rightwidget->width(),(p_mapWidget->y()+p_mapWidget->height()-p_rightwidget->height())/2);
    }
    else {
        p_FPDWidget->show();       p_UASWidget->show();
        p_dataFrameWidget->show(); p_textBrowserWidget->show(); p_cmdWidget->show();
        p_rightwidget->setText(">");
        p_rightwidget->move(this->width()-p_rightwidget->width()-300,(p_mapWidget->y()+p_mapWidget->height()-p_rightwidget->height())/2);
    }
}

void MainWindow::slot_hideMapToolbarButton()
{
    p_mapbutton->hide();
    p_maptoolbar->show();
}

void MainWindow::slot_showMapToolbarButton()
{
    p_mapbutton->show();
    p_maptoolbar->hide();
}

void MainWindow::slot_MaptoolTOJava(int idx)
{
    if (p_mapWidget   ==p_mapCentralStack->currentWidget()) p_mapWidget->MaptoolTOJava(idx);
    if (p_localPicture==p_mapCentralStack->currentWidget()) p_localPicture->MaptoolTOJava(idx);
}

void MainWindow::openFirmwareUpdate()
{
    if (p_serialPort->isOpen()) {
        p_firmwarwUpdate->show();
    }
    else QMessageBox::warning(this,"串口状态","未检测到串口开！");
}

void MainWindow::slot_setPrintText(QString text, QColor color)
{
    QString  str,str_time;
    
    str_time = QDateTime::currentDateTime().toString("hh:mm:ss: " );
    str = str_time + text;
    p_textBrowserWidget->setTextColor(color);
    p_textBrowserWidget->append(str);
}

void MainWindow::slot_setlight(int flag)
{
    p_statusToolbar->displaylight(flag);
}

void MainWindow::slot_setsendbutton(bool flag)
{
   p_cmdWidget->setbuttonstate(flag);
}

void MainWindow::slot_addToJava()
{
    p_mapWidget->addNametoJava("mainwindow",this);
}

void MainWindow::slot_fromjava(QString lng,QString lat)
{
    static int idx=0;
    QString fileName = "wpdata.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append)) {
        QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }
    QTextStream in(&file);
    in<<QString::number(1)<<","<<QString::number(idx+1)<<","<<lng<<","<<lat<<","<<"100"<<","<<"00"<<","<<"00"<<","<<"00"<<","<<"00"<<"\n";
    file.close();
    idx++;
}

void MainWindow::slot_setactiveseqid(quint8 seqid)
{
   active_seqid=seqid;
   p_cmdWidget->set_acseqid(seqid);
   p_UASWidget->set_acseqid(seqid);    //设置当前激活序列号

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    p_mapbutton->move(p_mapCentralStack->width()-p_mapbutton->width(),p_mapCentralStack->y()+p_mapCentralStack->height()-p_mapbutton->height());
    p_maptoolbar->move(p_mapCentralStack->width()-p_maptoolbar->width(),p_mapCentralStack->y()+p_mapCentralStack->height()-p_mapbutton->height()+p_mapbutton->height());
    p_rightwidget->move(p_mapCentralStack->width()-p_rightwidget->width(),(p_mapCentralStack->y()+p_mapCentralStack->height()-p_rightwidget->height())/2);
}

void MainWindow::slot_RealtimeDisplay()
{
//    if (p_serialPort->isOpen()||p_serialPortCommu->Play_Timer->isActive()) {
        m_activeNumofUAS = 1;
        if (m_activeNumofUAS>=1&&m_activeNumofUAS<=5) {
            switch (p_dataProtocol->data_heartbeat[m_activeNumofUAS].uasState) {
                case 0:   break;
                case 1:
                    if (!p_menuToolbar->isMenuChecked(1,5)) {
                        p_menuToolbar->setCheckMenu(1,5,true);
                        p_menuToolbar->setCheckMenu(1,3,false);
                        p_menuToolbar->setCheckMenu(1,4,false);
                
                        p_menuToolbar->setEnableMenu(3,1,false);
                        p_menuToolbar->setEnableMenu(3,2,false);
                        p_menuToolbar->setEnableMenu(3,3,false);
                        p_menuToolbar->setEnableMenu(3,4,false);
                        p_menuToolbar->setEnableMenu(3,5,false);
                        p_menuToolbar->setEnableMenu(3,6,false);
                        p_menuToolbar->setEnableMenu(3,7,false);
                    }
                
                    m_runMode = 1; p_statusToolbar->displayGcsRunMode(1);   break;  //飞行模式
                case 2:
                    if (!p_menuToolbar->isMenuChecked(1,3)) {
                        p_menuToolbar->setCheckMenu(1,3,true);
                        p_menuToolbar->setCheckMenu(1,4,false);
                        p_menuToolbar->setCheckMenu(1,5,false);
                
                        if (isOpenCom==true) {
                            p_menuToolbar->setEnableMenu(3,1,true);
                        }
                        else {
                            p_menuToolbar->setEnableMenu(3,1,false);
                            p_menuToolbar->setEnableMenu(3,2,false);
                            p_menuToolbar->setEnableMenu(3,3,false);
                            p_menuToolbar->setEnableMenu(3,4,false);
                            p_menuToolbar->setEnableMenu(3,6,false);
                            p_menuToolbar->setEnableMenu(3,7,false);
                        }
                    }
                    m_runMode = 2; p_statusToolbar->displayGcsRunMode(2);   break;  //测试模式
                case 3:
                    if (!p_menuToolbar->isMenuChecked(1,4)) {
                        p_menuToolbar->setCheckMenu(1,4,true);
                        p_menuToolbar->setCheckMenu(1,3,false);
                        p_menuToolbar->setCheckMenu(1,5,false);
                
                        p_menuToolbar->setEnableMenu(3,1,false);
                        p_menuToolbar->setEnableMenu(3,2,false);
                        p_menuToolbar->setEnableMenu(3,3,false);
                        p_menuToolbar->setEnableMenu(3,4,false);
                        p_menuToolbar->setEnableMenu(3,5,false);
                        p_menuToolbar->setEnableMenu(3,6,false);
                        p_menuToolbar->setEnableMenu(3,7,false);
                    }
                    m_runMode = 3; p_statusToolbar->displayGcsRunMode(3);   break;  //仿真模式
                default:  break;
            }
        }

       if (m_runMode!=0)  p_statusToolbar->displayUavFlyStatus(1);

        p_FPDWidget->SetAllData(p_dataProtocol->data_imu.theta,
                                p_dataProtocol->data_imu.phi,
                                p_dataProtocol->data_hmc.psi,
                                p_dataProtocol->data_gps.alt,
                                p_dataProtocol->data_gps.Vd,
                                p_dataProtocol->data_imu.R,
                                p_dataProtocol->data_gps.Hdot);          //刷新平显


        p_UASWidget->updateMultiUAS(p_dataProtocol->data_heartbeat);     //刷新多机心跳数据
        p_dataFrameWidget->updatePageDisplay();                        //刷新下传帧数据
        
        p_plotWidget->setPlotData(p_dataProtocol->data_gps.alt,
                                  p_dataProtocol->height_var,
                                  p_dataProtocol->data_gps.Vd,
                                 (p_dataProtocol->Vx_opt + p_dataProtocol->Vx_var),
                                  p_dataProtocol->ele_law,
                                  p_dataProtocol->ail_law,
                                  p_dataProtocol->rud_law,
                                  p_dataProtocol->col_law);              //刷新高度,速度,变距曲线

        p_mapWidget->TOJavaScript(QString("settimepath(%1,%2,%3);")      //刷新地图轨迹
                                   .arg(p_dataProtocol->data_gps.lon,0,'g',12)
                                   .arg(p_dataProtocol->data_gps.lat,0,'g',12)
                                   .arg(p_dataProtocol->data_hmc.psi));

        p_localPicture->setAirplane(p_dataProtocol->data_gps.lon,p_dataProtocol->data_gps.lat,p_dataProtocol->data_hmc.psi);

        p_statusToolbar->displayLocalTime(QDateTime::currentDateTime().toString("hh:mm:ss"));  //刷新时间

        float a=p_serialPortCommu->filepos;     //此处不好!
        a=a/p_serialPortCommu->filelength;
        p_recordDlg->setvalue(a*100);
 //  }
}

void MainWindow::slot_playbackset(int opt)
{
    switch (opt) {
        case 1:
            p_serialPortCommu->Play_Timer->start(0.2);
            p_recordDlg->setWindowTitle(QString("播放(%1倍速)").arg(p_serialPortCommu->speed));
            break;
        case 2:            
            p_serialPortCommu->Play_Timer->stop();
            p_recordDlg->setWindowTitle("暂停");
            break;        
        case 3:
            if(p_serialPortCommu->speed>1)  p_serialPortCommu->speed=p_serialPortCommu->speed/2;
            p_recordDlg->setWindowTitle(QString("播放(%1倍速)").arg(p_serialPortCommu->speed));
            break;
        case 4:
            if(p_serialPortCommu->speed<16) p_serialPortCommu->speed=p_serialPortCommu->speed*2;
            p_recordDlg->setWindowTitle(QString("播放(%1倍速)").arg(p_serialPortCommu->speed));
            break;
        default:  break;
    }
}

void  MainWindow::closeEvent(QCloseEvent *e)
{
   Q_UNUSED(e);
    if(QMessageBox::information(NULL, "退出地面站", "确认要退出地面站？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::No)
    {
        e->ignore();
    }
    else e->accept();
}
//end *.cpp
