#ifndef MULTICENTERDIALOG_H
#define MULTICENTERDIALOG_H

#include <QDialog>
#include "cfg.h"
#include "frameDialog.h"
#include "multiInstall.h"
#include "multiRC.h"
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"
#include "multicontrol.h"
#include "multianalogcfgwidget.h"
#include "multihmcsetwidget.h"
#include "multisplashwidget.h"

namespace Ui {
    class multiCenterDialog;
}

class multiCenterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit multiCenterDialog(QWidget *parent = 0);
    ~multiCenterDialog();
    cfgWidget *p_cfgWidget;
    frameDialog *P_framDialog;
    multiInstallDialog *p_mutiInstallDialog;
    mutiRCDialog *p_mutiRCDialog;
    multicontrol *p_mmulticontrol;
    multiAnalogCfgWidget *p_multiADcfgWidget;
    multiHMCsetWidget  *p_multiHMCsetWidget;
    multisplashWidget *p_multisplashWidget;
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
private:
    Ui::multiCenterDialog *ui;
    int ad0,ad1,ad2,ad3,ad4,ad5,ad6,ad7;
    void initDialog();
    void initbuttongroup();
private slots:
    void slot_buttonselect(int button);
    void slot_echoMessagePacket(datalink_message_t *echoMsg,bool cfgType);
};

#endif
