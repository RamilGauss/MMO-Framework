/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ResourceManager.h"

#include "PathOperations.h"
#include "GuidGenerator.h"

namespace nsTornadoEngine
{
    void TResourceManager::SetContentMap(const std::string& contentMapPath)
    {
        mContentMapPath = contentMapPath;

        TResourceManager::Load(mContentMapPath, &mResourceContentMap);
    }
    //------------------------------------------------------------------------------------
    std::string TResourceManager::Create(const std::string& absPath)
    {
        std::string relPath;
        bool convertRes = nsBase::TPathOperations::GetRelativePath(mContentMapPath, absPath, relPath);

        auto newGuid = nsBase::TGuidGenerator::Generate();

        mResourceContentMap.guidPathMap.insert({ newGuid, relPath });

        TResourceManager::Save(mContentMapPath, &mResourceContentMap);

        return newGuid;
    }
    //------------------------------------------------------------------------------------
    void TResourceManager::Delete(const std::string& guid)
    {
        auto absPath = GetAbsPath(guid);

        mResourceContentMap.guidPathMap.erase(guid);
        TResourceManager::Save(mContentMapPath, &mResourceContentMap);

        std::remove(absPath.c_str());
    }
    //------------------------------------------------------------------------------------
    std::string TResourceManager::GetGuid(const std::string& absPath)
    {
        for (auto& guidPath : mResourceContentMap.guidPathMap) {
            auto resourcesAbsPath = nsBase::TPathOperations::CalculatePathBy(mContentMapPath, guidPath.second);

            if (absPath == resourcesAbsPath || absPath == guidPath.second) {
                return guidPath.first;
            }
        }

        return "";
    }
    //------------------------------------------------------------------------------------
    std::string TResourceManager::GetAbsPath(const std::string& guid)
    {
        auto fit = mResourceContentMap.guidPathMap.find(guid);
        if (fit == mResourceContentMap.guidPathMap.end()) {
            return "";
        }

        return nsBase::TPathOperations::CalculatePathBy(mContentMapPath, fit->second);
    }
    //------------------------------------------------------------------------------------
    void TResourceManager::Rename(const std::string& guid, const std::string& newAbsPath)
    {
        auto fit = mResourceContentMap.guidPathMap.find(guid);
        if (fit == mResourceContentMap.guidPathMap.end()) {
            return;
        }

        std::string relPath;
        bool convertRes = nsBase::TPathOperations::GetRelativePath(mContentMapPath, newAbsPath, relPath);

        fit->second = relPath;

        TResourceManager::Save(mContentMapPath, &mResourceContentMap);
    }
    //------------------------------------------------------------------------------------
    void TResourceManager::Copy(const std::string& srcGuid, const std::string& dstGuid)
    {
        auto srcAbsPath = GetAbsPath(srcGuid);
        auto dstAbsPath = GetAbsPath(dstGuid);

        if (srcAbsPath.empty() || dstAbsPath.empty()) {
            return;
        }

        std::string content;

        TTextFile::Load(srcAbsPath, content);
        TTextFile::Save(dstAbsPath, content);
    }
    //------------------------------------------------------------------------------------
}
