/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectManager.h"

namespace nsTornadoEngine
{
    void TObjectManager::SetContentMap(const TResourceContentMap& resourceContentMap)
    {

    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
    {

    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::DestroyObject(const std::string& guid)
    {

    }
    //------------------------------------------------------------------------------------------------------
    bool TObjectManager::Deserialize(const std::string& absPath, std::list<TEntityContent>& entities)
    {
        return false;
    }
    //------------------------------------------------------------------------------------------------------
    void TObjectManager::DeserializeObjects(std::list<nsECSFramework::TEntityID>& newEntities, const std::list<TEntityContent>& entities)
    {

    }
    //------------------------------------------------------------------------------------------------------
}
