/****************************************************************************
** Meta object code from reading C++ file 'menuToolbarWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainWindow/menuToolbarWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuToolbarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMenuToolbarWidget_t {
    QByteArrayData data[13];
    char stringdata[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMenuToolbarWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMenuToolbarWidget_t qt_meta_stringdata_QMenuToolbarWidget = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 18),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 3),
QT_MOC_LITERAL(4, 43, 3),
QT_MOC_LITERAL(5, 47, 23),
QT_MOC_LITERAL(6, 71, 8),
QT_MOC_LITERAL(7, 80, 6),
QT_MOC_LITERAL(8, 87, 24),
QT_MOC_LITERAL(9, 112, 25),
QT_MOC_LITERAL(10, 138, 27),
QT_MOC_LITERAL(11, 166, 26),
QT_MOC_LITERAL(12, 193, 23)
    },
    "QMenuToolbarWidget\0signal_menu_action\0"
    "\0pID\0cID\0slot_ActionFileSelected\0"
    "QAction*\0action\0slot_ActionCommuSelected\0"
    "slot_ActionConfigSelected\0"
    "slot_ActionWaypointSelected\0"
    "slot_ActionWindowsSelected\0"
    "slot_ActionHelpSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMenuToolbarWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   54,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
       9,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,
      11,    1,   66,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void QMenuToolbarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMenuToolbarWidget *_t = static_cast<QMenuToolbarWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_menu_action((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 1: _t->slot_ActionFileSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->slot_ActionCommuSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->slot_ActionConfigSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->slot_ActionWaypointSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->slot_ActionWindowsSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->slot_ActionHelpSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 6:
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
            typedef void (QMenuToolbarWidget::*_t)(quint8 , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMenuToolbarWidget::signal_menu_action)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QMenuToolbarWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QMenuToolbarWidget.data,
      qt_meta_data_QMenuToolbarWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QMenuToolbarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMenuToolbarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMenuToolbarWidget.stringdata))
        return static_cast<void*>(const_cast< QMenuToolbarWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QMenuToolbarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QMenuToolbarWidget::signal_menu_action(quint8 _t1, quint8 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
