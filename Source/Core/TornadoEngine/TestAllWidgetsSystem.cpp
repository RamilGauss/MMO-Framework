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

    mMainWindow->mMenuNodes[5].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        auto mainWindowDockId = mMainWindow->mMW.GetDockId();
        mWindow0->mWindow.SetParentDockId(mainWindowDockId);
    });

    mMainWindow->mMenuNodes[1].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        //auto iniData = ImGui::SaveIniSettingsToMemory(&mOutIniSize);
        //mWindow0->mLogLabel.AppendText(iniData);
    });
    mMainWindow->mMenuNodes[2].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        //auto iniData = ImGui::SaveIniSettingsToMemory(&mOutIniSize);
        //mIniData = std::string(iniData);
    });
    mMainWindow->mMenuNodes[3].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        //ImGui::LoadIniSettingsFromMemory(mIniData.c_str(), mIniData.size());
    });
    mMainWindow->mMenuNodes[4].onLeftClick.Register([&](nsImGuiWidgets::TNode* pNode)
    {
        mWindow0->mLogLabel.SetText("");
    });
}
//------------------------------------------------------------------------------------------------