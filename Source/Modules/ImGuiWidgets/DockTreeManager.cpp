/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "DockTreeManager.h"
#include "Window.h"

#include <imgui.h>
#include <imgui_internal.h>

using namespace nsImGuiWidgets;

//###
static std::list<TLightDockTreeManager> g_History;
//###

void TDockTreeManager::Render()
{
    mLightForFrameTrees.Build();

    if (mLightForFrameTrees == mLightTrees) {
        return;
    }

    mLightForFrameTrees.DestroyImGuiDock();
    DestroyTrees();

    mLightForFrameTrees.CloneTo(mTrees);
    
    ApplyTreesAndBuildLight();

    mChangeTreeCB.Notify();

    //###
    g_History.push_back(mLightTrees);
    //###
}
//----------------------------------------------------------------------
std::vector<TDockTree>& TDockTreeManager::GetTrees()
{
    return mTrees;
}
//----------------------------------------------------------------------
void TDockTreeManager::ApplyTrees()
{
    for (auto& tree : mTrees) {
        tree.root->Build();
    }
}
//----------------------------------------------------------------------
void TDockTreeManager::ApplyTreesAndBuildLight()
{
    ApplyTrees();

    mLightTrees.Build();
}
//----------------------------------------------------------------------
void TDockTreeManager::ClearTrees()
{
    for (auto& tree : mTrees) {

        ImGui::DockBuilderRemoveNode(tree.root->GetId());
        delete tree.root;
    }

    mTrees.clear();
}
//----------------------------------------------------------------------
void TDockTreeManager::DestroyTrees()
{
    for (auto& tree : mTrees) {
        delete tree.root;
    }

    mTrees.clear();
}
//----------------------------------------------------------------------

