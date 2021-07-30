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
#include <ImGuiWidgets/MainWindow.h>
#include <ImGuiWidgets/Window.h>
#include <ImGuiWidgets/Button.h>

#include "Modules.h"
#include "ModuleGraphicEngine.h"

namespace nsTest
{
    class DllExport TInitWidgets : public nsECSFramework::TInitSystem
    {
        nsImGuiWidgets::TWindow mWindow;
        nsImGuiWidgets::TButton mButton;

    public:
        TInitWidgets() : mWindow("asd"), mButton("button")
        {

        }

        void Init() override
        {
            mWindow.PushWidget(&mButton);

            nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
        }
    };


    class DllExport TTestFeature : public nsECSFramework::TFeature
    {
        TInitWidgets mInitWidgets;
    public:
        void SetEntMng(nsECSFramework::TEntityManager* entMng) override
        {
            nsECSFramework::TFeature::SetEntMng(entMng);

            Add(&mInitWidgets);
        }
    };
}