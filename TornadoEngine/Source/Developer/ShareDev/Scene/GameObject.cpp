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
#include "BehaviourPattern.h"

TGameObject::TGameObject()
{
  mPtrPattern = NULL;
  mID = 0;

  mPtrGraphic.reset(new TGameObjectComponent_Graphic);
  mPtrPhysic.reset(new  TGameObjectComponent_Physic);
  mPtrSound.reset(new   TGameObjectComponent_Sound);
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
std::string TGameObject::GetType()
{ 
  return mType;
}
//----------------------------------------------------------------
void TGameObject::SetType(std::string v)
{ 
  mType = v;
}
//----------------------------------------------------------------
void TGameObject::SetPattern(TBehaviourPattern* p)
{
  mPtrPattern = p;
  mPtrPattern->SetGameObject(this);
}
//----------------------------------------------------------------
TBehaviourPattern* TGameObject::GetPattern()
{
  return mPtrPattern;
}
//----------------------------------------------------------------
void TGameObject::SetBuilder(TBuilderGameObjectFromGameItem* p)
{

}
//----------------------------------------------------------------
TBuilderGameObjectFromGameItem* TGameObject::GetBuilder()
{
  return mPtrBuilder;
}
//----------------------------------------------------------------
void TGameObject::SetDestructor(TDestructorGameObjectFromGameItem* p)
{

}
//----------------------------------------------------------------
TDestructorGameObjectFromGameItem* TGameObject::GetDestructor()
{
  return mPtrDestructor;
}
//----------------------------------------------------------------
void TGameObject::SetUpdater(TUpdaterGameObjectFromGameItem* p)
{

}
//----------------------------------------------------------------
TUpdaterGameObjectFromGameItem* TGameObject::GetUpdater()
{
  return mPtrUpdater;
}
//----------------------------------------------------------------
