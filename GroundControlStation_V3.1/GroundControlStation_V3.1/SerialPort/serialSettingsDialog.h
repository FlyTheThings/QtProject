#ifndef SERIALSETTINGSDIALOG_H
#define SERIALSETTINGSDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
    class QSerialSettingsDialog;
}

QT_END_NAMESPACE

class QSerialSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    explicit QSerialSettingsDialog(QWidget *parent = 0);
    ~QSerialSettingsDialog();

    Settings settings() const;
    
private slots:
    void showPortInfo(int idx);
    void apply();

private:
    Ui::QSerialSettingsDialog *ui;

    Settings     currentSettings;
    void showEvent(QShowEvent * event);
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();
};

#endif // SERIALSETTINGSDIALOG_H
