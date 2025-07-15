/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/StringExtensions.h"


void TStringExtensions::TrimRight(std::string& str, const std::string& symbols)
{
    auto index = str.find_last_not_of(symbols);
    if (index == std::string::npos) {
        str.clear();
        return;
    }

    str.erase(index + 1, str.length() - index - 1);
}
//-----------------------------------------------------------------------------------------------
void TStringExtensions::TrimLeft(std::string& str, const std::string& symbols)
{
    auto index = str.find_first_not_of(symbols);
    if (index == std::string::npos) {
        str.clear();
        return;
    }

    str.erase(0, index);
}
//-----------------------------------------------------------------------------------------------