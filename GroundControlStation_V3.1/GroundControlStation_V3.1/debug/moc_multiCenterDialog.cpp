/****************************************************************************
** Meta object code from reading C++ file 'multiCenterDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MutirotorsCfg/multiCenterDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiCenterDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_multiCenterDialog_t {
    QByteArrayData data[15];
    char stringdata[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_multiCenterDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_multiCenterDialog_t qt_meta_stringdata_multiCenterDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 16),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 5),
QT_MOC_LITERAL(4, 42, 6),
QT_MOC_LITERAL(5, 49, 5),
QT_MOC_LITERAL(6, 55, 13),
QT_MOC_LITERAL(7, 69, 6),
QT_MOC_LITERAL(8, 76, 6),
QT_MOC_LITERAL(9, 83, 17),
QT_MOC_LITERAL(10, 101, 6),
QT_MOC_LITERAL(11, 108, 22),
QT_MOC_LITERAL(12, 131, 19),
QT_MOC_LITERAL(13, 151, 7),
QT_MOC_LITERAL(14, 159, 7)
    },
    "multiCenterDialog\0signal_cmdOutput\0\0"
    "sysid\0compid\0msgid\0const quint8*\0"
    "packet\0length\0slot_buttonselect\0button\0"
    "slot_echoMessagePacket\0datalink_message_t*\0"
    "echoMsg\0cfgType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_multiCenterDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   40,    2, 0x08 /* Private */,
      11,    2,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,   13,   14,

       0        // eod
};

void multiCenterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        multiCenterDialog *_t = static_cast<multiCenterDialog *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->slot_buttonselect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slot_echoMessagePacket((*reinterpret_cast< datalink_message_t*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (multiCenterDialog::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&multiCenterDialog::signal_cmdOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject multiCenterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_multiCenterDialog.data,
      qt_meta_data_multiCenterDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *multiCenterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *multiCenterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_multiCenterDialog.stringdata))
        return static_cast<void*>(const_cast< multiCenterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int multiCenterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void multiCenterDialog::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
