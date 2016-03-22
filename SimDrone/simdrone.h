#ifndef SIMDRONE_H
#define SIMDRONE_H

#include <QWidget>
#include "dataStructureDefine.h"

class QTcpServer;
class QTcpSocket;
class QNetworkSession;

namespace Ui {
class simDrone;
}

class simDrone : public QWidget
{
    Q_OBJECT

public:
    explicit simDrone(QWidget *parent = 0);
    ~simDrone();

private slots:
    void sessionOpened();
    void updateClientDetail();
    void send_heartbeat_msg();
    void send_attitude_msg();

private:
    void getHeartBeatMessage();
    void getAttitudeMessage();
    heartbeat_Struc_t flightHBData;
    attitude_Struc_t flightAttiData;
    datalink_message_t flightDataParser;
    QTcpServer* tcpServer;
    QTcpSocket* clientConn;
    QNetworkSession* networkSession;
    Ui::simDrone *ui;
};

#endif // SIMDRONE_H
