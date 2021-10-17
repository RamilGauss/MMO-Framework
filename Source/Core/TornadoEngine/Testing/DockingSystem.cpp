/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockingSystem.h"
#include "Modules.h"
#include "ModuleGraphicEngine.h"

#include <ImGuiWidgets/DockNode.h>

using namespace nsTest;
using namespace nsImGuiWidgets;

void TDockingSystem::Init()
{
    for (int i = 0; i < WINDOW_COUNT; i++) {
        mWindows.push_back(new TDockingWindow(std::to_string(i)));
    }
    mMainWindow = new TDockMainWindow();

    mDockTreeManager = new TDockTreeManager();

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(mDockTreeManager);

    mMainWindow->mMenuNodes[1].mOnLeftClickCB.Register(this, [this](nsImGuiWidgets::TNode* pNode)
    {
        mDockTreeManager->ClearTrees();

        Next()->operator()();

        mDockTreeManager->ApplyTreesAndBuildLight();
    });
    mMainWindow->mMenuNodes[2].mOnLeftClickCB.Register(this, [this](nsImGuiWidgets::TNode* pNode)
    {
        mDockTreeManager->ApplyTreesAndBuildLight();
    });

    // Имитация работы features в GraphicEngine
    mCBs[0] = [this]() { OneTree(); };
    mCBs[1] = [this]() { TwoTrees(); };
    mCBs[2] = [this]() { HugeTree(); };
}
//-------------------------------------------------------------------------------
TDockingSystem::CB* TDockingSystem::Next()
{
    auto p = &mCBs[mCBIndex];
    mCBIndex++;
    if (mCBIndex >= mCBs.size()) {
        mCBIndex = 0;
    }

    return p;
}
//-------------------------------------------------------------------------------
void TDockingSystem::OneTree()
{
    /*
        Two trees

          D (Tabs)
        / | \
       W0 W1 W2       */

    auto& dockTrees = mDockTreeManager->GetTrees();
    dockTrees.push_back(TDockTree());

    auto& tree0 = dockTrees[0];

    auto root0 = new TDockNode();
    tree0.root = root0;

    root0->windowNames.push_back("0");
    root0->windowNames.push_back("1");
    root0->windowNames.push_back("2");

    root0->selectedWindowIndex = 1;

    root0->SetPos({200, 200});
    root0->SetSize({200, 200});
}
//-------------------------------------------------------------------------------
void TDockingSystem::TwoTrees()
{
    OneTree();

    /*
      D(X)
     / \
  (Y)D  D
    / \  \
   D   D  W5
  /     \
  W3     W4         */

    auto& dockTrees = mDockTreeManager->GetTrees();

    dockTrees.push_back(TDockTree());

    auto root = new TDockNode();
    root->type = TDockNode::Type::X_SPLIT;
    root->SetPos({200, 200});
    root->SetSize({600, 200});

    auto& tree = dockTrees.back();
    tree.root = root;

    root->childs[0] = new TDockNode();
    root->childs[0]->parent = root;
    root->childs[0]->SetPos({0, 0});
    root->childs[0]->SetSize({200, 200});
    root->childs[0]->windowNames.push_back("3");

    root->childs[1] = new TDockNode();
    root->childs[1]->type = TDockNode::Type::X_SPLIT;
    root->childs[1]->parent = root;
    root->childs[1]->SetPos({200, 0});
    root->childs[1]->SetSize({400, 200});

    auto child1 = root->childs[1];

    child1->childs[0] = new TDockNode();
    child1->childs[0]->SetPos({200, 0});
    child1->childs[0]->SetSize({200, 200});
    child1->childs[0]->parent = child1;
    child1->childs[0]->windowNames.push_back("4");

    child1->childs[1] = new TDockNode();
    child1->childs[1]->SetPos({400, 0});
    child1->childs[1]->SetSize({200, 200});
    child1->childs[1]->parent = child1;
    child1->childs[1]->windowNames.push_back("5");
}
//-------------------------------------------------------------------------------
void TDockingSystem::HugeTree()
{

}
//-------------------------------------------------------------------------------
