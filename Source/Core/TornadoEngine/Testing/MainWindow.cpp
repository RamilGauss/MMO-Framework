/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;

TMainWindow::TMainWindow()
{
    mMenuNodes[0].mLabel = "States";
    mMenuNodes[1].mLabel = "Print";
    mMenuNodes[2].mLabel = "Save";
    mMenuNodes[3].mLabel = "Load";
    mMenuNodes[4].mLabel = "Clear log";
    mMenuNodes[5].mLabel = "Other";
    mMenuNodes[6].mLabel = "Dock";
    mMenuNodes[7].mLabel = "Exit";
    mMenuNodes[7].onLeftClick.Register([](nsImGuiWidgets::TNode* pNode) 
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mMenuNodes[0].Add(&mMenuNodes[1]);
    mMenuNodes[0].Add(&mMenuNodes[2]);
    mMenuNodes[0].Add(&mMenuNodes[3]);
    mMenuNodes[0].Add(&mMenuNodes[4]);

    mMenuNodes[5].Add(&mMenuNodes[6]);

    mMW.Add(&mMenuNodes[0]);
    mMW.Add(&mMenuNodes[5]);
    mMW.Add(&mMenuNodes[7]);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mMW);
}
//--------------------------------------------------------------------------------------------------------