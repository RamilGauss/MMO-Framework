/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicH
#define ModuleServerLogicH

#include "ModuleDev.h"

class DllExport TModuleServerLogic : public TModuleDev
{
public:

  TModuleServerLogic();
  virtual ~TModuleServerLogic();

  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();
};

#endif
