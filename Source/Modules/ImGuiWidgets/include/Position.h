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
        void SetPos(const ImVec2& newPos);

        const ImVec2& GetPos() const;

        TCallbackPool<> mOnPositionCB;

    private:
        ImVec2 mPos = { 0, 0 };
    };
}
