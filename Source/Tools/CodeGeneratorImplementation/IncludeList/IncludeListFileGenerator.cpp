/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IncludeListFileGenerator.h"

#include <set>
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
    const auto& dirToInclude = mConfig->targetForCodeGeneration.includeListParams.dirToInclude;

    std::map<std::string, TStrSet> dirFiles;
    for (auto dirTo : dirToInclude) {

        TStrSet fileList;
        CollectAbsPaths(dirTo, fileList);
        dirFiles.insert({ dirTo, fileList });
    }

    for (auto& absFileName : *mHeaderSetPtr) {

        fs::path filePath(absFileName);
        auto fileName = filePath.filename().string();

        bool hasFound = false;
        for (auto dirTo : dirToInclude) {
            for (auto& dirFile : dirFiles) {
                if (dirFile.second.find(absFileName) != dirFile.second.end()) {

                    fs::path dirPath(dirFile.first);
                    auto dirName = dirPath.filename();
                    auto relativePath = fs::relative(absFileName, dirFile.first);

                    if (dirName.generic_string().size()) {
                        dirName += fs::path::preferred_separator;
                    }
                    dirName += relativePath;
                    fileName = dirName.generic_string();

                    hasFound = true;
                    break;
                }
            }
            if (hasFound) {
                break;
            }
        }

        AddInclude(fileName);
    }
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::SetIncludes(std::set<std::string>* headerSet)
{
    mHeaderSetPtr = headerSet;
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::CollectAbsPaths(const std::string& dir, TStrSet& fileList)
{
    TStrSet extSet(mConfig->filter.extensions.begin(), mConfig->filter.extensions.end());

    fs::recursive_directory_iterator dirIt((char*)dir.data());

    for (auto& p : dirIt) {
        auto path = p.path();
        std::string ext = path.extension().string();
        if (extSet.find(ext) == extSet.end()) {
            continue;
        }
        auto str = std::filesystem::canonical(path).string();
        fileList.insert(str);
    }
}
//---------------------------------------------------------------------------------------