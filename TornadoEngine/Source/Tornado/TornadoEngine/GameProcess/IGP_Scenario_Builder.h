/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef IGP_Scenario_BuilderH
#define IGP_Scenario_BuilderH

#include "TypeDef.h"
#include <string>

class DllExport IGP_Scenario_Builder
{
public:
    IGP_Scenario_Builder();
    virtual ~IGP_Scenario_Builder();

    virtual void LoadMap(std::string nameMap) = 0;
};

#endif
