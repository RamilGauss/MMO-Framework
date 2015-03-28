/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicSuperServer_DevH
#define ModuleServerLogicSuperServer_DevH

#include "ModuleServerLogic.h"

class TModuleServerLogicSuperServer_Dev : public TModuleServerLogic
{
protected:
  virtual bool WorkServer();
  virtual void EndWork();

  virtual void Input(int id, void* p, int size);
};

#endif
