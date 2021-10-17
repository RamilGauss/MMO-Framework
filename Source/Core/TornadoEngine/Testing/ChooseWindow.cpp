/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ChooseWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;
using namespace nsImGuiWidgets;

TChooseWindow::TChooseWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({220, 250});
    mWindow.SetPos({400, 100});

    const int width = 120;
    const int height = 20;

    mTestAllWidgetsButton.SetTitle("Test all widgets");
    mTestAllWidgetsButton.SetPos({50,30});
    mTestAllWidgetsButton.SetSize({width, height});

    mDockingButton.SetTitle("Docking");
    mDockingButton.SetPos({50,60});
    mDockingButton.SetSize({width, height});

    mDockingStuffButton.SetTitle("Docking stuff");
    mDockingStuffButton.SetPos({50,90});
    mDockingStuffButton.SetSize({width, height});

    mTreeViewButton.SetTitle("TreeView");
    mTreeViewButton.SetPos({50,120});
    mTreeViewButton.SetSize({width, height});

    mUnderMouseButton.SetTitle("UnderMouse");
    mUnderMouseButton.SetPos({50,150});
    mUnderMouseButton.SetSize({width, height});

    mExit.SetTitle("Exit");
    mExit.SetPos({50,200});
    mExit.SetSize({width, height});
    mExit.mOnClickCB.Register(this, [&](TButton* p)
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mWindow.Add(&mTestAllWidgetsButton);
    mWindow.Add(&mDockingButton);
    mWindow.Add(&mDockingStuffButton);
    mWindow.Add(&mTreeViewButton);
    mWindow.Add(&mUnderMouseButton);
    mWindow.Add(&mExit);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
}
//--------------------------------------------------------------------------------------------------------
TChooseWindow::~TChooseWindow()
{
    nsTornadoEngine::Modules()->G()->GetGE()->RemoveRender(&mWindow);
}
//--------------------------------------------------------------------------------------------------------