/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TTitle
    {
    public:
        void SetTitle(const std::string& str);
        std::string GetTitle() const;

    protected:
        std::string mTitle = "<Unknown>";
    };
}
