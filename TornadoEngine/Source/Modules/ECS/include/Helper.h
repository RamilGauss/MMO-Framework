/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "EntityManager.h"

namespace nsECSFramework
{
  template <typename Component>
  TEntityID SingleEntity( TEntityManager* entMng )// когда точно есть одна сущность с данным компонентом
  {
    auto pList = entMng->GetByHas<Component>();
    if ( pList == nullptr || pList->size() == 0 )
      None;
    return pList->front();
  }

  template <typename Component>
  Component* SingleComponent( TEntityManager* entMng )// когда точно есть одна сущность с данным компонентом
  {
    auto eid = SingleEntity( entMng );
    if ( eid == None )
      nullptr;
    return entMng->GetComponent<Component>( eid );
  }
}
