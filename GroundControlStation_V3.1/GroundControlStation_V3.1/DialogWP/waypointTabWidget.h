#ifndef WAYPOINTTABWIDGET_H
#define WAYPOINTTABWIDGET_H

#include <QTabWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QStringList>
#include <QPointF>
#include <QMap>
#include <QTimer>
#include <QtMath>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QVector>
#include "Shared/dataStructureDefine.H"
#include "Shared/buff.h"

namespace Ui {
    class QWaypointTabWidget;
}

class QWaypointTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit QWaypointTabWidget(QWidget *parent = 0);
    ~QWaypointTabWidget();
    
    QPointF  mDataPF[256];
    int      numDot_tab1;

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);    
    void signal_cmdOnDrawWP();
    void signal_cmdOnDelWP();
    void signal_clearscreen();
    void signal_picklonlat();
public:
    void setline_lonlat(QString lng,QString lat);
private slots:
    void slot_openFile();               //Tab1
    void slot_deleteFile();
    void slot_saveFile();    
    void slot_OnDrawWP();
    void slot_cmdCheckFCCWP(); 
    void slot_cmdUploadFCCWP(); 
    void slot_cmdDeleteFCCWP(); 
    
    void slot_waypointCmdEchoOK(quint8 idx, WayPoint_Struc_t dataWP);
    void slot_waypointcmdEchoOverTimer();
    
    void slot_addDotWaypoint();         //Tab2
    void slot_modifyDotWaypoint();
    void slot_delDotWaypoint();
    void slot_refreshWaypoint();
    void slot_deleteWaypoint();
    void slot_saveWaypoint();

    void slot_customContextMenuRequested(const QPoint &pos);
    void slot_newAirline();
    void slot_newWaypoint();
    void slot_deleAirline();
    void slot_editWaypoint();
    void slot_deletePoint();
    void slot_showcurrentpoint(QTableWidgetItem * item);
    void slot_deletePoint_table1();
    void slot_findpostion();
private:
    Ui::QWaypointTabWidget *ui;
      
    QString  curFileName;         //Tab1-variable
    int      curDot_tab1;
    QTimer  *cmdTimer;            //定时器变量 
    quint8   cmdID;
    
                                  //Tab2
    double   ref_lon, ref_lat;
    void getVxdFromInut(int sp1, QString sp1_Str, int sp2, QString sp2_Str, quint8* vxd);
    void addDotWaypoint_table_1(int row);
    
    
    
    QMap<int, waypoint_struc_t>  designWp;  
    
    QMenu   *popMenu;                         //右键菜单
    QAction *newAirline;

    QMenu   *waypointPopMenu;
    QAction *newWaypoint;
    QAction *deleteAirline;

    QMenu   *waypointCfgPopMenu;
    QAction *editWaypoint;
    QAction *deleteWaypoint;

    int row_current;

    void initTableWidget1(); 
    void processWaypointData(QString dotData, int num);
    
    void initTableWidget2(); 
    void initTableWidget3();  
};

#endif // WAYPOINTTABWIDGET_H
