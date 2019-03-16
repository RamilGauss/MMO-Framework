/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Entity.h"

using namespace nsECSFramework;

void TEntity::SetID( TEntityID id )
{
  // пробежка по всем компонентам и смена id внутри list

  for ( auto index : mComponetIndexInUse )
  {
    auto p = mComponents[index];
    if ( p == nullptr )
      continue;
  }
}
//---------------------------------------------------------------------------------------
void TEntity::Done()
{

}
//---------------------------------------------------------------------------------------
