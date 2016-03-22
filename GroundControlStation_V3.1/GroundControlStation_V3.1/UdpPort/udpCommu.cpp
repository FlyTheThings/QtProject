#include "udpCommu.h"
#include "flightgearCom.h"
#include<QDebug>

QUdpCommu::QUdpCommu(QObject *parent) : QObject(parent)
{
    p_udpSocketTx = new QUdpSocket(this);
    p_udpSocketRx = new QUdpSocket(this);
    connect(this,SIGNAL(siganl_udp2xplane()),this,SLOT(slot_udpsend2xplane()));

    fgDataCom = new FGNetData();
}

QUdpCommu::~QUdpCommu()
{
    if(p_udpSocketRx) delete p_udpSocketRx;
    if(p_udpSocketTx) delete p_udpSocketTx;
    if(fgDataCom)     delete fgDataCom;
}


bool QUdpCommu::setUdpPort(QUdpPortSettingDialog::Settings p)
{    
    hostIpAddress = p.hostIpAddress;   hostPort = p.hostPort;
    userIpAddress = p.userIpAddress;   userPort = p.userPort;
    
    if (p_udpSocketRx->bind(userIpAddress, userPort)==1) {
        p_udpSocketTx->connectToHost(hostIpAddress, hostPort, QIODevice::ReadWrite);

        connect(p_udpSocketRx, SIGNAL(readyRead()),  this, SLOT(slot_udpReceivePacket()));
        return(true);
    }
    else return(false);
}

void QUdpCommu::closeUdpPort()
{
    if (p_udpSocketRx->state()==QAbstractSocket::BoundState)     p_udpSocketRx->abort();
    if (p_udpSocketTx->state()==QAbstractSocket::ConnectedState) p_udpSocketTx->abort();
}

void QUdpCommu::setUdpProtocol(QDataProtocol *comProtocol)
{
    dataProtocol = comProtocol;
}

void QUdpCommu::slot_fccData2UdpSend(quint8 *data, quint8 len)
{
    len = len;
    fcc2xplane_law[0]=frame_return_float(data, 0)/20.0f;
    fcc2xplane_law[1]=frame_return_float(data, 4)/20.0f;
    fcc2xplane_law[2]=frame_return_float(data, 8)/10.0f+5.0f;
    fcc2xplane_law[3]=frame_return_float(data, 12)/10.0f;
}
void QUdpCommu::slot_udpsend2xplane()
{
    unsigned char buf[78];
    union{char B[8];long L[2];float F[2]; double DB;}src;
//    if (len<20) return;
    memset(buf,0x00,sizeof(buf));
   // qDebug()<<2;
        buf[0]=0x44;  buf[1]=0x41;  buf[2]=0x54;  buf[3]=0x41;  buf[4]='0';
    //纵向杆量
        src.L[0]=11;
        buf[5]=src.B[0]; buf[6]=src.B[1]; buf[7]=src.B[2]; buf[8]=src.B[3];
        src.F[0]=(float)(-fcc2xplane_law[0]/5.0f);  buf[9]=src.B[0]; buf[10]=src.B[1];buf[11]=src.B[2];buf[12]=src.B[3];
    //横向杆量
        src.F[0]=(float)fcc2xplane_law[1]/5.0f;     buf[13]=src.B[0];buf[14]=src.B[1];buf[15]=src.B[2];buf[16]=src.B[3];
    //航向杆量

        src.F[0]=(float)(fcc2xplane_law[2]-5.0f)/10.0f; buf[17]=src.B[0]; buf[18]=src.B[1]; buf[19]=src.B[2]; buf[20]=src.B[3];
        src.L[0]=39;                         buf[41]=src.B[0]; buf[42]=src.B[1]; buf[43]=src.B[2]; buf[44]=src.B[3];
        src.F[0]=(float)fcc2xplane_law[3];          buf[45]=src.B[0]; buf[46]=src.B[1]; buf[47]=src.B[2]; buf[48]=src.B[3];
        src.F[0]=-(float)(fcc2xplane_law[2]-5.0f)*2.0f; buf[49]=src.B[0]; buf[50]=src.B[1]; buf[51]=src.B[2]; buf[52]=src.B[3];
        buf[77]='\0';
    p_udpSocketTx->writeDatagram((const char*)buf, 78, hostIpAddress,hostPort);


}
void QUdpCommu::slot_udpReceivePacket()
{
    while (p_udpSocketRx->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(p_udpSocketRx->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;
        qint64  dataLen;

        dataLen = p_udpSocketRx->readDatagram(datagram.data(), datagram.size(),
                                            &sender, &senderPort);
        if (dataLen!=-1) {
            getXPlaneData(datagram.data(), dataLen);
            sendSimDataToFCC();
        }
    }
}

void QUdpCommu::getXPlaneData(char *buf,int len)
{
    union{char B[8]; long L[2]; float F[2]; double DB;}src;
	int   idx=0, totalframe=0;
	long  index=-1;
	unsigned char  buff[36];
	
	if(len<41) return;
	totalframe = (len-5)/36;
	for(idx=0;idx<totalframe;idx++) {
	    index=-1;
		for(int i=0;i<36;i++) buff[i]=buf[i+5+idx*36];

        index = frame_return_int32_t(buff, 0);
		switch(index){
//		    case 3:    //飞行速度信息
//                tmpF = frame_return_float(buff, 4);   dataXplane[0] = tmpF;
//                tmpF = frame_return_float(buff, 8);   dataXplane[1] = tmpF;
//                tmpF = frame_return_float(buff,12);   dataXplane[2] = tmpF;
//                tmpF = frame_return_float(buff,16);   dataXplane[3] = tmpF;
//                tmpF = frame_return_float(buff,20);   dataXplane[4] = tmpF;
//                tmpF = frame_return_float(buff,24);   dataXplane[5] = tmpF;
//                qDebug()<<"wdd2"<<tmpF;
//                tmpF = frame_return_float(buff,28);   dataXplane[6] = tmpF;
//                tmpF = frame_return_float(buff,32);   dataXplane[7] = tmpF;
//                emit signal_sim(dataXplane,6);
//		        break;
//		    case 4:       //加速度信息
//                tmpF = frame_return_float(buff, 4);   dataXplane[8] = tmpF;
//                tmpF = frame_return_float(buff, 8);   dataXplane[9] = tmpF;
//                tmpF = frame_return_float(buff,12);   dataXplane[10]= tmpF;
//                tmpF = frame_return_float(buff,16);   dataXplane[11]= tmpF;
//                tmpF = frame_return_float(buff,20);
//                tmpF = frame_return_float(buff,24);
//                tmpF = frame_return_float(buff,28);
//                tmpF = frame_return_float(buff,32);
//		        break;
//		    case 17:
//                tmpF = frame_return_float(buff, 4);
//                tmpF = frame_return_float(buff, 8);
//                tmpF = frame_return_float(buff,12);
//                tmpF = frame_return_float(buff,16);
//                tmpF = frame_return_float(buff,20);
//                tmpF = frame_return_float(buff,24);
//                tmpF = frame_return_float(buff,28);
//                tmpF = frame_return_float(buff,32);
//		        break;
//		    case 18:
//                tmpF = frame_return_float(buff, 4);
//                tmpF = frame_return_float(buff, 8);
//                tmpF = frame_return_float(buff,12);
//                tmpF = frame_return_float(buff,16);
//                tmpF = frame_return_float(buff,20);
//                tmpF = frame_return_float(buff,24);
//                tmpF = frame_return_float(buff,28);
//                tmpF = frame_return_float(buff,32);
//		        break;
//            case 19:
//		     tmpF = frame_return_float(buff, 4);
//                tmpF = frame_return_float(buff, 8);
//                tmpF = frame_return_float(buff,12);
//                tmpF = frame_return_float(buff,16);
//                tmpF = frame_return_float(buff,20);
//                tmpF = frame_return_float(buff,24);
//                tmpF = frame_return_float(buff,28);
//                tmpF = frame_return_float(buff,32);
//		        break;
//		    case 20:
//		        tmpF = frame_return_float(buff, 4);
//                tmpF = frame_return_float(buff, 8);
//                tmpF = frame_return_float(buff,12);
//                tmpF = frame_return_float(buff,16);
//                tmpF = frame_return_float(buff,20);
//                tmpF = frame_return_float(buff,24);
//                tmpF = frame_return_float(buff,28);
//                tmpF = frame_return_float(buff,32);
//		        break;
//		    case 39: break;
        case 3:        //飞行速度信息
                    src.B[0]=buff[4];  src.B[1]=buff[5];
                    src.B[2]=buff[6];  src.B[3]=buff[7];  // GEData.Vd_ac=src.F[0];  //空速  节knots*0.514=m/s
                    src.B[0]=buff[8];  src.B[1]=buff[9];
                    src.B[2]=buff[10];  src.B[3]=buff[11]; //GEData.Vd_ac=src.F[0];  //风速   节
                    src.B[0]=buff[12];  src.B[1]=buff[13];
                    src.B[2]=buff[14];  src.B[3]=buff[15]; //GEData.Vd_ac=src.F[0];  //空速   mph(miles per hour)
                    src.B[0]=buff[16];  src.B[1]=buff[17];
                    src.B[2]=buff[18];  src.B[3]=buff[19]; //GEData.Vd_ac=src.F[0];  //风速   mph(miles per hour)
                    src.B[0]=buff[20];  src.B[1]=buff[21];
                    src.B[2]=buff[22];  src.B[3]=buff[23];  dataXplane[6]=src.F[0]*0.005f;  //垂向速度   fpm(feet per minute)
                    src.B[0]=buff[24];  src.B[1]=buff[25];
                    src.B[2]=buff[26];  src.B[3]=buff[27];  //GEData.Vd_ac=src.F[0];  //风速   节
                    src.B[0]=buff[28];  src.B[1]=buff[29];
                    src.B[2]=buff[30];  src.B[3]=buff[31];  dataXplane[7]=src.F[0]*0.514f;    //地速  节-》米/秒
                    src.B[0]=buff[32];  src.B[1]=buff[33];
                    src.B[2]=buff[34];  src.B[3]=buff[35];  //GEData.Hdot_ac=src.F[0]*0.447f;  //垂向速度   mph->m/s
                    break;
                case 4:       //加速度信息
                    src.B[0]=buff[4];  src.B[1]=buff[5];
                    src.B[2]=buff[6];  src.B[3]=buff[7]; //马赫数;

                    src.B[0]=buff[8];  src.B[1]=buff[9];
                    src.B[2]=buff[10]; src.B[3]=buff[11];

                    src.B[0]=buff[12]; src.B[1]=buff[13];
                    src.B[2]=buff[14]; src.B[3]=buff[15]; dataXplane[14]=src.F[0]*(-1.0)*9.8;

                    src.B[0]=buff[16]; src.B[1]=buff[17];
                    src.B[2]=buff[18]; src.B[3]=buff[19]; dataXplane[12]=src.F[0]*9.8;

                    src.B[0]=buff[20]; src.B[1]=buff[21];
                    src.B[2]=buff[22]; src.B[3]=buff[23]; dataXplane[13]=src.F[0]*9.8;

                    break;
                case 17:
                    src.B[0]=buff[4];  src.B[1]=buff[5];
                    src.B[2]=buff[6];  src.B[3]=buff[7];  dataXplane[3]=src.F[0];
                    src.B[0]=buff[8];  src.B[1]=buff[9];
                    src.B[2]=buff[10]; src.B[3]=buff[11]; dataXplane[4]=src.F[0];
                    src.B[0]=buff[12]; src.B[1]=buff[13];
                    src.B[2]=buff[14]; src.B[3]=buff[15]; dataXplane[5]=src.F[0];
                    src.B[0]=buff[16]; src.B[1]=buff[17];
                    src.B[2]=buff[18]; src.B[3]=buff[19];
                    //qDebug()<<"r"<<dataXplane[5];
                    break;
                case 18:
                    src.B[0]=buff[4];  src.B[1]=buff[5];
                    src.B[2]=buff[6];  src.B[3]=buff[7]; dataXplane[0]=src.F[0];
                    src.B[0]=buff[8];  src.B[1]=buff[9];
                    src.B[2]=buff[10]; src.B[3]=buff[11]; dataXplane[1]=src.F[0];
                    src.B[0]=buff[12]; src.B[1]=buff[13];
                    src.B[2]=buff[14]; src.B[3]=buff[15]; dataXplane[2]=src.F[0];
                    if(dataXplane[2]<0.0f) dataXplane[2]+=360.0f;

                    break;
                case 19:
                    src.B[0]=buff[4];src.B[1]=buff[5];
                    src.B[2]=buff[6];src.B[3]=buff[7];  // GEData.lat_ac=src.F[0];
                    src.B[0]=buff[8];src.B[1]=buff[9];
                    src.B[2]=buff[10];src.B[3]=buff[11]; //GEData.lon_ac=src.F[0];
                    src.B[0]=buff[12];src.B[1]=buff[13];
                    src.B[2]=buff[14];src.B[3]=buff[15]; dataXplane[8]=src.F[0];  // 航迹角
                    break;
                case 20:
                    src.B[0]=buff[4];src.B[1]=buff[5];
                    src.B[2]=buff[6];src.B[3]=buff[7];   dataXplane[10]=src.F[0];
                    src.B[0]=buff[8];src.B[1]=buff[9];
                    src.B[2]=buff[10];src.B[3]=buff[11]; dataXplane[9]=src.F[0];
                    src.B[0]=buff[12];src.B[1]=buff[13];
                    src.B[2]=buff[14];src.B[3]=buff[15]; //GEData.alt_ac=src.F[0];
                    src.B[0]=buff[16];src.B[1]=buff[17];
                    src.B[2]=buff[18];src.B[3]=buff[19]; dataXplane[11]=src.F[0];


                    break;
                case 39:

                    break;
                default:

                    break;
		}
        emit signal_sim(dataXplane,15);
        emit siganl_udp2xplane();
	}
}

void QUdpCommu::sendSimDataToFCC()
{
    quint8  simData[60];
    
    frame_push_float(simData, 0, dataXplane[0]);  
    frame_push_float(simData, 4, dataXplane[1]);
    frame_push_float(simData, 8, dataXplane[2]);
    frame_push_float(simData,12, dataXplane[3]);
    frame_push_float(simData,16, dataXplane[4]);
    frame_push_float(simData,20, dataXplane[5]);
    frame_push_float(simData,24, dataXplane[6]);
    frame_push_float(simData,28, dataXplane[7]);
    frame_push_float(simData,32, dataXplane[8]);
    frame_push_float(simData,36, dataXplane[9]);
    frame_push_float(simData,40, dataXplane[10]);
    frame_push_float(simData,44, dataXplane[11]);
    frame_push_float(simData,48, dataXplane[12]);
    frame_push_float(simData,52, dataXplane[13]);
    frame_push_float(simData,56, dataXplane[14]);
    emit signal_cmdOutput(1, UAV_COMP_ID_SIM, UAV_MSG_SIM_MODEL2FCC, simData,60);
}
