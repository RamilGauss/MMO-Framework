/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Entity.h"

using namespace nsMappedComponents;

TEntity::~TEntity()
{
  Done();
}
//-----------------------------------------------------------------------------------------------
void TEntity::Done()
{
  auto func = GetFirstRemoveFunc();
  while ( func )
  {
    func();
    func = GetFirstRemoveFunc();
  }
}
//-----------------------------------------------------------------------------------------------
bool TEntity::HasComponent( std::type_index type )
{
  return mComponentMap.end() != mComponentMap.find( type );
}
//-----------------------------------------------------------------------------------------------
TEntity::RemoveFunc TEntity::GetFirstRemoveFunc()
{
  auto bit = mForRemoveMap.begin();
  auto eit = mForRemoveMap.end();
  if ( bit == eit )
    return nullptr;
  return bit->second;
}
//-----------------------------------------------------------------------------------------------
