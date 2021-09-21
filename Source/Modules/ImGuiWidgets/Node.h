/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Widget.h"
#include "WidgetContainer.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TNode : public TWidget, public TWidgetContainer
    {
    public:
        std::string mStrId;
        std::string mParentId;
        std::string mUserData;

        SubType GetSubType() const override;

        bool mSelected = false;

        using EventCallback = TCallbackPool<TNode*>;

        EventCallback onSelection;
        EventCallback onLeftClick;

        TNode();
    };
}
