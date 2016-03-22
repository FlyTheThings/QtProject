#include "multiUASForm.h"
#include "ui_multiUASForm.h"
#include <QDebug>

QMultiUASForm::QMultiUASForm(const QString type, const QString name, quint8 sysid, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMultiUASForm)
{
    ui->setupUi(this);
    ui->activeButton->setMinimumSize(40,40);
    ui->activeButton->setStyleSheet("background-color:rgb(255,0,0);");
    
    QPixmap photo = QPixmap(name);      //飞机图标
    initTableWidget1();
    initTableWidget2();
    initTableWidget3();
    initMapData();
    
    uas_Name = name;    uas_Type = type;    uas_sysID= sysid;
    connect(ui->activeButton,SIGNAL(clicked()), this, SLOT(slot_buttonSelected()));
    active_state=false;
}

QMultiUASForm::~QMultiUASForm()
{
    delete ui;
}

void QMultiUASForm::initTableWidget1()
{
    ui->tableWidget->clear();
    ui->tableWidget->setMinimumSize(260,25);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setRowHeight(0,24);
    ui->tableWidget->setColumnWidth(0,64);
    ui->tableWidget->setColumnWidth(1,65);
    ui->tableWidget->setColumnWidth(2,64);
    ui->tableWidget->setColumnWidth(3,65);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void QMultiUASForm::initTableWidget2()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setMinimumSize(260,25);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setRowCount(1);
    ui->tableWidget_2->setRowHeight(0,25);
    ui->tableWidget_2->setColumnWidth(0,35);
    ui->tableWidget_2->setColumnWidth(1,220);
  //  ui->tableWidget_2->setShowGrid(true);

    setFont(QFont("System", 5, QFont::Bold));
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(QString("位置")));
    ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(QString("   ,   ,  ")));
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->item(0,0)->setTextAlignment(Qt::AlignHCenter||Qt::AlignVCenter);
    ui->tableWidget_2->item(0,1)->setTextAlignment(Qt::AlignHCenter||Qt::AlignVCenter);
}

void QMultiUASForm::initTableWidget3()
{
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setMinimumSize(260,80);
    ui->tableWidget_3->verticalHeader()->setVisible(false);
    ui->tableWidget_3->horizontalHeader()->setVisible(false);
    ui->tableWidget_3->setColumnCount(6);
    ui->tableWidget_3->setRowCount(3);
    ui->tableWidget_3->setRowHeight(0,24);
    ui->tableWidget_3->setRowHeight(1,24);
    ui->tableWidget_3->setRowHeight(2,24);
    ui->tableWidget_3->setColumnWidth(0,34);
    ui->tableWidget_3->setColumnWidth(1,45);
    ui->tableWidget_3->setColumnWidth(2,34);
    ui->tableWidget_3->setColumnWidth(3,45);
    ui->tableWidget_3->setColumnWidth(4,34);
    ui->tableWidget_3->setColumnWidth(5,64);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

    setFont(QFont("System", 5, QFont::Bold));
    ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(tr("地速")));
    ui->tableWidget_3->setItem(0,2,new QTableWidgetItem(tr("垂速")));
    ui->tableWidget_3->setItem(0,4,new QTableWidgetItem(tr("GPS")));
    ui->tableWidget_3->setItem(1,0,new QTableWidgetItem(tr("航向")));
    ui->tableWidget_3->setItem(1,2,new QTableWidgetItem(tr("航迹")));
    ui->tableWidget_3->setItem(1,4,new QTableWidgetItem(tr("时间")));
    ui->tableWidget_3->setItem(2,0,new QTableWidgetItem(tr("电压")));
    ui->tableWidget_3->setItem(2,2,new QTableWidgetItem(tr("油位")));
    ui->tableWidget_3->setItem(2,4,new QTableWidgetItem(tr("温度")));
}

void QMultiUASForm::initMapData()
{
    mapCtrlMode.insert(1, "手动模式");    mapPlaneMode.insert(1, "起飞准备");      mapVertMode.insert(1, "高度保持");
    mapCtrlMode.insert(2, "速度模式");    mapPlaneMode.insert(2, "悬停保持");      mapVertMode.insert(2, "下滑");
    mapCtrlMode.insert(3, "距离模式");    mapPlaneMode.insert(3, "悬停回转");      mapVertMode.insert(3, "爬升");
    mapCtrlMode.insert(4, "遥控失控");    mapPlaneMode.insert(4, "回转->悬停");    mapVertMode.insert(4, "起飞");
    mapCtrlMode.insert(5, "测试");       mapPlaneMode.insert(5, "前飞->悬停");    mapVertMode.insert(5, "着陆");
    mapCtrlMode.insert(6, "仿真");       mapPlaneMode.insert(6, "侧飞->悬停");    mapVertMode.insert(6, "杆操控");
                                        mapPlaneMode.insert(7, "前转->悬停");    mapVertMode.insert(7, "7未定义");
    mapGuidMode.insert(1, "遥控");       mapPlaneMode.insert(8, "侧转->悬停");
    mapGuidMode.insert(2, "航线");       mapPlaneMode.insert(9, "斜飞->悬停");
    mapGuidMode.insert(3, "H切航点");   mapPlaneMode.insert(10, "前飞");
    mapGuidMode.insert(4, "H切航线");   mapPlaneMode.insert(11, "侧飞");
    mapGuidMode.insert(5, "F切航点");    mapPlaneMode.insert(12, "前飞转弯");
    mapGuidMode.insert(6, "F切航线");    mapPlaneMode.insert(13, "侧飞转弯");
    mapGuidMode.insert(7, "返航");      mapPlaneMode.insert(14, "前转->前飞");
    mapGuidMode.insert(8, "航点悬停");    mapPlaneMode.insert(15, "侧转->侧飞");
    mapGuidMode.insert(9, "飞越航点");    mapPlaneMode.insert(16, "斜飞");
    mapGuidMode.insert(10, "其它航线");   mapPlaneMode.insert(17, "杆操控");
    mapGuidMode.insert(11, "航点徘徊");   mapPlaneMode.insert(18, "未定义");
    mapGuidMode.insert(12, "航线回收");
    mapGuidMode.insert(13, "链路失效");
    mapGuidMode.insert(14, "P2P切入");
    mapGuidMode.insert(15, "农业作业");
}

void QMultiUASForm::set_buttonstate(bool state)
{
    active_state=state;
    if(state==false)
       ui->activeButton->setStyleSheet("background-color:rgb(255,0,0);");
    else
       ui->activeButton->setStyleSheet("background-color:rgb(0,255,0);");
}

void QMultiUASForm::slot_buttonSelected()
{
    if(active_state==false)
       emit signal_uavActivedButton(uas_sysID);

}

void QMultiUASForm::updateUASHeartbeat(heartbeat_Struc_t *data)
{
    QTableWidgetItem *newItem[17];
    for(int i = 0; i <= 16; i++) {
        newItem[i] = new QTableWidgetItem;
        newItem[i]->setFont(QFont("Times", 8, QFont::Bold));
        newItem[i]->setBackgroundColor(Qt::cyan);
        if(i>3)
            newItem[i]->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        else
            newItem[i]->setTextAlignment(Qt::AlignCenter);                    
    }

    if ((data->ctrlMode>0)&&(data->ctrlMode<7))  newItem[0]->setText(mapCtrlMode[data->ctrlMode]);
    else                                         newItem[0]->setText("未定义");
    if ((data->guidMode>0)&&(data->guidMode<15)) newItem[1]->setText(mapGuidMode[data->guidMode]);
    else                                         newItem[1]->setText("未定义");
    if ((data->plMode>0)&&(data->plMode<19))     newItem[2]->setText(mapPlaneMode[data->plMode]);
    else                                         newItem[2]->setText("未定义");
    if ((data->vtMode>0)&&(data->vtMode<8))      newItem[3]->setText(mapVertMode[data->vtMode]);
    else                                         newItem[3]->setText("未定义");

    newItem[4]->setText(QString("%1,  %2,  %3").arg(data->lon,0,'f',7).arg(data->lat,0,'f',7).arg(data->alt,0,'f',3));

    newItem[5]->setText(QString::number(data->vd,'f',2));
    newItem[6]->setText(QString::number(data->Hdot,'f',2));
    QString tmpS;
    switch((data->gpsState&0xE0)>>5){
       case 0: tmpS=tr("NA"); break;
       case 1: tmpS=tr("单点"); break;
       case 2: tmpS=tr("DGPS"); break;
       case 3: tmpS=tr("RTKF");break;
       case 4: tmpS=tr("RTK"); break;
       case 5:                 break;
       case 6:
       case 7:
       break;
    }
    newItem[7]->setText(tmpS+tr(" ")+QString::number(data->gpsState&0x1F));

    newItem[8]->setText(QString::number(data->psi,'f',1));
    newItem[9]->setText(QString::number(data->track,'f',1));
    tmpS = QString("%1:%2:%3").arg(data->flyTime/3600,2,10,QLatin1Char('0')).arg((data->flyTime%3600)/60,2,10,QLatin1Char('0')).arg(data->flyTime%60,2,10,QLatin1Char('0'));
    newItem[10]->setText(tmpS);

    newItem[11]->setText(QString::number(data->voltCell,'f',1));
    newItem[12]->setText(QString::number(data->oilEng,'f',1));
    newItem[13]->setText(QString::number(data->tempEng,'f',1));

    for(int i = 0;i <= 3; i++) {                                             
        ui->tableWidget->setItem(0, i, newItem[i]);                          
    }

    ui->tableWidget_2->setItem(0,1,newItem[4]);
    for(int i = 0;i<=8;i++) {
        if(i<3)         ui->tableWidget_3->setItem(0,i*2+1,newItem[i+5]);
        else if(i<6)    ui->tableWidget_3->setItem(1,i*2+1-6,newItem[i+5]);
        else            ui->tableWidget_3->setItem(2,i*2+1-12,newItem[i+5]);
    }
}

