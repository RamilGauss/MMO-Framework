/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicH
#define ModuleServerLogicH

#include "ModuleDev.h"
#include "StatisticValue.h"

class DllExport TModuleServerLogic : public TModuleDev
{
  unsigned int mCycleTime_ms;

  typedef TStatType_double TStatLoad;
  TStatLoad mStatLoad;

  unsigned int mStartTime;
public:

  TModuleServerLogic();
  virtual ~TModuleServerLogic();

  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();

protected:
  // вызов между input и output
  virtual bool WorkServer() = 0;
  // вызов в конце цикла работы
  virtual void EndWork()    = 0;
protected:
  // длительность рабочего цикла сервера,
  // например 100 мс, если он потратил 10 мс, то остаток 90 мс он спит
  // и нагрузка составит 10%
  void SetCycleTime(unsigned int t_ms);
  float GetLastLoad();// усредненная нагрузка, 0..100, %
private:
  void CalcAndWaitRestTime();
};

#endif
