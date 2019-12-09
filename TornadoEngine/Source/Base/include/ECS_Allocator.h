/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

template<typename TRegistry, TRegistry* mRegistry>
class DllExport TECS_Allocator
{// инфраструктура для маршаллинга
public:
  template<typename Type>
  static void* AllocateFunc()
  {
    auto entity = mRegistry->create();// создание entity
    mRegistry->assign<Type>( entity );// добавить компонент
    auto& component = mRegistry->get<Type>( entity );
    return &component;
  }
  static void DeallocateFunc( void* p )
  {
    // empty, call registry.destroy( entity ), in case TDataMemoryPoolComponent registry.destroy( entity ).Done()
  }
};