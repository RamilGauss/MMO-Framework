/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "TestFeature.h"

#include <ECS/include/Feature.h>

#include "Modules.h"
#include "GraphicEngineModule.h"
#include "StopAccessor.h"

#include <imgui.h>

using namespace nsTest;
using namespace nsImGuiWidgets;
using namespace nsTornadoEngine;

void TTestFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    nsECSFramework::TFeature::SetEntMng(entMng);

    Add(&mChooseSystem);

    mChooseSystem.mInitCB.Register(this, [&]()
    {
        auto p = mChooseSystem.mWindow;

        p->mDockingButton.mOnClickCB.Register(this, [&](TButton*) { AddSystemOnClick(mDockingSystem);});
        p->mDockingStuffButton.mOnClickCB.Register(this, [&](TButton*) { AddSystemOnClick(mDockingStuffSystem); });
        p->mTestAllWidgetsButton.mOnClickCB.Register(this, [&](TButton*) { AddSystemOnClick(mTestAllWidgetsSystem); });
        p->mTreeViewButton.mOnClickCB.Register(this, [&](TButton*) { AddSystemOnClick(mTreeViewSystem); });
        p->mUnderMouseButton.mOnClickCB.Register(this, [&](TButton*) { AddSystemOnClick(mUnderMouseSystem); });
    });
}
//------------------------------------------------------------------------------------------------
