/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GCS.h"
#include "BL_Debug.h"

GCS::GCS( const char *_dbgname )
{
  mDbgName = _dbgname;
}
//---------------------------------------------------------------------------
GCS::~GCS()
{

}
//---------------------------------------------------------------------------
void GCS::lock()
{
  m.lock();
}
//---------------------------------------------------------------------------
bool GCS::tryLock()    
{ 
  return m.try_lock(); 
}
//---------------------------------------------------------------------------
void GCS::unlock()
{
  m.unlock();
}
//---------------------------------------------------------------------------
