#ifndef FBLRUDWIDGET_H
#define FBLRUDWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class QFblrudWidget;
}

class QFblrudWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QFblrudWidget(QWidget *parent = 0);
    ~QFblrudWidget();
    
     void echoMessagePacket(datalink_message_t *msg);  

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots: 
    void slot_RudServoDir();
    void slot_cmdButtonClicked(int ButtonID);
    void slot_sliderFBLAIL(int value);
    void slot_sliderFBLELE(int value);
    void slot_sliderRUDMax(int value);
    void slot_sliderRUDMin(int value);
    void slot_sliderSOFFSET(int value);

private:
    Ui::QFblrudWidget *ui;
    
    QButtonGroup      *p_QButtongroup;   

    int               *flag;

    QFont             *font;
    
    void initButtonGroup();
    void initSlider();
    void fblRudCmdEchoOk(quint8 x, quint8 *data);
};

#endif // FBLRUDWIDGET_H
