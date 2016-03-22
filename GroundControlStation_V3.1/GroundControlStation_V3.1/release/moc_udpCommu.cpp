/****************************************************************************
** Meta object code from reading C++ file 'udpCommu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UdpPort/udpCommu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpCommu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QUdpCommu_t {
    QByteArrayData data[19];
    char stringdata[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QUdpCommu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QUdpCommu_t qt_meta_stringdata_QUdpCommu = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 16),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 5),
QT_MOC_LITERAL(4, 34, 6),
QT_MOC_LITERAL(5, 41, 5),
QT_MOC_LITERAL(6, 47, 13),
QT_MOC_LITERAL(7, 61, 6),
QT_MOC_LITERAL(8, 68, 6),
QT_MOC_LITERAL(9, 75, 10),
QT_MOC_LITERAL(10, 86, 6),
QT_MOC_LITERAL(11, 93, 4),
QT_MOC_LITERAL(12, 98, 17),
QT_MOC_LITERAL(13, 116, 20),
QT_MOC_LITERAL(14, 137, 7),
QT_MOC_LITERAL(15, 145, 4),
QT_MOC_LITERAL(16, 150, 3),
QT_MOC_LITERAL(17, 154, 21),
QT_MOC_LITERAL(18, 176, 19)
    },
    "QUdpCommu\0signal_cmdOutput\0\0sysid\0"
    "compid\0msgid\0const quint8*\0packet\0"
    "length\0signal_sim\0float*\0addr\0"
    "siganl_udp2xplane\0slot_fccData2UdpSend\0"
    "quint8*\0data\0len\0slot_udpReceivePacket\0"
    "slot_udpsend2xplane"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QUdpCommu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   44,    2, 0x06 /* Public */,
       9,    2,   55,    2, 0x06 /* Public */,
      12,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,   61,    2, 0x0a /* Public */,
      17,    0,   66,    2, 0x08 /* Private */,
      18,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::UChar,   11,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14, QMetaType::UChar,   15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QUdpCommu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QUdpCommu *_t = static_cast<QUdpCommu *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->signal_sim((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 2: _t->siganl_udp2xplane(); break;
        case 3: _t->slot_fccData2UdpSend((*reinterpret_cast< quint8*(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 4: _t->slot_udpReceivePacket(); break;
        case 5: _t->slot_udpsend2xplane(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QUdpCommu::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QUdpCommu::signal_cmdOutput)) {
                *result = 0;
            }
        }
        {
            typedef void (QUdpCommu::*_t)(float * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QUdpCommu::signal_sim)) {
                *result = 1;
            }
        }
        {
            typedef void (QUdpCommu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QUdpCommu::siganl_udp2xplane)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QUdpCommu::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QUdpCommu.data,
      qt_meta_data_QUdpCommu,  qt_static_metacall, 0, 0}
};


const QMetaObject *QUdpCommu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QUdpCommu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QUdpCommu.stringdata))
        return static_cast<void*>(const_cast< QUdpCommu*>(this));
    return QObject::qt_metacast(_clname);
}

int QUdpCommu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QUdpCommu::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QUdpCommu::signal_sim(float * _t1, quint8 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QUdpCommu::siganl_udp2xplane()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
