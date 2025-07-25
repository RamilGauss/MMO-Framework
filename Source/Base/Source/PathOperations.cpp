/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>
#include <boost/filesystem.hpp>

#include "Base/Common/PathOperations.h"

using namespace nsBase::nsCommon;

namespace fs = std::filesystem;

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
template <typename DirectoryIterator>
void TPathOperations::AddAbsPathsByDirectory(const std::string& directory, const std::set<std::string>& extensions, std::list<std::string>& fileList)
{
    DirectoryIterator dirIt((char*)directory.c_str());

    for (auto& p : dirIt) {
        auto path = p.path();
        std::string ext = path.extension().string();
        if ((extensions.size() > 0) && 
            (extensions.find(ext) == extensions.end())) {
            continue;
        }
        auto str = std::filesystem::canonical(path).string();
        fileList.push_back(str);
    }
}
//---------------------------------------------------------------------------------------
void TPathOperations::AddAbsPathsByDirectory(const std::string& directory, const std::set<std::string>& extensions,
    std::list<std::string>& fileList, bool recursive)
{
    if (recursive) {
        AddAbsPathsByDirectory<fs::recursive_directory_iterator>(directory, extensions, fileList);
    } else {
        AddAbsPathsByDirectory<fs::directory_iterator>(directory, extensions, fileList);
    }
}
//---------------------------------------------------------------------------------------
bool TPathOperations::GetRelativePath(const std::string& absBase, const std::string& abs, std::string& rel)
{
    boost::filesystem::path parentPath(absBase);
    boost::filesystem::path childPath(abs);

    boost::system::error_code ec;
    boost::filesystem::path relativePath = boost::filesystem::relative(childPath, parentPath, ec);

    if (ec) {
        return false;
    }

    rel = relativePath.string();
    
    return true;
}
//---------------------------------------------------------------------------------------
