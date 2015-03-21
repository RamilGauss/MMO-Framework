/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleClientLogic_DevH
#define ModuleClientLogic_DevH

#include "ModuleClientLogic.h"

class TModuleClientLogic_Dev : public TModuleClientLogic
{
protected:
  virtual bool WorkClient();

  virtual void Input(int id, void* p, int size);
  virtual bool Output(void* p, int size);
};

#endif
