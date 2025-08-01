/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/Config.h"

namespace nsReflectionCodeGenerator
{
    class TConfigContainer
    {
    public:
        TConfigContainer() = default;
        
        TConfig mConfig;

        TConfig* Config() { return &mConfig; }
    };
}
