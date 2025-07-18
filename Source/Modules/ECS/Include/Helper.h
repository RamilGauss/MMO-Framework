/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "EntityManager.h"

namespace nsECSFramework
{
    template <typename Component>
    TEntityID SingleEntity(TEntityManager* entMng)// когда точно есть одна сущность с данным компонентом
    {
        auto hasList = entMng->GetByHasCopy<Component>();
        if (hasList.size() == 0 ) {
            return NONE;
        }
        return hasList.front();
    }

    template <typename Component>
    const Component* SingleComponent(TEntityManager* entMng)// когда точно есть одна сущность с данным компонентом
    {
        auto eid = SingleEntity<Component>(entMng);
        if ( eid == NONE ) {
            return nullptr;
        }
        return entMng->ViewComponent<Component>(eid);
    }
}
