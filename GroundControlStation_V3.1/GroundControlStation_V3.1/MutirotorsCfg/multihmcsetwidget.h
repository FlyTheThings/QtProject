#ifndef MULTIHMCSETWIDGET_H
#define MULTIHMCSETWIDGET_H

#include <QWidget>
#include<QButtonGroup>
#include <QTimer>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class multiHMCsetWidget;
}

class multiHMCsetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit multiHMCsetWidget(QWidget *parent = 0);
    ~multiHMCsetWidget();
    void echoMessagePacket(datalink_message_t *msg);
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
     void slot_cmdButtonClicked(int ButtonID);
private:
    Ui::multiHMCsetWidget *ui;
    QButtonGroup      *p_QButtongroup;
    void   initButtonGroup(void);
};

#endif // MULTIHMCSETWIDGET_H
