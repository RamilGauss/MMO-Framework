/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleServerLogic.h"
#include "Logger.h"
#include "HiTimer.h"

#define STR_NAME_SERVER_LOGIC "ServerLogic"

TModuleServerLogic::TModuleServerLogic():mStatLoad(30)
{
  GetLogger()->Register(STR_NAME_SERVER_LOGIC, "xls");

#ifndef _DEBUG
  GetLogger(STR_NAME_SERVER_LOGIC)->SetEnable(false);
#endif

  mCycleTime_ms = 0;
  mStartTime    = 0;
}
//----------------------------------------------------------------
bool TModuleServerLogic::Work()
{
  InputFromSynchroPoint();
  bool resWork = WorkServer();
  CalcAndWaitRestTime();

  EndWork();
  resWork &= !NeedExit();

  mStartTime = ht_GetMSCount();
  return resWork;
}
//----------------------------------------------------------------
void TModuleServerLogic::SetCycleTime(unsigned int t_ms)
{
  mCycleTime_ms = t_ms;
}
//----------------------------------------------------------------
float TModuleServerLogic::GetLastLoad()
{
  return mStatLoad.aver();
}
//----------------------------------------------------------------
void TModuleServerLogic::CalcAndWaitRestTime()
{
  if(mCycleTime_ms == 0)
    return;

  unsigned int now = ht_GetMSCount();

  unsigned int work_time = now - mStartTime;// потрачено времени
  double loadProcent = (work_time*100.0)/mCycleTime_ms;// расчет нагрузки
  mStatLoad.add(loadProcent);                         // занести в статистику

  GetLogger(STR_NAME_SERVER_LOGIC)->WriteF("%d\n",int(mStatLoad.aver()));
  // спать остаток времени
  if(now>mCycleTime_ms+mStartTime) return;
  unsigned int time_sleep = mStartTime + mCycleTime_ms - now;
  ht_msleep(time_sleep);
}
//------------------------------------------------------------------------
