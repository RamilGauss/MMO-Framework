/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>
#include "TypeDef.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TPosition
    {
    public:
        void SetPosition(const ImVec2& value, bool withNotify = false);
        const ImVec2& GetPosition() const;

        TCallbackPool<> mOnPositionCB;

    private:
        ImVec2 mPosition = { 0, 0 };
    };
}
