/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/CallbackPool.h"

#include "GraphicEngine/Texture.h"

#include "ImGuiWidgets/Include/Widget.h"
#include "ImGuiWidgets/Include/WidgetContainer.h"
#include "ImGuiWidgets/Include/TextureReference.h"
#include "ImGuiWidgets/Include/TextureSize.h"

namespace nsImGuiWidgets
{
    class DllExport TNode : public TWidget, public TWidgetContainer, public TTextureReference, public TTextureSize
    {
    public:
        std::string mStrId;
        std::string mParentId;
        std::string mUserData;

        SubType GetSubType() const override;

        bool mSelected = false;

        using Callback = TCallbackPool<TNode*>;

        Callback mOnSelectionCB;
        Callback mOnLeftClickCB;

        TNode();
    };
}
