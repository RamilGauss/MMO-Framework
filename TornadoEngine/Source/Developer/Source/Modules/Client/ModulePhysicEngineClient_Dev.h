/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModulePhysicEngineClient_DevH
#define ModulePhysicEngineClient_DevH

#include "ModulePhysicEngine.h"

class TModulePhysicEngineClient_Dev : public TModulePhysicEngine
{
protected:
  virtual void Input(int id, void* p, int size);
  virtual bool Output(void* p, int size);
};

#endif
