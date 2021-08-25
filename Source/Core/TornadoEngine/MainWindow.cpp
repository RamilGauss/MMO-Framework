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
    mMenuNodes[0].mLabel = "Main";
    mMenuNodes[1].mLabel = "Open";
    mMenuNodes[2].mLabel = "Save";

    mMenuNodes[3].mLabel = "Other";
    mMenuNodes[4].mLabel = "Make";

    mMenuNodes[5].mLabel = "Exit";
    mMenuNodes[5].onLeftClick.Register([](nsImGuiWidgets::TNode* pNode) 
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mMenuNodes[0].Add(&mMenuNodes[1]);
    mMenuNodes[0].Add(&mMenuNodes[2]);

    mMenuNodes[3].Add(&mMenuNodes[4]);

    mMW.Add(&mMenuNodes[0]);
    mMW.Add(&mMenuNodes[3]);
    mMW.Add(&mMenuNodes[5]);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mMW);
}
