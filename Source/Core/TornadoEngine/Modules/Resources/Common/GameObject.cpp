/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GameObject.h"

namespace nsTornadoEngine
{
    TGameObject::TGameObject()
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject::TGameObject(nsECSFramework::TEntityID eid, nsECSFramework::TEntityManager* entMng)
    {

    }
    //------------------------------------------------------------------------------------------------------------------------------------
    nsECSFramework::TEntityID TGameObject::GetEid() const
    {
        return {};
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TGameObject::IsEmpty() const
    {
        return false;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    TGameObject TGameObject::GetParent()
    {
        return {};
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
}