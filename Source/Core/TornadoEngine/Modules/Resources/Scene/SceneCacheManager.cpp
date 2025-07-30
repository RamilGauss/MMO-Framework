/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/Resources/Scene/SceneCacheManager.h"

namespace nsTornadoEngine
{
    //-------------------------------------------------------------------------------
    void TSceneCacheManager::Add(const std::string& guid, TSceneResourceContentPtr ptr)
    {
        mScenes.insert({ guid, ptr });
    }
    //-------------------------------------------------------------------------------
    TSceneCacheManager::TSceneResourceContentPtr TSceneCacheManager::Get(const std::string& guid) const
    {
        auto fit = mScenes.find(guid);
        if (fit == mScenes.end()) {
            return nullptr;
        }
        return fit->second;
    }
    //-------------------------------------------------------------------------------
    void TSceneCacheManager::Remove(const std::string& guid)
    {
        mScenes.erase(guid);
    }
    //-------------------------------------------------------------------------------
    std::list<std::string> TSceneCacheManager::GetGuids() const
    {
        std::list<std::string> guids;
        for (auto scene : mScenes) {
            guids.push_back(scene.first);
        }

        return guids;
    }
    //-------------------------------------------------------------------------------
}
