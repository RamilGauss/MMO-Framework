/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Config.h"
#include "TearDownSystem.h"

namespace nsECSFramework
{
    class DllExport TBaseReactiveSystem : public TTearDownSystem
    {
    public:
        virtual void Reactive(TEntityID eid, IComponent* pC) = 0;
    };
}
