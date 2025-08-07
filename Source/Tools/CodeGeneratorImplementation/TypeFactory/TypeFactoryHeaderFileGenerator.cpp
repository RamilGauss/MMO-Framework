/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <set>

#include "TypeFactoryHeaderFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

void TTypeFactoryHeaderFileGenerator::Work()
{
    AddHeader(mResolvedConfig->header);
    AddProgramInfo();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("string");
    AddStandartInclude("vector");
    AddStandartInclude("functional");

    AddInclude("Base/Common/TypeDef.h");

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
