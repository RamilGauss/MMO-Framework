/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ReflectionHeaderFileGenerator.h"
#include <set>

using namespace nsReflectionCodeGenerator;

void TReflectionHeaderFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddStandartInclude("string");
    AddStandartInclude("map");
    AddStandartInclude("functional");

    AddInclude(mConfig->targetForCodeGeneration.includeListFileName + ".h");
    AddEmptyLine();

    auto namespaceName = mReflectionConfig->nameSpaceName;
    if ( namespaceName.length() ) {
        AddNamespaceBegin(namespaceName);
        IncrementTabs();
    }

    AddClassBegin(mReflectionConfig->exportDeclaration, mReflectionConfig->className);

    AddList(s_Decl);

    AddClassEnd();

    DecrementTabs();

    AddNamespaceEnd();
}
//-----------------------------------------------------------------------------------