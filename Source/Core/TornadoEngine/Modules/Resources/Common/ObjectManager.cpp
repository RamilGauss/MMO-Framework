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

namespace nsTornadoEngine
{
    void TObjectManager::SetContentMap(const TResourceContentMap& resourceContentMap)
    {
        mResourceContentMap = resourceContentMap;
    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
    {
        mEntityManager = entMng;
    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::DestroyObject(const std::string& guid)
    {

    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::DeserializeObjects(std::list<nsECSFramework::TEntityID>& newEntities,
        std::list<TEntityContent>::const_iterator& entIt, int count)
    {
        auto logger = GetLogger()->Get(TTimeSliceEngine::NAME);

        auto componentReflection = Project()->mScenePartAggregator->mComponents;

        // Convert typeName to rtti
        for (int i = 0; i < count; i++, entIt++) {
            // Add entity
            auto eid = mEntityManager->CreateEntity();
            newEntities.push_back(eid);

            for (auto& component : entIt->components) {
                // Add component by rtti
                int rtti;
                auto convertResult = componentReflection->mTypeInfo->ConvertNameToType(component.typeName, rtti);
                if (convertResult == false) {
                    logger->WriteF_time("Not converted typename \"%s\"", component.typeName);
                    continue;
                }

                auto pComponent = componentReflection->mTypeFactory->New(rtti);

                // Deserialize component by rtti and json body
                std::string err;
                auto componentDeserialzieResult =
                    componentReflection->mJson->Deserialize(pComponent, component.jsonBody, rtti, err);

                if (!componentDeserialzieResult) {
                    logger->WriteF_time("Not converted typename \"%s\", err=%s", component.typeName.c_str(), err.c_str());
                }

                componentReflection->mEntMng->SetComponent(eid, rtti, pComponent);

                componentReflection->mTypeFactory->Delete(pComponent);
            }
        }
    }
    //------------------------------------------------------------------------------------------------------
}
