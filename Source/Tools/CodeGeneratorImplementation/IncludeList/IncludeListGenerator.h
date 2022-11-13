/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IIncludeListGenerator.h"

namespace nsCodeGeneratorImplementation
{
    class DllExport TIncludeListGenerator : public nsReflectionCodeGenerator::IIncludeListGenerator
    {
        std::set<std::string> mHeaderSet;

    public:
        TIncludeListGenerator() : nsReflectionCodeGenerator::IIncludeListGenerator("IncludeListGenerator") {}

        void Work() override;

        void AddInclude(const std::string& header) override;
    };
}