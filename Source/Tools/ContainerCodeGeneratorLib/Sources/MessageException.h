/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <exception>

#include <TypeDef.h>

namespace nsContainerCodeGenerator
{
    class DllExport TMessageException : public std::exception
    {
        std::string mWhat;

    public:
        TMessageException(const std::string& what, const char* fileName, int line);

        const char* what() const noexcept;
    };

#define MSG_EXCEPTION(what) TMessageException(what, __FILE__, __LINE__)

}