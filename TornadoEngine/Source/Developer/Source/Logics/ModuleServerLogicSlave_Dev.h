/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicSlave_DevH
#define ModuleServerLogicSlave_DevH

#include "ModuleServerLogic.h"

class TModuleServerLogicSlave_Dev : public TModuleServerLogic
{
protected:
  virtual bool WorkServer();
  virtual void EndWork();

  virtual void Input(int id, void* p, int size);
};

#endif
