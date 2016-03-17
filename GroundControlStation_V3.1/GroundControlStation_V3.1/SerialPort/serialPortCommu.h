#ifndef SERIALPORTCOMMU_H
#define SERIALPORTCOMMU_H

#include <QWidget>
#include <QSerialPort>
#include <QBasicTimer>
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QProgressDialog>
#include "shared/buff.h"
#include "shared/checksum.h"
#include "Shared/dataStructureDefine.H"
#include "Shared/dataProtocol.h"

namespace Ui {
    class QSerialPortCommu;
}

class QSerialPortCommu : public QWidget
{
    Q_OBJECT

public:
    explicit QSerialPortCommu(QWidget *parent = 0);
    ~QSerialPortCommu();
    
    void setSerialPort(QSerialPort *comPort);
    void setSerialProtocol(QDataProtocol *comProtocol);
    void enableSimuCommu(bool flag);
    
    void record_open();
    void record_close();
    void savetofile(const quint8 &a);
    void playback_open();

signals:
    void signal_setPrintText(QString text,QColor color);
    void signal_setlight(int flag);
    void signal_setsendbutton(bool flag);
    
public slots: 
    void slot_protocol_send_packet   (quint8 sysid, quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);
    void slot_protocol_send_packetSim(quint8 sysid, quint8 compid, quint8 msgid, const quint8 *packet, quint8 length);    
    
    void slot_echoSendSuccess();
    
    void slot_playback();    
    void slot_setprogeess(int val);

protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    
private slots:
    void slot_protocol_receiveDataProcess();
    void slot_cmdEchoTimerMonitor();

private:
    QSerialPort    *serialPort;
    QDataProtocol  *dataProtocol;

    datalink_message_t    message_cur, rx_message_link, 
                       tx_message_cmd, tx_message_sim;
    datalink_status_t      status_cur, rx_msg_status_link;
    
    bool          isTxMsgCmd,
                  isTxMsgSim;  
    
    QTimer         *cmdTimer;         //定时器变量 
    QBasicTimer    dataTimer;
    int            tickTimer, numRepeatSend;                   
    
    void    protocol_send_packet  (datalink_message_t  tx_message, bool isEcho);               
    void    protocol_parse_state_initialize(datalink_status_t* initStatus);
    quint8  protocol_parse_char   (quint8 c, datalink_message_t* r_message, datalink_status_t* r_msg_status);
    quint8  protocol_parse_packet (datalink_message_t* r_message);

public:
    quint64  filepos,                 // 读取位置
             filelength;
    bool     playback,
             record;
    QFile    file;
    QTimer  *Play_Timer;
    float    speed;
};

#endif // SERIALPORTCOMMU_H
