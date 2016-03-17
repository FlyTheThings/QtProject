#include "waypointCmdDialog.h"
#include "ui_waypointCmdDialog.h"

QWaypointCmdDialog::QWaypointCmdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWaypointCmdDialog)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    this->setModal(0);

    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(slot_clickedSendCmd()));
}

QWaypointCmdDialog::~QWaypointCmdDialog()
{
    delete ui;
}

void QWaypointCmdDialog::slot_clickedSendCmd()
{
    quint8  cmdData[1];

    cmdData[0] = (quint8) ui->spinBox->value();    
    emit  signal_sendWaypointCmd(23, cmdData, 1);
}
