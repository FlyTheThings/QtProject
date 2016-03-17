#ifndef TOTALWIDGET_H
#define TOTALWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include "multiUASForm.h"

namespace Ui {
    class QPanelUASWidget;
}

class QPanelUASWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPanelUASWidget(QWidget *parent = 0);
    ~QPanelUASWidget();
    
    void updateMultiUAS(heartbeat_Struc_t *data);
    void set_acseqid(quint8 seqid);//设置当前激活sysid的序列号

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void signal_changedActiveUAS(quint8 sysid);
private slots:
    void slot_activebutton(quint8 ActiveseqID);
    void slot_RealtimeDisplay();
    
private:
    Ui::QPanelUASWidget *ui;    
    
    QMultiUASForm *multUAS[5];    
    bool           isChangingUAS; 
    quint8         curActiveID;
    QTimer         *p_realTimer;         //定时器变量
};

#endif // TOTALWIDGET_H
