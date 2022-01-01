/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "HierarchyHelper.h"
#include "ParentGuidComponent.h"
#include "GuidComponent.h"
#include "NameComponent.h"

using namespace nsTornadoEngine;

void THierarchyHelper::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    mEntMng = entMng;
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityID THierarchyHelper::GetParent(nsECSFramework::TEntityID eid)
{
    auto parentGuid = mEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid);

    nsCommonWrapper::TGuidComponent guid;
    guid.value = parentGuid->value;

    return mEntMng->GetByUnique(guid);
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityList THierarchyHelper::GetChilds(nsECSFramework::TEntityID eid)
{
    auto guid = mEntMng->ViewComponent<nsCommonWrapper::TGuidComponent>(eid);

    nsCommonWrapper::TParentGuidComponent parentGuid;
    parentGuid.value = guid->value;

    return mEntMng->GetByValueCopy(parentGuid);
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityID THierarchyHelper::GetBrotherByName(nsECSFramework::TEntityID eid,
    const std::string& brotherName)
{
    auto parentEid = GetParent(eid);
    auto childEids = GetChilds(parentEid);
    
    for (auto& childEid : childEids) {
        auto name = mEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(childEid)->value;
        if (name == brotherName) {
            return childEid;
        }
    }

    return nsECSFramework::NONE;
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityList THierarchyHelper::GetBrothersByName(nsECSFramework::TEntityID eid,
    const std::string& brotherName)
{
    auto parentEid = GetParent(eid);
    auto childEids = GetChilds(parentEid);

    nsECSFramework::TEntityList entities;

    for (auto& childEid : childEids) {
        auto name = mEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(childEid)->value;
        if (name == brotherName) {
            entities.push_back(childEid);
        }
    }

    return entities;
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityID THierarchyHelper::GetChildByName(nsECSFramework::TEntityID eid,
    const std::string& brotherName)
{
    auto childEids = GetChilds(eid);

    for (auto& childEid : childEids) {
        auto name = mEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(childEid)->value;
        if (name == brotherName) {
            return childEid;
        }
    }

    return nsECSFramework::NONE;
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityList THierarchyHelper::GetChildsByName(nsECSFramework::TEntityID eid,
    const std::string& brotherName)
{
    auto childEids = GetChilds(eid);

    nsECSFramework::TEntityList entities;

    for (auto& childEid : childEids) {
        auto name = mEntMng->ViewComponent<nsCommonWrapper::TNameComponent>(childEid)->value;
        if (name == brotherName) {
            entities.push_back(childEid);
        }
    }

    return entities;
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityID THierarchyHelper::GetByName(nsECSFramework::TEntityID anyInPrefabEid,
    const std::string& name)
{
    auto nameEids = GetListByName(anyInPrefabEid, name);
    if (nameEids.size() == 0) {
        return nsECSFramework::NONE;
    }
    return *(nameEids.begin());
}
//-----------------------------------------------------------------------------------------------
nsECSFramework::TEntityList THierarchyHelper::GetListByName(nsECSFramework::TEntityID anyInPrefabEid,
    const std::string& name)
{
    nsCommonWrapper::TNameComponent nameComponent;
    nameComponent.value = name;
    auto nameEids = mEntMng->GetByValueCopy(nameComponent);
    if (nameEids.size() == 0) {
        return {};
    }

    nsECSFramework::TEntityList filteredByPrefabGuidList;
    auto prefabGuid = mEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(anyInPrefabEid)->value;
    
    for (auto& nameEid : nameEids) {
        auto prefabGuidComponentByName = mEntMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(nameEid);
        if (prefabGuidComponentByName->value == prefabGuid) {
            filteredByPrefabGuidList.push_back(nameEid);
        }
    }

    return filteredByPrefabGuidList;
}
//-----------------------------------------------------------------------------------------------
