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

        virtual void SetSpacing(int value);

        virtual int GetSpacing() const;
    protected:
        int mSpacing = 0;
    };
}
