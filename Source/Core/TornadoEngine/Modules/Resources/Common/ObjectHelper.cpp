/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Common/ObjectHelper.h"

#include "Base/Common/HiTimer.h"//###
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"

#include "Generated files/TornadoEngineJsonSerializer.h"
#include "Modules/Common/Modules.h"
#include "TimeSliceEngine/TimeSliceEngine.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"
#include "Components/Meta/UniverseGuidComponent.h"
#include "ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsTornadoEngine
{
    void TObjectHelper::DeserializeObjects(nsECSFramework::TEntityManager* entMng,
        std::list<nsECSFramework::TEntityID>& newEntities,
        std::list<TEntityContent>::const_iterator& entIt, int count)
    {
        auto componentReflection = Project()->mScenePartAggregator->mComponents;
        auto reflectionEntMng = componentReflection->mEntMng->GetEntityManager();

        componentReflection->mEntMng->SetEntityManager(entMng);

        // Convert typeName to rtti
        for (int i = 0; i < count; i++, entIt++) {
            // Add entity
            auto eid = entMng->CreateEntity();
            newEntities.push_back(eid);

            for (auto& component : entIt->components) {
                componentReflection->mEntMng->SetComponent(eid, component.rtti, component.p);
            }
        }
        componentReflection->mEntMng->SetEntityManager(reflectionEntMng);
    }
    //------------------------------------------------------------------------------------------------------
}
