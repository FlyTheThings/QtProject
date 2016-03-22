#ifndef DOCKWIDGETCMD_H
#define DOCKWIDGETCMD_H

#include <QWidget>
#include <QAbstractButton>
#include <QMessageBox>
#include <QMenu>
#include <QTimer>
#include "speedCmdDialog.h"
#include "positionCmdDialog.h"
#include "waypointCmdDialog.h"
#include "shared/buff.h"
#include "Shared/dataStructureDefine.H"

namespace Ui {
    class QPanelCmdWidget;
}

class QPanelCmdWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QPanelCmdWidget(QWidget *parent = 0);
    ~QPanelCmdWidget();
    
    void isSerialPortOpen(bool flag);
    void setbuttonstate(bool flag);
    void set_acseqid(quint8 seqid);//设置当前激活sysid的序列号

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

public slots:
    void slot_CmdMissionEchoOK(datalink_message_t *message);

private slots:     
    void slot_ActionSelected(QAction *action);
    void slot_ActionSelected_2(QAction *action_2);
    void slot_ActionSelected_2PreSend(int count, quint8 *cmdData, quint8 dataLen);  
    
    void slot_OkSendCmd();
    void slot_cancelSendCmd();
    void slot_enabledSendButton(bool flag);
    void slot_cmdEchoTimer(void);
   
private:
    Ui::QPanelCmdWidget *ui;

    QSpeedCmdDialog    *speedmixwidget;
    QPositionCmdDialog *positionmixwidget;
    QWaypointCmdDialog *wpmixwidget;
    QMenu              *menu_flymix;
    
    QMap<int,     QString>  CmdNum;
    QMap<QString, QString>  CmdInfo, CmdRange; 
    QMap<QString, quint8>   CmdCode, mixCode;
    QMap<QString, double>   CmdZoom;
    
    QString curCmd_str;
    quint8  curCmd_seqid,
            curCmd_compid,              
            curCmd_msgid,               
            curCmd_payload[20],
            curCmd_len;            
    bool    isPermitSend, isSerialPort;
            
    QTimer  *p_cmdEchoTimer;         //定时器变量

    void initCmdButton();
    void initButtonGroup();  
};

#endif // DOCKWIDGETCMD_H
