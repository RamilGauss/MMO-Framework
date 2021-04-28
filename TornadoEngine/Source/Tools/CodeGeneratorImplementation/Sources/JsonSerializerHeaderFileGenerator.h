/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"
#include "fmt/core.h"

namespace nsCodeGeneratorImplementation
{
    class TJsonSerializerHeaderFileGenerator : public TJsonSerializerFileGenerator
    {
        const std::list<std::string> GetJsonDecl();
        const std::list<std::string> GetJsonImpl();

    public:
        virtual void Work() override;

    private:
        void AddDeclarations();

        void AddSerializeMethodDeclaration(std::string& namespaceWithType);
        void AddDeserializeMethodDeclaration(std::string& namespaceWithType);
    };
}

