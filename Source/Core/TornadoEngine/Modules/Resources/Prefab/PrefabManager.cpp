/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Common/ObjectHelper.h"
#include "Modules/Resources/Prefab/PrefabManager.h"

#include "Generated files/TornadoEngineJsonSerializer.h"

namespace nsTornadoEngine
{
    TGameObject TPrefabManager::Instantiate(TInstantiatePrefabParams&& instantiatePrefabParams)
    {
        if (instantiatePrefabParams.absPath.empty()) {
            // Convert to abs path
            auto absPath = GetAbsPath(instantiatePrefabParams.guid);
            if (absPath.empty()) {
                nsTornadoEngine::Modules()->Log()->AddWarningEvent("Guid \"{}\" not exists", instantiatePrefabParams.guid);
                return {};
            }

            instantiatePrefabParams.absPath = absPath;
        }

        //instantiatePrefabParams.absPath
        std::string fileContent;

        TPrefabResourceContent prefabResourceContent;

        std::string err;
        auto deserializeResult = TTornadoEngineJsonSerializer::Deserialize(&prefabResourceContent, fileContent, err);

        if (!deserializeResult) {
            nsTornadoEngine::Modules()->Log()->AddWarningEvent("Prefab by abs path \"{}\" not exists", instantiatePrefabParams.absPath);
            return;
        }

        // Convert typeName to rtti
        std::list<nsECSFramework::TEntityID> newEntities;
        TObjectHelper::DeserializeObjects(newEntities, prefabResourceContent);

        SetupUniverse(newEntities, instantiatePrefabParams.sceneInstanceGuid, instantiatePrefabParams.parentGuid);
        return TGameObject();
    }
    //---------------------------------------------------------------------------------------------------------
    void TPrefabManager::SetSceneManager(TSceneManager* pSceneMng)
    {
        mSceneMng = pSceneMng;
    }
    //---------------------------------------------------------------------------------------------------------
    std::string TPrefabManager::Create(const std::string& absPath)
    {
        auto guid = TResourceManager::Create(absPath);

        TPrefabResourceContent prefabResourceContent;
        TResourceManager::Save(absPath, &prefabResourceContent);

        return guid;
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
    void TPrefabManager::Save(const std::string& instancePrefabGuid)
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
