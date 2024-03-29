/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <limits>
#include "imgui.h"

#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TMaxSize
    {
    public:
        void SetMaxSize(const ImVec2& value);
        ImVec2 GetMaxSize() const;
    protected:
        ImVec2 mValue = { (float)std::numeric_limits<int>::max(), (float)std::numeric_limits<int>::max() };
    };
}
