/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject.h"
#include "GameObjectComponent_Graphic.h"
#include "GameObjectComponent_Physic.h"
#include "GameObjectComponent_Sound.h"

#include "BehaviourPatternModel.h"
#include "BehaviourPatternContext.h"

TGameObject::TGameObject()
{
  mPtrModel   = NULL;
  mPtrContext = NULL;

  mID = 0;

  mPtrGraphic.reset(new TGameObjectComponent_Graphic);
  mPtrPhysic.reset(new  TGameObjectComponent_Physic);
  mPtrSound.reset(new   TGameObjectComponent_Sound);
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
void TGameObject::SetBuilder(TBuilderGameObjectFromGameItem* p)
{
  mPtrBuilder = p;
}
//----------------------------------------------------------------
TBuilderGameObjectFromGameItem* TGameObject::GetBuilder()
{
  return mPtrBuilder;
}
//----------------------------------------------------------------
void TGameObject::SetDestructor(TDestructorGameObjectFromGameItem* p)
{
  mPtrDestructor = p;
}
//----------------------------------------------------------------
TDestructorGameObjectFromGameItem* TGameObject::GetDestructor()
{
  return mPtrDestructor;
}
//----------------------------------------------------------------
void TGameObject::SetUpdater(TUpdaterGameObjectFromGameItem* p)
{
  mPtrUpdater = p;
}
//----------------------------------------------------------------
TUpdaterGameObjectFromGameItem* TGameObject::GetUpdater()
{
  return mPtrUpdater;
}
//----------------------------------------------------------------
