#ifndef MULTICONTROL_H
#define MULTICONTROL_H

#include <QWidget>
#include<QButtonGroup>
#include "Shared/dataStructureDefine.H"
#include "Shared/messageIDDefine.h"
#include "Shared/buff.h"

namespace Ui {
class multicontrol;
}

class multicontrol : public QWidget
{
    Q_OBJECT

public:
    explicit multicontrol(QWidget *parent = 0);
    ~multicontrol();
    void echoMessagePacket(datalink_message_t *msg);
signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);

    void signal_cmdEleOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void signal_cmdAilOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void signal_cmdColOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void signal_cmdRudOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
private slots:
    void slot_cmdEleButtonClicked(int ButtonID);
    void slot_cmdAilButtonClicked(int ButtonID);
    void slot_cmdColButtonClicked(int ButtonID);
    void slot_cmdRudButtonClicked(int ButtonID);

    void selectcontrol(int index);
private:
    Ui::multicontrol *ui;

    QButtonGroup      *p_QButtongroupEle;
    QButtonGroup      *p_QButtongroupAil;
    QButtonGroup      *p_QButtongroupCol;
    QButtonGroup      *p_QButtongroupRud;

    void initButtonGroupEle(void);
    void initButtonGroupAil(void);
    void initButtonGroupCol(void);
    void initButtonGroupRud(void);
};

#endif // MULTICONTROL_H
