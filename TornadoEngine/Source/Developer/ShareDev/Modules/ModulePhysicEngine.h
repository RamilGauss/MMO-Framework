/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModulePhysicEngineH
#define ModulePhysicEngineH

#include "ModuleDev.h"

class DllExport TModulePhysicEngine : public TModuleDev
{
public:
  TModulePhysicEngine();
  virtual ~TModulePhysicEngine();

  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();
};

#endif
