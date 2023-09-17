/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TComponentContent
    {
        std::string typeName;
        std::string jsonBody;

#pragma IGNORE_ATTRIBUTE
        void* p = nullptr;
#pragma IGNORE_ATTRIBUTE
        int rtti = 0;
    };
}
