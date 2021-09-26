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

TDockTreeManager::TDockTreeManager()
{
    TWindow::SetDockTreeManager(this);
}
//----------------------------------------------------------------------
struct TWindowNode
{
    ImGuiID id;
    std::string name;
    ImGuiWindow* imWindow = nullptr;
};
struct TNode
{
    ImGuiID id;

    TNode* parent = nullptr;
    TNode* child[2] = {nullptr};

    ImGuiDockNode* imParent = nullptr;
    ImGuiDockNode* imChild[2] = {nullptr};

    ImGuiAxis splitMode;
    ImGuiDockNodeState state;

    // Strict order
    std::vector<TWindowNode> windows;

    int selectedWindowIndex = 0;
};

void TDockTreeManager::Render()
{
    auto ctx = ImGui::GetCurrentContext();

    std::list<TNode> nodeList;
    std::map<ImGuiID, TNode*> nodeMap;

    // Fill
    auto& nodes = ctx->DockContext.Nodes;
    for (auto& data : nodes.Data) {
        auto n = (ImGuiDockNode*) data.val_p;
        if (n == nullptr) {
            continue;
        }
        TNode node;
        node.id = n->ID;
        node.imParent = n->ParentNode;
        node.imChild[0] = n->ChildNodes[0];
        node.imChild[1] = n->ChildNodes[1];

        node.splitMode = n->SplitAxis;
        node.state = n->State;

        if (n->TabBar != nullptr) {
            int index = 0;
            for (auto& tab : n->TabBar->Tabs) {
                auto w = tab.Window;
                TWindowNode windowNode;
                windowNode.id = w->ID;
                windowNode.name = w->Name;
                windowNode.imWindow = w;
                node.windows.push_back(windowNode);

                if (n->TabBar->SelectedTabId == tab.ID) {
                    node.selectedWindowIndex = index;
                }
                index++;
            }
        }

        nodeList.push_back(node);
        nodeMap.insert({node.id,&nodeList.back()});
    }

    // Resolving 
    for (auto& id_node : nodeMap) {
        auto node = id_node.second;
        if (node->imParent != nullptr) {
            node->parent = nodeMap[node->imParent->ID];
        }
        if (node->imChild[0] != nullptr) {
            node->child[0] = nodeMap[node->imChild[0]->ID];
        }
        if (node->imChild[1] != nullptr) {
            node->child[1] = nodeMap[node->imChild[1]->ID];
        }
    }

    for (auto& node : nodeList) {

        if (node.parent == nullptr &&
            node.child[0] == nullptr && node.child[1] == nullptr &&
            node.windows.size() == 0) {

            ImGui::DockBuilderRemoveNode(node.id);
        }
    }

    // Go through all the nodes
}
//----------------------------------------------------------------------
