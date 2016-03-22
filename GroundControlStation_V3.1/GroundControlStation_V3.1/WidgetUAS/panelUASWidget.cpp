#include "panelUASWidget.h"
#include "ui_panelUASWidget.h"
#include <QDebug>

QPanelUASWidget::QPanelUASWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanelUASWidget)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);

    multUAS[0] = new QMultiUASForm("HAG1","AG1",0,this);
    multUAS[1] = new QMultiUASForm("HAG2","AG2",1,this);
    multUAS[2] = new QMultiUASForm("HAG3","AG3",2,this);
    multUAS[3] = new QMultiUASForm("RR4","R4",3,this);
    multUAS[4] = new QMultiUASForm("RR6","R6",4,this);

    for (int idx=0; idx<5; idx++){
        ui->tabWidget->addTab(multUAS[idx], multUAS[idx]->uas_Type);
        connect(multUAS[idx], SIGNAL(signal_uavActivedButton(quint8)), this, SLOT(slot_activebutton(quint8)));
    }  
    
    curActiveID = 0;           //初始化.都没有激活
    isChangingUAS = false;

    p_realTimer=new QTimer();
    p_realTimer->start(200);
    connect(p_realTimer,SIGNAL(timeout()),this, SLOT(slot_RealtimeDisplay()));
    
}

QPanelUASWidget::~QPanelUASWidget()
{
    delete ui;

    for (int idx=0; idx<5; idx++){
        if (multUAS[idx])  delete multUAS[idx];
    }
}

void QPanelUASWidget::slot_activebutton(quint8 ActiveseqID)
{
//   quint8 payload[20];
//   for (int idx=0; idx<5; idx++){
//       if(ActiveseqID==idx)  payload[0]=1;
//       else                  payload[0]=0;
//   }
//   emit signal_cmdOutput(ActiveseqID, 6, 0x1F, payload, 1);
    curActiveID=ActiveseqID;
    qDebug()<<"wsf"<<curActiveID;
}

void QPanelUASWidget::slot_RealtimeDisplay()
{
    static quint8 tick=0;
    quint8 payload[20];
    qDebug()<<"minh"<<tick;
    if(tick==(curActiveID))   payload[0]=1;
    else                        payload[0]=0;
    emit signal_cmdOutput((tick), 6, 0x1F, payload, 1);
    tick=(tick+1)%5;
}

void  QPanelUASWidget::updateMultiUAS(heartbeat_Struc_t  *data)
{
    for (int idx=0; idx<5; idx++){
        multUAS[idx]->updateUASHeartbeat(data+idx);
    }
}

 void QPanelUASWidget::set_acseqid(quint8 seqid)
 {
     for (int idx=0; idx<5; idx++){
         if(seqid==idx)  multUAS[idx]->set_buttonstate(true);
         else            multUAS[idx]->set_buttonstate(false);
     }
 }
