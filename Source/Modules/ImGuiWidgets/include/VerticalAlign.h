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
    struct DllExport TVerticalAlign
    {
    public:
        enum class Type
        {
            TOP,
            CENTER,
            BOTTOM,
        };

        void SetVerticalAlign(Type value);
        Type GetVerticalAlign() const;

    protected:
        Type mValue = Type::CENTER;
    };
}
