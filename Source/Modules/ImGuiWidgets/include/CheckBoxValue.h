/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TCheckBoxValue
    {
        bool mValue = false;
    public:
        bool GetCheckBoxValue();
        void SetCheckBoxValue(bool value);
    };
}
