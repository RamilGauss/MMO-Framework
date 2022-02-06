/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"
#include <ECS/include/EntityManager.h>

#include "ResourceContentMap.h"
#include "ResourceContent.h"
#include "GuidConstants.h"

#include "GuidGenerator.h"
#include "ParentGuidComponent.h"
#include "GuidComponent.h"

namespace nsTornadoEngine
{
    class DllExport TObjectManager
    {
    protected:
        nsECSFramework::TEntityManager* mEntityManager = nullptr;
        TResourceContentMap mResourceContentMap;
    public:

        void SetContentMap(const TResourceContentMap& resourceContentMap);
        virtual void SetEntityManager(nsECSFramework::TEntityManager* entMng);

        // Каскадное уничтожение детей, только для редактирования префабов и сцен
        // доступ только в редакторе!
        void DestroyObject(const std::string& guid);

    protected:
        bool Deserialize(TResourceContent& content, const std::string& absPath);

        void DeserializeObjects(std::list<nsECSFramework::TEntityID>& newEntities, const TResourceContent& content);

        template <typename Component>
        void AddComponent(std::list<nsECSFramework::TEntityID>& newEntities, Component* pComponent);

        template <typename OriginalGuidType, typename InstanceGuidType>
        void UpdateGuidsAndInstantiate(const std::list<nsECSFramework::TEntityID>& newEntities,
            const std::string& instanceGuid);
    };
    //--------------------------------------------------------------------------------
    template <typename Component>
    void TObjectManager::AddComponent(std::list<nsECSFramework::TEntityID>& newEntities, Component* pComponent)
    {
        auto copyComponent = *pComponent;
        for (auto& eid : newEntities) {
            mEntityManager->SetComponent(eid, copyComponent);
        }
    }
    //--------------------------------------------------------------------------------
    template <typename OriginalGuidType, typename InstanceGuidType>
    void TObjectManager::UpdateGuidsAndInstantiate(const std::list<nsECSFramework::TEntityID>& newEntities,
        const std::string& instanceGuid)
    {
        for (auto& eid : newEntities) {
            auto pGuidComponent = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(eid);
            if (pGuidComponent == nullptr) {
                continue;
            }
            auto guidComponent = *pGuidComponent;

            auto newGuid = TGuidGenerator::Generate();

            nsCommonWrapper::TParentGuidComponent parentGuidComponent;
            parentGuidComponent.value = guidComponent.value;
            auto copyChildEids = mEntityManager->GetByValueCopy<nsCommonWrapper::TParentGuidComponent>(parentGuidComponent);
            for (auto& childEid : copyChildEids) {
                parentGuidComponent.value = newGuid;
                mEntityManager->SetComponent(childEid, parentGuidComponent);
            }

            OriginalGuidType originalGuid;
            originalGuid.value = guidComponent.value;
            mEntityManager->SetComponent(eid, originalGuid);

            guidComponent.value = newGuid;
            mEntityManager->SetComponent(eid, guidComponent);

            InstanceGuidType instanceGuidComponent;
            instanceGuidComponent.value = instanceGuid;
            mEntityManager->SetComponent(eid, instanceGuidComponent);
        }
    }
    //--------------------------------------------------------------------------------
}