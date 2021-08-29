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

#include "ComplexWindow.h"
#include "MainWindow.h"

namespace nsTest
{
    class DllExport TTestAllWidgetsSystem : public nsECSFramework::TInitSystem
    {
        TComplexWindow* mWindow0 = nullptr;

        TMainWindow* mMainWindow = nullptr;
    public:
        void Init() override;
    };
}