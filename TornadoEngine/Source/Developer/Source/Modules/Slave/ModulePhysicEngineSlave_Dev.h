/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModulePhysicEngineSlave_DevH
#define ModulePhysicEngineSlave_DevH

#include "ModulePhysicEngine.h"

class TModulePhysicEngineSlave_Dev : public TModulePhysicEngine
{
protected:
  virtual void Input(int id, void* p, int size);
  virtual bool Output(void* p, int size);
};

#endif
