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
    class TTreeNode;

    class DllExport TTreeView : public TFrame
    {
        std::list<TTreeNode*> mAllNodes;

        TTreeNode* mSelectedNode = nullptr;

    public:
        void AddNode(TTreeNode* pNode);
        void Replace(TTreeNode* pNode);
        void RemoveNode(const std::string& id);
        TTreeNode* GetNode(const std::string& id);

        struct TClickEvent
        {
            TTreeNode* pNode = nullptr;// maybe null
            //TEventType::MouseButtonType mouseButtonType;
            //TEventType::ButtonStateType buttonStateType;
        };

        using EventCallback = TCallbackPool<TTreeNode*>;
        using ClickEventCallback = TCallbackPool<const TClickEvent&>;

        using OnDragEvent = std::function<bool(TTreeNode*)>;
        using OnDropEvent = std::function<bool(TTreeNode*, TTreeNode*)>;

        EventCallback onSelectionEvent;
        ClickEventCallback onClickEvent;

        TTreeNode* GetSelectedNode() const;
    private:
        TTreeNode* FoundNode(const std::string& id);
        void OnSelection(TTreeNode* pSelectedNode);
        void OnClicked(TTreeNode* pSelectedNode);
    };
}
