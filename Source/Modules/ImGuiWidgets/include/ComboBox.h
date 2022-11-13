/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "Unit.h"
#include "ComboBoxCurrentIndex.h"

namespace nsImGuiWidgets
{
    //TComboBoxItems{std::vector<std::string>};
    //TComboBoxItemCurrentIndex{int};

    class DllExport TComboBox : public TUnit, public TComboBoxCurrentIndex
    {
    protected:
        std::vector<std::string> mItems;
        std::string* mCurrentItem = nullptr;
    public:
        void SetItems(const std::vector<std::string>& items);
    protected:
        void RenderInheritance() override final;
    };
}
