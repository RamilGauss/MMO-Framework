/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/Core/CoreSystemGeneratorFeature.h"
#include "Systems/Core/CoreEcsSystemGeneratorFeature.h"
#include "Systems/Core/CoreHandlerGeneratorFeature.h"
#include "Systems/Core/CoreComponentGeneratorFeature.h"

namespace nsContainerCodeGenerator
{
    class DllExport TCoreGeneratorFeature : public nsECSFramework::TFeature
    {
        TCoreComponentGeneratorFeature mCoreComponentGeneratorFeature;
        TCoreHandlerGeneratorFeature mCoreHandlerGeneratorFeature;
        TCoreEcsSystemGeneratorFeature mCoreEcsSystemGeneratorFeature;
        TCoreSystemGeneratorFeature mCoreSystemGeneratorFeature;
    public:
        void InitConveyor() override;
    };
}