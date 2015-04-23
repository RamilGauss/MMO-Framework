/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleDataBaseH
#define ModuleDataBaseH

#include "ModuleComponent.h"

class DllExport TModuleDataBase : public TModuleComponent
{
public:
  TModuleDataBase();
  virtual ~TModuleDataBase();

  virtual void StartEvent();
  virtual bool Work();
  virtual void StopEvent();
};

#endif
