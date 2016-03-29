/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject.h"

TGameObject::TGameObject(std::string type)
{
  mType = type;
}
//----------------------------------------------------------------
TGameObject::~TGameObject()
{

}
//----------------------------------------------------------------
int TGameObject::GetID() const
{
  return mID;
}
//----------------------------------------------------------------
void TGameObject::SetID( int id )
{ 
  mID = id;
}
//----------------------------------------------------------------
std::string TGameObject::GetSelfType()
{ 
  return mType;
}
//----------------------------------------------------------------