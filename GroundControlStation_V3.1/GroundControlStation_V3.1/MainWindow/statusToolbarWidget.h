#ifndef DISPLAYTOOLBAR_H
#define DISPLAYTOOLBAR_H

#include <QWidget>
#include <QTimer>

namespace Ui {
    class QStatusToolbarWidget;
}

class QStatusToolbarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QStatusToolbarWidget(QWidget *parent = 0);
    ~QStatusToolbarWidget();
    
    void displayGcsRunMode(quint8 idx);                             //显示软件运行模式 
    void displayUavActiveNumber(quint8 activeID, quint8 totaleNum); //显示当前激活飞机编号和总的飞机数
    void displayUavFlyStatus(quint8 idx);                           //显示飞行的总状态
    void displayLocalTime(QString tm);                              //显示当地时间

public slots:
    void displaylight(int flag);                                    //选择链路状态等的颜色类型

private slots:
    void slot_timer();                                              //定时闪烁处理

private:
    Ui::QStatusToolbarWidget *ui;
        
    QTimer *timer;
    int     flag_light;
};

#endif // DISPLAYTOOLBAR_H
