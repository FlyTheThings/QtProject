#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

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

namespace Ui {
    class centerWidget;
}

class centerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit centerWidget(QWidget *parent = 0);
    ~centerWidget();

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_buttonSelect(int button);
    
    void slot_echoMessagePacket(datalink_message_t *echoMsg);

private:
    Ui::centerWidget *ui;    
        
    QInstallWidget      *p_InstallWidget;     //设备安装
    QRcWidget           *p_RcWidget;          //遥控器
    QSwashplateWidget   *P_SwashplateWidget;  //十字盘
    QFblrudWidget       *P_FblrudWidget;      //旋翼锁尾
    QRpmgyroWidget      *P_RpmgyroWidget;     //罗盘发动机
    QSelfflyWidget      *p_SelfflyWidget;     //自驾参数
    
    QSplashWidget       *P_SplashWidget;      //喷洒系统
    QControlWidget      *p_ControlWidget;     //控制律
    
    QMap<int, int>      idPage;  
    void initWidget();
    void initButtonGroup();
};

#endif // CENTERWIDGET_H
