/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "Base/Common/CallbackPool.h"

#include "ImGuiWidgets/Include/Unit.h"
#include "ImGuiWidgets/Include/CheckBoxValue.h"

namespace nsImGuiWidgets
{
    class DllExport TCheckBox : public TUnit, public TCheckBoxValue
    {
    public:
        using TCheckChange = TCallbackPool<bool>;
        TCheckChange mOnCheckChangeCB;

    protected:
        void RenderInheritance() override final;
    };
}
