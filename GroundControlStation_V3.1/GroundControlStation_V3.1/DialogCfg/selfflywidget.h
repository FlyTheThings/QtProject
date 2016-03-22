#ifndef SELFFLYWIDGET_H
#define SELFFLYWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class QSelfflyWidget;
}

class QSelfflyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QSelfflyWidget(QWidget *parent = 0);
    ~QSelfflyWidget();

    void echoMessagePacket(datalink_message_t *msg); 
    
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

private slots:
    void slot_cmdButtonClicked(int ButtonID); 
    void slot_sliderCOL(int value);
    void slot_sliderRUD(int value);
    void slot_sliderPHI2AIL(int value);
    void slot_sliderTHETA2ELE(int value);
    void slot_sliderVX2ELE(int value);
    void slot_sliderVY2AIL(int value);
    
private:
    Ui::QSelfflyWidget *ui;
    
    QButtonGroup       *p_QButtongroup;   

    
    void initButtonGroup(); 
    void initSlider();
    void autoCmdEchoOk(quint8 x, quint8 *data);
};

#endif // SELFFLYWIDGET_H
