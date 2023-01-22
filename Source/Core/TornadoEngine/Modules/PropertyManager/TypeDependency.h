/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "TypeDef.h"

namespace nsTornadoEngine
{
    struct DllExport TTypeDependency
    {
        std::string typeName;
        std::list<std::string> parentComponentNames;
        std::list<std::string> properties;
    };
}