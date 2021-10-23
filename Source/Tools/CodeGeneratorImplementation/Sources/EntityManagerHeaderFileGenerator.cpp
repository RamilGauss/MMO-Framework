/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EntityManagerHeaderFileGenerator.h"
#include <set>

using namespace nsCodeGeneratorImplementation;

void TEntityManagerHeaderFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("string");
    AddStandartInclude("map");
    AddStandartInclude("functional");
    AddInclude("TypeDef.h");

    auto fit = mSerializer->keyValueMap.find(s_EntityManagerHeaderPath);
    std::string entityManagerHeaderPath = "EntityManager.h";
    if (fit != mSerializer->keyValueMap.end()) {
        entityManagerHeaderPath = mSerializer->keyValueMap[s_EntityManagerHeaderPath];
        AddStandartInclude(entityManagerHeaderPath);
    } else {
        AddInclude(entityManagerHeaderPath);
    }

    AddInclude(mConfig->targetForCodeGeneration.includeListFileName + ".h");
    AddEmptyLine();

    auto namespaceName = mSerializer->nameSpaceName;
    if ( namespaceName.length() ) {
        AddNamespaceBegin(namespaceName);
        IncrementTabs();
    }

    AddClassBegin(mSerializer->exportDeclaration, mSerializer->className);

    AddList(s_Decl);

    AddClassEnd();

    DecrementTabs();

    AddNamespaceEnd();
}
//-----------------------------------------------------------------------------------
