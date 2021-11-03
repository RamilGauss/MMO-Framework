/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <functional>

#include "TypeDef.h"

#include <ECS/include/Feature.h>

#include "DockingWindow.h"
#include "DockMainWindow.h"

#include <ImGuiWidgets/include/DockTreeManager.h>

namespace nsTest
{
    class DllExport TDockingSystem : public nsECSFramework::TInitSystem
    {
        std::list<TDockingWindow*> mWindows;
        TDockMainWindow* mMainWindow = nullptr;

        nsImGuiWidgets::TDockTreeManager* mDockTreeManager = nullptr;

        static const int WINDOW_COUNT = 6;

        using CB = std::function<void()>;

        std::array<CB,3> mCBs;

        int mCBIndex = 0;

    public:
        void Init() override;

    private:
        CB* Next();


        void OneTree();
        void TwoTrees();
        void HugeTree();
    };
}