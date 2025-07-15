/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/LightDockTreeManager.h"
#include "ImGuiWidgets/Include/DockTypeHelper.h"

using namespace nsImGuiWidgets;

void TLightDockTreeManager::Build()
{
    mNodes.clear();
    mNodeMap.clear();

    auto ctx = ImGui::GetCurrentContext();

    // Fill
    auto& nodes = ctx->DockContext.Nodes;
    for (auto& data : nodes.Data) {
        auto n = (ImGuiDockNode*) data.val_p;
        if (n == nullptr) {
            continue;
        }
        TLightDockNode node;

        node.pos = n->Pos;
        node.size = n->Size;

        node.id = n->ID;
        node.imParent = n->ParentNode;
        node.imChild[0] = n->ChildNodes[0];
        node.imChild[1] = n->ChildNodes[1];

        node.splitMode = n->SplitAxis;
        node.state = n->State;

        if (n->TabBar != nullptr) {
            std::map<int, TLightWindowNode> orderedWindow;
            for (auto& tab : n->TabBar->Tabs) {
                auto w = tab.Window;

                TLightWindowNode windowNode;
                windowNode.id = w->ID;
                windowNode.name = w->Name;
                windowNode.imWindow = w;
                orderedWindow.insert({w->DockOrder, windowNode});
            }

            int index = 0;
            for (auto& orderW : orderedWindow) {
                auto& w = orderW.second;
                node.windows.push_back(orderW.second);

                if (n->TabBar->SelectedTabId == w.id) {
                    node.selectedWindowIndex = index;
                }
                index++;
            }
        }

        mNodes.push_back(node);
        mNodeMap.insert({node.id,&mNodes.back()});
    }

    // Resolving 
    for (auto& id_node : mNodeMap) {
        auto node = id_node.second;
        if (node->imParent != nullptr) {
            node->parent = mNodeMap[node->imParent->ID];
        }
        if (node->imChild[0] != nullptr) {
            node->child[0] = mNodeMap[node->imChild[0]->ID];
        }
        if (node->imChild[1] != nullptr) {
            node->child[1] = mNodeMap[node->imChild[1]->ID];
        }
    }

    // Thinning
    auto copyNodes = mNodes;
    for (auto& node : copyNodes) {

        if (node.parent == nullptr &&
            node.child[0] == nullptr && node.child[1] == nullptr &&
            node.windows.size() == 0) {

            ImGui::DockBuilderRemoveNode(node.id);

            mNodes.remove_if([&](const TLightDockNode& lightNode) { return lightNode.id == node.id; });
            mNodeMap.erase(node.id);
        }
    }
}
//-----------------------------------------------------------------------------
bool TLightDockTreeManager::operator == (const TLightDockTreeManager& other)
{
    if (mNodes.size() != other.mNodes.size()) {
        return false;
    }

    for (auto& tree : mNodes) {
        auto otherTree = std::find_if(other.mNodes.begin(), other.mNodes.end(), [&](const TLightDockNode& x) { return x.id == tree.id; });
        if (otherTree == other.mNodes.end()) {
            return false;
        }
        if (tree == (*otherTree)) {
            continue;
        }
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
void TLightDockTreeManager::CloneTo(std::vector<TDockTree>& dstTrees)
{
    auto trees = ResolveTrees();

    for (auto& lightNode : trees) {
        dstTrees.push_back(TDockTree());

        auto newRoot = new TDockNode();
        dstTrees.back().root = newRoot;

        CloneTo(lightNode, newRoot);
    }
}
//----------------------------------------------------------------------
void TLightDockTreeManager::CloneTo(TLightDockNode* lightNode, TDockNode* dockNode)
{
    dockNode->SetPosition(lightNode->pos);
    dockNode->SetSize(lightNode->size);

    dockNode->type = TDockTypeHelper::FromImGui(lightNode->splitMode);

    for (int i = 0; i < 2; i++) {
        if (lightNode->child[i] != nullptr) {
            auto newNode = new TDockNode();
            newNode->parent = dockNode;
            dockNode->childs[i] = newNode;

            CloneTo(lightNode->child[i], newNode);
        }
    }

    if (lightNode->HasChild()) {
        return;
    }

    for (auto& w : lightNode->windows) {
        dockNode->windowNames.push_back(w.name);
    }

    dockNode->selectedWindowIndex = lightNode->selectedWindowIndex;
}
//----------------------------------------------------------------------
std::list<TLightDockNode*> TLightDockTreeManager::ResolveTrees()
{
    std::list<TLightDockNode*> trees;

    for (auto& node : mNodes) {
        if (node.parent == nullptr) {
            trees.push_back(&node);
        }
    }

    return trees;
}
//----------------------------------------------------------------------
void TLightDockTreeManager::DestroyImGuiDock()
{
    auto trees = ResolveTrees();
    for (auto& tree : trees) {
        ImGui::DockBuilderRemoveNode(tree->id);
    }
}
//----------------------------------------------------------------------
int TLightDockTreeManager::GetNodeCount() const
{
    return mNodes.size();
}
//----------------------------------------------------------------------
