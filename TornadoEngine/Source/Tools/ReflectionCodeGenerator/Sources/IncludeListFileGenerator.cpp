/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IncludeListFileGenerator.h"
#include <set>

using namespace nsReflectionCodeGenerator;

void TIncludeListFileGenerator::Work()
{
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddIncludes();
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::AddIncludes()
{
    for (auto& fileName : *mHeaderSetPtr) {
        AddInclude(fileName);
    }
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::SetIncludes(std::set<std::string>* headerSet)
{
    mHeaderSetPtr = headerSet;
}
//-----------------------------------------------------------------------------------