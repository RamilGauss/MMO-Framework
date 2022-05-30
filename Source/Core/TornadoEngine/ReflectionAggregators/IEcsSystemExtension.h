/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"
#include "ECS/include/System.h"

namespace nsTornadoEngine
{
    class DllExport IEcsSystemExtension
    {
    public:
        virtual ~IEcsSystemExtension() {}

        virtual nsECSFramework::TSystem* DynamicCast(void* p, int rtti) = 0;
    };
}