#ifndef ANALOGWIDGET_H
#define ANALOGWIDGET_H

#include <QWidget>
#include<QButtonGroup>
#include <QTimer>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class analogWidget;
}

class analogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit analogWidget(QWidget *parent = 0);
    ~analogWidget();

    void echoMessagePacket(datalink_message_t *msg);
    
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_ADTimerDisplay();
    void slot_cmdButtonClicked(int ButtonID);
    
private:
    Ui::analogWidget *ui;

    QButtonGroup      *p_QButtongroup;
    QTimer            *p_Timer;                //定时器变量

    void initButtonGroup(void);
    void showEvent(QShowEvent * event);
    void hideEvent(QHideEvent * event);
   
};

#endif // ANALOGWIDGET_H
