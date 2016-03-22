/****************************************************************************
** Meta object code from reading C++ file 'serialPortCommu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroundControlStation_V3.1/SerialPort/serialPortCommu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialPortCommu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSerialPortCommu_t {
    QByteArrayData data[22];
    char stringdata[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSerialPortCommu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSerialPortCommu_t qt_meta_stringdata_QSerialPortCommu = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 19),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 4),
QT_MOC_LITERAL(4, 43, 5),
QT_MOC_LITERAL(5, 49, 15),
QT_MOC_LITERAL(6, 65, 4),
QT_MOC_LITERAL(7, 70, 20),
QT_MOC_LITERAL(8, 91, 25),
QT_MOC_LITERAL(9, 117, 5),
QT_MOC_LITERAL(10, 123, 6),
QT_MOC_LITERAL(11, 130, 5),
QT_MOC_LITERAL(12, 136, 13),
QT_MOC_LITERAL(13, 150, 6),
QT_MOC_LITERAL(14, 157, 6),
QT_MOC_LITERAL(15, 164, 28),
QT_MOC_LITERAL(16, 193, 20),
QT_MOC_LITERAL(17, 214, 13),
QT_MOC_LITERAL(18, 228, 16),
QT_MOC_LITERAL(19, 245, 3),
QT_MOC_LITERAL(20, 249, 32),
QT_MOC_LITERAL(21, 282, 24)
    },
    "QSerialPortCommu\0signal_setPrintText\0"
    "\0text\0color\0signal_setlight\0flag\0"
    "signal_setsendbutton\0slot_protocol_send_packet\0"
    "sysid\0compid\0msgid\0const quint8*\0"
    "packet\0length\0slot_protocol_send_packetSim\0"
    "slot_echoSendSuccess\0slot_playback\0"
    "slot_setprogeess\0val\0"
    "slot_protocol_receiveDataProcess\0"
    "slot_cmdEchoTimerMonitor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSerialPortCommu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       7,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    5,   75,    2, 0x0a /* Public */,
      15,    5,   86,    2, 0x0a /* Public */,
      16,    0,   97,    2, 0x0a /* Public */,
      17,    0,   98,    2, 0x0a /* Public */,
      18,    1,   99,    2, 0x0a /* Public */,
      20,    0,  102,    2, 0x08 /* Private */,
      21,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 12, QMetaType::UChar,    9,   10,   11,   13,   14,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 12, QMetaType::UChar,    9,   10,   11,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSerialPortCommu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSerialPortCommu *_t = static_cast<QSerialPortCommu *>(_o);
        switch (_id) {
        case 0: _t->signal_setPrintText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->signal_setlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_setsendbutton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slot_protocol_send_packet((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 4: _t->slot_protocol_send_packetSim((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 5: _t->slot_echoSendSuccess(); break;
        case 6: _t->slot_playback(); break;
        case 7: _t->slot_setprogeess((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_protocol_receiveDataProcess(); break;
        case 9: _t->slot_cmdEchoTimerMonitor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QSerialPortCommu::*_t)(QString , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSerialPortCommu::signal_setPrintText)) {
                *result = 0;
            }
        }
        {
            typedef void (QSerialPortCommu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSerialPortCommu::signal_setlight)) {
                *result = 1;
            }
        }
        {
            typedef void (QSerialPortCommu::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSerialPortCommu::signal_setsendbutton)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QSerialPortCommu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QSerialPortCommu.data,
      qt_meta_data_QSerialPortCommu,  qt_static_metacall, 0, 0}
};


const QMetaObject *QSerialPortCommu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSerialPortCommu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSerialPortCommu.stringdata))
        return static_cast<void*>(const_cast< QSerialPortCommu*>(this));
    return QWidget::qt_metacast(_clname);
}

int QSerialPortCommu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QSerialPortCommu::signal_setPrintText(QString _t1, QColor _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSerialPortCommu::signal_setlight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSerialPortCommu::signal_setsendbutton(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
