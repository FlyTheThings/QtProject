#ifndef WAYPOINTDIALOG_H
#define WAYPOINTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPoint>
#include <QMap>
#include <QtMath>
//#include "DialogWP/pettyChart.h"
#include "DialogWP/waypointTabWidget.h"
#include "WidgetMap2D/panelMap2DWidget.h"

namespace Ui {
class QWaypointDialog;
}

class QWaypointDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QWaypointDialog(QWidget *parent = 0);
    ~QWaypointDialog();  
    void setmapwidget(QPanelMap2DWidget *mapwidget);
public slots:
    void slot_fromjava(QString lng,QString lat);
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void signal_waypointCmdEchoOK(quint8 idx, WayPoint_Struc_t dataWP);
    void signal_addconnecttojava();
private slots:
    void slot_onDrawWP();
    //void slot_clearDraw();
    void slot_addconnecttojava();
    void slot_picklonlat();

private:
    Ui::QWaypointDialog *ui;
    
    QPanelMap2DWidget   *p_wpDisplayChart;
    QWaypointTabWidget  *p_wpDesignWidget;
    //QTimer                 *p_realTimer;
};

#endif // WAYPOINTDIALOG_H
