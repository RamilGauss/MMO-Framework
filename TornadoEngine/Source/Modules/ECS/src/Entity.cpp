/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Entity.h"

using namespace nsECSFramework;

TEntity::TEntity()
{
  mComponentInfoMemoryPool = SingletonManager()->Get<TMemoryObjectPool<TComponentInfo>>();
}
//---------------------------------------------------------------------------------------
void TEntity::Done()
{
  while ( true )
  {
    if ( mComponentIndexInUse.size() == 0 )
      return;
    auto bit = mComponentIndexInUse.begin();
    auto index = *bit;
    RemoveComponent( index );
  }
}
//---------------------------------------------------------------------------------------
void TEntity::RemoveComponent( int index )
{
  auto pCI = mComponents[index];
  if ( pCI == nullptr )
    return;
  pCI->Done();
  mComponents[index] = nullptr;
  mComponentInfoMemoryPool->Push( pCI );
}
//---------------------------------------------------------------------------------------
bool TEntity::HasComponent( int index )
{
  return mComponents[index] != nullptr;
}
//---------------------------------------------------------------------------------------

