/****************************************************************************
** Meta object code from reading C++ file 'recorddialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroundControlStation_V3.1/RecordData/recorddialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recorddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QRecordDialog_t {
    QByteArrayData data[12];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRecordDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRecordDialog_t qt_meta_stringdata_QRecordDialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 18),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 3),
QT_MOC_LITERAL(4, 38, 19),
QT_MOC_LITERAL(5, 58, 1),
QT_MOC_LITERAL(6, 60, 20),
QT_MOC_LITERAL(7, 81, 3),
QT_MOC_LITERAL(8, 85, 12),
QT_MOC_LITERAL(9, 98, 6),
QT_MOC_LITERAL(10, 105, 11),
QT_MOC_LITERAL(11, 117, 5)
    },
    "QRecordDialog\0signal_setplayback\0\0opt\0"
    "signal_valuechanged\0b\0signal_sliderchanged\0"
    "val\0buttoncliked\0button\0playchecked\0"
    "check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRecordDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x08 /* Private */,
      10,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void QRecordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRecordDialog *_t = static_cast<QRecordDialog *>(_o);
        switch (_id) {
        case 0: _t->signal_setplayback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signal_valuechanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_sliderchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->buttoncliked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->playchecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QRecordDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRecordDialog::signal_setplayback)) {
                *result = 0;
            }
        }
        {
            typedef void (QRecordDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRecordDialog::signal_valuechanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QRecordDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRecordDialog::signal_sliderchanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QRecordDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QRecordDialog.data,
      qt_meta_data_QRecordDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *QRecordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRecordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QRecordDialog.stringdata))
        return static_cast<void*>(const_cast< QRecordDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QRecordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QRecordDialog::signal_setplayback(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QRecordDialog::signal_valuechanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QRecordDialog::signal_sliderchanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
