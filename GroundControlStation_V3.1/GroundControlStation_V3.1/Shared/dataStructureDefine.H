#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#include "Shared/messageIDDefine.h"

/* --[Protocol data structure define]-- */   
typedef struct __datalink_message {
    quint8  magic1,                              ///< protocol magic marker1
            magic2;                              ///< protocol magic marker2
    quint8  len;                                 ///< Length of payload
    quint8  seq;                                 ///< Sequence of packet
    quint8  sysid;                               ///< ID of message sender system/aircraft
    quint8  compid;                              ///< ID of the message sender component
    quint8  msgid;                               ///< ID of message in payload
    quint8  payload[DATALINK_MAX_PAYLOAD_LEN];
    quint8  ck_a,                                ///< sent at end of packet
            ck_b;
} datalink_message_t;

typedef enum {
    DATALINK_PARSE_STATE_UNINIT=0,
    DATALINK_PARSE_STATE_IDLE,
    DATALINK_PARSE_STATE_GOT_STX1,
    DATALINK_PARSE_STATE_GOT_STX2,
    DATALINK_PARSE_STATE_GOT_LENGTH,
    DATALINK_PARSE_STATE_GOT_SEQ,
    DATALINK_PARSE_STATE_GOT_SYSID,
    DATALINK_PARSE_STATE_GOT_COMPID,
    DATALINK_PARSE_STATE_GOT_MSGID,
    DATALINK_PARSE_STATE_GOT_PAYLOAD,
    DATALINK_PARSE_STATE_GOT_CRC1
} datalink_parse_state_t;                    ///< The state machine for the comm parser

typedef struct __mavlink_status {
    quint8  msg_received;                    ///< flag of received messages
    quint8  parse_error;                     ///< Number of parse errors
    quint8  packet_idx;                      ///< Index in current packet
    quint8  current_rx_seq;                  ///< Sequence number of last packet received
    quint8  current_tx_seq;                  ///< Sequence number of last packet sent
    quint16 packet_rx_success_count;         ///< Received packets
    quint16 packet_rx_drop_count;            ///< Number of packet drops
    datalink_parse_state_t parse_state;      ///< Parsing state machine
} datalink_status_t;


typedef enum {
    RUN_MODE_STATE_NAN=0,                //NAN     
    RUN_MODE_STATE_DIR,                  //裸飞模式
    RUN_MODE_STATE_ACS,                  //增稳模式
    RUN_MODE_STATE_MIX,                  //半自动模
    RUN_MODE_STATE_AUTO,                 //全自动模
    RUN_MODE_STATE_TEST,                 //测试模式
    RUN_MODE_STATE_SIMU                  //仿真模式
} sysMode_state_t;  

typedef struct __sysEnable {
    quint8          run_mode;           //系统运行模式
    quint8          data_ask_enable;    //数据查询使能
    quint8          data_set_enable;    //数据设置使能
    quint8          data_save_enable;   //数据保存使能
    quint8          data_del_enable;    //数据删除使能
    quint8          data_file_enable;   //文件处理使能
	quint8          fly_cmd_enable;     //飞行指令使能
	quint8          uas_actived_enable; //飞行指令使能
} sysEnable_Struc_t;

typedef struct __dateYMD {               
    quint8     year;                      //年
	quint8     month;                     //月
	quint8     day;                       //日
} timeYMD_struc_t;                       
typedef struct __datetime {              
    quint16    year;                      //年
	quint8     month;                     //月
	quint8     day;                       //日
	quint8     hour;                      //时
	quint8     minute;                    //分
	quint8     second;                    //秒	
} time_struc_t;

typedef struct __sysInfo {
	quint8            sys_ID;            //系统编号
	quint8            uav_ID;            //飞机编号
	quint8            fcc_ID;            //飞控编号
	quint8            fcc_TY;            //飞控类型
	quint8            soft_ID;           //软件版本                         
	quint8            user_ID;           //用户编号
	timeYMD_struc_t   Manu_date;         //交付时间
	timeYMD_struc_t  Valid_date;         //有效期  
} sysInfo_Struc_t;

typedef struct __heliInfo {
	quint8     type;                    //飞机类型           
	quint16    weight;                  //飞机重量[g]（空重）   
	quint8     CG[3];                   //飞机重心[X Y Z]    
	quint8     haveFlybar;              //副翼配置类型(有1/无0副翼)           
	quint8     engine_type;             //发动机配置类型                             
	quint8     palyload_type;           //任务设备类型       
	quint16    palyload_weight;         //任务设备重量[g]（Max）   
    quint8     RC_type;                 //接收机类型   
} heliInfo_Struc_t;

typedef struct __WayPoint {                       
    quint8     num;                     /*[航线号]*/
    quint8     dot;                     /*[航点号]*/
    double     lon,                     /*[航点经度][deg]*/
               lat;                     /*[航点纬度][deg]*/
    float      alt;                     /*[高度][m]*/
	quint8     vxd[4];                  /*[任务特征]*/
} WayPoint_Struc_t; 

typedef struct __AirPort {
    float      lon,
               lat,
               alt,                     /*[海拔高度]*/
               height,                  /*[气压高度]*/
               psi;                     /*[地理航向]*/
} AirPort_Struc_t; 

typedef struct __PID{
    float       Kp,
                Ki,
                Kd;
} pid_Struct_t;

typedef struct __NonFB_Ctrl{
	float       Kp,                      /*[无副翼角速率项控制参数]*/
	            Ki,                      /*[无副翼姿态项控制参数]*/
	            T,                       /*[无副翼角速率低通时间常数]*/
	            gain;                    /*[无副翼角速率低通增益常数]*/
} NonFB_Ctrl_Struct_t;

typedef struct __Analog{
        float     ratio,                 /*[比例因子]*/
                 offset;                 /*[偏移量]  */
        float       vol,                 /*[电压](V) */
                    val;                 /*[物理量]  */
} Analog_Struc_t;   

typedef struct  __imu {
    float         theta,
                    phi,
                    psi;
    float             P,
                      Q,
                      R;
    float            Axb, Axg,
                     Ayb, Ayg,
                     Azb, Azg;
	
    float        Weight,
                std_bet,
                   temp;
                   
    float     theta_avg,
	            phi_avg;
	          
    quint16        info;
    quint8          dir;
    qint16       pos[3];
    quint8         freq;
} imu_Struc_t;

typedef struct __gps{        						
    double           lon,            /*[经度]    [deg]*/
                     lat;            /*[纬度]    [deg]*/
    float            alt,            /*[高度]    [m  ]*/   
                    Hdot,            /*[升降速度][m/s]*/
                      Vd,            /*[地速]    [m/s]*/
                   track;            /*[航迹角]  [deg]*/
    quint16     POSState;		 	 /*[GPS定位状态]*/
    float        sol_age; 
    float         lon_SD,
		          lat_SD,
				  alt_SD;                              
    quint8          used;		     /*[用于gps解算的卫星颗数]*/          
    time_struc_t    time;

    qint16          ANTX,
                    ANTY,
                    ANTZ;	
    quint8          freq;
} gps_Struc_t;

typedef struct __hmc{
    qint16        MagX,
                  MagY,
                  MagZ;                     
    float          psi,
            psi_offset;
    
    quint8       state;
    float           Kx,
                    Ky,
                    Bx,
                    By;
    quint8         dir;
	quint8        freq;
} hmc_Struc_t;

typedef struct _AUTO_Ctrl{
	quint16     Sen_eleInner, Sen_eleOuter,		      /* 内环灵敏度 / 外环灵敏度[0%-100%] */
		        Sen_ailInner, Sen_ailOuter,
		        Sen_rud,
		        Sen_col,  
		        Sen_eleFlybar,
		        Sen_ailFlybar;
	float       Opt_VxMax,   Opt_VxMin,               /*[操纵杆量对应的速度指令范围]*/
		        Opt_VyMax,   Opt_VyMin,
		        Opt_HdotMax, Opt_HdotMin,
		        Opt_RrMax,   Opt_RrMin;
} AUTO_Ctrl_Struct_t;

typedef struct __swashplate{
	quint8      SwashType;                            /*[十字盘类型]*/
	float       phaseAngle;                           /*[十字盘相位]*/
	qint8       eleDir,  ailDir,  colDir;             /*[十字盘变距极性][-1/+1]*/         
	quint8      eleMix,  ailMix,  colMix;             /*[十字盘变距混控比][0~100%]*/     
    qint8       S1Dir,   S2Dir,   S3Dir,   S4Dir;     /*[十字盘对应舵机的方向][-1/+1]*/
	qint16      S1Offset,S2Offset,S3Offset,S4Offset;  /*[十字盘对应舵机的微调]*/ 
} swashplate_Struc_t;

typedef struct __RUDSERVO{
    quint8      servoType,                             /*[锁尾电机类型]*/
   		        gyroType;                              /*[锁尾控制陀螺类型]*/
    qint16      rudMix;
    qint16      rudMax, rudMin;                        /*[尾桨舵面的范围]*/
	qint16      rudOffset;                             /*[尾桨舵面的微调]*/
	qint8       rudDir;                                /*[尾桨舵面的极性]*/
} rudservo_struc_t;

typedef struct __ENG{
	quint8      ctrlMode;                              /*[发动机定速控制模式][内部定速/外部定速]*/
	quint16     Sen_rpmCtrl;                           /*[发动机控制的灵敏度]*/
	qint8       engDir;                                /*[发动机油门的极性]*/
	qint16      engOffset;                             /*[发动机舵面的微调]*/
	qint16      engMix;
	qint16      engMax, engMin;                        /*[发动机油门的行程范围]*/ 
    qint16    	ENG_STOP,                              /*[发动机停车的油门位置]*/
			    ENG_IDLE,                              /*[发动机怠速的油门位置]*/
			    ENG_NORMAL,                            /*[发动机额定工作的油门位置]*/
			    ENG_HIGH;                              /*[发动机高速运行的油门位置]*/
	quint16		RPM_ROTOR;                             /*[旋翼理论转速]*/
	float       RPM_ENG,                               /*[发动机理论转速][此项是通过旋翼转速和减速比计算得出]!*/
			    GearRatio;                             /*[发动机和旋翼之间的齿轮减速比]*/
} eng_struc_t;

typedef struct __PWM{                                  //舵机控制和RC通道捕获信号均为PWM类型
    qint8       sign;                                  /*[极性]*/
    float       min;                                   /*[最小允许值]*/
    float       max;                                   /*[最大允许值]*/
    float       center;                                /*[中立位置]*/
    qint16      offset;                                /*[偏移量(微调)]*/
    quint16     out;                                   /*[PWM输出]*/
    qint16      cali;                                  /*[捕获PWM信号校准]*/
    quint16     raw;                                   /*[捕获原始数据值]*/
    float       val;                                   /*[捕获整定后值]*/
} pwm_Struc_t;

typedef struct __SPD{
	quint8      mode;
	float       vd,
		        width,
		        VolPerMu;
	float       Velmin,
		        Ki,
		        Kp;
} spd_struc_t;


typedef struct __heartbeat {
    quint8     uasInfo,  uasState;
	quint8     ctrlMode, plMode, vtMode, guidMode;
    double     lon, lat;
    float      vd, alt, Hdot, psi, track;
	quint16    flyTime;
    quint8     gpsState;
    float      oilEng, voltCell, cpuRatio,tempEng;
} heartbeat_Struc_t;


typedef struct __lineWP{             
    double     lon,                    /*[航段起点/圆心经纬度][deg]*/
               lat;                    
    float      psi;                    /*[航段方位角/圆心角][deg]*/
    float      alt;                    /*[航段高度][m]*/
    float      len;                    /*[航段长度][m]*/
    float      rad;                    /*[航段半径][m][直线段:0;左转-R;右转+R]*/
    quint8     vxd[4];                 /*[任务特征]*/
} wpline_struc_t;                           
                                       
typedef struct __pointWP{                       
    int        num;                    /*[航线号]*/
    int        dot;                    /*[航点号]*/
    double     lon,                    /*[航点经度][deg]*/
               lat;                    /*[航点纬度][deg]*/
    float      alt;                    /*[高度][m]*/
	quint8     vxd[4];                 /*[任务特征]*/
} waypoint_struc_t; 
                                           
#endif   //  END  DATASTRUCTURE_H
