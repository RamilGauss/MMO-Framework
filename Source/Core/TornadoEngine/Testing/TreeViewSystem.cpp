/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TreeViewSystem.h"
#include <fmt/core.h>
#include <ImGuiWidgets/Helper.h>

using namespace nsTest;
using namespace nsImGuiWidgets;

void TTreeViewSystem::Init()
{
    mWindow = new TTreeViewWindow("TreeView");
}
//---------------------------------------------------------------------------------
void TTreeViewSystem::Execute()
{
    auto& nodes = *(mWindow->mTreeView.GetAllNodes());
    for (auto& node : nodes) {
        auto title = node->GetTitle();
        auto fpos = title.find("_");
        if (fpos != std::string::npos) {
            title = title.substr(0, fpos);
        }
        auto sizeStr = nsImGuiWidgets::ToString(node->GetSize());
        auto globalPosStr = nsImGuiWidgets::ToString(node->GetGlobalPos());
        title = fmt::format("{}_{}_{}", title, globalPosStr, sizeStr);
        node->SetTitle(title);
    }
}
//---------------------------------------------------------------------------------
