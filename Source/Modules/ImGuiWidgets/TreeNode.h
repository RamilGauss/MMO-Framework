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

#include "CallbackPool.h"
#include "Widget.h"

namespace nsImGuiWidgets
{
    class TTreeView;

    class DllExport TTreeNode : public TWidget
    {
        std::list<TTreeNode*> mNodes;
        bool mSelected = false;
    public:
        std::string mId;
        std::string mParentId;
        std::string mLabel;
        std::string mUserData;

        using EventCallback = TCallbackPool<TTreeNode*>;

        EventCallback onSelection;
        EventCallback onClicked;

        void Render() override;
        void AddNode(TTreeNode* pNode);
    private:
        void SearchEvents();
    };
}
