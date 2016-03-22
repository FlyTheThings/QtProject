#ifndef DATAHANDLE_H
#define DATAHANDLE_H

/*[小端模式：X86/ARM]*/
static __inline void byte_copy_2(unsigned char *dst, unsigned char *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
}

static __inline void byte_copy_4(unsigned char *dst, unsigned char *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

static __inline void byte_copy_8(unsigned char *dst, unsigned char *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
}

/* 将数据以字节流的形式放置在缓冲区中 */
#define frame_push_uint8_t(buf, wire_offset, b) buf[wire_offset] = (quint8)b
#define frame_push_int8_t(buf, wire_offset, b)  buf[wire_offset] = (qint8)b
#define frame_push_char(buf, wire_offset, b)    buf[wire_offset] = b

#define frame_push_uint16_t(buf, wire_offset, b) byte_copy_2(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_int16_t(buf, wire_offset, b)  byte_copy_2(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_uint32_t(buf, wire_offset, b) byte_copy_4(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_int32_t(buf, wire_offset, b)  byte_copy_4(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_uint64_t(buf, wire_offset, b) byte_copy_8(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_int64_t(buf, wire_offset, b)  byte_copy_8(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_float(buf, wire_offset, b)    byte_copy_4(&buf[wire_offset], (unsigned char *)&b)
#define frame_push_double(buf, wire_offset, b)   byte_copy_8(&buf[wire_offset], (unsigned char *)&b)

/* 从缓冲区字节流中获取数据 */
#define frame_return_char(buf, wire_offset)    (char)   buf[wire_offset]
#define frame_return_int8_t(buf, wire_offset)  (qint8) buf[wire_offset]
#define frame_return_uint8_t(buf, wire_offset) (quint8)buf[wire_offset]

static __inline quint16 frame_return_uint16_t(unsigned char buf[],int wire_offset)
{
    quint16 r;
    byte_copy_2((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline qint16 frame_return_int16_t(unsigned char buf[],int wire_offset)
{
    qint16 r;
    byte_copy_2((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline quint32 frame_return_uint32_t(unsigned char buf[],int wire_offset)
{
    quint32 r;
    byte_copy_4((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline qint32 frame_return_int32_t(unsigned char buf[],int wire_offset)
{
    qint32 r;
    byte_copy_4((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline quint64 frame_return_uint64_t(unsigned char buf[],int wire_offset)
{
    quint64 r;
    byte_copy_8((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline qint64 frame_return_int64_t(unsigned char buf[],int wire_offset)
{
    qint64 r;
    byte_copy_8((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline float frame_return_float(unsigned char buf[],int wire_offset)
{
    float r;
    byte_copy_4((unsigned char*)&r, &buf[wire_offset]);
    return r;
}

static __inline double frame_return_double(unsigned char buf[],int wire_offset)
{
    double r;
    byte_copy_8((unsigned char*)&r, &buf[wire_offset]);
    return r;
}


#endif // DATAHANDLE_H
