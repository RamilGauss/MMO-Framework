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
    mWindow.SetSize({200, 250});
    mWindow.SetPos({400, 100});

    mTestAllWidgetsButton.SetTitle("Test all widgets");
    mTestAllWidgetsButton.SetPos({50,30});
    mTestAllWidgetsButton.SetSize({100, 20});

    mDockingButton.SetTitle("Docking");
    mDockingButton.SetPos({50,60});
    mDockingButton.SetSize({100, 20});

    mDockingStuffButton.SetTitle("Docking stuff");
    mDockingStuffButton.SetPos({50,90});
    mDockingStuffButton.SetSize({100, 20});

    mTreeViewButton.SetTitle("TreeView");
    mTreeViewButton.SetPos({50,120});
    mTreeViewButton.SetSize({100, 20});

    mUnderMouseButton.SetTitle("UnderMouse");
    mUnderMouseButton.SetPos({50,150});
    mUnderMouseButton.SetSize({100, 20});

    mExit.SetTitle("Exit");
    mExit.SetPos({50,200});
    mExit.SetSize({100, 20});
    mExit.mClickCB.Register([&](TButton* p) 
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