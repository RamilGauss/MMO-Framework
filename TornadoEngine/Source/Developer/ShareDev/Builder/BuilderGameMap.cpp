/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderGameMap.h"
#include "FactoryGameItem.h"
#include <boost/foreach.hpp>

#include "MapItem.h"
#include "TableSoundItem.h"
#include "GameTableSound.h"

#include "PreBuilderCameraUp.h"
#include "PreBuilderGravityVector.h"
#include "PreBuilderTableSound.h"
#include "PreBuilderGameObject.h"

#include "Builder_Ogre.h"
#include "Builder_Bullet.h"
#include "Builder_OpenAL.h"

TBuilderGameMap::TBuilderGameMap()
{
  mBuilderOgre.reset(new TBuilder_Ogre);
  mBuilderBullet.reset(new TBuilder_Bullet);
  mBuilderOpenAL.reset(new TBuilder_OpenAL);

  mFactoryGameItem = NULL;
  mMapItem         = NULL;
  mTableSound      = NULL;
  mState           = eIdle;
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::~TBuilderGameMap()
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Init( TPreBuilder::TVectorTypeTask& vec, TFactoryGameItem* pFactoryGameItem )
{
  mVecTask         = vec;
  mFactoryGameItem = pFactoryGameItem;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitPhysic( int id_physic_world )
{
  mBuilderBullet->SetID_PhysicWorld(id_physic_world);
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BuildMap( TMapItem* pMI )
{
  if(CheckIdle()==false)
    return false;

  mState = eIdle;
  mListGameObject.clear();

  mMapItem = pMI;
  if( mMapItem==NULL )
    return false;
  mTableSound = 
    (TTableSoundItem*)mFactoryGameItem->Get( TFactoryGameItem::TableSound, mMapItem->mNameTableSound);

  if( PrepareCameraUp()==false )
    return false;
  if( PrepareGravity()==false )
    return false;
  if( PrepareTableSound()==false )
    return false;
  if( PrepareGameObject()==false )
    return false;

  mState = eBuildMap;
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BuildObject( TMapItem::TObject* pObject )
{
  if(CheckIdle()==false)
    return false;

  mState = eIdle;
  mListGameObject.clear();

  if( AddObject_Private( pObject )==false )
    return false;

  mState = eBuildObject;
  return true;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Ogre()
{
  //std::min(CountTaskPerQuant, );
  for(;;)
  {

  }
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Bullet()
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_OpenAL()
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::GetResult(TListPtrGameObject& listPtrGameObject)
{
  listPtrGameObject = mListGameObject;
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::State TBuilderGameMap::GetState()
{
  return mState;
}
//--------------------------------------------------------------------------------------------
int TBuilderGameMap::GetProgress()
{
  return 0;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::CheckIdle()
{
  if((mState==eBuildMap) || 
     (mState==eBuildObject))
    return false;
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareCameraUp()
{
  TPreBuilderCameraUp preBuilderCameraUp;
  preBuilderCameraUp.Set(mMapItem->mCameraUp);
  if( preBuilderCameraUp.GenerateTask(mVecTask)==false )
    return false;

  CollectTask(&preBuilderCameraUp);
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareGravity()
{
  TPreBuilderGravityVector preBuilderGravityVector;
  preBuilderGravityVector.Set(mMapItem->mGravity);
  if( preBuilderGravityVector.GenerateTask(mVecTask)==false )
    return false;
  CollectTask(&preBuilderGravityVector);
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareTableSound()
{
  TPreBuilderTableSound preBuilderTableSound;
  preBuilderTableSound.Set(mTableSound);
  if( preBuilderTableSound.GenerateTask(mVecTask)==false )
    return false;
  CollectTask(&preBuilderTableSound);
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareGameObject()
{
  BOOST_FOREACH(TMapItem::TObject& objectItem, mMapItem->mListObject)
  {
    if( AddObject_Private(&objectItem)==false )
      return false;
  }
  return true;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::CollectTask(TPreBuilder* pPreBuilder)
{
  TPreBuilder::TListTaskOgre   listTask_Ogre;
  TPreBuilder::TListTaskBullet listTask_Bullet;
  TPreBuilder::TListTaskOpenAL listTask_OpenAL;

  pPreBuilder->TakeTask_Ogre(listTask_Ogre);
  pPreBuilder->TakeTask_Bullet(listTask_Bullet);
  pPreBuilder->TakeTask_OpenAL(listTask_OpenAL);
  // слияние списков задач по типам:
  mListTask_Ogre.insert(mListTask_Ogre.end(),     listTask_Ogre.begin(),   listTask_Ogre.end());
  mListTask_Bullet.insert(mListTask_Bullet.end(), listTask_Bullet.begin(), listTask_Bullet.end());
  mListTask_OpenAL.insert(mListTask_OpenAL.end(), listTask_OpenAL.begin(), listTask_OpenAL.end());
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::AddObject_Private( TMapItem::TObject* pObject )
{
  TPreBuilderGameObject* pPreBuilder = mFactoryPreBuilderObject.GetPreBuilderByType(pObject->type);
  if( pPreBuilder )
  {
    pPreBuilder->SetObjectItem(pObject);
    if( pPreBuilder->GenerateTask(mVecTask)==false )
      return false;
    TGameObject* pGameObject = pPreBuilder->GetGameObject();
    mListGameObject.push_back(pGameObject);

    CollectTask(pPreBuilder);
  }
  return true;
}
//--------------------------------------------------------------------------------------------
