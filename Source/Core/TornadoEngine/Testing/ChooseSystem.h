/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/Feature.h>

#include "ChooseWindow.h"

namespace nsTest
{
    class DllExport TChooseSystem : public nsECSFramework::TInitSystem, public nsECSFramework::TTearDownSystem
    {
    public:
        TChooseWindow* mWindow = nullptr;

        TCallbackPool<> mInitCB;

        void Init() override;
        void TearDown() override;
    };
}