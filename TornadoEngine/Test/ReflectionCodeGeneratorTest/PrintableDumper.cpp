/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "PrintableDumper.h"

#include <fmt/core.h>

void TPrintableDumper::Save(const std::string& absFileName, std::list<std::string>& content)
{
    fmt::print("file: \"{}\"\n", absFileName);
    for (auto& str : content) {
        fmt::print("{}\n", str);
    }
}
