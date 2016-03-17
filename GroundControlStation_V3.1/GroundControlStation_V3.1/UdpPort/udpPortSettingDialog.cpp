#include "udpPortSettingDialog.h"
#include "ui_udpPortSettingDialog.h"

QUdpPortSettingDialog::QUdpPortSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QUdpPortSettingDialog)
{
    ui->setupUi(this);

    fillPortsParameters();
    updateSettings();
    connect(ui->buttonBox, SIGNAL(accepted()),  this, SLOT(slot_applyOK()));
}

QUdpPortSettingDialog::~QUdpPortSettingDialog()
{
    delete ui;
}

QUdpPortSettingDialog::Settings QUdpPortSettingDialog::settings() const
{
    return currentSettings;
}

void QUdpPortSettingDialog::fillPortsParameters()
{
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("49000");
    ui->lineEdit_3->setText("127.0.0.1");
    ui->lineEdit_4->setText("49005");
}

void QUdpPortSettingDialog::updateSettings()
{
    currentSettings.hostIpAddress = QHostAddress(ui->lineEdit->text());
    currentSettings.hostPort = ui->lineEdit_2->text().toInt();
    currentSettings.userIpAddress = QHostAddress(ui->lineEdit_3->text());
    currentSettings.userPort = ui->lineEdit_4->text().toInt();
}

void QUdpPortSettingDialog::slot_applyOK()
{
    updateSettings();
    hide();
}

