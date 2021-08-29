/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeViewWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;

TTreeViewWindow::TTreeViewWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({300, 400});
    mWindow.SetPos({20, 20});

    auto mouseClickFunc = [&](nsGraphicEngine::TKeyboardEvent event)
    {
        if (event.keyCode != nsGraphicEngine::KeyCodes::F2) {
            return;
        }
        if (event.state != nsGraphicEngine::KeyState::UP) {
            return;
        }

        auto pNode = mTreeView.GetSelectedNode();
        if (pNode != nullptr) {
            //mTreeView.Edit();
        }
    };
    mTreeView.mKeyCB.Register(mouseClickFunc);

    mTreeView.SetPos({30,180});
    mTreeView.SetSize({150, 120});

    mWindow.Add(&mTreeView);

    mTreeNodes[0].mStrId = "0";
    mTreeNodes[0].mLabel = "Scene0";

    mTreeNodes[1].mStrId = "1";
    mTreeNodes[1].mLabel = "Scene1";

    mTreeNodes[2].mParentId = "0";
    mTreeNodes[2].mStrId = "2";
    mTreeNodes[2].mLabel = "Camera";

    mTreeNodes[3].mParentId = "0";
    mTreeNodes[3].mStrId = "3";
    mTreeNodes[3].mLabel = "Light";

    mTreeNodes[4].mParentId = "1";
    mTreeNodes[4].mStrId = "4";
    mTreeNodes[4].mLabel = "Camera";

    mTreeNodes[5].mParentId = "1";
    mTreeNodes[5].mStrId = "5";
    mTreeNodes[5].mLabel = "Light";

    for (auto& node : mTreeNodes) {
        mTreeView.AddNode(&node);
    }

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
}
//--------------------------------------------------------------------------------------------------------
