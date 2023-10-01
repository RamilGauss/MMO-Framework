/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneCacheManager.h"

namespace nsTornadoEngine
{
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
