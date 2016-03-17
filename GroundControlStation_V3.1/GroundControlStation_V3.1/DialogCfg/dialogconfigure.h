#ifndef DIALOGCONFIGURE_H
#define DIALOGCONFIGURE_H

#include <QDialog>
#include <QWidget>
#include <QMap>
#include <QMessageBox>
#include "DialogCfg/rcWidget.h"
#include "DialogCfg/controlWidget.h"
#include "DialogCfg/rpmgyroWidget.h"
#include "DialogCfg/fblrudwidget.h"
#include "DialogCfg/splashwidget.h"
#include "DialogCfg/swashplatewidget.h"
#include "DialogCfg/installwidget.h"
#include "DialogCfg/selfflywidget.h"
#include "DialogCfg/analogwidget.h"

namespace Ui {
class QDialogConfigure;
}

class QDialogConfigure : public QDialog
{
    Q_OBJECT

public:
    explicit QDialogConfigure(QWidget *parent = 0);
    ~QDialogConfigure();
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_buttonSelect(int button);

    void slot_echoMessagePacket(datalink_message_t *echoMsg,bool cfgType);

private:
    Ui::QDialogConfigure *ui;
    QInstallWidget      *p_InstallWidget;     //设备安装
    QRcWidget           *p_RcWidget;          //遥控器
    QSwashplateWidget   *P_SwashplateWidget;  //十字盘
    QFblrudWidget       *P_FblrudWidget;      //旋翼锁尾
    QRpmgyroWidget      *P_RpmgyroWidget;     //罗盘发动机
    QSelfflyWidget      *p_SelfflyWidget;     //自驾参数

    QSplashWidget       *P_SplashWidget;      //喷洒系统
    QControlWidget      *p_ControlWidget;     //控制律
    analogWidget        *p_analogWidget;
    QMap<int, int>      idPage;
    void initWidget();
    void initButtonGroup();
};

#endif // DIALOGCONFIGURE_H
