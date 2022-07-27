/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ProtoFrame.h"

#include <functional>
#include <list>

namespace nsImGuiWidgets
{
    class TNode;
    class TTreeNode;

    class DllExport TTreeView : public TProtoFrame
    {
        std::list<TTreeNode*> mAllNodes;

        TTreeNode* mSelectedNode = nullptr;
    public:
        TWidget* GetChildByGlobalPos(const ImVec2& mousePos) override;

        void AddNode(TTreeNode* pNode);

        void RemoveNode(const std::string& id);
        TTreeNode* GetNode(const std::string& id);

        const std::list<TTreeNode*>* GetAllNodes() const;

        void RemoveAllNodes();

        using EventCallback = TCallbackPool<TTreeNode*>;

        using OnDragEvent = TCallbackPool<TTreeNode*>;
        using OnDragMovingEvent = TCallbackPool <TTreeNode*, TTreeNode*>;
        using OnDropEvent = TCallbackPool<TTreeNode*, TTreeNode*>;
        using OnEndEditEvent = TCallbackPool<TTreeNode*, const std::string&>;

        EventCallback mOnSelectionEventCB;
        OnDragEvent mOnDragEventCB;
        OnDragMovingEvent mOnDragMovingEventCB;
        OnDropEvent mOnDropEventCB;
        OnEndEditEvent mOnEndEditEventCB;

        TTreeNode* GetSelectedNode() const;

        // pNode = nullptr - using current
        void BeginEdit(TTreeNode* pNode = nullptr);

        void ContinueDrag(bool result);
        void ContinueDrop(bool result);
    protected:
        void BeginRender() override;

    private:
        TTreeNode* FoundNode(const std::string& id);
        void OnSelection(TNode* pSelectedNode);
    };
}
