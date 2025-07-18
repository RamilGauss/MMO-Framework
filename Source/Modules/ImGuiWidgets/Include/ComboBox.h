/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "ImGuiWidgets/Include/Unit.h"
#include "ImGuiWidgets/Include/ComboBoxCurrentIndex.h"
#include "ImGuiWidgets/Include/ComboBoxItems.h"

namespace nsImGuiWidgets
{
    class DllExport TComboBox : public TUnit, public TComboBoxCurrentIndex, public TComboBoxItems
    {
    protected:
        void RenderInheritance() override final;
    };
}
