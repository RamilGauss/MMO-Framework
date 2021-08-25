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

#include "Window.h"
#include "MainWindow.h"

namespace nsTest
{
    class DllExport TInitWidgets : public nsECSFramework::TInitSystem
    {
        TWindow* mDebugLog = nullptr;
        TWindow* mWindow = nullptr;

        TMainWindow* mMainWindow = nullptr;
    public:
        TInitWidgets();
        void Init() override;
    private:
        void SelectNode(nsImGuiWidgets::TTreeNode* pNode);
    };


    class DllExport TTestFeature : public nsECSFramework::TFeature
    {
        TInitWidgets mInitWidgets;
    public:
        void SetEntMng(nsECSFramework::TEntityManager* entMng) override;
    };
}