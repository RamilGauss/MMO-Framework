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
    class DllExport TInputTextValue
    {
    public:
        std::string GetInputTextValue() const;
        void SetInputTextValue(const std::string& str);
    private:
        std::string mInputTextValue;
    };
}
