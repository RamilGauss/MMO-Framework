/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/ITargetCodeGenerator.h"

namespace nsCodeGeneratorImplementation
{
    class DllExport TDynamicCasterGenerator : public nsReflectionCodeGenerator::ITargetCodeGenerator
    {
    public:
        TDynamicCasterGenerator() :
            nsReflectionCodeGenerator::ITargetCodeGenerator("DynamicCaster"){}

        void Work() override;
        void GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencyNames) override;
    private:
        void GenerateHeader();
        void GenerateSource();
    };
}


