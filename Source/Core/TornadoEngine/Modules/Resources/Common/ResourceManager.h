/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/TextFile.h"

#include "ResourceContentMap.h"
#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "Modules/Common/Modules.h"

namespace nsTornadoEngine
{
    class DllExport TResourceManager
    {
        std::string mContentMapPath;
        TResourceContentMap mResourceContentMap;
    public:
        void SetContentMap(const std::string& contentMapPath);

        // Per one call
        std::string Create(const std::string& absPath);
        void Delete(const std::string& guid);
        std::string GetGuid(const std::string& absPath);
        std::string GetAbsPath(const std::string& guid);
        void Rename(const std::string& guid, const std::string& newAbsPath);
        void Copy(const std::string& srcGuid, const std::string& dstGuid);

    public:

        template <typename T>
        static bool Load(const std::string& absPath, T* p);

        template <typename T>
        static void Save(const std::string& absPath, T* p);
    };
    //---------------------------------------------------------------------------------------
    template <typename T>
    bool TResourceManager::Load(const std::string& absPath, T* p)
    {
        std::string jsonContent;
        nsBase::nsCommon::TTextFile::Load(absPath, jsonContent);
        if (jsonContent.length() == 0) {
            Modules()->Log()->AddWarningEvent("{} no such file", absPath);
            return false;
        }
        std::string err;
        auto deserResult = TTornadoEngineJsonSerializer::Deserialize(p, jsonContent, err);
        if (!deserResult) {
            Modules()->Log()->AddWarningEvent("{} {}", absPath, err);
        }
        return deserResult;
    }
    //---------------------------------------------------------------------------------------
    template <typename T>
    void TResourceManager::Save(const std::string& absPath, T* p)
    {
        std::string jsonContent;
        TTornadoEngineJsonSerializer::Serialize(p, jsonContent);
        nsBase::nsCommon::TTextFile::Save(absPath, jsonContent);
    }
    //---------------------------------------------------------------------------------------
}
