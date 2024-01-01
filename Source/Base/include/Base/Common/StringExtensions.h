/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

class DllExport TStringExtensions
{
public:
    static void TrimRight(std::string& str, const std::string& symbols);
    static void TrimLeft(std::string& str, const std::string& symbols);
};