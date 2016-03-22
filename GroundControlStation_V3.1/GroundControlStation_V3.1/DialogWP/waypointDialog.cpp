#include "waypointDialog.h"
#include "ui_waypointDialog.h"

QWaypointDialog::QWaypointDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWaypointDialog)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setMinimumSize(525,598);
    setMaximumSize(525,598);  setModal(0);

    p_wpDesignWidget = new QWaypointTabWidget(this);  //小部件创建
    p_wpDesignWidget->setMinimumSize(525,598);
    p_wpDesignWidget->setMaximumSize(525,598);

    QHBoxLayout *Hlayout = new QHBoxLayout();
    Hlayout->setContentsMargins(0,0,0,0);
   //Hlayout->addWidget(p_wpDisplayChart);
    Hlayout->addWidget(p_wpDesignWidget);
    setLayout(Hlayout);
    connect(p_wpDesignWidget,SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)), this, SIGNAL(signal_cmdOutput(quint8,quint8,quint8,const quint8 *,quint8)));
   connect(p_wpDesignWidget,SIGNAL(signal_cmdOnDrawWP()),                                         this, SLOT(slot_onDrawWP()));
    //connect(p_wpDesignWidget,SIGNAL(signal_cmdOnDelWP()),                                          this, SLOT(slot_clearDraw()));
   // connect(p_wpDisplayChart,SIGNAL(signal_addToJava()),                                           this, SLOT(slot_addconnecttojava()));

    connect(this, SIGNAL(signal_waypointCmdEchoOK(quint8,WayPoint_Struc_t)), p_wpDesignWidget, SLOT(slot_waypointCmdEchoOK(quint8,WayPoint_Struc_t)));
    connect(p_wpDesignWidget,SIGNAL(signal_picklonlat()),this,SLOT(slot_picklonlat()));

}

QWaypointDialog::~QWaypointDialog()
{
    delete ui;
    if (p_wpDisplayChart)  delete p_wpDisplayChart;
    if (p_wpDesignWidget)  delete p_wpDesignWidget;
}

 void QWaypointDialog::setmapwidget(QPanelMap2DWidget *mapwidget)
 {
     p_wpDisplayChart=mapwidget;
     connect(p_wpDisplayChart,SIGNAL(signal_addToJava()),                                           this, SLOT(slot_addconnecttojava()));
 }

void QWaypointDialog::slot_onDrawWP()
{


  p_wpDisplayChart->TOJavaScript(QString("clear_frame();"));
  for(int i=1;i<p_wpDesignWidget->numDot_tab1+1;i++){
      p_wpDisplayChart->TOJavaScript(QString("setframepath(%1,%2);")
                                .arg(p_wpDesignWidget->mDataPF[i].x(),0,'g',12)
                                .arg(p_wpDesignWidget->mDataPF[i].y(),0,'g',12));
  }
  p_wpDisplayChart->TOJavaScript(QString("frame_center();"));
  p_wpDisplayChart->TOJavaScript(QString("addlabel();"));
}


//void QWaypointDialog::slot_clearDraw()
//{
////    p_wpDisplayChart->mDataP.clear();
////    p_wpDisplayChart->update();
//}

void QWaypointDialog::slot_addconnecttojava()
{
    p_wpDisplayChart->addNametoJava("WaypointDialog",this);


}

void QWaypointDialog::slot_fromjava(QString lng,QString lat)
{
    double x=lng.toDouble();
    double y=lat.toDouble();
    p_wpDesignWidget->setline_lonlat(QString("%1").arg(x,0,'g',9),QString("%1").arg(y,0,'g',8));
}

void QWaypointDialog::slot_picklonlat()
{
    p_wpDisplayChart->TOJavaScript(QString("picklonlat();"));

}
