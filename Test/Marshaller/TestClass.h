/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "ParamClass.h"

namespace nsUnknown0
{
    namespace nsUnknown1
    {
#pragma REFLECTION_ATTRIBUTE
        struct UnknownType
        {
            std::string name;
        };
    }
};

#pragma REFLECTION_ATTRIBUTE
class TTestClass : public nsECSFramework::IComponent
{
public:// member region
    std::vector<TParamClass> vParam;

    nsUnknown0::nsUnknown1::UnknownType unknownType;
};
