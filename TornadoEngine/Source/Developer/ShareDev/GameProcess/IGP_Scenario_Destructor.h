/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef IGP_Scenario_DestructorH
#define IGP_Scenario_DestructorH

#include "TypeDef.h"
#include "IGP_General.h"

class DllExport IGP_Scenario_Destructor
{
public:
  IGP_Scenario_Destructor();
  virtual ~IGP_Scenario_Destructor();

  virtual void UnloadAll() = 0;
};

#endif
