/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <map>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    struct DllExport TArchetype
    {
        std::string typeName;// Pivot of

        std::list<std::string> parentNames;// other TArchetype
        std::list<std::string> properties;
    };
}