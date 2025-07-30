/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEngine/Features/Logic/End/Object/NeedDestroyObjectSystem.h"

namespace nsLogicWrapper
{
    class DllExport TObjectFeature : public nsECSFramework::TFeature
    {
        TNeedDestroyObjectSystem mNeedDestroyObjectSystem;
    public:
        void InitConveyor() override;
    };
}