/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/Mutex.h"
#include "Base/Common/BL_Debug.h"

TMutex::TMutex(const char* _dbgname)
{
    if (_dbgname) {
        mDbgName = _dbgname;
    }
}
//---------------------------------------------------------------------------
TMutex::~TMutex()
{

}
//---------------------------------------------------------------------------
void TMutex::lock()
{
    m.lock();
}
//---------------------------------------------------------------------------
bool TMutex::tryLock()
{
    return m.try_lock();
}
//---------------------------------------------------------------------------
void TMutex::unlock()
{
    m.unlock();
}
//---------------------------------------------------------------------------
