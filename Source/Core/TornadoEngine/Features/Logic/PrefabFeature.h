/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "NeedUnloadPrefabSystem.h"
#include "NeedDestroyPrefabSystem.h"

namespace nsLogicWrapper
{
    class DllExport TPrefabFeature : public nsECSFramework::TFeature
    {
        TNeedUnloadPrefabSystem mNeedUnloadPrefabSystem;
        TNeedDestroyPrefabSystem mNeedDestroyPrefabSystem;
    public:
        void InitConveyor() override;
    };
}