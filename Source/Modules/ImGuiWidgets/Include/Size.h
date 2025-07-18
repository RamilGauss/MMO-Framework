/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>
#include "Base/Common/TypeDef.h"
#include "Base/Common/CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TSize
    {
    public:
        void SetSize(const ImVec2& value, bool withNotify = false);
        const ImVec2& GetSize() const;

        TCallbackPool<> mOnSizeCB;

    private:
        ImVec2 mSize = { 0, 0 };
    };
}
