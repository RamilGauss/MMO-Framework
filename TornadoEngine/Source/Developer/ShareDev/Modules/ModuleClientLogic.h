/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleClientLogicH
#define ModuleClientLogicH

#include "ModuleDev.h"

class DllExport TModuleClientLogic : public TModuleDev
{
public:
  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();
protected:
  virtual bool WorkClient() = 0;
};

#endif
