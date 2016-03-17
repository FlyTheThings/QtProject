#ifndef MULTIINSTALL_H
#define MULTIINSTALL_H

#include "QWidget"
#include<QButtonGroup>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class multiInstallDialog;
}

class multiInstallDialog : public QWidget
{
    Q_OBJECT

public:
    explicit multiInstallDialog(QWidget *parent = 0);
    ~multiInstallDialog();

    void echoMessagePacket(datalink_message_t *msg);

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_cmdButtonClicked(int ButtonID);

private:
    Ui::multiInstallDialog *ui;

    QButtonGroup      *p_QButtongroup;

    void initButtonGroup();
    void cmdImuPosAskEcho(int x, int y, int z);
    void cmdGpsPosAskEcho(int x, int y, int z);
};

#endif
