/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TestAllWidgetsSystem.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

#include <imgui.h>

using namespace nsTest;
using namespace nsImGuiWidgets;
using namespace nsTornadoEngine;

void TTestAllWidgetsSystem::Init()
{
    mWindow0 = new TComplexWindow("Test 0");
    mMainWindow = new TMainWindow();

    mMainWindow->mMenuNodes[2].mOnLeftClickCB.Register(this, [&](nsImGuiWidgets::TNode* pNode)
    {
        //auto mainWindowDockId = mMainWindow->mMW.GetDockId();
        //mWindow0->mWindow.SetParentDockId(mainWindowDockId);
    });
}
//------------------------------------------------------------------------------------------------