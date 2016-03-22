/****************************************************************************
** Meta object code from reading C++ file 'panelPlotWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WidgetPlot/panelPlotWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panelPlotWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPanelPlotWidget_t {
    QByteArrayData data[12];
    char stringdata[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPanelPlotWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPanelPlotWidget_t qt_meta_stringdata_QPanelPlotWidget = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 20),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 3),
QT_MOC_LITERAL(4, 43, 21),
QT_MOC_LITERAL(5, 65, 12),
QT_MOC_LITERAL(6, 78, 1),
QT_MOC_LITERAL(7, 80, 22),
QT_MOC_LITERAL(8, 103, 22),
QT_MOC_LITERAL(9, 126, 19),
QT_MOC_LITERAL(10, 146, 8),
QT_MOC_LITERAL(11, 155, 6)
    },
    "QPanelPlotWidget\0signal_checkFailMenu\0"
    "\0idx\0slot_Heightmousepress\0QMouseEvent*\0"
    "e\0slot_Controlmousepress\0"
    "slot_Voltagemousepress\0slot_ActionSelected\0"
    "QAction*\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPanelPlotWidget[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       8,    1,   48,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void QPanelPlotWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPanelPlotWidget *_t = static_cast<QPanelPlotWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_checkFailMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slot_Heightmousepress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->slot_Controlmousepress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->slot_Voltagemousepress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->slot_ActionSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPanelPlotWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPanelPlotWidget::signal_checkFailMenu)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPanelPlotWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPanelPlotWidget.data,
      qt_meta_data_QPanelPlotWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QPanelPlotWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPanelPlotWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPanelPlotWidget.stringdata))
        return static_cast<void*>(const_cast< QPanelPlotWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPanelPlotWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QPanelPlotWidget::signal_checkFailMenu(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
