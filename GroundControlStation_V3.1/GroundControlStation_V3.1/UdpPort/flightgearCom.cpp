#include "flightgearCom.h"
FGNetData::FGNetData(void)
{
}

FGNetData::~FGNetData(void)
{
}

//主机字节网络字节互换
void FGNetData::ConverData(char *buf,int len)
{
    union{char B[8]; long L[2];uint32_t UL[2]; float F[2]; double DB;}src;
    FGNetData *net=this;

    len = len;
    src.B[3] = buf[0];  src.B[2] = buf[1];  src.B[1] = buf[2];  src.B[0] = buf[3];
    net->version = src.UL[0];
    src.B[3] = buf[36]; src.B[2] = buf[37]; src.B[1] = buf[38]; src.B[0] = buf[39];
    net->phi = src.F[0];
    src.B[3] = buf[40]; src.B[2] = buf[41]; src.B[1] = buf[42]; src.B[0] = buf[43];
    net->theta = src.F[0];
    src.B[3] = buf[44]; src.B[2] = buf[45]; src.B[1] = buf[46]; src.B[0] = buf[47];
    net->psi = src.F[0];
    src.B[3] = buf[52]; src.B[2] = buf[53]; src.B[1] = buf[54]; src.B[0] = buf[55];
    net->phidot = src.F[0];
    src.B[3] = buf[56]; src.B[2] = buf[57]; src.B[1] = buf[58]; src.B[0] = buf[59];
    net->thetadot = src.F[0];
    src.B[3] = buf[60]; src.B[2] = buf[61]; src.B[1] = buf[62]; src.B[0] = buf[63];
    net->psidot = src.F[0];
    src.B[3] = buf[64]; src.B[2] = buf[65]; src.B[1] = buf[66]; src.B[0] = buf[67];
    net->vcas = src.F[0];
    src.B[3] = buf[68]; src.B[2] = buf[69]; src.B[1] = buf[70]; src.B[0] = buf[71];
    net->climb_rate = src.F[0];
    src.B[7] = buf[8]; src.B[6] = buf[9]; src.B[5] = buf[10]; src.B[4] = buf[11];
    src.B[3] = buf[12]; src.B[2] = buf[13]; src.B[1] = buf[14]; src.B[0] = buf[15];
    net->longitude = src.DB;
    src.B[7] = buf[16]; src.B[6] = buf[17]; src.B[5] = buf[18]; src.B[4] = buf[19];
    src.B[3] = buf[20]; src.B[2] = buf[21]; src.B[1] = buf[22]; src.B[0] = buf[23];
    net->latitude = src.DB;
    src.B[7] = buf[24]; src.B[6] = buf[25]; src.B[5] = buf[26]; src.B[4] = buf[27];
    src.B[3] = buf[28]; src.B[2] = buf[29]; src.B[1] = buf[30]; src.B[0] = buf[31];
    net->altitude = src.DB;
}
