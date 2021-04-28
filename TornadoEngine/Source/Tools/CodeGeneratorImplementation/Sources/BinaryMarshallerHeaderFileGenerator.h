/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BinaryMarshallerFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TBinaryMarshallerHeaderFileGenerator : public TBinaryMarshallerFileGenerator
    {
        const std::string s_MemoryObjectPoolAllocator = "TMemoryObjectPoolAllocator";

        const std::list<std::string> GetBinaryDeclBeforeEnum();
        const std::list<std::string> GetBinaryDeclAfterEnum_BeforeTypesDecl();
        const std::list<std::string> GetBinaryImpl();
    public:
        virtual void Work() override;

    private:
        void AddDeclarations();
        void AddEnums();

    };
}

