/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleTimer.h"

#include "BL_Debug.h"
#include "SrcEvent.h"

TModuleTimer::TModuleTimer()
{
  mLastID = 0;
}
//-----------------------------------------------------------------
TModuleTimer::~TModuleTimer()
{
  Done();
}
//-----------------------------------------------------------------
bool TModuleTimer::WorkInherit()
{
  InputFromSynchroPoint();
  WorkTimer();
  OutputToSynchroPoint();
  return true;
}
//-----------------------------------------------------------------
void TModuleTimer::WorkTimer()
{
  unsigned int now_ms = ht_GetMSCount();
  int cnt = mVecTimer.size();
  for( int i = 0 ; i < cnt ; i++)
  {
    TDescTimer* pDesc = mVecTimer[i];
    if(pDesc->enable)
      if(pDesc->start_time_ms + pDesc->interval_ms < now_ms)
      {
        pDesc->start_time_ms = now_ms;
        TEvent event;
        event.id = pDesc->id;
        AddEventCopy(mLogicID, &event,sizeof(event));
      }
  }
}
//-----------------------------------------------------------------
unsigned int TModuleTimer::New(int interval_ms, bool enable)
{
  mLastID++;

  TDescTimer* pDesc = new TDescTimer;
  pDesc->id          = mLastID;
  pDesc->interval_ms = interval_ms;
  pDesc->enable      = enable;
  mVecTimer.push_back(pDesc);
  
  return pDesc->id;
}
//-----------------------------------------------------------------
void TModuleTimer::Delete(unsigned int id)
{
  int cnt = mVecTimer.size();
  TVectorDescPtr::iterator bit = mVecTimer.begin();
  for( int i = 0 ; i < cnt ; i++, bit++)
  {
    if(id==mVecTimer[i]->id)
    {
      delete mVecTimer[i];
      mVecTimer.erase(bit);
      return;
    }
  }
}
//-----------------------------------------------------------------
void TModuleTimer::SetEnable(unsigned int id, bool val)
{
  TDescTimer* pDesc = Get(id);
  if(pDesc==NULL)
    return;
  pDesc->enable = val;
}
//-----------------------------------------------------------------
void TModuleTimer::SetInterval(unsigned int id, int val)
{
  TDescTimer* pDesc = Get(id);
  if(pDesc==NULL)
    return;
  pDesc->interval_ms = val;
}
//-----------------------------------------------------------------
TModuleTimer::TDescTimer* TModuleTimer::Get(unsigned int id)
{
  int cnt = mVecTimer.size();
  for( int i = 0 ; i < cnt ; i++)
  {
    if(id==mVecTimer[i]->id)
      return mVecTimer[i];
  }
  BL_FIX_BUG();
  return NULL;
}
//-----------------------------------------------------------------
void TModuleTimer::Done()
{
  for( auto pDesc : mVecTimer)
    delete pDesc;
  mVecTimer.clear();
}
//-----------------------------------------------------------------
void TModuleTimer::StartEvent()
{
  mCBStartEvent.Notify();
}
//-----------------------------------------------------------------
void TModuleTimer::StopEvent()
{
  mCBStopEvent.Notify();
}
//-----------------------------------------------------------------
