/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject.h"

#include "BehaviourPatternModel.h"
#include "BehaviourPatternContext.h"

TGameObject::TGameObject()
{
  mPtrModel   = NULL;
  mPtrContext = NULL;

  mID = 0;
}
//----------------------------------------------------------------
TGameObject::~TGameObject()
{
  delete mPtrContext;
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
void TGameObject::SetContext(TBehaviourPatternContext* p)
{
  delete mPtrContext;
  mPtrContext = p;
  if( mPtrContext )
    mPtrContext->SetGameObject(this);
}
//----------------------------------------------------------------
TBehaviourPatternContext* TGameObject::GetContext()
{
  return mPtrContext;
}
//----------------------------------------------------------------
