/****************************************************************************
** Meta object code from reading C++ file 'cfg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroundControlStation_V3.1/MutirotorsCfg/cfg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cfg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cfgWidget_t {
    QByteArrayData data[18];
    char stringdata[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cfgWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cfgWidget_t qt_meta_stringdata_cfgWidget = {
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
QT_MOC_LITERAL(9, 75, 21),
QT_MOC_LITERAL(10, 97, 8),
QT_MOC_LITERAL(11, 106, 14),
QT_MOC_LITERAL(12, 121, 5),
QT_MOC_LITERAL(13, 127, 14),
QT_MOC_LITERAL(14, 142, 18),
QT_MOC_LITERAL(15, 161, 20),
QT_MOC_LITERAL(16, 182, 17),
QT_MOC_LITERAL(17, 200, 17)
    },
    "cfgWidget\0signal_cmdOutput\0\0sysid\0"
    "compid\0msgid\0const quint8*\0packet\0"
    "length\0slot_cmdButtonClicked\0ButtonID\0"
    "slot_sliderCOL\0value\0slot_sliderRUD\0"
    "slot_sliderPHI2AIL\0slot_sliderTHETA2ELE\0"
    "slot_sliderVX2ELE\0slot_sliderVY2AIL"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cfgWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   65,    2, 0x08 /* Private */,
      11,    1,   68,    2, 0x08 /* Private */,
      13,    1,   71,    2, 0x08 /* Private */,
      14,    1,   74,    2, 0x08 /* Private */,
      15,    1,   77,    2, 0x08 /* Private */,
      16,    1,   80,    2, 0x08 /* Private */,
      17,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void cfgWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cfgWidget *_t = static_cast<cfgWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->slot_cmdButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slot_sliderCOL((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_sliderRUD((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_sliderPHI2AIL((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_sliderTHETA2ELE((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_sliderVX2ELE((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_sliderVY2AIL((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cfgWidget::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cfgWidget::signal_cmdOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject cfgWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cfgWidget.data,
      qt_meta_data_cfgWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *cfgWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cfgWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cfgWidget.stringdata))
        return static_cast<void*>(const_cast< cfgWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int cfgWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void cfgWidget::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
