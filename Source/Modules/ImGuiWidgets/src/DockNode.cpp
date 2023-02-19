/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockNode.h"

#include <imgui.h>
#include <imgui_internal.h>

#include "DockTypeHelper.h"

using namespace nsImGuiWidgets;

TDockNode::TDockNode()
{

}
//--------------------------------------------------------------------------
TDockNode::TDockNode(const TDockNode& other)
{

}
//--------------------------------------------------------------------------
TDockNode::~TDockNode()
{
    delete childs[0];
    delete childs[1];
}
//--------------------------------------------------------------------------
TDockNode& TDockNode::operator = (const TDockNode& other)
{
    return *this;
}
//--------------------------------------------------------------------------
bool TDockNode::operator == (const TDockNode& other)
{
    return false;
}
//--------------------------------------------------------------------------
void TDockNode::Build()
{
    ImGui::DockBuilderAddNode(GetId());

    auto node = ImGui::DockBuilderGetNode(GetId());

    if (HasDockChilds()) {
        int childIndex = 0;
        for (auto& child : childs) {
            if (child == nullptr) {

                childIndex++;
                continue;
            }
            child->Build();

            auto childNode = ImGui::DockBuilderGetNode(child->GetId());
            childNode->ParentNode = node;

            node->ChildNodes[childIndex] = childNode;

            childIndex++;
        }
    } else {
        int index = 0;
        for (auto& windowName : windowNames) {

            ImGui::DockBuilderDockWindow(windowName.c_str(), GetId());
            ImGuiWindow* window = ImGui::FindWindowByName(windowName.c_str());
            window->DockOrder = index;
            index++;
        }
    }

    node->SplitAxis = TDockTypeHelper::ToImGui(type);

    ImGui::DockBuilderSetNodePos(GetId(), GetPosition());
    ImGui::DockBuilderSetNodeSize(GetId(), GetSize());
    ImGui::DockBuilderFinish(GetId());

    // Reorder windows
    if (!HasDockChilds()) {
        // After finish node may be changed
        node = ImGui::DockBuilderGetNode(GetId());

        auto selectedWindowName = windowNames[selectedWindowIndex];
        for (auto& tab : node->TabBar->Tabs) {
            if (tab.Window->Name == selectedWindowName) {
                node->TabBar->SelectedTabId = tab.ID;
                break;
            }
        }
    }
}
//--------------------------------------------------------------------------
bool TDockNode::HasDockChilds() const
{
    return childs[0] != nullptr || childs[1] != nullptr;
}
//--------------------------------------------------------------------------
