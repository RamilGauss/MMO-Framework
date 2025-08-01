/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Base/Common/HiTimer.h"//###
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"

#include "TornadoEngine/GeneratedFiles/TornadoEngineJsonSerializer.h"
#include "TornadoEngine/TimeSliceEngine/TimeSliceEngine.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/Components/Meta/UniverseGuidComponent.h"
#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"
#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/ObjectHelper.h"

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
