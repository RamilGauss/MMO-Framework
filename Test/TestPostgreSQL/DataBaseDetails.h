/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "DataBase.h"

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/query.hxx>

template<typename Type>
auto TDataBase::Persist( Type& obj )
{
  return ((odb::database*)pDB)->persist<Type>( obj );
}
