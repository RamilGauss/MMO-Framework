/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/SetupConfig/CheckArgumentsSystem.h"
#include "Systems/SetupConfig/ResolveJsonPathSystem.h"
#include "Systems/SetupConfig/TryLoadConfigSystem.h"
#include "Systems/SetupConfig/ResolvePathesSystem.h"

namespace nsContainerCodeGenerator
{
    class DllExport TSetupConfigFeature : public nsECSFramework::TFeature
    {
        TCheckArgumentsSystem  mCheckArgumentsSystem;
        TResolveJsonPathSystem mResolveJsonPathSystem;
        TTryLoadConfigSystem   mTryLoadConfigSystem;
        TResolvePathesSystem   mResolvePathesSystem;

    public:

        void InitConveyor() override;
    };
}