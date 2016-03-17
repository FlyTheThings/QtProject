#include "multiCenterDialog.h"
#include "ui_multiCenterDialog.h"

multiCenterDialog::multiCenterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::multiCenterDialog)
{
    ui->setupUi(this);

    initDialog();
    initbuttongroup();
    setWindowTitle(tr("多轴配置-安装方式"));
    ui->stackedWidget->setCurrentWidget(p_mutiInstallDialog);

    connect(p_mutiInstallDialog,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(P_framDialog,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_mutiRCDialog,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_cfgWidget,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_mmulticontrol,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_multiADcfgWidget,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_multiHMCsetWidget,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
}

multiCenterDialog::~multiCenterDialog()
{
    delete ui;      
    if(p_mutiInstallDialog) delete p_mutiInstallDialog;
    if(P_framDialog)        delete P_framDialog;
    if(p_mutiRCDialog)      delete p_mutiRCDialog;
    if(p_cfgWidget)         delete p_cfgWidget;
    if(p_mmulticontrol)     delete p_mmulticontrol;
    if(p_multiADcfgWidget)  delete p_multiADcfgWidget;
    if(p_multiHMCsetWidget) delete p_multiHMCsetWidget;
}

void multiCenterDialog::initDialog()
{
    p_mutiInstallDialog = new multiInstallDialog(this);
    P_framDialog = new frameDialog(this);
    p_mutiRCDialog = new mutiRCDialog(this);
    p_cfgWidget = new cfgWidget(this);
    p_mmulticontrol=new multicontrol(this);
    p_multiADcfgWidget=new multiAnalogCfgWidget(this);
    p_multiHMCsetWidget=new multiHMCsetWidget(this);
    p_multisplashWidget=new multisplashWidget(this);
    ad0 = ui->stackedWidget->addWidget(p_mutiInstallDialog);
    ad1 = ui->stackedWidget->addWidget(P_framDialog);
    ad2 = ui->stackedWidget->addWidget(p_mutiRCDialog);
    ad3 = ui->stackedWidget->addWidget(p_cfgWidget);
    ad4 = ui->stackedWidget->addWidget(p_mmulticontrol);
    ad5 = ui->stackedWidget->addWidget(p_multiADcfgWidget);
    ad6 = ui->stackedWidget->addWidget(p_multiHMCsetWidget);
    ad7 = ui->stackedWidget->addWidget (p_multisplashWidget);

}

void multiCenterDialog::initbuttongroup()
{
    QButtonGroup *buttongroup = new QButtonGroup(this);
    buttongroup->addButton(ui->pushButton_Install,0);
    buttongroup->addButton(ui->pushButton_Frame,1);
    buttongroup->addButton(ui->pushButton_RCCfg,2);
    buttongroup->addButton(ui->pushButton_AutoCfg,3);
    buttongroup->addButton(ui->pushButton_controlset,4);
    buttongroup->addButton(ui->pushButton_analogset,5);
    buttongroup->addButton(ui->pushButton_HMCSet,6);
    buttongroup->addButton (ui->pushButton_slashset,7);
    connect(buttongroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_buttonselect(int)));
}

void multiCenterDialog::slot_buttonselect(int button)
{
    switch(button)
    {
        case 0:
        setWindowTitle(tr("多轴配置-安装方式"));
        ui->stackedWidget->setCurrentIndex(ad0);
        break;

        case 1:
        setWindowTitle(tr("多轴配置-机架选择"));
        ui->stackedWidget->setCurrentIndex(ad1);
        break;

        case 2:
        setWindowTitle(tr("多轴配置-遥控器校准"));
        ui->stackedWidget->setCurrentIndex(ad2);
        break;

        case 3:
        setWindowTitle(tr("多轴配置-自驾仪参数"));
        ui->stackedWidget->setCurrentIndex(ad3);
        break;

       case 4:
       setWindowTitle(tr("多轴配置-控制律参数"));
       ui->stackedWidget->setCurrentIndex(ad4);
       break;

       case 5:
        setWindowTitle(tr("多轴配置-模拟量标定"));
        ui->stackedWidget->setCurrentIndex(ad5);
       break;

       case 6:
        setWindowTitle(tr("多轴配置-磁力计设置"));
        ui->stackedWidget->setCurrentIndex(ad6);
        break;

       case 7:
       setWindowTitle(tr("多轴配置-喷洒系统配置"));
       ui->stackedWidget->setCurrentIndex(ad7);
       break;


    default: break;
    }
}

void multiCenterDialog::slot_echoMessagePacket(datalink_message_t *echoMsg,bool cfgType)
{
    if(!cfgType)
    {
        int idx;
        idx = ui->stackedWidget->currentIndex();
        if(idx == ad0) p_mutiInstallDialog->echoMessagePacket(echoMsg);
        if(idx == ad1) P_framDialog->echoMessagePacket(echoMsg);
        if(idx == ad2) p_mutiRCDialog->echoMessagePacket(echoMsg);
        if(idx == ad3) p_cfgWidget->echoMessagePacket(echoMsg);
        if(idx == ad4) p_mmulticontrol->echoMessagePacket(echoMsg);
        if(idx == ad5) p_multiADcfgWidget->echoMessagePacket(echoMsg);
        if(idx == ad6) p_multiHMCsetWidget->echoMessagePacket(echoMsg);
    }
}
