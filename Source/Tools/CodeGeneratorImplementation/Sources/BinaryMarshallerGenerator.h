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
    class DllExport TBinaryMarshallerGenerator : public nsReflectionCodeGenerator::ITargetCodeGenerator
    {
    public:
        TBinaryMarshallerGenerator() : 
            nsReflectionCodeGenerator::ITargetCodeGenerator("BinaryMarshallerGenerator") {}

        void Work() override;

        void GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencies) override;
    private:
        void GenerateHeader();
        void GenerateSource();
    };
}
