/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>
#include "PathOperations.h"

using namespace nsBase;

std::string TPathOperations::CalculatePathBy(const std::string& abs, const std::string& absOrRel)
{
    auto absOrRelPath = std::filesystem::path(absOrRel);
    if (absOrRelPath.is_absolute()) {
        return absOrRel;
    }

    auto absPath = std::filesystem::path(abs);

    absPath += std::filesystem::path::preferred_separator;
    absPath += absOrRelPath;

    try {
        auto absByAbs = std::filesystem::absolute(absPath);
        return absByAbs.string();

    } catch (std::filesystem::filesystem_error err) {

    }
    return std::string();
}
//-----------------------------------------------------------------------
std::string TPathOperations::FileDirPath(const std::string& filePath)
{
    auto filePathPath = std::filesystem::path(filePath);
    if (filePathPath.empty()) {
        return filePath;
    }

    return filePathPath.remove_filename().string();
}
//-----------------------------------------------------------------------
std::string TPathOperations::GetCurrentDir()
{
    return std::filesystem::current_path().string();
}
//-----------------------------------------------------------------------