/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleSoundEngineH
#define ModuleSoundEngineH

#include "ModuleComponent.h"

class DllExport TModuleSoundEngine : public TModuleComponent
{
public:
  TModuleSoundEngine();

  virtual void StartEvent();
  virtual bool WorkInherit();
  virtual void StopEvent();
};

#endif
