/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabObjectConstructor.h"

#include "PrefabRootComponent.h"
#include "PrefabGuidComponent.h"
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

    auto newPrefabGuid = TGuidGenerator::Generate();

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

        guidComponent.value = newGuid;
        mEntityManager->SetComponent(eid, guidComponent);

        nsCommonWrapper::TPrefabGuidComponent prefabGuidComponent;
        prefabGuidComponent.value = newPrefabGuid;
        mEntityManager->SetComponent(eid, prefabGuidComponent);
    }

    return rootEid;
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::AttachByGuid(nsECSFramework::TEntityID prefabChildEid, const std::string& prefabGuid)
{
    // Convert to abs path
    auto fit = mResourceContentMap.guidPathMap.find(prefabGuid);
    if (fit == mResourceContentMap.guidPathMap.end()) {
        GetLogger()->Get(TTimeSliceEngine::NAME)->WriteF_time("Guid \"%s\" not exist", prefabGuid.c_str());
        return nsECSFramework::NONE;
    }

    return AttachByPath(prefabChildEid, fit->second);
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::AttachByPath(nsECSFramework::TEntityID prefabChildEid, const std::string& absPath)
{
    auto prefabRootEid = InstatiateByAbsPath(absPath);
    return Attach(prefabChildEid, prefabRootEid);
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::Attach(TEntityID prefabChildEid, TEntityID prefabRootEid)
{
    auto parentGuid = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(prefabChildEid)->value;
    auto parentPrefabGuid = mEntityManager->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(prefabChildEid)->value;

    nsCommonWrapper::TParentGuidComponent parentGuidComponent;
    parentGuidComponent.value = parentGuid;
    mEntityManager->SetComponent(prefabRootEid, parentGuidComponent);

    mEntityManager->RemoveComponent<nsCommonWrapper::TPrefabRootComponent>(prefabRootEid);

    auto pAttachedPrefabGuidComponent = mEntityManager->ViewComponent<nsCommonWrapper::TPrefabGuidComponent>(prefabRootEid);

    auto attachedPrefabGuidComponent = *pAttachedPrefabGuidComponent;

    auto attachedEids = mEntityManager->GetByValueCopy(attachedPrefabGuidComponent);

    nsCommonWrapper::TPrefabGuidComponent newPrefabGuidComponent;
    newPrefabGuidComponent.value = parentPrefabGuid;

    for (auto& attachedEid : attachedEids) {
        mEntityManager->SetComponent(attachedEid, newPrefabGuidComponent);
    }

    return true;
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
