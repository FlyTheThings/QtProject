/****************************************************************************
** Meta object code from reading C++ file 'waypointDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroundControlStation_V3.1/DialogWP/waypointDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'waypointDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QWaypointDialog_t {
    QByteArrayData data[20];
    char stringdata[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QWaypointDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QWaypointDialog_t qt_meta_stringdata_QWaypointDialog = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 16),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 5),
QT_MOC_LITERAL(4, 40, 6),
QT_MOC_LITERAL(5, 47, 5),
QT_MOC_LITERAL(6, 53, 13),
QT_MOC_LITERAL(7, 67, 6),
QT_MOC_LITERAL(8, 74, 6),
QT_MOC_LITERAL(9, 81, 24),
QT_MOC_LITERAL(10, 106, 3),
QT_MOC_LITERAL(11, 110, 16),
QT_MOC_LITERAL(12, 127, 6),
QT_MOC_LITERAL(13, 134, 23),
QT_MOC_LITERAL(14, 158, 13),
QT_MOC_LITERAL(15, 172, 3),
QT_MOC_LITERAL(16, 176, 3),
QT_MOC_LITERAL(17, 180, 13),
QT_MOC_LITERAL(18, 194, 21),
QT_MOC_LITERAL(19, 216, 15)
    },
    "QWaypointDialog\0signal_cmdOutput\0\0"
    "sysid\0compid\0msgid\0const quint8*\0"
    "packet\0length\0signal_waypointCmdEchoOK\0"
    "idx\0WayPoint_Struc_t\0dataWP\0"
    "signal_addconnecttojava\0slot_fromjava\0"
    "lng\0lat\0slot_onDrawWP\0slot_addconnecttojava\0"
    "slot_picklonlat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWaypointDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   49,    2, 0x06 /* Public */,
       9,    2,   60,    2, 0x06 /* Public */,
      13,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   66,    2, 0x0a /* Public */,
      17,    0,   71,    2, 0x08 /* Private */,
      18,    0,   72,    2, 0x08 /* Private */,
      19,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 11,   10,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QWaypointDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWaypointDialog *_t = static_cast<QWaypointDialog *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->signal_waypointCmdEchoOK((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< WayPoint_Struc_t(*)>(_a[2]))); break;
        case 2: _t->signal_addconnecttojava(); break;
        case 3: _t->slot_fromjava((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->slot_onDrawWP(); break;
        case 5: _t->slot_addconnecttojava(); break;
        case 6: _t->slot_picklonlat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWaypointDialog::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWaypointDialog::signal_cmdOutput)) {
                *result = 0;
            }
        }
        {
            typedef void (QWaypointDialog::*_t)(quint8 , WayPoint_Struc_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWaypointDialog::signal_waypointCmdEchoOK)) {
                *result = 1;
            }
        }
        {
            typedef void (QWaypointDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWaypointDialog::signal_addconnecttojava)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QWaypointDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QWaypointDialog.data,
      qt_meta_data_QWaypointDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *QWaypointDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWaypointDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWaypointDialog.stringdata))
        return static_cast<void*>(const_cast< QWaypointDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QWaypointDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QWaypointDialog::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QWaypointDialog::signal_waypointCmdEchoOK(quint8 _t1, WayPoint_Struc_t _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QWaypointDialog::signal_addconnecttojava()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
