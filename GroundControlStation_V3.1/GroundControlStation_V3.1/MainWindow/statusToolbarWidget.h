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
    
    void displayGcsRunMode(quint8 idx);                             //��ʾ�������ģʽ 
    void displayUavActiveNumber(quint8 activeID, quint8 totaleNum); //��ʾ��ǰ����ɻ���ź��ܵķɻ���
    void displayUavFlyStatus(quint8 idx);                           //��ʾ���е���״̬
    void displayLocalTime(QString tm);                              //��ʾ����ʱ��

public slots:
    void displaylight(int flag);                                    //ѡ����·״̬�ȵ���ɫ����

private slots:
    void slot_timer();                                              //��ʱ��˸����

private:
    Ui::QStatusToolbarWidget *ui;
        
    QTimer *timer;
    int     flag_light;
};

#endif // DISPLAYTOOLBAR_H
