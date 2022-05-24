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

#include "Texture.h"

namespace nsImGuiWidgets
{
    class DllExport TNode : public TWidget, public TWidgetContainer
    {
    protected:
        void* mTextureId = nullptr;
        int mWidth = 0;
        int mHeight = 0;

        nsGraphicEngine::TTexture* mTexture = nullptr;

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

        void SetTexture(void* textureId, int width, int height);
    };
}
