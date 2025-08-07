/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EcsComponentExtensionHeaderFileGenerator.h"

#include <set>

#include "CodeGeneratorImplementation/Constants.h"

using namespace nsCodeGeneratorImplementation;

void TEcsComponentExtensionHeaderFileGenerator::Work()
{
    AddHeader(mResolvedConfig->header);
    AddProgramInfo();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("string");
    AddStandartInclude("map");
    AddStandartInclude("functional");
    AddInclude("Base/Common/TypeDef.h");

    auto fit = mSerializer->keyValueMap.find(TConstants::s_EntityManagerHeaderPath);
    std::string entityManagerHeaderPath = "EntityManager.h";
    if (fit != mSerializer->keyValueMap.end()) {
        entityManagerHeaderPath = fit->second;
    }
    AddInclude(entityManagerHeaderPath);

    AddInclude(mResolvedConfig->includeFileForInclude + ".h");
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
