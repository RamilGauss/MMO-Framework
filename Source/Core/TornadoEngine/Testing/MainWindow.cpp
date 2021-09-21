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
    mMenuNodes[0].SetTitle("Commands");
    mMenuNodes[1].SetTitle("Print state");
    mMenuNodes[2].SetTitle("Exit");
    mMenuNodes[2].onLeftClick.Register([](nsImGuiWidgets::TNode* pNode) 
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mMenuNodes[0].Add(&mMenuNodes[1]);
    mMenuNodes[0].Add(&mMenuNodes[2]);

    mMW.Add(&mMenuNodes[0]);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mMW);
}
//--------------------------------------------------------------------------------------------------------