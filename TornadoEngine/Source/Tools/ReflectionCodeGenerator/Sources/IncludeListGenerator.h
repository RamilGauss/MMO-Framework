/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ICodeGenerator.h"

namespace nsReflectionCodeGenerator
{
    class TIncludeListGenerator : public ICodeGenerator
    {
        std::set<std::string> mHeaderSet;

    public:
        TIncludeListGenerator() : ICodeGenerator("IncludeListGenerator") {}

        void Work() override;

        void AddInclude(const std::string& header);
    };
}