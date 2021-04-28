/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IIncludeListGenerator.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TIncludeListGenerator : public IIncludeListGenerator
    {
        std::set<std::string> mHeaderSet;

    public:
        TIncludeListGenerator() : IIncludeListGenerator("IncludeListGenerator") {}

        void Work() override;

        void AddInclude(const std::string& header) override;
    };
}