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
using namespace nsImGuiWidgets;

TTreeViewWindow::TTreeViewWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({300, 400});
    mWindow.SetPos({20, 20});

    mTreeView.mOnEndEditEventCB.Register(this, [&](TTreeNode* pNode, const std::string& newTitle)
    {
        pNode->SetTitle(newTitle);
    });


    mTreeView.mOnKeyCB.Register(this, [&](nsGraphicEngine::TKeyboardEvent event)
    {
        if (event.keyCode != nsGraphicEngine::KeyCodes::F2) {
            return;
        }
        if (event.state != nsGraphicEngine::KeyState::UP) {
            return;
        }

        auto pNode = mTreeView.GetSelectedNode();
        if (pNode != nullptr) {
            mTreeView.BeginEdit();
        }
    });

    mTreeView.mOnMouseMoveCB.Register(this, [&](nsGraphicEngine::TMouseMotionEvent event)
    {
        auto pNode = mTreeView.GetChildByGlobalPos({(float)event.x, (float) event.y});

        if (pNode != &mTreeView && pNode != nullptr) {
            mToolTip.SetTitle(((TTreeNode*)pNode)->GetTitle());
        } else if (pNode == &mTreeView) {
            mToolTip.SetTitle("TreeView");
        }
        mToolTip.SetShow(pNode != nullptr);
    });

    mTreeView.SetPos({30,100});
    mTreeView.SetSize({300, 150});

    mButton.SetPos({30,30});
    mButton.SetSize({50, 20});
    mButton.SetTitle("Exit");
    mButton.mOnClickCB.Register(this, [&](nsImGuiWidgets::TButton*p) {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mWindow.Add(&mButton);
    mWindow.Add(&mTreeView);

    mTreeNodes[0].mStrId = "0";
    mTreeNodes[0].SetTitle("Scene0");

    mTreeNodes[1].mStrId = "1";
    mTreeNodes[1].SetTitle("Scene1");

    mTreeNodes[2].mParentId = "0";
    mTreeNodes[2].mStrId = "2";
    mTreeNodes[2].SetTitle("Camera");

    mTreeNodes[3].mParentId = "0";
    mTreeNodes[3].mStrId = "3";
    mTreeNodes[3].SetTitle("Light");

    mTreeNodes[4].mParentId = "1";
    mTreeNodes[4].mStrId = "4";
    mTreeNodes[4].SetTitle("Camera");

    mTreeNodes[5].mParentId = "1";
    mTreeNodes[5].mStrId = "5";
    mTreeNodes[5].SetTitle("Light");

    for (auto& node : mTreeNodes) {
        mTreeView.AddNode(&node);
    }

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mToolTip);
}
//--------------------------------------------------------------------------------------------------------
