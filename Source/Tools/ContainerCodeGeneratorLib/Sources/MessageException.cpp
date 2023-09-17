/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "MessageException.h"

namespace nsContainerCodeGenerator
{
    TMessageException::TMessageException(const std::string& what, const char* fileName, int line)
    {
        mWhat = fmt::format("{}, {}: {}", what, fileName, line);
    }
    //---------------------------------------------------------------------------------------------
    const char* TMessageException::what() const noexcept
    {
        return mWhat.c_str();
    }
    //---------------------------------------------------------------------------------------------
}