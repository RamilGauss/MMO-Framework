/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BinaryMarshallerHeaderFileGenerator.h"
#include "fmt/core.h"
#include <set>

using namespace nsReflectionCodeGenerator;

void TBinaryMarshallerHeaderFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();

    AddStandartInclude("functional");
    AddInclude("ContainerRise.h");
    AddInclude("TypeDef.h");
    AddInclude("BinaryPushMaster.h");
    AddInclude("BinaryPopMaster.h");
    AddInclude("MemoryObjectPoolAllocator.h");
    AddInclude("BL_Debug.h");
    AddInclude("lz4.h");

    AddEmptyLine();
    AddInclude(mConfig->targetForCodeGeneration.includeListFileName + ".h");
    AddEmptyLine();

    auto namespaceName = mBinaryMarshaller->nameSpaceName;
    if ( namespaceName.length() ) {
        AddNamespaceBegin(namespaceName);
        IncrementTabs();
    }

    AddClassBegin(mBinaryMarshaller->exportDeclaration, mBinaryMarshaller->className);

    AddList(s_BinaryDeclBeforeEnum);

    AddEnums();

    AddList(s_BinaryDeclAfterEnum_BeforeTypesDecl);

    AddDeclarations();

    AddClassEnd();

    AddList(s_BinaryImpl);

    if ( namespaceName.length() ) {
        DecrementTabs();
        AddNamespaceEnd();
    }
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerHeaderFileGenerator::AddDeclarations()
{
    IncrementTabs();
    for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
        auto namespaceName = namespaceTypeInfo.first;
        auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
        for ( auto filenameType : filenameTypeMap ) {
            auto p = filenameType.second.get();
            auto typeWithNamespace = p->GetTypeNameWithNameSpace();
            auto serMethod = fmt::format("{} {}( {}* p );", s_Void, s_Serialize, typeWithNamespace);
            Add(serMethod);
            auto deserMethod = fmt::format("{} {}( {}* p );", s_Void, s_Deserialize, typeWithNamespace);
            Add(deserMethod);
            auto deser = fmt::format("{} {}( {}* p );", s_TypeID, s_GetTypeID, typeWithNamespace);
            Add(deser);
            std::list<std::string> paramList = { fmt::format("{}* p", typeWithNamespace) };
            AddStaticMethodDeclaration(s_Void, s_Deallocate, paramList);
            AddEmptyLine();
        }
    }
    DecrementTabs();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerHeaderFileGenerator::AddEnums()
{
    IncrementTabs();
    IncrementTabs();

    std::set<std::string> sortedTypeNameSet;
    for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap ) {
        auto namespaceName = namespaceTypeInfo.first;
        auto& filenameTypeMap = *(namespaceTypeInfo.second.get());
        for ( auto filenameType : filenameTypeMap ) {
            auto p = filenameType.second.get();
            sortedTypeNameSet.insert(MakeEnumName(p));
        }
    }

    int i = 0;
    std::string sEnum;
    for ( auto& enumName : sortedTypeNameSet ) {
        if ( i != 0 )
            sEnum = fmt::format("{},", enumName);
        else
            sEnum = fmt::format("{} = {},", enumName, mBinaryMarshaller->beginID);
        Add(sEnum);
        i++;
    }
    DecrementTabs();
    DecrementTabs();
}
//-------------------------------------------------------------------------------------
