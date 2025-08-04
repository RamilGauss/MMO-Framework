/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeInformationHeaderFileGenerator.h"
#include <set>

using namespace nsCodeGeneratorImplementation;

void TTypeInformationHeaderFileGenerator::Work()
{
    AddHeader(mResolvedConfig->header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("string");
    AddStandartInclude("unordered_map");
    AddStandartInclude("list");
    AddStandartInclude("vector");

    AddEmptyLine();
    AddInclude("Base/Common/TypeDef.h");
    AddInclude("Parser/Sources/TypeInfo.h");

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
