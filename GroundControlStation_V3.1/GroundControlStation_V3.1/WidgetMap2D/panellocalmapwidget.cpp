#include "panellocalmapwidget.h"
#include "ui_panellocalmapwidget.h"

QPanellocalmapWidget::QPanellocalmapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanellocalmapWidget)
{
    ui->setupUi(this);
    ui->waypointPlot->setBackground(QPixmap(":/qfi/images/back.jpg"));
    ui->waypointPlot->xAxis->setVisible(false);
    ui->waypointPlot->yAxis->setVisible(false);
    ui->waypointPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom| QCP::iSelectPlottables);

    fermatSpiral1 = new QCPCurve(ui->waypointPlot->xAxis, ui->waypointPlot->yAxis);
    ui->waypointPlot->addPlottable(fermatSpiral1);    //用来绘制航线的
    fermatSpiral1->setPen(QPen(Qt::yellow,4));
    fermatSpiral1->setBrush(QBrush(QColor(0, 0, 255,0)));

    fermatSpiral2 = new QCPCurve(ui->waypointPlot->xAxis, ui->waypointPlot->yAxis);
    ui->waypointPlot->addPlottable(fermatSpiral2);
    fermatSpiral2->setPen(QPen(Qt::blue,3));
    fermatSpiral2->setBrush(QBrush(QColor(0, 0, 255,0)));

    ui->waypointPlot->addGraph();                     // 绘制飞机形状
    ui->waypointPlot->graph(0)->setPen(QPen(Qt::yellow));
    ui->waypointPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    QPixmap image1 = QPixmap(":/qfi/images/airplane.png");
    image2=image1.scaled(32,32);                      //改变大小
 
    timeline_center = true;   wp_center = false;  
     
    connect(ui->waypointPlot,SIGNAL(mouseWheel(QWheelEvent*)), this,SLOT(slot_break_autocentre()));
}

QPanellocalmapWidget::~QPanellocalmapWidget()
{
    delete ui;
}

void QPanellocalmapWidget::setWPData(QVector<double> lon,QVector<double> lat)
{
    waylon=lon;waylat=lat;
    waylonmax=waylonmin=waylon.at(0);
    waylatmax=waylatmin=waylat.at(0);

    for(int idx=1;idx<waylon.size();idx++) {
        if (waylon.at(idx)<waylonmin)    waylonmin=waylon.at(idx);
        else {
            if(waylon.at(idx)>waylonmax) waylonmax=waylon.at(idx);
        }

        if (waylat.at(idx)<waylatmin)    waylatmin=waylat.at(idx);
        else {
            if(waylat.at(idx)>waylatmax) waylatmax=waylat.at(idx);
        }
    }
    waylonlen=waylonmax-waylonmin;
    waylatlen=waylatmax-waylatmin;

    fermatSpiral1->setData(waylon, waylat);//给图形赋值
   // fermatSpiral1->setPen(QPen(Qt::red));
   // fermatSpiral1->setBrush(QBrush(QColor(0, 0, 255,0)));
   //ui->waypointPlot->rescaleAxes(true);
    setWPCenter();
    ui->waypointPlot->replot();            //图形绘制
}

void QPanellocalmapWidget::setAirplane(double lon ,double lat ,double psi)
{
    static double lonmax,lonmin,latmax,latmin;   
    
    lonmax=lon; lonmin=lon;
    latmax=lat; latmin=lat;
    
    if (lon>lonmax)     lonmax=lon;
    else {
        if(lon<=lonmin) lonmin=lon;
    }
    if (lat>latmax)     latmax=lat;
    else {
        if(lat<=latmin) latmin=lat;
    }

    if (psi<=90)
    {

    }
    ui->waypointPlot->graph(0)->clearData();
    matrix2=matrix1;
    matrix2.rotate(psi);
    fermatSpiral2->addData(lon,lat);
    image3=image2.transformed(matrix2);
    ui->waypointPlot->graph(0)->setScatterStyle(QCPScatterStyle(image3));  //添加飞机
    ui->waypointPlot->graph(0)->addData(lon,lat);
    if (timeline_center==true){
         ui->waypointPlot->xAxis->setRange(lonmin-0.3*(lonmax-lonmin),lonmax+0.3*(lonmax-lonmin));
         ui->waypointPlot->yAxis->setRange(latmin-0.3*(latmax-latmin),latmax+0.3*(latmax-latmin));
    }

    ui->waypointPlot->replot();         //图形绘制
}

void QPanellocalmapWidget::setTimeLineCenter()
{
    timeline_center=true;
}

void QPanellocalmapWidget::setWPCenter()
{
    timeline_center=false;
    ui->waypointPlot->xAxis->setRange(waylonmin-0.3*waylonlen,waylonmax+0.3*waylonlen);
    ui->waypointPlot->yAxis->setRange(waylatmin-0.3*waylatlen,waylatmax+0.3*waylatlen);
}

void QPanellocalmapWidget::MaptoolTOJava(int sign)
{
    switch(sign) {
        case 1: fermatSpiral1->setVisible(true);          break;
        case 2: fermatSpiral1->setVisible(false);         break;
       // case 3: fermatSpiral2->setVisible(true);          break;
       // case 4: fermatSpiral2->setVisible(false);         break;
       // case 5: {setWPCenter();  timeline_center=false;   break;}
       // case 6: timeline_center=true;                     break;
       case 7: fermatSpiral2->clearData();                break;
       case 8: fermatSpiral2->setVisible(false);          break;
       case 9: fermatSpiral2->setVisible(true);           break;
       case 10: setWPCenter();  timeline_center=false;   break;
       case 11: timeline_center=true;                     break;
       case 12: fermatSpiral1->clearData();               break;
}
}

void QPanellocalmapWidget::slot_break_autocentre()
{
    timeline_center=false;
}
