#ifndef MULTIANALOGCFGWIDGET_H
#define MULTIANALOGCFGWIDGET_H

#include <QWidget>
#include<QButtonGroup>
#include <QTimer>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class multiAnalogCfgWidget;
}

class multiAnalogCfgWidget : public QWidget
{
    Q_OBJECT

public:
    explicit multiAnalogCfgWidget(QWidget *parent = 0);
    ~multiAnalogCfgWidget();

    void echoMessagePacket(datalink_message_t *msg);
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
private slots:
    void slot_ADTimerDisplay();
    void slot_cmdButtonClicked(int ButtonID);
private:
    Ui::multiAnalogCfgWidget *ui;

    QButtonGroup      *p_QButtongroup;
    QTimer            *p_Timer;                //定时器变量

    void initButtonGroup(void);
    void showEvent(QShowEvent * event);
    void hideEvent(QHideEvent * event);
};

#endif // MULTIANALOGCFGWIDGET_H
