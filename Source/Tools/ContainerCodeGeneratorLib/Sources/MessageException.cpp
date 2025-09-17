/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <sstream>
#include <boost/stacktrace/stacktrace.hpp>
#include <fmt/core.h>

#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

namespace nsContainerCodeGenerator
{
    TMessageException::TMessageException(const std::string& what)
    {
        std::ostringstream ss;
        boost::stacktrace::stacktrace stacktrace;
        ss << stacktrace;
        mWhat = fmt::format("{}:\n{}", what, ss.str());
    }
    //---------------------------------------------------------------------------------------------
    const char* TMessageException::what() const noexcept
    {
        return mWhat.c_str();
    }
    //---------------------------------------------------------------------------------------------
}
