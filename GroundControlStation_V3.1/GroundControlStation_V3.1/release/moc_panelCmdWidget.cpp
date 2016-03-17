/****************************************************************************
** Meta object code from reading C++ file 'panelCmdWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WidgetGCSCmd/panelCmdWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panelCmdWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPanelCmdWidget_t {
    QByteArrayData data[27];
    char stringdata[337];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPanelCmdWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPanelCmdWidget_t qt_meta_stringdata_QPanelCmdWidget = {
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
QT_MOC_LITERAL(9, 81, 21),
QT_MOC_LITERAL(10, 103, 19),
QT_MOC_LITERAL(11, 123, 7),
QT_MOC_LITERAL(12, 131, 19),
QT_MOC_LITERAL(13, 151, 8),
QT_MOC_LITERAL(14, 160, 6),
QT_MOC_LITERAL(15, 167, 21),
QT_MOC_LITERAL(16, 189, 8),
QT_MOC_LITERAL(17, 198, 28),
QT_MOC_LITERAL(18, 227, 5),
QT_MOC_LITERAL(19, 233, 7),
QT_MOC_LITERAL(20, 241, 7),
QT_MOC_LITERAL(21, 249, 7),
QT_MOC_LITERAL(22, 257, 14),
QT_MOC_LITERAL(23, 272, 18),
QT_MOC_LITERAL(24, 291, 22),
QT_MOC_LITERAL(25, 314, 4),
QT_MOC_LITERAL(26, 319, 17)
    },
    "QPanelCmdWidget\0signal_cmdOutput\0\0"
    "sysid\0compid\0msgid\0const quint8*\0"
    "packet\0length\0slot_CmdMissionEchoOK\0"
    "datalink_message_t*\0message\0"
    "slot_ActionSelected\0QAction*\0action\0"
    "slot_ActionSelected_2\0action_2\0"
    "slot_ActionSelected_2PreSend\0count\0"
    "quint8*\0cmdData\0dataLen\0slot_OkSendCmd\0"
    "slot_cancelSendCmd\0slot_enabledSendButton\0"
    "flag\0slot_cmdEchoTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPanelCmdWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   70,    2, 0x0a /* Public */,
      12,    1,   73,    2, 0x08 /* Private */,
      15,    1,   76,    2, 0x08 /* Private */,
      17,    3,   79,    2, 0x08 /* Private */,
      22,    0,   86,    2, 0x08 /* Private */,
      23,    0,   87,    2, 0x08 /* Private */,
      24,    1,   88,    2, 0x08 /* Private */,
      26,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   16,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 19, QMetaType::UChar,   18,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void,

       0        // eod
};

void QPanelCmdWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPanelCmdWidget *_t = static_cast<QPanelCmdWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->slot_CmdMissionEchoOK((*reinterpret_cast< datalink_message_t*(*)>(_a[1]))); break;
        case 2: _t->slot_ActionSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->slot_ActionSelected_2((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->slot_ActionSelected_2PreSend((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint8*(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 5: _t->slot_OkSendCmd(); break;
        case 6: _t->slot_cancelSendCmd(); break;
        case 7: _t->slot_enabledSendButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slot_cmdEchoTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPanelCmdWidget::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPanelCmdWidget::signal_cmdOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPanelCmdWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPanelCmdWidget.data,
      qt_meta_data_QPanelCmdWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QPanelCmdWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPanelCmdWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPanelCmdWidget.stringdata))
        return static_cast<void*>(const_cast< QPanelCmdWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPanelCmdWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QPanelCmdWidget::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
