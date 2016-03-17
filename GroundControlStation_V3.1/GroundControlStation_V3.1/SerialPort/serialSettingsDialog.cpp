#include "serialsettingsdialog.h"
#include "ui_serialsettingsdialog.h"

QT_USE_NAMESPACE

QSerialSettingsDialog::QSerialSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QSerialSettingsDialog)
{
    ui->setupUi(this);

    fillPortsInfo();
    fillPortsParameters();
    updateSettings();
        
    connect(ui->serialPortInfoListBox, SIGNAL(currentIndexChanged(int)), this, SLOT(showPortInfo(int)));
    connect(ui->applyButton,           SIGNAL(clicked()),                this, SLOT(apply()));
}

QSerialSettingsDialog::~QSerialSettingsDialog()
{
    delete ui;
}

QSerialSettingsDialog::Settings QSerialSettingsDialog::settings() const
{
    return currentSettings;
}

void QSerialSettingsDialog::showEvent(QShowEvent * event)
{
    event=event;

    fillPortsInfo();
    fillPortsParameters();
    updateSettings();
}

void QSerialSettingsDialog::fillPortsInfo()
{
    ui->serialPortInfoListBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        list << info.portName()
             << info.description()
             << info.manufacturer()
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString())
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : QString());

        ui->serialPortInfoListBox->addItem(list.first(), list);
    }
}

void QSerialSettingsDialog::fillPortsParameters()
{
    // fill baud rate (is not the entire list of available values, desired values??, add your independently)
    ui->baudRateBox->clear();
    ui->baudRateBox->addItem(QLatin1String("9600"),   QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QLatin1String("19200"),  QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QLatin1String("38400"),  QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QLatin1String("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->addItem(QLatin1String("Custom"));

    // fill data bits
    ui->dataBitsBox->clear();
    ui->dataBitsBox->addItem(QLatin1String("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QLatin1String("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QLatin1String("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QLatin1String("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    // fill parity
    ui->parityBox->clear();
    ui->parityBox->addItem(QLatin1String("None"),  QSerialPort::NoParity);
    ui->parityBox->addItem(QLatin1String("Even"),  QSerialPort::EvenParity);
    ui->parityBox->addItem(QLatin1String("Odd"),   QSerialPort::OddParity);
    ui->parityBox->addItem(QLatin1String("Mark"),  QSerialPort::MarkParity);
    ui->parityBox->addItem(QLatin1String("Space"), QSerialPort::SpaceParity);

    // fill stop bits
    ui->stopBitsBox->clear();
    ui->stopBitsBox->addItem(QLatin1String("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(QLatin1String("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QLatin1String("2"), QSerialPort::TwoStop);

    // fill flow control
    ui->flowControlBox->clear();
    ui->flowControlBox->addItem(QLatin1String("None"), QSerialPort::NoFlowControl);
    ui->flowControlBox->addItem(QLatin1String("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlBox->addItem(QLatin1String("XON/XOFF"), QSerialPort::SoftwareControl);
}

void QSerialSettingsDialog::updateSettings()
{
    currentSettings.name = ui->serialPortInfoListBox->currentText();

    // Baud Rate
    if (ui->baudRateBox->currentIndex() == 4) {
        // custom baud rate
        currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
    } else {
        // standard baud rate
        currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                    ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
    }
    currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);

    // Data bits
    currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
    currentSettings.stringDataBits = ui->dataBitsBox->currentText();

    // Parity
    currentSettings.parity = static_cast<QSerialPort::Parity>(
                ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
    currentSettings.stringParity = ui->parityBox->currentText();

    // Stop bits
    currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
    currentSettings.stringStopBits = ui->stopBitsBox->currentText();

    // Flow control
    currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toInt());
    currentSettings.stringFlowControl = ui->flowControlBox->currentText();
}

void QSerialSettingsDialog::showPortInfo(int idx)
{
    if (idx != -1) {
        QStringList list = ui->serialPortInfoListBox->itemData(idx).toStringList();

        ui->descriptionLabel->setText(tr("Description: %1").arg(list.at(1)));
        ui->manufacturerLabel->setText(tr("Manufacturer: %1").arg(list.at(2)));
        ui->locationLabel->setText(tr("Location: %1").arg(list.at(3)));
        ui->vidLabel->setText(tr("Vendor Identifier: %1").arg(list.at(4)));
        ui->pidLabel->setText(tr("Product Identifier: %1").arg(list.at(5)));
    }
}

void QSerialSettingsDialog::apply()
{
    updateSettings();
    hide();
}
