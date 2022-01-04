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
    class DllExport TGeometry
    {
    public:
        void SetPos(const ImVec2& newPos);
        void SetSize(const ImVec2& newSize);

        const ImVec2& GetPos();
        const ImVec2& GetSize();

        TCallbackPool<> mOnPositionCB;
        TCallbackPool<> mOnSizeCB;

    private:
        ImVec2 mPos;
        ImVec2 mSize;
    };
}
