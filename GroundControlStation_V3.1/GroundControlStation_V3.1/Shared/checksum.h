#ifndef _CHECKSUM_H_
#define _CHECKSUM_H_

#include "Shared/dataStructureDefine.H"

#define X25_INIT_CRC                0xffff
#define X25_VALIDATE_CRC            0xf0b8

static inline void  crc_accumulate(quint8 data, quint16 *crcAccum)
{
    quint8 tmp;

    tmp = data ^ (quint8)(*crcAccum &0xff);                      /*Accumulate one byte of data into the CRC*/
    tmp ^= (tmp<<4);
    *crcAccum = (*crcAccum>>8) ^ (tmp<<8) ^ (tmp <<3) ^ (tmp>>4);
}

static inline void  crc_init(quint16* crcAccum)
{
    *crcAccum = X25_INIT_CRC;
}

static inline quint16  crc_calculate(const quint8* pBuffer, quint16 length)
{
    quint16 crcTmp;

    crc_init(&crcTmp);
    while (length--) {
        crc_accumulate(*pBuffer++, &crcTmp);
    }

    return crcTmp;
}

static inline void crc_accumulate_buffer(quint16 *crcAccum, const unsigned char *pBuffer, quint16 length)
{
    const quint8 *p = (const quint8 *)pBuffer;
    while (length--) {
        crc_accumulate(*p++, crcAccum);
    }
}

static __inline void  protocol_start_checksum(datalink_message_t* msg)
{
    union {quint16 s; quint8 c[2];}ck;

    crc_init(&(ck.s));
    msg->ck_a = ck.c[0];
    msg->ck_b = ck.c[1];
}

static __inline void  protocol_update_checksum(datalink_message_t* msg, quint8 c)
{
    union {quint16 s; quint8 c[2];}ck;

    ck.c[0] = msg->ck_a;
    ck.c[1] = msg->ck_b;
    crc_accumulate(c, &(ck.s));
    msg->ck_a = ck.c[0];
    msg->ck_b = ck.c[1];
}

#endif // CHECKSUM_H
