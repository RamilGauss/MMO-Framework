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
    struct DllExport THorizontalAlign
    {
    public:
        enum class Type
        {
            LEFT,
            CENTER,
            RIGHT,
        };

        virtual void SetAlign(Type value);
        virtual Type GetAlign() const;

    protected:
        Type mValue = Type::CENTER;
    };
}
