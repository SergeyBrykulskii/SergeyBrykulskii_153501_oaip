/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_OpenFile_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "on_Exit_clicked"
QT_MOC_LITERAL(4, 48, 14), // "on_Add_clicked"
QT_MOC_LITERAL(5, 63, 19), // "on_ShowInfo_clicked"
QT_MOC_LITERAL(6, 83, 17), // "on_Search_clicked"
QT_MOC_LITERAL(7, 101, 15), // "on_Sort_clicked"
QT_MOC_LITERAL(8, 117, 25), // "on_comboBoxFirm_activated"
QT_MOC_LITERAL(9, 143, 5), // "index"
QT_MOC_LITERAL(10, 149, 25), // "on_comboBoxType_activated"
QT_MOC_LITERAL(11, 175, 27), // "on_radioButtonStock_clicked"
QT_MOC_LITERAL(12, 203, 7), // "checked"
QT_MOC_LITERAL(13, 211, 28), // "on_radioButtonNStock_clicked"
QT_MOC_LITERAL(14, 240, 20) // "on_Equipment_clicked"

    },
    "MainWindow\0on_OpenFile_clicked\0\0"
    "on_Exit_clicked\0on_Add_clicked\0"
    "on_ShowInfo_clicked\0on_Search_clicked\0"
    "on_Sort_clicked\0on_comboBoxFirm_activated\0"
    "index\0on_comboBoxType_activated\0"
    "on_radioButtonStock_clicked\0checked\0"
    "on_radioButtonNStock_clicked\0"
    "on_Equipment_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    1,   81,    2, 0x08 /* Private */,
      13,    1,   84,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_OpenFile_clicked(); break;
        case 1: _t->on_Exit_clicked(); break;
        case 2: _t->on_Add_clicked(); break;
        case 3: _t->on_ShowInfo_clicked(); break;
        case 4: _t->on_Search_clicked(); break;
        case 5: _t->on_Sort_clicked(); break;
        case 6: _t->on_comboBoxFirm_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_comboBoxType_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_radioButtonStock_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_radioButtonNStock_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_Equipment_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
