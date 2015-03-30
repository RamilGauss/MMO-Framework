/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicSlave_DevH
#define ModuleServerLogicSlave_DevH

#include "ModuleServerLogic.h"

class TSlaveForm;

class TModuleServerLogicSlave_Dev : public TModuleServerLogic
{
  TSlaveForm* mSlaveForm;

  enum
  {
    eCycleTime = 100,
  };
public:
  TModuleServerLogicSlave_Dev();

  virtual void StartEvent();
  virtual void StopEvent();
protected:
  virtual bool WorkServer();
  virtual void EndWork();

  virtual void Input(int id, void* p, int size);

private:
  void StartTimer();
  void InitForms();

};

#endif
