/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ICodeGenerator.h"

#include "Parser/Sources/TypeInfo.h"

namespace nsReflectionCodeGenerator
{
    class DllExport ITargetCodeGenerator : public ICodeGenerator
    {
    protected:
        TTypeNameDataBase mTypeNameDB;
    public:
        ITargetCodeGenerator(const std::string& name);

        virtual void GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencies) = 0;

        TSerializer* GetSerializer();
        bool HasSerializer();
        TTypeNameDataBase* GetTypeNameDB();
    };
}