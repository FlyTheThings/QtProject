#include "panelFPDWidget.h"
#include "ui_panelFPDWidget.h"
#include "qdebug.h"
QPanelFPDWidget::QPanelFPDWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QPanelFPDWidget)
{
    ui->setupUi(this);
    
    m_pPFD = new qfi_PFD(ui->graphicsView);
    m_pPFD->setFixedSize(300,300);
    m_pPFD->setEnabled(false);
    m_pPFD->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pPFD->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pPFD->setIlsGs(1);
    m_pPFD->setIlsLc(1);

    m_pPFD->update();
}

QPanelFPDWidget::~QPanelFPDWidget()
{
    delete ui;    
    if (m_pPFD)  delete m_pPFD;    
}

void QPanelFPDWidget::SetAllData(float pitch, float roll, float psi, float alt, float Vd, float R, float Hdot)
{
    m_pPFD->setPitch(pitch);
    m_pPFD->setRoll(roll);
    m_pPFD->setHeading(psi);
    m_pPFD->setAltitude(alt);
    m_pPFD->setAirspeed(Vd);
    m_pPFD->setTurnRate(R);
    m_pPFD->setClimbRate(Hdot);
    
    m_pPFD->update();
}

void QPanelFPDWidget::SetPitch(float x)
{
    m_pPFD->setPitch(x);
    m_pPFD->update();
}

void QPanelFPDWidget::SetRoll(float x)
{
    m_pPFD->setRoll(x);
    m_pPFD->update();
}

void QPanelFPDWidget::SetHeading(float x)
{
    m_pPFD->setHeading(x);
    m_pPFD->update();
}

void QPanelFPDWidget::SetAltitude(float x)
{
    m_pPFD->setAltitude(x);
    m_pPFD->update();
}

void QPanelFPDWidget::SetAirspeed(float x)
{
    m_pPFD->setAirspeed(x);
    m_pPFD->update();
}

void QPanelFPDWidget::SetTurnRate(float x)
{
    m_pPFD->setTurnRate(x);
    m_pPFD->update();
}

void QPanelFPDWidget::SetClimbRate(float x)
{
    m_pPFD->setClimbRate(x);
    m_pPFD->update();
}
