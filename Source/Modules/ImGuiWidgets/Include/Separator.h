/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ImGuiWidgets/Include/Widget.h"

namespace nsImGuiWidgets
{
    class DllExport TSeparator : public TWidget
    {
    protected:
        void Render() override final;
    };
}
