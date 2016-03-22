#include "centerWidget.h"
#include "ui_centerWidget.h"

centerWidget::centerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::centerWidget)
{
    ui->setupUi(this);
    
    initWidget();
    initButtonGroup();
    
    connect(p_InstallWidget,   SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_RcWidget,        SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(P_SwashplateWidget,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(p_SelfflyWidget,   SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(P_FblrudWidget,    SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
    connect(P_RpmgyroWidget,   SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
}

centerWidget::~centerWidget()
{
    delete ui;
    if (p_RcWidget)         delete p_RcWidget;
    if (p_ControlWidget)    delete p_ControlWidget;
    if (P_FblrudWidget)     delete P_FblrudWidget;
    if (P_RpmgyroWidget)    delete P_RpmgyroWidget;
    if (P_SplashWidget)     delete P_SplashWidget;    
    if (P_SwashplateWidget) delete P_SwashplateWidget;    
    if (p_InstallWidget)    delete p_InstallWidget;    
    if (p_SelfflyWidget)    delete p_SelfflyWidget;            
}

void centerWidget::initWidget()
{
    p_RcWidget        = new QRcWidget(this);
    p_ControlWidget   = new QControlWidget(this);
    P_FblrudWidget    = new QFblrudWidget(this);
    P_RpmgyroWidget   = new QRpmgyroWidget(this);
    P_SplashWidget    = new QSplashWidget(this);
    P_SwashplateWidget= new QSwashplateWidget(this);
    p_InstallWidget   = new QInstallWidget(this);
    p_SelfflyWidget   = new QSelfflyWidget(this);
    
    int idx;
    idx = ui->stackedWidget->addWidget(p_RcWidget);         idPage.insert(1, idx);
    idx = ui->stackedWidget->addWidget(p_ControlWidget);    idPage.insert(2, idx);
    idx = ui->stackedWidget->addWidget(P_FblrudWidget);     idPage.insert(3, idx);
    idx = ui->stackedWidget->addWidget(P_RpmgyroWidget);    idPage.insert(4, idx);
    idx = ui->stackedWidget->addWidget(P_SplashWidget);     idPage.insert(5, idx);
    idx = ui->stackedWidget->addWidget(P_SwashplateWidget); idPage.insert(6, idx);
    idx = ui->stackedWidget->addWidget(p_InstallWidget);    idPage.insert(7, idx);
    idx = ui->stackedWidget->addWidget(p_SelfflyWidget);    idPage.insert(8, idx);
    
    ui->stackedWidget->setCurrentIndex(idPage[7]);
}

void centerWidget::initButtonGroup()
{
    QButtonGroup *buttongroup = new QButtonGroup(this);
    
    buttongroup->addButton(ui->pushButton_rcset,     0);
    buttongroup->addButton(ui->pushButton_controlset,1);
    buttongroup->addButton(ui->pushButton_ailset,    2);
    buttongroup->addButton(ui->pushButton_rpmset,    3);
    buttongroup->addButton(ui->pushButton_spayset,   4);
    buttongroup->addButton(ui->pushButton_tiltset,   5);
    buttongroup->addButton(ui->pushButton_install,   6);
    buttongroup->addButton(ui->pushButton_selflyset, 7);    
    connect(buttongroup,SIGNAL(buttonClicked(int)), this,SLOT(slot_buttonSelect(int)));
}

void centerWidget::slot_buttonSelect(int button)
{
    switch(button) {
        case 0: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 1: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 2: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 3: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 4: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 5: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 6: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
        case 7: ui->stackedWidget->setCurrentIndex(idPage[button+1]);  break;
    }   
}

void centerWidget::slot_echoMessagePacket(datalink_message_t *echoMsg)
{
    int idxPage;
    
    idxPage = ui->stackedWidget->currentIndex();
    switch (idPage.key(idxPage)) {
        case 1:  p_RcWidget->echoMessagePacket(echoMsg);         break;
        case 2:  p_ControlWidget->echoMessagePacket(echoMsg);    break;
        case 3:  P_FblrudWidget->echoMessagePacket(echoMsg);     break;
        case 4:  P_RpmgyroWidget->echoMessagePacket(echoMsg);    break;
        case 5:  P_SplashWidget->echoMessagePacket(echoMsg);     break;
        case 6:  P_SwashplateWidget->echoMessagePacket(echoMsg); break;
        case 7:  p_InstallWidget->echoMessagePacket(echoMsg);    break;    
        case 8:  p_SelfflyWidget->echoMessagePacket(echoMsg);    break;
    }
}
