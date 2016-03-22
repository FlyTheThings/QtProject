#ifndef QUDPCOMMU_H
#define QUDPCOMMU_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include "UdpPort/udpPortSettingDialog.h"
#include "Shared/dataProtocol.h"
#include "Shared/buff.h"
#include "flightgearCom.h"

class QUdpCommu : public QObject
{
    Q_OBJECT
public:
    explicit QUdpCommu(QObject *parent = 0);
    ~QUdpCommu();
    
    bool setUdpPort(QUdpPortSettingDialog::Settings p);
    void closeUdpPort();
    void setUdpProtocol(QDataProtocol *protocol);

signals:
    void signal_cmdOutput(quint8 sysid,quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void signal_sim(float *addr, quint8 length);
    void siganl_udp2xplane();

public slots:
    void slot_fccData2UdpSend(quint8 *data, quint8 len);
    
private slots:
    void slot_udpReceivePacket();
    void slot_udpsend2xplane();
    
private:
    QUdpSocket      *p_udpSocketTx,
                    *p_udpSocketRx;       //ÍøÂç±äÁ¿
        
    QHostAddress     hostIpAddress, userIpAddress;
    int              hostPort, userPort;
    
    QDataProtocol   *dataProtocol;
    float            dataXplane[15];
    float            fcc2xplane_law[4];

    FGNetData       *fgDataCom;

    void getXPlaneData(char *buf,int len);
    void sendSimDataToFCC();
};

#endif // QUDPCOMMU_H
