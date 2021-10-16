/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockMainWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;

TDockMainWindow::TDockMainWindow()
{
    mMenuNodes[0].SetTitle("Dock commands");
    mMenuNodes[1].SetTitle("Next");
    mMenuNodes[2].SetTitle("Apply");
    mMenuNodes[3].SetTitle("Exit");
    mMenuNodes[3].onLeftClick.Register(this, [](nsImGuiWidgets::TNode* pNode)
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mMenuNodes[0].Add(&mMenuNodes[1]);
    mMenuNodes[0].Add(&mMenuNodes[2]);

    mMW.Add(&mMenuNodes[0]);
    mMW.Add(&mMenuNodes[3]);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mMW);
}
//--------------------------------------------------------------------------------------------------------