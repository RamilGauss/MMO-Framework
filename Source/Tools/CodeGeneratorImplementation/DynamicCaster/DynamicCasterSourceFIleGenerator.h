/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <functional>
#include <list>
#include <set>

#include "DynamicCasterFileGenerator.h"

namespace nsCodeGeneratorImplementation
{
    class TDynamicCasterSourceFileGenerator : public TDynamicCasterFileGenerator
    {
    public:
        virtual void Work() override;

    private:
        void AddImplementations();

        void AddInit();

        void AddMethodDeinitions();
    private:
        struct TPair
        {
            nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo srcType;
            std::list<nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo> dstTypes;
        };

        std::list<TPair> mTasks;

        std::map<std::string, std::list<nsCppParser::TTypeInfo*>> mChildsMap;

        void AddCasters();

        void PreparePairs();
        void GenerateByPairs();

        void CreateInheritanceGraph();

        void GetParents(const nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo& type, std::set<nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo>& parents);
        void GetChilds(const nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo& type, std::set<nsReflectionCodeGenerator::TTypeNameDataBase::TTypeInfo>& childs);
    };
}
