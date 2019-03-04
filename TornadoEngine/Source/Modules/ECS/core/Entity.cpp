/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Entity.h"

using namespace nsECSFramework;

void Entity::SetID( EntityID id )
{
  mData->mID = id;
}
//---------------------------------------------------------------------------------------
void Entity::Done()
{

}
//---------------------------------------------------------------------------------------
