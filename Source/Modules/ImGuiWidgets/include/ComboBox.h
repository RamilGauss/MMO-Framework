/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "Unit.h"

namespace nsImGuiWidgets
{
    class DllExport TComboBox : public TUnit
    {
    protected:
        int mCurrentItemIndex = 0;
        std::vector<std::string> mItems;
        std::string* mCurrentItem = nullptr;
    public:

        int GetCurrent();
        void SetCurrent(int value);

        void SetItems(const std::vector<std::string>& items);
    protected:
        void RenderInheritance() override final;
    };
}
