/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GameObject.h"

#include "BehaviourPattern.h"

TGameObject::TGameObject()
{
  mPtrPattern   = NULL;
  mID = 0;
}
//----------------------------------------------------------------
TGameObject::~TGameObject()
{
  delete mPtrPattern;
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
void TGameObject::SetPattern(TBehaviourPattern* p)
{
  mPtrPattern = p;
}
//----------------------------------------------------------------
TBehaviourPattern* TGameObject::GetPattern()
{
  return mPtrPattern;
}
//----------------------------------------------------------------
