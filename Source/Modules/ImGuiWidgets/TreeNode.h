/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <functional>

#include "imgui.h"
#include "Typedef.h"

#include "Node.h"
#include "InputText.h"

namespace nsImGuiWidgets
{
    class TTreeView;

    class DllExport TTreeNode : public TNode
    {
        bool mEditProcessong = false;
        bool mBeginEditProcessing = false;

        TInputText mInputText;

        TTreeView* mTreeView = nullptr;

        bool mIsOpen = false;

    public:
        TTreeNode();
        ~TTreeNode();

        void Render() override;

        void SetEdit(bool value);

        using CallbackOnEndEditEvent = TCallbackPool<TTreeNode*, const std::string&>;
        CallbackOnEndEditEvent mOnEndEditEventCB;


        void SetTreeView(TTreeView* treeView);
        TTreeView* GetTreeView() const;

    private:
        void SearchEvents();

        void EndEditing();
    };
}
