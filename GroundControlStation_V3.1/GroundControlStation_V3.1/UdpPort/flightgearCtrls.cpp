#include "flightgearCtrls.h"

FGCtrls::FGCtrls()
{

}
FGCtrls::~FGCtrls()
{

}
void FGCtrls::ConverData(char *buf, int len)
{
    union{char B[8]; long L[2];float F[2]; double DB;}src;
    FGCtrls *net = this;

    len = len;
    src.DB = net->throttle[0];
    buf[59] = src.B[0]; buf[58] = src.B[1]; buf[57] = src.B[2]; buf[56] = src.B[3];
    buf[55] = src.B[4]; buf[54] = src.B[5]; buf[53] = src.B[6]; buf[52] = src.B[7];
    src.DB = net->throttle[1];
    buf[67] = src.B[0]; buf[66] = src.B[1]; buf[65] = src.B[2]; buf[64] = src.B[3];
    buf[63] = src.B[4]; buf[62] = src.B[5]; buf[61] = src.B[6]; buf[60] = src.B[7];
    src.DB = net->throttle[2];
    buf[75] = src.B[0]; buf[74] = src.B[1]; buf[73] = src.B[2]; buf[72] = src.B[3];
    buf[71] = src.B[4]; buf[70] = src.B[5]; buf[69] = src.B[6]; buf[68] = src.B[7];
    src.DB = net->throttle[3];
    buf[83] = src.B[0]; buf[82] = src.B[1]; buf[81] = src.B[2]; buf[80] = src.B[3];
    buf[79] = src.B[4]; buf[78] = src.B[5]; buf[77] = src.B[6]; buf[76] = src.B[7];
}
