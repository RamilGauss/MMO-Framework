/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "Widget.h"

namespace nsImGuiWidgets
{
    class DllExport TComboBox : public TWidget
    {
    protected:
        int mCurrentItemIndex = 0;
        std::vector<std::string> mItems = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO", "PPPP", "QQQQQQQQQQ", "RRR", "SSSS"};
        std::string* mCurrentItem = nullptr;
    public:
        TComboBox(const std::string& name);

        int GetCurrent();
        void SetCurrent(int value);

        void SetItems(std::vector<std::string>& items);
    protected:
        void RenderInheritance() override final;
    };
}
