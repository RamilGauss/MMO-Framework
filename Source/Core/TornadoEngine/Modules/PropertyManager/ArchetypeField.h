/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <unordered_set>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    enum class FieldAccessType
    {
        SHOW,
        READ,
        WRITE,
        REMOVE,
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TArchetypeField
    {
        std::string name;
        std::unordered_set<FieldAccessType> access;
    };

    //{
    //    "name" : "nsCommonWrapper::TGuidComponent",
    //    "access" : ["SHOW", "READ"],
    //}
}
