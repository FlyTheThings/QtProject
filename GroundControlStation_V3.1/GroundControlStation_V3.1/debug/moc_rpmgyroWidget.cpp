/****************************************************************************
** Meta object code from reading C++ file 'rpmgyroWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DialogCfg/rpmgyroWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rpmgyroWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QRpmgyroWidget_t {
    QByteArrayData data[22];
    char stringdata[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRpmgyroWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRpmgyroWidget_t qt_meta_stringdata_QRpmgyroWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 5),
QT_MOC_LITERAL(4, 39, 6),
QT_MOC_LITERAL(5, 46, 5),
QT_MOC_LITERAL(6, 52, 13),
QT_MOC_LITERAL(7, 66, 6),
QT_MOC_LITERAL(8, 73, 6),
QT_MOC_LITERAL(9, 80, 16),
QT_MOC_LITERAL(10, 97, 21),
QT_MOC_LITERAL(11, 119, 8),
QT_MOC_LITERAL(12, 128, 17),
QT_MOC_LITERAL(13, 146, 5),
QT_MOC_LITERAL(14, 152, 17),
QT_MOC_LITERAL(15, 170, 14),
QT_MOC_LITERAL(16, 185, 20),
QT_MOC_LITERAL(17, 206, 15),
QT_MOC_LITERAL(18, 222, 17),
QT_MOC_LITERAL(19, 240, 4),
QT_MOC_LITERAL(20, 245, 17),
QT_MOC_LITERAL(21, 263, 4)
    },
    "QRpmgyroWidget\0signal_cmdOutput\0\0sysid\0"
    "compid\0msgid\0const quint8*\0packet\0"
    "length\0slot_colServoDir\0slot_cmdButtonClicked\0"
    "ButtonID\0slot_sliderColMax\0value\0"
    "slot_sliderColMin\0slot_sliderEng\0"
    "slot_sliderEngOffset\0slot_sliderRPMI\0"
    "slot_lineEditRPM1\0str1\0slot_lineEditRPM2\0"
    "str2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRpmgyroWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   75,    2, 0x08 /* Private */,
      10,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      14,    1,   82,    2, 0x08 /* Private */,
      15,    1,   85,    2, 0x08 /* Private */,
      16,    1,   88,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,
      18,    1,   94,    2, 0x08 /* Private */,
      20,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 6, QMetaType::UChar,    3,    4,    5,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,

       0        // eod
};

void QRpmgyroWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRpmgyroWidget *_t = static_cast<QRpmgyroWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_cmdOutput((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< const quint8*(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 1: _t->slot_colServoDir(); break;
        case 2: _t->slot_cmdButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_sliderColMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_sliderColMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_sliderEng((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_sliderEngOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_sliderRPMI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_lineEditRPM1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slot_lineEditRPM2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QRpmgyroWidget::*_t)(quint8 , quint8 , quint8 , const quint8 * , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRpmgyroWidget::signal_cmdOutput)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QRpmgyroWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QRpmgyroWidget.data,
      qt_meta_data_QRpmgyroWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QRpmgyroWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRpmgyroWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QRpmgyroWidget.stringdata))
        return static_cast<void*>(const_cast< QRpmgyroWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QRpmgyroWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QRpmgyroWidget::signal_cmdOutput(quint8 _t1, quint8 _t2, quint8 _t3, const quint8 * _t4, quint8 _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
