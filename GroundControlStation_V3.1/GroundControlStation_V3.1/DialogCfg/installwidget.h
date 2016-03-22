#ifndef INSTALLWIDGET_H
#define INSTALLWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QString>
#include <QFont>
#include "Shared/messageIDDefine.h"
#include "Shared/dataStructureDefine.H"
#include "Shared/buff.h"

namespace Ui {
class QInstallWidget;
}

class QInstallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QInstallWidget(QWidget *parent = 0);
    ~QInstallWidget();

    void echoMessagePacket(datalink_message_t *msg);        

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_buttonSelect(int button); 
    
private:
    Ui::QInstallWidget *ui;
    
    void initButtonGroup();
    void cmdImuPosAskEcho(int x, int y, int z);
    void cmdGpsPosAskEcho(int x, int y, int z);
};

#endif // INSTALLWIDGET_H
