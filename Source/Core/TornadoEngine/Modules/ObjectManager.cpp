/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectManager.h"

#include "Modules.h"
#include "TornadoEngineJsonSerializer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TextFile.h"
#include "ProjectConfigContainer.h"
#include "UniverseGuidComponent.h"

using namespace nsTornadoEngine;

void TObjectManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
{
    mEntityManager = entMng;
}
//--------------------------------------------------------------------------------
void TObjectManager::SetContentMap(const TResourceContentMap& resourceContentMap)
{
    mResourceContentMap = resourceContentMap;
}
//--------------------------------------------------------------------------------
void TObjectManager::DestroyObject(const std::string& guid)
{

}
//--------------------------------------------------------------------------------
bool TObjectManager::Deserialize(TResourceContent& content, const std::string& absPath)
{
    auto logger = GetLogger()->Get(TTimeSliceEngine::NAME);

    std::string json;
    TTextFile::Load(absPath, json);

    std::string err;
    auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&content, json, err);
    if (deserResult == false) {
        logger->WriteF_time("Deserialize error %s with %s", err.c_str(), absPath.c_str());
        return false;
    }

    return true;
}
//--------------------------------------------------------------------------------
void TObjectManager::DeserializeObjects(std::list<nsECSFramework::TEntityID>& newEntities, const TResourceContent& content)
{
    auto logger = GetLogger()->Get(TTimeSliceEngine::NAME);

    auto componentReflection = Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(mEntityManager);

    // Convert typeName to rtti
    for (auto& entity : content.entities) {
        // Add entity
        auto eid = mEntityManager->CreateEntity();
        newEntities.push_back(eid);

        for (auto& component : entity.components) {
            // Add component by rtti
            int rtti;
            auto convertResult = componentReflection->mTypeInfo->ConvertNameToType(component.typeName, rtti);
            if (convertResult == false) {
                logger->WriteF_time("Not converted typename \"%s\"", component.typeName);
                continue;
            }
            componentReflection->mEntMng->CreateComponent(eid, rtti, [&](void* pComponent)
            {
                // Deserialize component by rtti and json body
                std::string err;
                auto componentDeserialzieResult =
                    componentReflection->mJson->Deserialize(pComponent, component.jsonBody, rtti, err);

                if (!componentDeserialzieResult) {
                    logger->WriteF_time("Not converted typename \"%s\", err=%s", component.typeName.c_str(), err.c_str());
                }
            });
        }
    }
}
//--------------------------------------------------------------------------------
