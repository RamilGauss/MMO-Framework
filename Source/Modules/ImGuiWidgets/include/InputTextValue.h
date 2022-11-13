/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TInputTextValue
    {
    public:
        virtual std::string GetText() const;
        virtual void SetText(const std::string& str);
    private:
        std::string mInputTextValue;
    };
}
