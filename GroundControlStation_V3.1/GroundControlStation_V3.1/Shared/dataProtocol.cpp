#include "dataProtocol.h"
#include <QDebug>

QDataProtocol::QDataProtocol(QObject *parent) : QObject(parent)
{
    Idcount=0;
    Id2num.clear();
    memset(&curSendMsg, 0, sizeof(curSendMsg));
}

QDataProtocol::~QDataProtocol()
{
    ;
}

void  QDataProtocol::setCurrentSendMsg(datalink_message_t  tx_message)
{
    curSendMsg = tx_message;
}    

quint8  QDataProtocol::msg_compID_sysEnable(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                isOK=true;       
                
	            switch (echoMsg) {
	                case UAV_MSG_REQU_STATUS:  break;
	                case UAV_MSG_SET_SYSMODE:
	                case UAV_MSG_ASK_SYSMODE:  
	                    switch (r_message->payload[1]) { 
	                        case 0x01: emit signal_enableCmdEchoOK(1); break;  //飞行模式
	                        case 0x02: emit signal_enableCmdEchoOK(2); break;  //测试模式
	                        case 0x03: emit signal_enableCmdEchoOK(3); break;  //仿真模式
	                    }
	                    break;
	                case UAV_MSG_SET_PARAM:
	                case UAV_MSG_ASK_PARAM:    
	                    switch (r_message->payload[1]) {
	                        case 0x01: emit signal_enableCmdEchoOK(4); break;  //查询使能开
	                        case 0x02: emit signal_enableCmdEchoOK(5); break;  //查询使能关
	                        case 0x03: emit signal_enableCmdEchoOK(6); break;  //设置使能开
	                        case 0x04: emit signal_enableCmdEchoOK(7); break;  //设置使能关
	                        case 0x05: emit signal_enableCmdEchoOK(8); break;  //保存所有数据
	                        case 0x06: emit signal_enableCmdEchoOK(9); break;  //删除所有数据
	                    }    		
	                    break;
	                case UAV_MSG_SET_FILE:
	                case UAV_MSG_ASK_FILE:     
	                    if (r_message->payload[1]==0xAA)     status_SysEnable.data_file_enable = true;  
	                    else { 
	                        if (r_message->payload[1]==0x55) status_SysEnable.data_file_enable = false;   
	                    }                  
	                    break;  
	                case UAV_MSG_SET_FLYCMD: 
	                case UAV_MSG_ASK_FLYCMD:   
	                    if (r_message->payload[1]==0xAA)     status_SysEnable.fly_cmd_enable = true;  
	                    else { 
	                        if (r_message->payload[1]==0x55) status_SysEnable.fly_cmd_enable = false;   
	                    }     	                    
	                    break;  
	                case UAV_MSG_SET_ACTIVED: 
	                case UAV_MSG_ASK_ACTIVED:  
	                    if (r_message->payload[1]==0xAA)     status_SysEnable.uas_actived_enable = true;  
	                    else { 
	                        if (r_message->payload[1]==0x55) status_SysEnable.uas_actived_enable = false;   
	                    }     	                    
	                    break; 
	                case UAV_MSG_SET_UPDATE:  
	                case UAV_MSG_UPDATE_FCS:   break;   //??待定!
	            }   
	        }       
	        else  isOK=false; 
	        break;
        default:  isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_sysInfo(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                isOK=true;       

	            switch (echoMsg) {
	                case UAV_MSG_REQU_READ:   
	                case UAV_MSG_REQU_SEND: 
	                    status_SysInfo.sys_ID          = frame_return_uint8_t(r_message->payload, 1);
	                    status_SysInfo.uav_ID          = frame_return_uint8_t(r_message->payload, 2);
	                    status_SysInfo.fcc_ID          = frame_return_uint8_t(r_message->payload, 3);
	                    status_SysInfo.soft_ID         = frame_return_uint8_t(r_message->payload, 4);
	                    status_SysInfo.user_ID         = frame_return_uint8_t(r_message->payload, 5); 
	                    status_SysInfo.Manu_date.year  = frame_return_uint8_t(r_message->payload, 6);
	                    status_SysInfo.Manu_date.month = frame_return_uint8_t(r_message->payload, 7);
	                    status_SysInfo.Manu_date.day   = frame_return_uint8_t(r_message->payload, 8);
	                    status_SysInfo.Valid_date.year = frame_return_uint8_t(r_message->payload, 9);
	                    status_SysInfo.Valid_date.month= frame_return_uint8_t(r_message->payload,10);
	                    status_SysInfo.Valid_date.day  = frame_return_uint8_t(r_message->payload,11);	                   
	                    break;	                
	                case UAV_MSG_REQU_SAVE:       break;
	                case UAV_MSG_REQU_DEL:        break;	                    
	                case UAV_MSG_INFO_SYSNUM:     
	                    status_SysInfo.sys_ID          = frame_return_uint8_t(r_message->payload, 1);
	                    break;
	                case UAV_MSG_INFO_UAVNUM:     
	                    status_SysInfo.uav_ID          = frame_return_uint8_t(r_message->payload, 1);
	                    break;
	                case UAV_MSG_INFO_FCCNUM:     
	                    status_SysInfo.fcc_ID          = frame_return_uint8_t(r_message->payload, 1);
	                    break;
	                case UAV_MSG_INFO_SOFTVER:    
	                    status_SysInfo.soft_ID         = frame_return_uint8_t(r_message->payload, 1);
	                    break;
	                case UAV_MSG_INFO_USERNUM:    
	                    status_SysInfo.user_ID         = frame_return_uint8_t(r_message->payload, 1); 
	                    break;
	                case UAV_MSG_INFO_STARTTIME:  
	                    status_SysInfo.Manu_date.year  = frame_return_uint8_t(r_message->payload, 1);
	                    status_SysInfo.Manu_date.month = frame_return_uint8_t(r_message->payload, 2);
	                    status_SysInfo.Manu_date.day   = frame_return_uint8_t(r_message->payload, 3);
	                    break;
	                case UAV_MSG_INFO_ENDTIME:    
	                    status_SysInfo.Valid_date.year = frame_return_uint8_t(r_message->payload, 1);
	                    status_SysInfo.Valid_date.month= frame_return_uint8_t(r_message->payload, 2);
	                    status_SysInfo.Valid_date.day  = frame_return_uint8_t(r_message->payload, 3);
	                    break;  
	                default:                      break;    
	            }
	        }  
	        else  isOK=false;
	        break;
        default:  isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_heliCFG(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
//    switch (r_message->msgid) {
//	    case UAV_MSG_REQU_ECHO:
//	        echoMsg = r_message->payload[0];
//	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
//	            emit signal_echoSuccess();
//                isOK=true;

//	            switch (echoMsg) {
//	                case UAV_MSG_REQU_READ:
//	                case UAV_MSG_REQU_SEND:
//	                    status_HeliInfo.type           = frame_return_uint8_t(r_message->payload, 1);
//	                    status_HeliInfo.weight         = frame_return_uint16_t(r_message->payload,2);
//                        status_HeliInfo.CG[0]          = frame_return_uint8_t(r_message->payload, 4);
//                        status_HeliInfo.CG[1]          = frame_return_uint8_t(r_message->payload, 5);
//                        status_HeliInfo.CG[2]          = frame_return_uint8_t(r_message->payload, 6);
//                        status_HeliInfo.engine_type    = frame_return_uint8_t(r_message->payload, 7);
//                        status_HeliInfo.palyload_type  = frame_return_uint8_t(r_message->payload, 8);
//                        status_HeliInfo.palyload_weight= frame_return_uint16_t(r_message->payload,9);
//                        status_HeliInfo.haveFlybar     = frame_return_uint8_t(r_message->payload, 11);
//                        status_HeliInfo.RC_type        = frame_return_uint8_t(r_message->payload, 12);
//	                    break;
//	                case UAV_MSG_REQU_SAVE:       break;
//	                case UAV_MSG_REQU_DEL:        break;
//	                case UAV_MSG_PLANE_TYPE:
//	                    status_HeliInfo.type           = frame_return_uint8_t(r_message->payload, 1);
//	                    break;
//	                case UAV_MSG_PLANE_WEIGHT:
//	                    status_HeliInfo.weight         = frame_return_uint16_t(r_message->payload,1);
//	                    break;
//	                case UAV_MSG_PLANE_CG:
//	                    status_HeliInfo.CG[0]          = frame_return_uint8_t(r_message->payload, 1);
//                        status_HeliInfo.CG[1]          = frame_return_uint8_t(r_message->payload, 2);
//                        status_HeliInfo.CG[2]          = frame_return_uint8_t(r_message->payload, 3);
//	                    break;
//	                case UAV_MSG_PLANE_ENGINE:
//	                    status_HeliInfo.engine_type    = frame_return_uint8_t(r_message->payload, 1);
//	                    break;
//	                case UAV_MSG_PLANE_PAYLOAD:
//	                    status_HeliInfo.palyload_type  = frame_return_uint8_t(r_message->payload, 1);
//	                    break;
//	                case UAV_MSG_PLANE_PLOADWT:
//	                    status_HeliInfo.palyload_weight= frame_return_uint16_t(r_message->payload,1);
//	                    break;
//	                case UAV_MSG_PLANE_FLAPTYPE:
//	                    status_HeliInfo.haveFlybar     = frame_return_uint8_t(r_message->payload, 1);
//	                    break;
//	                case UAV_MSG_PLANE_RUDTYPE:
//                        status_HeliInfo.RC_type        = frame_return_uint8_t(r_message->payload, 1);
//	                    break;
//	                default:                      break;
//	            }
//	        }
//	        else  isOK=false;
//	        break;
//        default:  isOK=false;break;
//	}
        
    switch (r_message->msgid) {
        case UAV_MSG_REQU_ECHO:
            echoMsg = r_message->payload[0];
            if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
                emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;
            }
            else  isOK=false;
            break;
        default:  isOK=false;break;
    }

    return (isOK);
}

quint8  QDataProtocol::msg_compID_wayPoint(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                isOK=true;       

	            switch (echoMsg) {
	                case UAV_MSG_WP_SET:  
	                    data_Waypoint.num    = frame_return_uint8_t(r_message->payload,1);  
	                    data_Waypoint.dot    = frame_return_uint8_t(r_message->payload,2);
                        data_Waypoint.lon    = frame_return_double(r_message->payload,3);
                        data_Waypoint.lat    = frame_return_double(r_message->payload,11);
                        data_Waypoint.alt    = frame_return_float(r_message->payload,19);
                        data_Waypoint.vxd[0] = frame_return_uint8_t(r_message->payload,23);
                        data_Waypoint.vxd[1] = frame_return_uint8_t(r_message->payload,24);
                        data_Waypoint.vxd[2] = frame_return_uint8_t(r_message->payload,25);
                        data_Waypoint.vxd[3] = frame_return_uint8_t(r_message->payload,26);
	                    emit signal_waypointCmdEchoOK(1, data_Waypoint);
	                    break;
	                case UAV_MSG_WP_ASK:          
	                    data_Waypoint.num    = frame_return_uint8_t(r_message->payload,1);  
	                    data_Waypoint.dot    = frame_return_uint8_t(r_message->payload,2);
                        data_Waypoint.lon    = frame_return_double(r_message->payload,3);
                        data_Waypoint.lat    = frame_return_double(r_message->payload,11);
                        data_Waypoint.alt    = frame_return_float(r_message->payload,19);
                        data_Waypoint.vxd[0] = frame_return_uint8_t(r_message->payload,23);
                        data_Waypoint.vxd[1] = frame_return_uint8_t(r_message->payload,24);
                        data_Waypoint.vxd[2] = frame_return_uint8_t(r_message->payload,25);
                        data_Waypoint.vxd[3] = frame_return_uint8_t(r_message->payload,26);
                        emit signal_waypointCmdEchoOK(2, data_Waypoint);
	                    break;
	                case UAV_MSG_WP_SAVE:         break;
	                case UAV_MSG_WP_DEL:
	                    data_Waypoint.num    = 0;  
	                    data_Waypoint.dot    = 0;
                        emit signal_waypointCmdEchoOK(3, data_Waypoint);
	                    break;
	                case UAV_MSG_WP_AIRPORTSET:
	                case UAV_MSG_WP_AIRPORTASK:   
	                    data_Airport.lon    = frame_return_float(r_message->payload,1);  
                        data_Airport.lat    = frame_return_float(r_message->payload,5);  
                        data_Airport.alt    = frame_return_float(r_message->payload,9); 
                        data_Airport.height = frame_return_float(r_message->payload,13);  
                        data_Airport.psi    = frame_return_float(r_message->payload,17); 
	                    break;             
	                default:                      break;    
	            }  
	        }
	        else  isOK=false;  
	        break;
        default:  isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_ctrlChannel(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;
	        }
	        else  isOK=false;   
	        break;
        default:  isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_cmdFly(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	         echoMsg = r_message->payload[0];
	         if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
                 qDebug()<<"fdfdfd"<<echoMsg<<"  "<<r_message->payload[1];
                 if((echoMsg==0x1F)&&(r_message->payload[1]==1))//如果是激活指令，则置换新的新的激活序列号
                 {
                     ac_seqid=Id2num[r_message->sysid];
                     emit signal_setacseqid(ac_seqid);
                 }
	             emit signal_echoSuccess();
                 isOK=true;              
	         }
	         else  isOK=false; 
	         break;
        default:  isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_cmdMission(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	         echoMsg = r_message->payload[0];
	         if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致

	             emit signal_echoSuccess();
                 //emit signal_CmdMissionEchoOK(r_message);
                 isOK=true;                
	         }
	         else  isOK=false; 
	         break;
        default:   isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_cmdTest(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
     
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	         echoMsg = r_message->payload[0];
	         if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	             emit signal_echoSuccess();
                 isOK=true;                
	         }
	         else  isOK=false; 
	         break;
        default:   isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_fileTrans(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	         echoMsg = r_message->payload[0];
	         if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	             emit signal_echoSuccess();
                 isOK=true;  
                 
	             switch (echoMsg) {
	                 case UAV_MSG_FILE_SAVE:  break;  
	                 case UAV_MSG_FILE_DEL:   break;
	                 case UAV_MSG_FILE_START: break;
	                 case UAV_MSG_FILE_DATA:  break;
	                 case UAV_MSG_FILE_END:   break;
	                 case UAV_MSG_FILE_STOP:  break;
	                 default:                 break;    
	             }  
	         }
	         else  isOK=false; 
	         break;
        default:   isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_FCC(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false,data[16];
    int    idx;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;  
                
	            switch (echoMsg) {
	                case UAV_MSG_REQU_SAVE:       break;
	                case UAV_MSG_REQU_DEL:        break;	                     
	                case UAV_MSG_FCC_TYPESET: 
	                case UAV_MSG_FCC_TYPEASK:     
	                    status_SysInfo.fcc_TY = frame_return_uint8_t(r_message->payload, 1);
	                    break;
	                case UAV_MSG_FCC_ADSET:
	                case UAV_MSG_FCC_ADASK:       
                        idx = frame_return_uint8_t(r_message->payload, 1);
	                    data_AD[idx].ratio  = frame_return_float(r_message->payload, 2);
	                    data_AD[idx].offset = frame_return_float(r_message->payload, 6);
	                    break;
	                case UAV_MSG_FCC_DASET: 
	                case UAV_MSG_FCC_DAASK:       
                        idx = frame_return_uint8_t(r_message->payload, 1);
	                    data_DA[idx].ratio  = frame_return_float(r_message->payload, 2);
	                    data_DA[idx].offset = frame_return_float(r_message->payload, 6);
	                    break;
	                case UAV_MSG_FCC_RTCSET:
	                case UAV_MSG_FCC_RTCASK:      
	                    data_RTC.year   = frame_return_uint8_t(r_message->payload, 1) + 2000;
	                    data_RTC.month  = frame_return_uint8_t(r_message->payload, 2);
	                    data_RTC.day    = frame_return_uint8_t(r_message->payload, 3);  
	                    data_RTC.hour   = frame_return_uint8_t(r_message->payload, 4);  
	                    data_RTC.minute = frame_return_uint8_t(r_message->payload, 5);  
	                    data_RTC.second = frame_return_uint8_t(r_message->payload, 6); 	                    
	                    break;	                         
	                default:  break;    
	            }
	        }                                                             
	        else  isOK=false;                                             
	        break;                                                        
        case UAV_MSG_FCC_HEARTBEAT:
            if(!Id2num.contains(r_message->sysid))
            {
               qDebug()<<"minghaosb1"<<r_message->sysid;
               Id2num.insert(r_message->sysid,Idcount);
               Idcount++;
            }//新增一个ID号，记录其心跳帧
            idx = Id2num[r_message->sysid];
            if(idx>=4)  break;
            data_heartbeat[idx].uasInfo  = frame_return_uint8_t(r_message->payload, 0);   
            data_heartbeat[idx].uasState = frame_return_uint8_t(r_message->payload, 1 );
            data_heartbeat[idx].ctrlMode = frame_return_uint8_t(r_message->payload, 2 );
            data_heartbeat[idx].plMode   = frame_return_uint8_t(r_message->payload, 3 );
            data_heartbeat[idx].vtMode   = frame_return_uint8_t(r_message->payload, 4 );
            data_heartbeat[idx].guidMode = frame_return_uint8_t(r_message->payload, 5 );
            data_heartbeat[idx].lon      = frame_return_double(r_message->payload,  6 );
            data_heartbeat[idx].lat      = frame_return_double(r_message->payload,  14 );
            data_heartbeat[idx].vd       = frame_return_float(r_message->payload,   22);
            data_heartbeat[idx].alt      = frame_return_float(r_message->payload,   26);
            data_heartbeat[idx].Hdot     = frame_return_float(r_message->payload,   30);
            data_heartbeat[idx].psi      = frame_return_float(r_message->payload,   34);
            data_heartbeat[idx].track    = frame_return_float(r_message->payload,   38);
            data_heartbeat[idx].flyTime  = frame_return_uint16_t(r_message->payload,42);
            data_heartbeat[idx].gpsState = frame_return_uint8_t(r_message->payload,44);
            data_heartbeat[idx].tempEng  = 0.1f*frame_return_int16_t(r_message->payload,45);
            data_heartbeat[idx].oilEng   = 0.5f*frame_return_uint8_t(r_message->payload, 47);
            data_heartbeat[idx].voltCell = 0.2f*frame_return_uint8_t(r_message->payload, 48);
            data_heartbeat[idx].cpuRatio = frame_return_uint8_t(r_message->payload, 49);
            break;                                                                  
	    case UAV_MSG_FCC_FLYSTATUS1:  
            data_imu.theta = 0.01f * frame_return_int16_t(r_message->payload,0);
            data_imu.phi   = 0.01f * frame_return_int16_t(r_message->payload,2);
            data_imu.Q     = 0.01f * frame_return_int16_t(r_message->payload,4);
            data_imu.P     = 0.01f * frame_return_int16_t(r_message->payload,6);
            data_imu.R     = 0.01f * frame_return_int16_t(r_message->payload,8);
            data_imu.Axb   = 0.01f * frame_return_int16_t(r_message->payload,10);
            data_imu.Ayb   = 0.01f * frame_return_int16_t(r_message->payload,12);
            data_imu.Azb   = 0.01f * frame_return_int16_t(r_message->payload,14);
	                     
            ele_law        = 0.01f * frame_return_int16_t(r_message->payload,16);
            ail_law        = 0.01f * frame_return_int16_t(r_message->payload,18);
            rud_law        = 0.01f * frame_return_int16_t(r_message->payload,20);
            col_law        = 0.01f * frame_return_int16_t(r_message->payload,22);
            eng_law        = 0.01f * frame_return_int16_t(r_message->payload,24);
            ele_RC         = 0.01f * frame_return_int16_t(r_message->payload,26);
            ail_RC         = 0.01f * frame_return_int16_t(r_message->payload,28);
            rud_RC         = 0.01f * frame_return_int16_t(r_message->payload,30);
            col_RC         = 0.01f * frame_return_int16_t(r_message->payload,32);
            eng_RC         = 0.01f * frame_return_int16_t(r_message->payload,34);

            frame_push_float(data,0,ele_law);
            frame_push_float(data,4,ail_law);
            frame_push_float(data,8,rud_law);
            frame_push_float(data,12,col_law);
            emit signal_simFCC2Model(data,16);
	        break;
	    case UAV_MSG_FCC_FLYSTATUS2:  
	        data_wp       =        frame_return_uint8_t(r_message->payload,0);
	        data_dot      =        frame_return_uint8_t(r_message->payload,1);
            data_gps.lon  =        frame_return_double(r_message->payload,2);
            data_gps.lat  =        frame_return_double(r_message->payload,10);
            data_gps.alt  =        frame_return_float(r_message->payload,18);
            data_gps.Vd   = 1e-1 * frame_return_int16_t(r_message->payload, 22);
            data_gps.Hdot = 1e-1 * frame_return_int8_t(r_message->payload, 24);
            data_gps.track= 1e-1 * frame_return_uint16_t(r_message->payload,25);
            data_gps.used =        frame_return_uint8_t(r_message->payload, 27);
            data_hmc.psi  = 1e-1 * frame_return_uint16_t(r_message->payload,28);
            data_rpm      =        frame_return_uint16_t(r_message->payload,30);
            data_gps.freq =        frame_return_uint8_t(r_message->payload, 32);
            data_imu.freq =        frame_return_uint16_t(r_message->payload, 33);
            data_hmc.freq =        frame_return_uint8_t(r_message->payload, 35);
	        break;   
        case UAV_MSG_FCC_FLYSTATUS3:
            Hdot_opt  = frame_return_float(r_message->payload, 0);
            Hdot_var  = frame_return_float(r_message->payload, 4);
            height_var= frame_return_float(r_message->payload, 8);
            R_opt     = frame_return_float(r_message->payload, 12);
            R_var     = frame_return_float(r_message->payload, 16);
            psi_var   = frame_return_float(r_message->payload, 20);
            Vx_opt    = frame_return_float(r_message->payload, 24);
            Vx_var    = frame_return_float(r_message->payload, 28);
            ac_dX     = frame_return_float(r_message->payload, 32);
            Vy_opt    = frame_return_float(r_message->payload, 36);
            Vy_var    = frame_return_float(r_message->payload, 40);
            ac_dY     = frame_return_float(r_message->payload, 44);
            dX_mix    = frame_return_float(r_message->payload, 48);
            dY_mix    = frame_return_float(r_message->payload, 52);
            OSCPUUsage= (float)frame_return_uint8_t(r_message->payload, 56);
            break;
	    case UAV_MSG_FCC_DEVSTATUS1:  break;    
	    case UAV_MSG_FCC_DEVSTATUS2:  break;
	    case UAV_MSG_FCC_DEBUG:	      break;        
        default: isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_sensorIMU(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;  
	        }
	        else  isOK=false;  
	        break;
        default:  isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_sensorGPS(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;  
	        }
	        else  isOK=false;
	        break;
        default:  isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_sensorHMR(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;
	        }
	        else  isOK=false;
	        break;
        default:  isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_ACS(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true; 
	        }
	        else   isOK=false;  
	        break;
        default:   isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_RC(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;  
	        }
	        else   isOK=false;  
	        break;
        default:   isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_auxRecoder(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        switch (echoMsg) {	            
	            case UAV_MSG_REQU_READ: break;                
	            case UAV_MSG_REQU_SEND: break;
	            case UAV_MSG_REQU_SAVE: break;
	            case UAV_MSG_REQU_DEL:  break;
	                	            
	            default:                break;    
	        }
	        break;
        default:                              isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_auxPower(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        switch (echoMsg) {	            
	            case UAV_MSG_REQU_READ:  break;                
	            case UAV_MSG_REQU_SEND:  break;
	            case UAV_MSG_REQU_SAVE:  break;
	            case UAV_MSG_REQU_DEL:   break;
	                	            
	            default:                 break;    
	        }
	        break;
        default:                              isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_auxEngine(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	    case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                emit signal_echoMessagePacket(r_message,cfgType);
                isOK=true;
	        }
	        else   isOK=false;                             
	        break;                             
        default:   isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_auxSpray(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        switch (echoMsg) {
	            case UAV_MSG_REQU_READ: break;                
	            case UAV_MSG_REQU_SEND: break;
	            case UAV_MSG_REQU_SAVE: break;
	            case UAV_MSG_REQU_DEL:  break;
	                	            
	            default:                break;    
	        }
	        break;
        default:                               isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_auxCamera(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        switch (echoMsg) {
	            case UAV_MSG_REQU_READ: break;                
	            case UAV_MSG_REQU_SEND: break;
	            case UAV_MSG_REQU_SAVE: break;
	            case UAV_MSG_REQU_DEL:  break;
	                	            
	            default:                break;    
	        }
	        break;
        default:                               isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_simMode(datalink_message_t* r_message)
{
    quint8 isOK=false;
    
    switch (r_message->msgid) {
        case UAV_MSG_SIM_FCC2MODEL:	
	        break;
        default: isOK=false; break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_simScene(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        switch (echoMsg) {
	            case UAV_MSG_REQU_READ:  break;                
	            case UAV_MSG_REQU_SEND:  break;
	            case UAV_MSG_REQU_SAVE:  break;
	            case UAV_MSG_REQU_DEL:   break;
	                	            
	            default:                 break;    
	        }
	        break;
        default:                               isOK=false;break;
	}
        
    return (isOK);
}

quint8  QDataProtocol::msg_compID_IAP(datalink_message_t* r_message)
{
    quint8 echoMsg, isOK=false;
    quint8 lenData, tmpData[DATALINK_MAX_PAYLOAD_LEN];
    
    switch (r_message->msgid) {
	     case UAV_MSG_REQU_ECHO:    
	        echoMsg = r_message->payload[0];
	        if (curSendMsg.msgid==echoMsg) {	       //发送指令与回报一致
	            emit signal_echoSuccess();
                isOK=true;  
                
	            switch (echoMsg) {
	                case UAV_MSG_IAP_START: 
	                    lenData = r_message->len - 1;
	                    for (int idx=0; idx<lenData; idx++) tmpData[idx] = r_message->payload[idx+1];                   
	                    emit signal_IAPCmdEchoOk(2, tmpData, lenData);	
	                    break;
                    case UAV_MSG_IAP_UPLOAD: 
                        lenData = r_message->len - 1;
	                    for (int idx=0; idx<lenData; idx++) tmpData[idx] = r_message->payload[idx+1];                   
	                    emit signal_IAPCmdEchoOk(3, tmpData, lenData);	
                        break;
                    case UAV_MSG_IAP_FINISHED: 
                        lenData = r_message->len - 1;
	                    for (int idx=0; idx<lenData; idx++) tmpData[idx] = r_message->payload[idx+1];                   
	                    emit signal_IAPCmdEchoOk(4, tmpData, lenData);	
                        break;
                    case UAV_MSG_IAP_VERIFY: break;   
                    case UAV_MSG_IAP_ENABLE:               
	                    emit signal_IAPCmdEchoOk(1, tmpData, 0);	
	                    break;                 	            
	                default:                 break;    
	            }  
	        }    
	        else   isOK=false; 
	        break;        
        default:                               isOK=false;break;
	}
        
    return (isOK);
}

