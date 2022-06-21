/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GameObject.h"

#include "Modules.h"

#include "ParentGuidComponent.h"
#include "GuidComponent.h"
#include "NameComponent.h"

using namespace nsTornadoEngine;

TGameObject::TGameObject()
{

}
//------------------------------------------------------------------------------------------
TGameObject::TGameObject(nsECSFramework::TEntityID eid)
{
    mEid = eid;

    mEntMng = Modules()->EntMng();
}
//------------------------------------------------------------------------------------------
void TGameObject::SetEntityManager(nsECSFramework::TEntityManager* entMng)
{
    mEntMng = entMng;
}
//------------------------------------------------------------------------------------------
nsECSFramework::TEntityManager* TGameObject::GetEntityManager() const
{
    return mEntMng;
}
//------------------------------------------------------------------------------------------
TGameObject TGameObject::GetParent()
{
    auto parentGuid = GetComponent<nsCommonWrapper::TParentGuidComponent>();

    nsCommonWrapper::TGuidComponent guid;
    guid.value = parentGuid.value;

    return TGameObject(mEntMng->GetByUnique(guid));
}
//------------------------------------------------------------------------------------------
void TGameObject::GetChilds(std::list<TGameObject>& gos)
{
    auto guid = GetComponent<nsCommonWrapper::TGuidComponent>();

    nsCommonWrapper::TParentGuidComponent parentGuid;
    parentGuid.value = guid.value;

    auto childEids = mEntMng->GetByValueCopy(parentGuid);

    for (auto& childEid : childEids) {
        gos.push_back(TGameObject(childEid));
    }
}
//------------------------------------------------------------------------------------------
void TGameObject::GetChilds(nsECSFramework::TEntityList& eids)
{
    auto guid = GetComponent<nsCommonWrapper::TGuidComponent>();

    nsCommonWrapper::TParentGuidComponent parentGuid;
    parentGuid.value = guid.value;

    auto childEids = mEntMng->GetByValueCopy(parentGuid);

    for (auto& childEid : childEids) {
        eids.push_back(childEid);
    }
}
//------------------------------------------------------------------------------------------
void TGameObject::GetAllTree(std::list<TGameObject>& gos)
{
    gos.push_back(*this);

    GetAllChilds(gos);
}
//------------------------------------------------------------------------------------------
void TGameObject::GetAllChilds(std::list<TGameObject>& gos)
{
    std::list<TGameObject> selfGos;
    GetChilds(selfGos);
    gos.insert(selfGos.begin(), selfGos.size());

    for (auto& child : selfGos) {
        child.GetAllChilds(gos);
    }
}
//------------------------------------------------------------------------------------------
void TGameObject::GetAllTree(nsECSFramework::TEntityList& eids)
{
    eids.push_back(GetEid());

    GetAllChilds(eids);
}
//------------------------------------------------------------------------------------------
void TGameObject::GetAllChilds(nsECSFramework::TEntityList& eids)
{
    nsECSFramework::TEntityList selfEids;
    GetChilds(eids);
    eids.insert(selfEids.begin(), selfEids.size());

    std::list<TGameObject> selfGos;
    GetChilds(selfGos);
    for (auto& child : selfGos) {
        child.GetAllChilds(eids);
    }
}
//------------------------------------------------------------------------------------------
TGameObject TGameObject::GetBrotherByName(const std::string& brotherName)
{
    auto parent = GetParent();
    return parent.GetChildByName(brotherName);
}
//------------------------------------------------------------------------------------------
std::list<TGameObject> TGameObject::GetBrothersByName(const std::string& brotherName)
{
    auto parent = GetParent();
    return parent.GetChildsByName(brotherName);
}
//------------------------------------------------------------------------------------------
TGameObject TGameObject::GetChildByName(const std::string& childName)
{
    std::list<TGameObject> gos;
    GetChilds(gos);

    for (auto& go : gos) {
        auto nameComponent = go.GetComponent<nsCommonWrapper::TNameComponent>();
        if (nameComponent.value == childName) {
            return go;
        }
    }

    return {};
}
//------------------------------------------------------------------------------------------
std::list<TGameObject> TGameObject::GetChildsByName(const std::string& childName)
{
    std::list<TGameObject> returnedGos;

    std::list<TGameObject> childs;
    GetChilds(childs);

    for (auto& go : childs) {
        auto nameComponent = go.GetComponent<nsCommonWrapper::TNameComponent>();
        if (nameComponent.value == childName) {
            returnedGos.push_back(go);
        }
    }

    return returnedGos;
}
//------------------------------------------------------------------------------------------
void TGameObject::GetChildsByNameRecursively(const std::string& name, std::list<TGameObject>& gos)
{
    auto childsByName = GetChildsByName(name);
    gos.insert(childsByName.begin(), childsByName.size());

    std::list<TGameObject> childs;
    GetChilds(childs);

    for (auto& child : childs) {
        child.GetChildsByNameRecursively(name, gos);
    }
}
//------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TGameObject::GetEid() const
{
    return mEid;
}
//------------------------------------------------------------------------------------------
bool TGameObject::IsEmpty() const
{
    return mEid == nsECSFramework::NONE;
}
//------------------------------------------------------------------------------------------
void TGameObject::RemoveChilds()
{
    std::list<TGameObject> childs;
    GetChilds(childs);

    for (auto& child : childs) {
        RemoveChild(child);
    }
}
//------------------------------------------------------------------------------------------
void TGameObject::RemoveChild(const TGameObject& child)
{
    mEntMng->DestroyEntity(child.GetEid());
}
//------------------------------------------------------------------------------------------
