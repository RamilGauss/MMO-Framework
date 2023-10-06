/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabManager.h"

namespace nsTornadoEngine
{
    TGameObject TPrefabManager::Instantiate(const TInstantiatePrefabParams& instantiatePrefabParams)
    {
        return {};
    }
    //---------------------------------------------------------------------------------------------------------
    void TPrefabManager::SetSceneManager(TSceneManager* pSceneMng)
    {
        mSceneMng = pSceneMng;
    }
    //---------------------------------------------------------------------------------------------------------
    std::string TPrefabManager::Create(const std::string& absPath)
    {
        return {};
    }
    //--------------------------------------------------------------------------------------------------------
    void TPrefabManager::Destroy(nsECSFramework::TEntityID anyEidInScene)
    {

    }
    //---------------------------------------------------------------------------------------------------------
    void TPrefabManager::Destroy(const std::string& prefabInstanceGuid)
    {

    }
    //---------------------------------------------------------------------------------------------------------
    void TPrefabManager::Save(const std::string& prefabGuid)
    {

    }
    //---------------------------------------------------------------------------------------------------------
    void TPrefabManager::InstantiateEntities(const std::list<nsECSFramework::TEntityID>& newEntities,
        const std::string& sceneInstanceGuid, const std::string& parentGuid)
    {

    }
    //---------------------------------------------------------------------------------------------------------
    void TPrefabManager::SetupUniverse(const std::list<nsECSFramework::TEntityID>& newEntities,
        const std::string& sceneInstanceGuid, const std::string& parentGuid)
    {

    }
    //---------------------------------------------------------------------------------------------------------
}
