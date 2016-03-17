/****************************************************************************
** Meta object code from reading C++ file 'firmwareUupdateDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroundControlStation_V3.1/DialogCfg/firmwareUupdateDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firmwareUupdateDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QFirmwareUpdateDialog_t {
    QByteArrayData data[17];
    char stringdata[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QFirmwareUpdateDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QFirmwareUpdateDialog_t qt_meta_stringdata_QFirmwareUpdateDialog = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 16),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 5),
QT_MOC_LITERAL(4, 46, 6),
QT_MOC_LITERAL(5, 53, 5),
QT_MOC_LITERAL(6, 59, 13),
QT_MOC_LITERAL(7, 73, 6),
QT_MOC_LITERAL(8, 80, 6),
QT_MOC_LITERAL(9, 87, 13),
QT_MOC_LITERAL(10, 101, 17),
QT_MOC_LITERAL(11, 119, 16),
QT_MOC_LITERAL(12, 136, 17),
QT_MOC_LITERAL(13, 154, 1),
QT_MOC_LITERAL(14, 156, 7),
QT_MOC_LITERAL(15, 164, 4),
QT_MOC_LITERAL(16, 169, 3)
    },
    "QFirmwareUpdateDialog\0signal_cmdOutput\0"
    "\0sysid\0compid\0msgid\0const quint8*\0"
    "packet\0length\0slot_openFile\0"
    "slot_enableUpdate\0slot_startUpdate\0"
    "slot_IAPCmdEchoOk\0x\0quint8*\0data\0len"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QFirmwareUpdateDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   50,    2, 0x08 /* Private */,
      10,    0,   51,    2, 0x08 /* Private */,
      11,    0,   52,    2, 0x08 /* Private */,
      12,    3,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 14, QMetaType::UChar,   13,   15,   16,

       0        // eod
};

void QFirmwareUpdateDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QFirmwareUpdateDialog *_t = static_cast<QFirmwareUpdateDialog *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->slot_openFile(); break;
        case 2: _t->slot_enableUpdate(); break;
        case 3: _t->slot_startUpdate(); break;
        case 4: _t->slot_IAPCmdEchoOk((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8*(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QFirmwareUpdateDialog::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QFirmwareUpdateDialog::signal_cmdOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QFirmwareUpdateDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QFirmwareUpdateDialog.data,
      qt_meta_data_QFirmwareUpdateDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *QFirmwareUpdateDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFirmwareUpdateDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QFirmwareUpdateDialog.stringdata))
        return static_cast<void*>(const_cast< QFirmwareUpdateDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QFirmwareUpdateDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QFirmwareUpdateDialog::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
