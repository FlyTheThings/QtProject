#ifndef HEIGHTVOLTAGEPLOT_H
#define HEIGHTVOLTAGEPLOT_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
    class QPanelPlotWidget;
}

class QPanelPlotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPanelPlotWidget(QWidget *parent = 0);
    ~QPanelPlotWidget();

    void setPlotData(float height_j, float height_r,float v_k, float v_d,float ele, float ail,float rud, float col);
    
    void showHeightPlot(bool flag);
    void showVoltagePlot(bool flag);
    void showControlPlot(bool flag);
    
signals:
   void signal_checkFailMenu(int idx);

private slots:  
    void slot_Heightmousepress(QMouseEvent*e);
    void slot_Controlmousepress(QMouseEvent*e);
    void slot_Voltagemousepress(QMouseEvent*e);
    void slot_ActionSelected(QAction *action);

private:
    Ui::QPanelPlotWidget *ui;

    QHBoxLayout          *p_plotLayout;
    QCustomPlot          *p_heightPlot;
    QCustomPlot          *p_voltagePlot;
    QCustomPlot          *p_controlPlot;    

    QMenu                *menu_control;
    QMenu                *menu_voltage;
    QMenu                *menu_height;
    
    QAction              *action_ele;
    QAction              *action_ail;
    QAction              *action_rud;
    QAction              *action_col;
    QAction              *action_vd;
    QAction              *action_vk;
    QAction              *action_rh;
    QAction              *action_ah;
    
    QCPItemText          *textLabel,
                         *textLabel_2,
                         *textLabel_3,
                         *textLabel_4,
                         *textLabel_5,
                         *textLabel_6;                         

    void initQMenu();
    void initHeightPlot();
    void initVoltagePlot();
    void initControlPlot();
};

#endif // HEIGHTVOLTAGEPLOT_H
