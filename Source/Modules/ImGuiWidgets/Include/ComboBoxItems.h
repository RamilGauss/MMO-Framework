/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <string>

#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TComboBoxItems
    {
        std::vector<std::string> mItems;
    public:
        void SetItems(const std::vector<std::string>& items);
        const std::vector<std::string>& GetItems() const;
    };
}
