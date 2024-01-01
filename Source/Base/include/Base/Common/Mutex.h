/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <boost/thread/recursive_mutex.hpp>

#include "Base/Common/TypeDef.h"
//---------------------------------------------------------------------------
// надстройка над мьютексом
class DllExport TMutex
{
    boost::recursive_mutex m;

    std::string mDbgName;
public:
    TMutex(const char* _dbgname = nullptr);
    virtual ~TMutex();

    void setDbgName(const char* _dbgname) { mDbgName = _dbgname; }
    std::string dbgName() { return mDbgName; }

    bool tryLock();
    void lock();
    void unlock();
};

//---------------------------------------------------------------------------
// Класс автоматического блокиратора
// Обеспечивает вход в критическую секцию при создании объекта
// и выход из нее при удалении объекта.
// Предназначен для создания объектов на стеке
class TBL_Locker
{
    TMutex* mCS;
public:
    TBL_Locker(TMutex* cs) { mCS = cs; mCS->lock(); }

    virtual ~TBL_Locker() { done(); }

    void done() { if (mCS) { mCS->unlock(); mCS = NULL; } }
};

#define AUTO_LOCK( cs )     TBL_Locker locker( cs )
//===========================================================================
