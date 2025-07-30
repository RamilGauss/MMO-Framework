/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/ICodeGenerator.h"

namespace nsReflectionCodeGenerator
{
    class DllExport IIncludeListGenerator : public ICodeGenerator
    {
    public:
        IIncludeListGenerator(const std::string& name) : ICodeGenerator(name) {}

        virtual void AddInclude(const std::string& header) = 0;
    };
}