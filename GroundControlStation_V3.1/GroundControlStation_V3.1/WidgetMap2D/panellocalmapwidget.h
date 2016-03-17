#ifndef PANELLOCALMAPWIDGET_H
#define PANELLOCALMAPWIDGET_H

#include <QWidget>
#include "WidgetPlot/qcustomplot.h"

namespace Ui {
class QPanellocalmapWidget;
}

class QPanellocalmapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPanellocalmapWidget(QWidget *parent = 0);
    ~QPanellocalmapWidget();
    
    void setAirplane(double lon, double lat, double psi);
    void setWPData(QVector<double> lon,QVector<double> lat);

    void setWPCenter();
    void setTimeLineCenter();    
    void MaptoolTOJava(int sign);
    
private slots:
    void slot_break_autocentre();
    
private:
    Ui::QPanellocalmapWidget *ui;
        
    typedef struct {
        int            num;
        double         lon;
        double         lat;
        double         alt;
        unsigned char  vxd[4];
    }WayPointstruct;
        
    QCPCurve       *fermatSpiral1;
    QCPCurve       *fermatSpiral2;
    QPixmap         image2,image3;
    QMatrix         matrix1,matrix2;
    
    WayPointstruct  waypoint[64];
    QVector<double> waylon, waylat;       //航点集
    
    double waylonmax,waylonmin,waylatmax,waylatmin;
    double waylonlen,waylatlen;
    bool   timeline_center, wp_center;    //居中标志位
};

#endif // PANELLOCALMAPWIDGET_H
