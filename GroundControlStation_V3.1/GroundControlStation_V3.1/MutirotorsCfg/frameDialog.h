#ifndef FRAMEDIALOG_H
#define FRAMEDIALOG_H
#include "QWidget"
#include <QButtonGroup>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class frameDialog;
}
class frameDialog : public QWidget
{
    Q_OBJECT

public:
    explicit frameDialog(QWidget *parent = 0);
    ~frameDialog();

    void echoMessagePacket(datalink_message_t *msg);

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_cmdButtonClicked(int ButtonID);

private:
    Ui::frameDialog *ui;

    QButtonGroup      *p_QButtongroup;

    void initButtonGroup();
};


#endif // FRAMEDIALOG_H
