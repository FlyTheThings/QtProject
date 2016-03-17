#ifndef UDPPORTSETTINGDIALOG_H
#define UDPPORTSETTINGDIALOG_H

#include <QDialog>
#include <QtNetwork/QUdpSocket>
#include <QHostAddress>

namespace Ui {
    class QUdpPortSettingDialog;
}

class QUdpPortSettingDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QHostAddress hostIpAddress,
                     userIpAddress;
        int          hostPort,
                     userPort;
    };

    explicit QUdpPortSettingDialog(QWidget *parent = 0);
    ~QUdpPortSettingDialog();

    Settings settings() const;

private slots:
    void slot_applyOK();

private:
    Ui::QUdpPortSettingDialog *ui;

    Settings  currentSettings;
    
    void fillPortsParameters();
    void updateSettings();
};

#endif // UDPPORTSETTINGDIALOG_H
