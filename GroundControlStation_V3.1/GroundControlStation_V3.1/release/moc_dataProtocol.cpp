/****************************************************************************
** Meta object code from reading C++ file 'dataProtocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Shared/dataProtocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataProtocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QDataProtocol_t {
    QByteArrayData data[21];
    char stringdata[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDataProtocol_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDataProtocol_t qt_meta_stringdata_QDataProtocol = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 18),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 24),
QT_MOC_LITERAL(4, 59, 19),
QT_MOC_LITERAL(5, 79, 7),
QT_MOC_LITERAL(6, 87, 7),
QT_MOC_LITERAL(7, 95, 22),
QT_MOC_LITERAL(8, 118, 3),
QT_MOC_LITERAL(9, 122, 24),
QT_MOC_LITERAL(10, 147, 16),
QT_MOC_LITERAL(11, 164, 6),
QT_MOC_LITERAL(12, 171, 19),
QT_MOC_LITERAL(13, 191, 1),
QT_MOC_LITERAL(14, 193, 7),
QT_MOC_LITERAL(15, 201, 4),
QT_MOC_LITERAL(16, 206, 3),
QT_MOC_LITERAL(17, 210, 23),
QT_MOC_LITERAL(18, 234, 19),
QT_MOC_LITERAL(19, 254, 17),
QT_MOC_LITERAL(20, 272, 5)
    },
    "QDataProtocol\0signal_echoSuccess\0\0"
    "signal_echoMessagePacket\0datalink_message_t*\0"
    "message\0cfgType\0signal_enableCmdEchoOK\0"
    "idx\0signal_waypointCmdEchoOK\0"
    "WayPoint_Struc_t\0dataWP\0signal_IAPCmdEchoOk\0"
    "x\0quint8*\0data\0len\0signal_CmdMissionEchoOK\0"
    "signal_simFCC2Model\0signal_setacseqid\0"
    "seqid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDataProtocol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,
       9,    2,   63,    2, 0x06 /* Public */,
      12,    3,   68,    2, 0x06 /* Public */,
      17,    1,   75,    2, 0x06 /* Public */,
      18,    2,   78,    2, 0x06 /* Public */,
      19,    1,   83,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::UChar,    8,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 10,    8,   11,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 14, QMetaType::UChar,   13,   15,   16,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 14, QMetaType::UChar,   15,   16,
    QMetaType::Void, QMetaType::UChar,   20,

       0        // eod
};

void QDataProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDataProtocol *_t = static_cast<QDataProtocol *>(_o);
        switch (_id) {
        case 0: _t->signal_echoSuccess(); break;
        case 1: _t->signal_echoMessagePacket((*reinterpret_cast< datalink_message_t*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->signal_enableCmdEchoOK((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 3: _t->signal_waypointCmdEchoOK((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< WayPoint_Struc_t(*)>(_a[2]))); break;
        case 4: _t->signal_IAPCmdEchoOk((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8*(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 5: _t->signal_CmdMissionEchoOK((*reinterpret_cast< datalink_message_t*(*)>(_a[1]))); break;
        case 6: _t->signal_simFCC2Model((*reinterpret_cast< quint8*(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 7: _t->signal_setacseqid((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDataProtocol::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_echoSuccess)) {
                *result = 0;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(datalink_message_t * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_echoMessagePacket)) {
                *result = 1;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_enableCmdEchoOK)) {
                *result = 2;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(quint8 , WayPoint_Struc_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_waypointCmdEchoOK)) {
                *result = 3;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(quint8 , quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_IAPCmdEchoOk)) {
                *result = 4;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(datalink_message_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_CmdMissionEchoOK)) {
                *result = 5;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_simFCC2Model)) {
                *result = 6;
            }
        }
        {
            typedef void (QDataProtocol::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDataProtocol::signal_setacseqid)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject QDataProtocol::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDataProtocol.data,
      qt_meta_data_QDataProtocol,  qt_static_metacall, 0, 0}
};


const QMetaObject *QDataProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDataProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDataProtocol.stringdata))
        return static_cast<void*>(const_cast< QDataProtocol*>(this));
    return QObject::qt_metacast(_clname);
}

int QDataProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QDataProtocol::signal_echoSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDataProtocol::signal_echoMessagePacket(datalink_message_t * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QDataProtocol::signal_enableCmdEchoOK(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QDataProtocol::signal_waypointCmdEchoOK(quint8 _t1, WayPoint_Struc_t _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QDataProtocol::signal_IAPCmdEchoOk(quint8 _t1, quint8 * _t2, quint8 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QDataProtocol::signal_CmdMissionEchoOK(datalink_message_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QDataProtocol::signal_simFCC2Model(quint8 * _t1, quint8 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QDataProtocol::signal_setacseqid(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
