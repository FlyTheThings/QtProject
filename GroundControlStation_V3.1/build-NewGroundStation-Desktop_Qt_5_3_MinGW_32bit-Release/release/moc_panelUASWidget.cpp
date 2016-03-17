/****************************************************************************
** Meta object code from reading C++ file 'panelUASWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroundControlStation_V3.1/WidgetUAS/panelUASWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panelUASWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPanelUASWidget_t {
    QByteArrayData data[13];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPanelUASWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPanelUASWidget_t qt_meta_stringdata_QPanelUASWidget = {
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
QT_MOC_LITERAL(9, 81, 23),
QT_MOC_LITERAL(10, 105, 17),
QT_MOC_LITERAL(11, 123, 11),
QT_MOC_LITERAL(12, 135, 20)
    },
    "QPanelUASWidget\0signal_cmdOutput\0\0"
    "sysid\0compid\0msgid\0const quint8*\0"
    "packet\0length\0signal_changedActiveUAS\0"
    "slot_activebutton\0ActiveseqID\0"
    "slot_RealtimeDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPanelUASWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   34,    2, 0x06 /* Public */,
       9,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   48,    2, 0x08 /* Private */,
      12,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,
    QMetaType::Void, QMetaType::UChar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar,   11,
    QMetaType::Void,

       0        // eod
};

void QPanelUASWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPanelUASWidget *_t = static_cast<QPanelUASWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->signal_changedActiveUAS((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 2: _t->slot_activebutton((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 3: _t->slot_RealtimeDisplay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPanelUASWidget::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPanelUASWidget::signal_cmdOutput)) {
                *result = 0;
            }
        }
        {
            typedef void (QPanelUASWidget::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPanelUASWidget::signal_changedActiveUAS)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QPanelUASWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPanelUASWidget.data,
      qt_meta_data_QPanelUASWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QPanelUASWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPanelUASWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPanelUASWidget.stringdata))
        return static_cast<void*>(const_cast< QPanelUASWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPanelUASWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QPanelUASWidget::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QPanelUASWidget::signal_changedActiveUAS(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
