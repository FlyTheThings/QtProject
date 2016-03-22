#ifndef MULTIRC_H
#define MULTIRC_H

#include "QWidget"
#include <QTimer>
#include<QButtonGroup>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class mutiRCDialog;
}

class mutiRCDialog : public QWidget
{
    Q_OBJECT

public:
    explicit mutiRCDialog(QWidget *parent = 0);
    ~mutiRCDialog();

    void echoMessagePacket(datalink_message_t *msg);

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_rcCapTimerDisplay();
    void slot_CmdButtonGroup(int i);
    void slot_dirButtonClicked(int i);

private:
    Ui::mutiRCDialog *ui;

    int              *flag;                   /* 极性标志位*/
    QButtonGroup     *p_QButtongroupFlag;
    QButtonGroup     *cmdButtonGroup;
    QTimer           *p_Timer;                //定时器变量
    quint8            caliState;

    void initButtonGroup();
    void initCmdButtonGroup();
    void rcRawDataEchoOk(quint8 *data);
    void rcTypeEchoOk(quint8 x);

    void showEvent(QShowEvent * event);
    void hideEvent(QHideEvent * event);
};

#endif
