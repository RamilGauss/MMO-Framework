/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterTimer.h"

#include <boost/foreach.hpp>
#include "BL_Debug.h"

#define STR_NAME_TIMER "Timer"

AdapterTimer::AdapterTimer()
{
  GetLogger()->Register(STR_NAME_TIMER);

  mLastID = 0;
}
//-----------------------------------------------------------------
AdapterTimer::~AdapterTimer()
{
  Done();
}
//-----------------------------------------------------------------
bool AdapterTimer::Work()
{
  unsigned int now_ms = ht_GetMSCount();
  BOOST_FOREACH(TMapDescPtr::value_type& bit, mMapIDTimer)
  {
    if(bit.second->enable)
    if(bit.second->start_time_ms + bit.second->interval_ms < now_ms)
    {
      bit.second->start_time_ms = now_ms;
      TEvent event;
      event.id = bit.second->id;
      AddEventCopy(&event,sizeof(event));
    }
  }
  return true;
}
//-----------------------------------------------------------------
unsigned int AdapterTimer::New(int interval_ms, bool enable)
{
  mLastID++;

  TDescTimer* pDesc = new TDescTimer;
  pDesc->id          = mLastID;
  pDesc->interval_ms = interval_ms;
  pDesc->enable      = enable;
  mMapIDTimer.insert(TMapDescPtr::value_type(mLastID, pDesc));
  
  return pDesc->id;
}
//-----------------------------------------------------------------
void AdapterTimer::Delete(unsigned int id)
{
  TDescTimer* pDesc = Get(id);
  if(pDesc==NULL)
    return;
  mMapIDTimer.erase(id);

  delete pDesc;
}
//-----------------------------------------------------------------
void AdapterTimer::SetEnable(unsigned int id, bool val)
{
  TDescTimer* pDesc = Get(id);
  if(pDesc==NULL)
    return;
  pDesc->enable = val;
}
//-----------------------------------------------------------------
void AdapterTimer::SetInterval(unsigned int id, int val)
{
  TDescTimer* pDesc = Get(id);
  if(pDesc==NULL)
    return;
  pDesc->interval_ms = val;
}
//-----------------------------------------------------------------
AdapterTimer::TDescTimer* AdapterTimer::Get(unsigned int id)
{
  TMapDescPtrIt fit = mMapIDTimer.find(id);
  if(fit==mMapIDTimer.end())
  {
    BL_FIX_BUG();
    return NULL;
  }
  return fit->second;
}
//-----------------------------------------------------------------
void AdapterTimer::Done()
{
  BOOST_FOREACH(TMapDescPtr::value_type& bit, mMapIDTimer)
    delete bit.second;
  mMapIDTimer.clear();
}
//-----------------------------------------------------------------
PrototypeBaseModule* AdapterTimer::NewExample()
{
  return new AdapterTimer;
}
//-----------------------------------------------------------------
void AdapterTimer::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//-----------------------------------------------------------------
int AdapterTimer::GetVersionAdapter()
{
  return 1;
}
//-----------------------------------------------------------------

