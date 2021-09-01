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

#include "DockingWindow.h"
#include "MainWindow.h"

namespace nsTest
{
    class DllExport TDockingSystem : public nsECSFramework::TInitSystem
    {
        std::list<TDockingWindow*> mWindows;
        TMainWindow* mMainWindow = nullptr;

        std::string mIniData;
        size_t mOutIniSize = 0;

        static const int WIDGET_COUNT = 6;
    public:
        void Init() override;
    };
}