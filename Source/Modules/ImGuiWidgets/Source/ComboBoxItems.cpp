/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/ComboBoxItems.h"

using namespace nsImGuiWidgets;

void TComboBoxItems::SetItems(const std::vector<std::string>& items)
{
    mItems = items;
}
//----------------------------------------------------------------------------------------
const std::vector<std::string>& TComboBoxItems::GetItems() const
{
    return mItems;
}
//----------------------------------------------------------------------------------------
