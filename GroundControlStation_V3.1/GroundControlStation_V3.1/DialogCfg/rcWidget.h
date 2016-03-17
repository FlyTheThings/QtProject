#ifndef RCWIDGET_H
#define RCWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <QTimer>
#include <QFont>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class QRcWidget;
}

class QRcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QRcWidget(QWidget *parent = 0);
    ~QRcWidget();

    void echoMessagePacket(datalink_message_t *msg); 
    
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_rcCapTimerDisplay();
        
    void slot_dirButtonClicked(int i);
    void slot_cmdButtonClicked(int ButtonID);
    
private:
    Ui::QRcWidget *ui;
        
    int              *flag;                   /* 极性标志位*/
    QButtonGroup     *p_QButtongroupFlag,
                     *p_QButtongroupFlag1;
    QTimer           *p_Timer;                //定时器变量
    
    void initButtonGroup1();
    void initButtonGroup2();
    
    void rcRawDataEchoOk(quint8 *data);
    void rcTypeEchoOk(quint8 x);
    void rcCaliAskEchoOk(quint8 x, quint8 *data);
};

#endif // RCWIDGET_H
