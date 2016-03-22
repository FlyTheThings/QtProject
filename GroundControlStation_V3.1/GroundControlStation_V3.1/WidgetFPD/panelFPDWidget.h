#ifndef _QPFD_H
#define _QPFD_H

#include <QWidget>
#include "qfi_PFD.h"

namespace Ui {
    class QPanelFPDWidget;
}

class QPanelFPDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QPanelFPDWidget(QWidget *parent = 0);
    ~QPanelFPDWidget();
    
    void  SetAllData(float pitch, float roll, float psi, float alt, float Vd, float R, float Az);

private:   
    Ui::QPanelFPDWidget *ui;
        
    qfi_PFD  *m_pPFD;    
    
    void  SetPitch(float x);
    void  SetRoll (float x);
    void  SetHeading(float x);
    void  SetAltitude(float x);
    void  SetAirspeed(float x);
    void  SetTurnRate(float x);
    void  SetClimbRate(float x);    
};

#endif // QPFD_H
