/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MessageException.h"

namespace nsContainerCodeGenerator
{
    TMessageException::TMessageException(const std::string& what)
    {
        mWhat = what;
    }
    //---------------------------------------------------------------------------------------------
    const char* TMessageException::what() const noexcept
    {
        return mWhat.c_str();
    }
    //---------------------------------------------------------------------------------------------
}