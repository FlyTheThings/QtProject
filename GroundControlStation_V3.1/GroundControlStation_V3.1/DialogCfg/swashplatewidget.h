#ifndef SWASHPLATEWIDGET_H
#define SWASHPLATEWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class QSwashplateWidget;
}

class QSwashplateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QSwashplateWidget(QWidget *parent = 0);
    ~QSwashplateWidget();
    
    void echoMessagePacket(datalink_message_t *msg); 

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_dirButtonClicked(int ButtonID);
    void slot_cmdButtonClicked(int ButtonID);

    void slot_sliderPhase(int value);
    void slot_sliderMixcol(int value);
    void slot_sliderMixail(int value);
    void slot_sliderMixele(int value);
    void slot_sliderS1(int value);
    void slot_sliderS2(int value);
    void slot_sliderS3(int value);
    void slot_sliderS4(int value);
    
private:
    Ui::QSwashplateWidget *ui;
    
    QButtonGroup   *p_QButtongroup,
                   *p_QButtongroup1,
                   *p_radioButtonGroup;
    int            *flag;

    QFont          *font;       //存放QT默认字体
        
    void initButtonGroup1();
    void initButtonGroup2();
    void initSliders();
    void tiltCmdEchoOk(quint8 x, quint8 *data);
};

#endif // SWASHPLATEWIDGET_H
