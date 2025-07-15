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
#include "GameObject.h"

using namespace nsTornadoEngine;
using namespace nsECSFramework;

TPrefabObjectConstructor::TPrefabObjectConstructor() :
    mInnerEntityManager("PrefabObjectConstructor")
{

}
//-----------------------------------------------------------------------------------------------------
void TPrefabObjectConstructor::Setup(const std::list<std::string>& libPathList) 
{
    SetEntityManager(&mInnerEntityManager);

    mEntityManager->Setup(libPathList);
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::InstantiateByGuid(const std::string& prefabGuid)
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

    auto newPrefabGuid = nsBase::TGuidGenerator::Generate();

    for (auto& eid : newEntities) {
        auto pGuidComponent = mEntityManager->ViewComponent<nsCommonWrapper::TGuidComponent>(eid);
        if (pGuidComponent == nullptr) {
            continue;
        }
        auto guidComponent = *pGuidComponent;

        auto newGuid = nsBase::TGuidGenerator::Generate();

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
    TGameObject go(eid);
    go.SetEntityManager(&mInnerEntityManager);

    return go.GetParent().GetEid();
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetChilds(nsECSFramework::TEntityID eid)
{
    TGameObject go(eid);
    go.SetEntityManager(&mInnerEntityManager);

    nsECSFramework::TEntityList eids;
    go.GetChilds(eids);
    return eids;
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::GetChildByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    TGameObject go(eid);
    go.SetEntityManager(&mInnerEntityManager);

    return go.GetChildByName(name).GetEid();
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::GetBrotherByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    TGameObject go(eid);
    go.SetEntityManager(&mInnerEntityManager);

    return go.GetBrotherByName(name).GetEid();
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetChildsByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    TGameObject go(eid);
    go.SetEntityManager(&mInnerEntityManager);

    nsECSFramework::TEntityList eids;
    auto childs = go.GetChildsByName(name);
    for (auto& child : childs) {
        eids.push_back(child.GetEid());
    }

    return eids;
}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityList TPrefabObjectConstructor::GetBrothersByName(nsECSFramework::TEntityID eid, const std::string& name)
{
    TGameObject go(eid);
    go.SetEntityManager(&mInnerEntityManager);

    nsECSFramework::TEntityList eids;
    auto brothers = go.GetBrothersByName(name);
    for (auto& brother : brothers) {
        eids.push_back(brother.GetEid());
    }

    return eids;
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
}
//-----------------------------------------------------------------------------------------------------
