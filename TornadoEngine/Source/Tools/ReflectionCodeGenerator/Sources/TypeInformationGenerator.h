/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITargetCodeGenerator.h"

namespace nsReflectionCodeGenerator
{
    class TTypeInformationGenerator : public ITargetCodeGenerator
    {
    public:
        TTypeInformationGenerator() : ITargetCodeGenerator("TypeInformationGenerator") {}

        void Work() override;

        void GetDependencies(const nsCppParser::TTypeInfo* typeName, std::list<std::string>& dependencyNames) override {}
        TSerializer* GetSerializer() override;
    private:

        void GenerateHeader();
        void GenerateSource();
    };
}


