/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <unordered_set>

#include "ReflectionCodeGeneratorLib/Sources/IFileGenerator.h"

namespace nsCodeGeneratorImplementation
{
    class TIncludeListFileGenerator : public nsReflectionCodeGenerator::IFileGenerator
    {
        std::set<std::string>* mHeaderSetPtr = nullptr;
    public:
        void SetIncludes(std::set<std::string>* headerSet);

        virtual void Work() override;

    private:
        void AddIncludes();
    };
}