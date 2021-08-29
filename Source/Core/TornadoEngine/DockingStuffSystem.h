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

#include "DockingStuffWindow.h"
#include "MainWindow.h"

namespace nsTest
{
    class DllExport TDockingStuffSystem : public nsECSFramework::TInitSystem
    {
        std::list<TDockingStuffWindow*> mWindows;
        TMainWindow* mMainWindow = nullptr;

        static const int WIDGET_COUNT = 2;
    public:
        void Init() override;
    };
}