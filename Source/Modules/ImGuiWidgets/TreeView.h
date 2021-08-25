/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Frame.h"

#include <functional>
#include <list>

namespace nsImGuiWidgets
{
    class TNode;
    class TTreeNode;

    class DllExport TTreeView : public TFrame
    {
        std::list<TTreeNode*> mAllNodes;

        TTreeNode* mSelectedNode = nullptr;
    public:
        TWidget* GetUnderMouseChild(const ImVec2& mousePos) override;

        void AddNode(TTreeNode* pNode);

        void RemoveNode(const std::string& id);
        TTreeNode* GetNode(const std::string& id);

        using EventCallback = TCallbackPool<TTreeNode*>;

        using OnDragEvent = std::function<bool(TTreeNode*)>;
        using OnDropEvent = std::function<bool(TTreeNode*, TTreeNode*)>;

        EventCallback onSelectionEvent;

        TTreeNode* GetSelectedNode() const;
    private:
        TTreeNode* FoundNode(const std::string& id);
        void OnSelection(TNode* pSelectedNode);
        void OnClicked(TNode* pSelectedNode);
    };
}
