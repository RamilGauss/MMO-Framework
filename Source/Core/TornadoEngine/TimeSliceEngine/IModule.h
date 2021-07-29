/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "TypeDef.h"
#include "ModuleType.h"

namespace nsTornadoEngine
{
    class DllExport IModule
    {
    public:
        virtual ~IModule() {};

        ModuleType mType;

        virtual bool StartEvent() = 0;

        virtual void Work() = 0;

        virtual void StopEvent() = 0;
    };
}