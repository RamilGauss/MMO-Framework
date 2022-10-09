/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "NeedDestroyObjectSystem.h"

namespace nsLogicWrapper
{
    class DllExport TObjectFeature : public nsECSFramework::TFeature
    {
        TNeedDestroyObjectSystem mNeedDestroyObjectSystem;
    public:
        void InitConveyor() override;
    };
}