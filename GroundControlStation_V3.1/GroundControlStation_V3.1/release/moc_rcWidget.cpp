/****************************************************************************
** Meta object code from reading C++ file 'rcWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DialogCfg/rcWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rcWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QRcWidget_t {
    QByteArrayData data[14];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRcWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRcWidget_t qt_meta_stringdata_QRcWidget = {
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
QT_MOC_LITERAL(9, 75, 22),
QT_MOC_LITERAL(10, 98, 21),
QT_MOC_LITERAL(11, 120, 1),
QT_MOC_LITERAL(12, 122, 21),
QT_MOC_LITERAL(13, 144, 8)
    },
    "QRcWidget\0signal_cmdOutput\0\0sysid\0"
    "compid\0msgid\0const quint8*\0packet\0"
    "length\0slot_rcCapTimerDisplay\0"
    "slot_dirButtonClicked\0i\0slot_cmdButtonClicked\0"
    "ButtonID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRcWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   45,    2, 0x08 /* Private */,
      10,    1,   46,    2, 0x08 /* Private */,
      12,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void QRcWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRcWidget *_t = static_cast<QRcWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->slot_rcCapTimerDisplay(); break;
        case 2: _t->slot_dirButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_cmdButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QRcWidget::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRcWidget::signal_cmdOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QRcWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QRcWidget.data,
      qt_meta_data_QRcWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QRcWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRcWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QRcWidget.stringdata))
        return static_cast<void*>(const_cast< QRcWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QRcWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QRcWidget::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE