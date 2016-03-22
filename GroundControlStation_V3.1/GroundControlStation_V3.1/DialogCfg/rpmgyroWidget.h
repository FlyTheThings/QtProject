#ifndef RPMGYROWIDGET_H
#define RPMGYROWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class QRpmgyroWidget;
}

class QRpmgyroWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QRpmgyroWidget(QWidget *parent = 0);
    ~QRpmgyroWidget();

    void echoMessagePacket(datalink_message_t *msg); 
    
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_colServoDir();
    void slot_cmdButtonClicked(int ButtonID);
    void slot_sliderColMax(int value);
    void slot_sliderColMin(int value);
    void slot_sliderEng(int value);
    void slot_sliderEngOffset(int value);
    void slot_sliderRPMI(int value);
    void slot_lineEditRPM1(QString str1);
    void slot_lineEditRPM2(QString str2);

private:
    Ui::QRpmgyroWidget *ui;
    
    QButtonGroup       *p_QButtongroup;   

    int                *flag;

    int                *rpm;

    QFont              *font;          //存放QT默认字体
    
    void initButtonGroup();   
    void initSlider();
    void initLineEdit();
    void engCmdEchoOk(quint8 x, quint8 *data);
    void hmcCmdEchoOk(quint8 x, quint8 *data);
};

#endif // RPMGYROWIDGET_H
