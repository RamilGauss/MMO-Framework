/****************************************************************************
** Meta object code from reading C++ file 'SlaveForm.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI/SlaveForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlaveForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TSlaveForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      29,   11,   11,   11, 0x09,
      44,   11,   11,   11, 0x09,
      61,   11,   11,   11, 0x09,
      79,   11,   11,   11, 0x09,
      97,   11,   11,   11, 0x09,
     113,   11,   11,   11, 0x09,
     131,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_TSlaveForm[] = {
    "TSlaveForm\0\0sl_DownPressed()\0"
    "sl_UpPressed()\0sl_LeftPressed()\0"
    "sl_RightPressed()\0sl_DownReleased()\0"
    "sl_UpReleased()\0sl_LeftReleased()\0"
    "sl_RightReleased()\0"
};

void TSlaveForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TSlaveForm *_t = static_cast<TSlaveForm *>(_o);
        switch (_id) {
        case 0: _t->sl_DownPressed(); break;
        case 1: _t->sl_UpPressed(); break;
        case 2: _t->sl_LeftPressed(); break;
        case 3: _t->sl_RightPressed(); break;
        case 4: _t->sl_DownReleased(); break;
        case 5: _t->sl_UpReleased(); break;
        case 6: _t->sl_LeftReleased(); break;
        case 7: _t->sl_RightReleased(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TSlaveForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TSlaveForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TSlaveForm,
      qt_meta_data_TSlaveForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TSlaveForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TSlaveForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TSlaveForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TSlaveForm))
        return static_cast<void*>(const_cast< TSlaveForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int TSlaveForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
