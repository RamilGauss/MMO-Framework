/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/PathOperations.h"
#include "Base/Common/GuidGenerator.h"

#include "TornadoEngine/Modules/Resources/Common/ResourceManager.h"

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
        bool convertRes = nsBase::nsCommon::TPathOperations::GetRelativePath(mContentMapPath, absPath, relPath);

        auto newGuid = nsBase::nsCommon::TGuidGenerator::Generate();

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
            auto resourcesAbsPath = nsBase::nsCommon::TPathOperations::CalculatePathBy(mContentMapPath, guidPath.second);

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
        auto contentMapDirAbsPath = nsBase::nsCommon::TPathOperations::TPathOperations::FileDirPath(mContentMapPath);
        return nsBase::nsCommon::TPathOperations::CalculatePathBy(contentMapDirAbsPath, fit->second);
    }
    //------------------------------------------------------------------------------------
    void TResourceManager::Rename(const std::string& guid, const std::string& newAbsPath)
    {
        auto fit = mResourceContentMap.guidPathMap.find(guid);
        if (fit == mResourceContentMap.guidPathMap.end()) {
            return;
        }

        std::string relPath;
        bool convertRes = nsBase::nsCommon::TPathOperations::GetRelativePath(mContentMapPath, newAbsPath, relPath);

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

        nsBase::nsCommon::TTextFile::Load(srcAbsPath, content);
        nsBase::nsCommon::TTextFile::Save(dstAbsPath, content);
    }
    //------------------------------------------------------------------------------------
}
