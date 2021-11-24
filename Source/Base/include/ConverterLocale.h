/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ContainerTypes.h"
#include <string>

class DllExport TConverterLocale
{
public:
    [[nodiscard]]
    static TContainer ConvertUtf8ToCp1251(TContainer& utf8);
    [[nodiscard]]
    static std::wstring ConvertUtf8ToCp1251(std::string& utf8);
};

