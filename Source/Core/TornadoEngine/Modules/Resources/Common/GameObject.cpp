/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules/Resources/Common/GameObject.h"
#include "Modules/Resources/Common/GuidConstants.h"
#include "Components/Meta/ParentGuidComponent.h"
#include "Components/Meta/GuidComponent.h"

namespace nsTornadoEngine
{
    TGameObject::TGameObject()
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject::TGameObject(nsECSFramework::TEntityID eid, nsECSFramework::TEntityManager* entMng)
    {
        mEid = eid;
        mEntMng = entMng;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    nsECSFramework::TEntityID TGameObject::GetEid() const
    {
        return mEid;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TGameObject::IsParent(const TGameObject& go, bool recursive)
    {
        auto parent = GetParent();
        while (true) {
            if (parent.IsEmpty()) {
                break;
            }
            if (parent == go) {
                return true;
            }
            if (recursive == false) {
                break;
            }

            parent = parent.GetParent();
        }
        return false;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TGameObject::IsEmpty() const
    {
        return (mEid == nsECSFramework::NONE);
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject::operator bool() const
    {
        return IsEmpty();
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject TGameObject::GetParent()
    {   
        auto parentGuid = GetComponent<nsCommonWrapper::TParentGuidComponent>().value;

        if (parentGuid == TGuidConstants::NONE) {
            return {};
        }

        nsCommonWrapper::TGuidComponent guidComponent;
        guidComponent.value = parentGuid;

        auto parentEid = mEntMng->GetByUnique(guidComponent);

        return TGameObject(parentEid, mEntMng);
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetChilds(std::list<TGameObject>& gos)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetChilds(nsECSFramework::TEntityList& eids)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetAllTree(std::list<TGameObject>& gos)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetAllChilds(std::list<TGameObject>& gos)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetAllTree(nsECSFramework::TEntityList& eids)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetAllChilds(nsECSFramework::TEntityList& eids)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject TGameObject::GetBrotherByName(const std::string& brotherName)
    {
        return {};
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    std::list<TGameObject> TGameObject::GetBrothersByName(const std::string& brotherName)
    {
        return {};
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject TGameObject::GetChildByName(const std::string& childName)
    {
        return {};
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    std::list<TGameObject> TGameObject::GetChildsByName(const std::string& childName)
    {
        return {};
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::GetChildsByNameRecursively(const std::string& name, std::list<TGameObject>& gos)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::RemoveChilds()
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::RemoveChild(const TGameObject& child)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TGameObject::SetEntityManager(nsECSFramework::TEntityManager* entMng)
    {
        mEntMng = entMng;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    nsECSFramework::TEntityManager* TGameObject::GetEntityManager() const
    {
        return mEntMng;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TGameObject::operator == (const TGameObject& go) const
    {
        return ((mEntMng == go.GetEntityManager()) && 
                (mEid == go.GetEid()));
    }
    //------------------------------------------------------------------------------------------------------------------------------------
}
