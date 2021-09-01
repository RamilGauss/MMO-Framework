/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "TestFeature.h"

#include <ECS/include/Feature.h>

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

#include <imgui.h>

using namespace nsTest;
using namespace nsImGuiWidgets;
using namespace nsTornadoEngine;

void TTestFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    nsECSFramework::TFeature::SetEntMng(entMng);

    //Add(&mTestAllWidgetsSystem);
    //Add(&mDockingSystem);
    //Add(&mDockingStuffSystem);
    Add(&mTreeViewSystem);
    //Add(&mUnderMouseSystem);
}
//------------------------------------------------------------------------------------------------