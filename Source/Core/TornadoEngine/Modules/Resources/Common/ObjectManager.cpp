/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Common/ObjectManager.h"

#include "Base/Common/HiTimer.h"//###
#include "Base/Common/TextFile.h"
#include "Base/Common/Logger.h"

#include "Generated Files/TornadoEngineJsonSerializer.h"
#include "Modules/Common/Modules.h"
#include "TimeSliceEngine/TimeSliceEngine.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"
#include "Components/Meta/UniverseGuidComponent.h"
#include "ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsTornadoEngine
{
    //void TObjectManager::SetContentMap(const std::string& contentMapPath)
    //{
        //mResourceContentMap = resourceContentMap;
    //}
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
        //nsTornadoEngine::TEngineLogger::Log()
        //auto start = ht_GetUSCount();//###

        auto componentReflection = Project()->mScenePartAggregator->mComponents;

        // Convert typeName to rtti
        for (int i = 0; i < count; i++, entIt++) {
            // Add entity
            auto eid = mEntityManager->CreateEntity();
            newEntities.push_back(eid);

            for (auto& component : entIt->components) {
                componentReflection->mEntMng->SetComponent(eid, component.rtti, component.p);
            }
        }

        //###
        //int dt = ht_GetUSCount() - start;
        //logger->WriteF_time("sync load %d us\n", dt);
        //logger->ReOpen((char*)"1.log", true);
        //###
    }
    //------------------------------------------------------------------------------------------------------
}
