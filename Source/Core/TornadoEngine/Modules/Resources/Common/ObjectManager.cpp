/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectManager.h"

#include "HiTimer.h"//###

#include "Modules.h"
#include "TornadoEngineJsonSerializer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TextFile.h"
#include "ProjectConfigContainer.h"
#include "UniverseGuidComponent.h"

namespace nsTornadoEngine
{
    void TObjectManager::SetContentMap(const std::string& contentMapPath)
    {
        //mResourceContentMap = resourceContentMap;
    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
    {
        mEntityManager = entMng;
    }
    //------------------------------------------------------------------------------------------------------
    std::string TObjectManager::Create(const std::string& absPath)
    {
        return {};
    }
    //--------------------------------------------------------------------------------------------------------
    void TObjectManager::Delete(const std::string& guid)
    {

    }
    //--------------------------------------------------------------------------------------------------------
    std::string TObjectManager::GetGuid(const std::string& absPath)
    {
        return {};
    }
    //--------------------------------------------------------------------------------------------------------
    std::string TObjectManager::GetAbsPath(const std::string& guid)
    {
        return {};
    }
    //--------------------------------------------------------------------------------------------------------
    void TObjectManager::Rename(const std::string& guid, const std::string& newAbsPath)
    {
        
    }
    //--------------------------------------------------------------------------------------------------------
    void TObjectManager::Copy(const std::string& srcGuid, const std::string& dstGuid)
    {
        
    }
    //--------------------------------------------------------------------------------------------------------
    void TObjectManager::DestroyObject(const std::string& guid)
    {

    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::DeserializeObjects(std::list<nsECSFramework::TEntityID>& newEntities,
        std::list<TEntityContent>::const_iterator& entIt, int count)
    {
        auto logger = GetLogger()->Get(TTimeSliceEngine::NAME);

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
