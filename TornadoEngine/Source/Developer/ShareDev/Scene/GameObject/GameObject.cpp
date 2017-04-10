/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject.h"

#include "BehaviourPatternModel.h"

TGameObject::TGameObject()
{
  mPtrModel   = NULL;
  mID = 0;
}
//----------------------------------------------------------------
TGameObject::~TGameObject()
{
	delete mPtrModel;
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
void TGameObject::SetModel(TBehaviourPatternModel* p)
{
  mPtrModel = p;
}
//----------------------------------------------------------------
TBehaviourPatternModel* TGameObject::GetModel()
{
  return mPtrModel;
}
//----------------------------------------------------------------
