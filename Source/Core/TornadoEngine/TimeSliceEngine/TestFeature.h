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
    class DllExport TDebugWindow : public nsGraphicEngine::IRenderable
    {
    public:
        void Render() override
        {
            ImGui::ShowDemoWindow();
        }
    };

    class DllExport TInitWidgets : public nsECSFramework::TInitSystem
    {
        TWindow* mDebugLog = nullptr;
        TWindow* mWindow0 = nullptr;
        TWindow* mWindow1 = nullptr;

        TMainWindow* mMainWindow = nullptr;

        TDebugWindow mDebugWindow;

        std::string mIniData;
        size_t mOutIniSize = 0;
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