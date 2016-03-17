#include "simdrone.h"
#include "ui_simdrone.h"
#include "messageIDDefine.h"

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QtNetwork>
#include <QMessageBox>
#include <stdlib.h>
#include <QTimer>
#include <QtNetwork/QTcpServer>

simDrone::simDrone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simDrone)
{
    ui->setupUi(this);

    QNetworkConfigurationManager manager;
    if(manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();

    } else {
        sessionOpened();
    }

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(updateClientDetail()));
    connect(ui->send_heartbeat, SIGNAL(clicked()), this, SLOT(send_heartbeat_msg()));

    // disable send_heartbeat button
    ui->send_heartbeat->setEnabled(false);

}

void simDrone::updateClientDetail() {

    clientConn = tcpServer->nextPendingConnection();
    ui->client_ip->setText(clientConn->peerAddress().toString());

    // able send_heartbeat button. To send heartbeat message.
    ui->send_heartbeat->setEnabled(true);

}

/*
 * send the heartbeat message to the app
 */
void simDrone::send_heartbeat_msg() {
    quint8 chk[2];
    quint16 checksum;
    quint8 payload[64];
    quint8 dataToSend[64];

    dataToSend[0] = DATALINK_STX1;
    dataToSend[1] = DATALINK_STX2;
    dataToSend[3] = 0x00;
    dataToSend[4] = UAV_SYS_ID;
    dataToSend[5] = UAV_COMP_ID_FCC;
    dataToSend[6] = UAV_MSG_FCC_HEARTBEAT;

    /*
    * get the uav flight heartbeat message.
    */
    getHeartBeatMessage();

    clientConn->write((const char*)dataToSend, 20);
}

void simDrone::getHeartBeatMessage() {
    flightHBData.uasInfo = ui->uav_type_num->text().toUShort();
    flightHBData.ctrlMode = ui->uav_contralmode->text().toUShort();
    flightHBData.uasState = ui->uav_state->text().toUShort();
    flightHBData.plMode = ui->uav_flymode->text().toUShort();

    flightHBData.alt = ui->uav_altitude->text().toFloat();
    flightHBData.lon = ui->uav_longitude->text().toDouble();
    flightHBData.lat = ui->uav_latitude->text().toDouble();

    flightHBData.vd = ui->uav_verticalspeed->text().toFloat();
    flightHBData.track = ui->uav_grouundspeed->text().toFloat();
    flightHBData.Hdot = ui->uav_line_angle->text().toFloat();
    flightHBData.psi = ui->uav_flight_angle->text().toFloat();

    flightHBData.cpuRatio = ui->uav_cpuratio->text().toFloat();
    flightHBData.voltCell = ui->uav_voltage->text().toFloat();
    flightHBData.oilEng = ui->uav_oil_meter->text().toFloat();
    flightHBData.flyTime = ui->uav_flight_time->text().toUInt();
}

void simDrone::sessionOpened() {

    // Save the used configuration
    if (networkSession) {
            QNetworkConfiguration config = networkSession->configuration();
            QString id;
            if (config.type() == QNetworkConfiguration::UserChoice)
                id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
            else
                id = config.identifier();

            QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
            settings.beginGroup(QLatin1String("QtNetwork"));
            settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
            settings.endGroup();
        }

        tcpServer = new QTcpServer(this);
        if(!tcpServer->listen()) {
            QMessageBox::critical(this, tr("AndServer"),
                                  tr("Unable to start the server: %1")
                                  .arg(tcpServer->errorString()));
            close();
            return ;
        }

        QString ipAddress;
        QString localHostName = QHostInfo::localHostName();
        qDebug() << "LocalHostName: " << localHostName;
        QHostInfo info = QHostInfo::fromName(localHostName);
        qDebug() << "IP Address: " << info.addresses();

        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
            // use the first non-localhost IPv4 address
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            /*
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                ipAddress = ipAddressesList.at(i).toString();
                qDebug() << ipAddress;
                break;
            }
            */
            ipAddress = ipAddressesList.at(i).toString();
            qDebug() << ipAddress;
        }

        if(ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

        ui->server_port->setText(tr("%1").arg(tcpServer->serverPort()));

}

simDrone::~simDrone()
{
    delete ui;
    delete clientConn;
    delete tcpServer;
}
