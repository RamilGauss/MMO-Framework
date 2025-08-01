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
    AddHeader(mConfig->targetForCodeGeneration.header);
    AddTimeHeader();

    AddPragmaOnce();
    AddEmptyLine();
    AddIncludes();
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::AddIncludes()
{
    //const auto& sourceRootPath = mConfig->targetForCodeGeneration.sourceRootPath;
    //const auto& absPathAllFilesInDir = mCache->absPathAllFilesInDir;

    //for (auto& absFileName : *mHeaderSetPtr) {
    //    fs::path filePath(absFileName);
    //    if (absPathAllFilesInDir.contains(absFileName)) {

    //        fs::path dirPath(sourceRootPath);
    //        auto dirName = dirPath.filename();
    //        auto relativePath = fs::relative(absFileName, sourceRootPath);

    //        if (dirName.generic_string().size()) {
    //            dirName += fs::path::preferred_separator;
    //        }
    //        dirName += relativePath;

    //        AddInclude(dirName.generic_string());
    //    }
    //}
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::SetIncludes(std::set<std::string>* headerSet)
{
    mHeaderSetPtr = headerSet;
}
//-----------------------------------------------------------------------------------
