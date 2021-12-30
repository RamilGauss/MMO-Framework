/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabObjectConstructor.h"

#include "PrefabRootComponent.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "TextFile.h"
#include "HierarchyHelper.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;


void TPrefabObjectConstructor::Setup(const std::list<std::string>& libPathList)
{
    SetEntityManager(&mInnerEntityManager);

    mEntityManager->Setup(libPathList);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::InstatiateByGuid(const std::string& prefabGuid)
{
    // Convert to abs path
    auto fit = mResourceContentMap.guidPathMap.find(prefabGuid);
    if (fit == mResourceContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", prefabGuid.c_str());
        return nsECSFramework::NONE;
    }

    return InstatiateByAbsPath(fit->second);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::InstatiateByAbsPath(const std::string& absPath)
{
    using namespace nsCommonWrapper;

    TResourceContent prefabContent;
    auto deserializeResult = Deserialize(prefabContent, absPath);
    if (!deserializeResult) {
        return nsECSFramework::NONE;
    }

    // 2. Convert typeName to rtti
    std::list<nsECSFramework::TEntityID> newEntities;
    DeserializeObjects(newEntities, prefabContent);

    // 3. Search prefabInstance
    nsECSFramework::TEntityID rootEid = nsECSFramework::NONE;
    for (auto& entity : newEntities) {
        auto hasRoot = mEntityManager->HasComponent<TPrefabRootComponent>(entity);
        if (hasRoot) {
            rootEid = entity;
        }
    }

    return rootEid;
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::AttachByGuid(nsECSFramework::TEntityID prefabChildEid, const std::string& prefabGuid)
{
    return false;
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::AttachByPath(nsECSFramework::TEntityID prefabChildEid, const std::string& absPath)
{
    return false;
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::Attach(TEntityID prefabChildEid, TEntityID prefabRootEid)
{
    return false;
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::GetParent(nsECSFramework::TEntityID eid)
{
    return mHierarchyHelper.GetParent(eid);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetChilds(nsECSFramework::TEntityID eid)
{
    return mHierarchyHelper.GetChilds(eid);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::GetChildByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    return mHierarchyHelper.GetChildByName(eid, name);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::GetBrotherByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    return mHierarchyHelper.GetBrotherByName(eid, name);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetChildsByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    return mHierarchyHelper.GetChildsByName(eid, name);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetBrothersByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    return mHierarchyHelper.GetBrothersByName(eid, name);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetRoots()
{
    return mEntityManager->GetByHasCopy<nsCommonWrapper::TPrefabRootComponent>();
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityManager* TPrefabObjectConstructor::EntMng()
{ 
    return mEntityManager;
}
//-----------------------------------------------------------------------------------------------------
void TPrefabObjectConstructor::SetEntityManager(nsECSFramework::TEntityManager* entMng)
{
    TObjectManager::SetEntityManager(entMng);
    mHierarchyHelper.SetEntMng(entMng);
}
//-----------------------------------------------------------------------------------------------------
