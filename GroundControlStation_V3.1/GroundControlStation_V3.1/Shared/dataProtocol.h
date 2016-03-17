#ifndef QDATAPROTOCOL_H
#define QDATAPROTOCOL_H

#include <QObject>
#include <QMessageBox>
#include <QMap>
#include "Shared/messageIDDefine.h"
#include "Shared/dataStructureDefine.H"
#include "Shared/buff.h"

class QDataProtocol : public QObject
{
    Q_OBJECT
    
public:
    explicit QDataProtocol(QObject *parent = 0);
    ~QDataProtocol();
                                               //receive message
    quint8  msg_compID_sysEnable  (datalink_message_t* r_message);
    quint8  msg_compID_sysInfo    (datalink_message_t* r_message);
    quint8  msg_compID_heliCFG    (datalink_message_t* r_message);

    quint8  msg_compID_wayPoint   (datalink_message_t* r_message);
    quint8  msg_compID_ctrlChannel(datalink_message_t* r_message);
    quint8  msg_compID_cmdFly     (datalink_message_t* r_message);
    quint8  msg_compID_cmdMission (datalink_message_t* r_message);
    quint8  msg_compID_cmdTest    (datalink_message_t* r_message);
    quint8  msg_compID_fileTrans  (datalink_message_t* r_message);

    quint8  msg_compID_FCC        (datalink_message_t* r_message);
    quint8  msg_compID_sensorIMU  (datalink_message_t* r_message);
    quint8  msg_compID_sensorGPS  (datalink_message_t* r_message);
    quint8  msg_compID_sensorHMR  (datalink_message_t* r_message);
    quint8  msg_compID_ACS        (datalink_message_t* r_message);
    quint8  msg_compID_RC         (datalink_message_t* r_message);

    quint8  msg_compID_auxRecoder (datalink_message_t* r_message);
    quint8  msg_compID_auxPower   (datalink_message_t* r_message);
    quint8  msg_compID_auxEngine  (datalink_message_t* r_message);
    quint8  msg_compID_auxSpray   (datalink_message_t* r_message);
    quint8  msg_compID_auxCamera  (datalink_message_t* r_message);

    quint8  msg_compID_simMode    (datalink_message_t* r_message);
    quint8  msg_compID_simScene   (datalink_message_t* r_message);

    quint8  msg_compID_IAP        (datalink_message_t* r_message);
    
    void setCurrentSendMsg(datalink_message_t  message);   

signals:                                                      //send code&data
    void signal_echoSuccess();
    
    void signal_echoMessagePacket(datalink_message_t *message, bool cfgType);
    void signal_enableCmdEchoOK(quint8 idx);
    void signal_waypointCmdEchoOK(quint8 idx, WayPoint_Struc_t dataWP);        
    void signal_IAPCmdEchoOk(quint8 x, quint8 *data, quint8 len); 
    void signal_CmdMissionEchoOK(datalink_message_t *message);
    
    void signal_simFCC2Model(quint8 *data, quint8 len);
    void signal_setacseqid(quint8 seqid);

private:
    datalink_message_t   curSendMsg;              //可以更简洁些,只判断指令编码是否正确!
 
    sysEnable_Struc_t    status_SysEnable;
    sysInfo_Struc_t      status_SysInfo;
    heliInfo_Struc_t     status_HeliInfo;      

    WayPoint_Struc_t     data_Waypoint;    
    AirPort_Struc_t      data_Airport;
    Analog_Struc_t       data_AD[4], data_DA[4];       
    time_struc_t         data_RTC;   

public:
    //QMap<int,imu_Struc_t> data_imu;
    QMap<int,int>        Id2num;//<id号，序号>
    int                  Idcount;
    quint8               ac_seqid;//当前激活sysid的序列号
    heartbeat_Struc_t    data_heartbeat[5];
    imu_Struc_t          data_imu;
    gps_Struc_t          data_gps;
    hmc_Struc_t          data_hmc;
    quint16              data_rpm;
    quint8               data_wp, data_dot;
    float                ele_law, ail_law, rud_law, col_law, eng_law;
    float                ele_RC,  ail_RC,  rud_RC,  col_RC,  eng_RC;
    bool                 cfgType;

    float                Hdot_opt, Hdot_var, height_var,
                         R_opt,    R_var,    psi_var,
                         Vx_opt,   Vx_var,   ac_dX,
                         Vy_opt,   Vy_var,   ac_dY,
                         dX_mix,   dY_mix,
                         OSCPUUsage;
};

#endif // QDATAPROTOCOL_H
