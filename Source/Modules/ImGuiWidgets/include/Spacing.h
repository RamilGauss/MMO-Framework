/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TSpacing
    {
    public:
        void SetSpacing(int value);
        int GetSpacing() const;
    protected:
        int mSpacing = 0;
    };
}
