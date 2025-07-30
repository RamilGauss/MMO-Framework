/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/GuidGenerator.h"

#include "ECS/Include/EntityManager.h"

#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Meta/GuidComponent.h"

#include "TornadoEngine/Modules/Resources/Common/ResourceContentMap.h"
#include "TornadoEngine/Modules/Resources/Common/GuidConstants.h"
#include "TornadoEngine/Modules/Resources/Common/EntityContent.h"
#include "TornadoEngine/Modules/Resources/Common/ResourceManager.h"

namespace nsTornadoEngine
{
    class DllExport TObjectHelper
    {
    public:
        static void DeserializeObjects(nsECSFramework::TEntityManager* entMng,
            std::list<nsECSFramework::TEntityID>& newEntities,
            std::list<TEntityContent>::const_iterator& entIt, int count);

        template <typename Component>
        static void AddComponent(nsECSFramework::TEntityManager* entMng,
            const std::list<nsECSFramework::TEntityID>& newEntities,
            Component* pComponent);

        template <typename OriginalGuidType, typename InstanceGuidType>
        static void UpdateGuidsAndInstantiate(nsECSFramework::TEntityManager* entMng,
            const std::list<nsECSFramework::TEntityID>& newEntities,
            const std::string& instanceGuid);
    };
    //--------------------------------------------------------------------------------
    template <typename Component>
    void TObjectHelper::AddComponent(nsECSFramework::TEntityManager* entMng,
        const std::list<nsECSFramework::TEntityID>& newEntities, Component* pComponent)
    {
        auto copyComponent = *pComponent;
        for (auto& eid : newEntities) {
            entMng->SetComponent(eid, copyComponent);
        }
    }
    //--------------------------------------------------------------------------------
    template <typename OriginalGuidType, typename InstanceGuidType>
    void TObjectHelper::UpdateGuidsAndInstantiate(nsECSFramework::TEntityManager* entMng,
        const std::list<nsECSFramework::TEntityID>& newEntities,
        const std::string& instanceGuid)
    {
        for (auto& eid : newEntities) {
            auto pGuidComponent = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid);
            if (pGuidComponent == nullptr) {
                continue;
            }
            auto guidComponent = *pGuidComponent;

            auto newGuid = nsBase::nsCommon::TGuidGenerator::Generate();

            auto parentGuidComponent = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid);

            if (parentGuidComponent) {
                OriginalGuidType originalGuid;
                originalGuid.value = parentGuidComponent->value;
                auto copyParentEids = entMng->GetByValueCopy<OriginalGuidType>(originalGuid);
                for (auto& parentEid : copyParentEids) {
                    nsCommonWrapper::TParentGuidComponent newParentComponent;
                    newParentComponent.value = entMng->ViewComponent<nsCommonWrapper::TGuidComponent>(parentEid)->value;
                    entMng->SetComponent(eid, newParentComponent);
                }
            }

            OriginalGuidType originalGuid;
            originalGuid.value = guidComponent.value;
            entMng->SetComponent(eid, originalGuid);

            guidComponent.value = newGuid;
            entMng->SetComponent(eid, guidComponent);

            InstanceGuidType instanceGuidComponent;
            instanceGuidComponent.value = instanceGuid;
            entMng->SetComponent(eid, instanceGuidComponent);
        }
    }
    //--------------------------------------------------------------------------------
}
