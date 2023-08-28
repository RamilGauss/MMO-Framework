/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabManager.h"

namespace nsTornadoEngine
{
    TGameObject TPrefabManager::InstantiateByGuid(TInstantiatePrefabParams instantiatePrefabParams)
    {
        return {};
    }
    //---------------------------------------------------------------------------------------------------------
    TGameObject TPrefabManager::InstantiateByAbsPath(const TInstantiatePrefabParams& instantiatePrefabParams)
    {
        return {};
    }
    //---------------------------------------------------------------------------------------------------------
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
    void TPrefabManager::CreateEntity(TPrefabObjectConstructor* prefabObjConstructor,
        nsECSFramework::TEntityID eid, std::list<nsECSFramework::TEntityID>& newEntities)
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
