/****************************************************************************
** Meta object code from reading C++ file 'positionCmdDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WidgetGCSCmd/positionCmdDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'positionCmdDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPositionCmdDialog_t {
    QByteArrayData data[9];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPositionCmdDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPositionCmdDialog_t qt_meta_stringdata_QPositionCmdDialog = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 22),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 5),
QT_MOC_LITERAL(4, 49, 7),
QT_MOC_LITERAL(5, 57, 7),
QT_MOC_LITERAL(6, 65, 7),
QT_MOC_LITERAL(7, 73, 19),
QT_MOC_LITERAL(8, 93, 1)
    },
    "QPositionCmdDialog\0signal_sendPositionCmd\0"
    "\0count\0quint8*\0cmdData\0dataLen\0"
    "slot_clickedSendCmd\0i"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPositionCmdDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::UChar,    3,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void QPositionCmdDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPositionCmdDialog *_t = static_cast<QPositionCmdDialog *>(_o);
        switch (_id) {
        case 0: _t->signal_sendPositionCmd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint8*(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 1: _t->slot_clickedSendCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPositionCmdDialog::*_t)(int , quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPositionCmdDialog::signal_sendPositionCmd)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPositionCmdDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QPositionCmdDialog.data,
      qt_meta_data_QPositionCmdDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *QPositionCmdDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPositionCmdDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPositionCmdDialog.stringdata))
        return static_cast<void*>(const_cast< QPositionCmdDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QPositionCmdDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QPositionCmdDialog::signal_sendPositionCmd(int _t1, quint8 * _t2, quint8 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
