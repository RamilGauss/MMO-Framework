/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IncludeListFileGenerator.h"

#include <filesystem>

namespace fs = std::filesystem;
using namespace nsCodeGeneratorImplementation;

void TIncludeListFileGenerator::Work()
{
    AddHeader(mResolvedConfig->header);
    if (mResolvedConfig->addTimeStamp) {
        AddTimeHeader();
    }

    AddPragmaOnce();
    AddEmptyLine();
    AddIncludes();
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::AddIncludes()
{
    for (auto& includeFile : *mHeaderSetPtr) {
        AddInclude(includeFile);
    }
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::SetIncludes(std::set<std::string>* headerSet)
{
    mHeaderSetPtr = headerSet;
}
//-----------------------------------------------------------------------------------
