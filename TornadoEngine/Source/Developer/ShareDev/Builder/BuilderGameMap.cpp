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

#include "CacheTableSound.h"
#include "ApplySetup_GravityVector.h"
#include "ApplySetup_CameraUp.h"

#include "GameObject.h"

#include "PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"

TBuilderGameMap::TBuilderGameMap()
{
  flgNeedInitPhysic = true;

  mUsePattern      = NULL;

  mMapItem         = NULL;
  mTableSound      = NULL;
  mState           = eIdle;

  mCTableSound.reset(new TCacheTableSound);
  mAS_GravityVector.reset(new TApplySetup_GravityVector);
  mAS_CameraUp.reset(new TApplySetup_CameraUp);
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Init(TUsePattern* pUsePattern, TFactoryBehaviourPattern* pFBP)
{
  mUsePattern              = pUsePattern;
  mFactoryBehaviourPattern = pFBP;
  mFactoryGameItem         = TModuleLogic::Get()->GetFGI();
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::~TBuilderGameMap()
{
  // прежде чем уничтожать мир, деструктор должен уничтожить всего объекты, связанные с ним!
  TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->DeleteWorld(mPhysicWorldID);
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitPhysic()
{
  // Создание физического мира.
  mPhysicWorldID = TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->AddWorld();
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BuildMap( TMapItem* pMI )
{
  //if(CheckIdle()==false)
    //return false;
  mState = eIdle;
  mListGameObject.clear();

  mMapItem = pMI;
  if( mMapItem==NULL )
    return false;
  mTableSound = 
    (TTableSoundItem*)mFactoryGameItem->Get( TFactoryGameItem::TableSound, mMapItem->mNameTableSound);

  //if( PrepareCameraUp()==false )
  //  return false;
  //if( PrepareGravity()==false )
  //  return false;
  //if( PrepareTableSound()==false )
  //  return false;
  //if( PrepareGameObject()==false )
  //  return false;

  //CalcStatisticForProgress();
  //PrepareIterator();

  //if( mAllCount )
    //mState = eBuildMap;
  //else
    //mState = eIdle;
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BuildObject( TMapItem::TObject* pObject, bool fast )
{
  //if(CheckIdle()==false)
    //return false;

  mState = eIdle;
  mListGameObject.clear();

  //if( AddObject_Private( pObject )==false )
    //return false;

  //CalcStatisticForProgress();
  mState = eBuildObject;
  return true;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Logic()
{
  // создание и настройка игровых объектов

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Ogre()
{
  //TProgressTask progress;
  //progress.mCurIndex = mProgressTask_Ogre.mCurIndex;
  //progress.mCount    = mProgressTask_Ogre.mCount;
  //BuildFromThread_XXX(progress, mBuilderOgre.get(), mLastTask_Ogre);
  //mProgressTask_Ogre.mCurIndex = progress.mCurIndex;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Bullet()
{
  if(flgNeedInitPhysic)
  {
    InitPhysic();
    flgNeedInitPhysic = false;
  }
  // когда вывести из состояния паузы - решит логика
  TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->Setup(mPhysicWorldID, TPhysicEngine_Bullet::eStatePause);

  //TProgressTask progress;
  //progress.mCurIndex = mProgressTask_Bullet.mCurIndex;
  //progress.mCount    = mProgressTask_Bullet.mCount;
  //BuildFromThread_XXX(progress, mBuilderBullet.get(), mLastTask_Bullet);
  //mProgressTask_Bullet.mCurIndex = progress.mCurIndex;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_OpenAL()
{
  //TProgressTask progress;
  //progress.mCurIndex = mProgressTask_OpenAL.mCurIndex;
  //progress.mCount    = mProgressTask_OpenAL.mCount;
  //BuildFromThread_XXX(progress, mBuilderOpenAL.get(), mLastTask_OpenAL);
  //mProgressTask_OpenAL.mCurIndex = progress.mCurIndex;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::GetResult(TListPtrGameObject& listPtrGameObject)
{
  listPtrGameObject = mListGameObject;
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::State TBuilderGameMap::GetState()
{
  if( mState==eIdle )
    return mState;

  int progress = GetProgress();
  if( progress==100 )
    mState = eBuildComplete;
  return mState;
}
//--------------------------------------------------------------------------------------------
int TBuilderGameMap::GetProgress()
{
  //if( mAllCount==0 )
    return 100;
  //int cntComplete = mProgressTask_Ogre.mCurIndex + mProgressTask_Bullet.mCurIndex + mProgressTask_OpenAL.mCurIndex;
  //return ( cntComplete * 100 ) / mAllCount;
}
//--------------------------------------------------------------------------------------------
//bool TBuilderGameMap::CheckIdle()
//{
//  if((mState==eBuildMap) || 
//     (mState==eBuildObject))
//    return false;
//  return true;
//}
//--------------------------------------------------------------------------------------------
//bool TBuilderGameMap::PrepareCameraUp()
//{
//  TPreBuilderCameraUp preBuilderCameraUp;
//  preBuilderCameraUp.Set(mMapItem->mCameraUp);
//  if( preBuilderCameraUp.GenerateTask(mVecTask)==false )
//    return false;
//
//  CollectTask(&preBuilderCameraUp);
//  return true;
//}
//--------------------------------------------------------------------------------------------
//bool TBuilderGameMap::PrepareGravity()
//{
//  TPreBuilderGravityVector preBuilderGravityVector;
//  preBuilderGravityVector.Set(mMapItem->mGravity);
//  if( preBuilderGravityVector.GenerateTask(mVecTask)==false )
//    return false;
//  CollectTask(&preBuilderGravityVector);
//  return true;
//}
//--------------------------------------------------------------------------------------------
//bool TBuilderGameMap::PrepareTableSound()
//{
//  TPreBuilderTableSound preBuilderTableSound;
//  preBuilderTableSound.Set(mTableSound);
//  if( preBuilderTableSound.GenerateTask(mVecTask)==false )
//    return false;
//  CollectTask(&preBuilderTableSound);
//  return true;
//}
//--------------------------------------------------------------------------------------------
//bool TBuilderGameMap::PrepareGameObject()
//{
//  BOOST_FOREACH(TMapItem::TObject& objectItem, mMapItem->mListObject)
//  {
//    if( AddObject_Private(&objectItem)==false )
//      return false;
//  }
//  return true;
//}
//--------------------------------------------------------------------------------------------
//void TBuilderGameMap::CollectTask(TPreBuilder* pPreBuilder)
//{
//  TPreBuilder::TListTaskOgre   listTask_Ogre;
//  TPreBuilder::TListTaskBullet listTask_Bullet;
//  TPreBuilder::TListTaskOpenAL listTask_OpenAL;
//
//  pPreBuilder->TakeTask_Ogre(listTask_Ogre);
//  pPreBuilder->TakeTask_Bullet(listTask_Bullet);
//  pPreBuilder->TakeTask_OpenAL(listTask_OpenAL);
//  // слияние списков задач по типам:
//  mListTask_Ogre.insert(mListTask_Ogre.end(),     listTask_Ogre.begin(),   listTask_Ogre.end());
//  mListTask_Bullet.insert(mListTask_Bullet.end(), listTask_Bullet.begin(), listTask_Bullet.end());
//  mListTask_OpenAL.insert(mListTask_OpenAL.end(), listTask_OpenAL.begin(), listTask_OpenAL.end());
//}
//--------------------------------------------------------------------------------------------
//bool TBuilderGameMap::AddObject_Private( TMapItem::TObject* pObject )
//{
//  TPreBuilderGameObject* pPreBuilder = mFactoryPreBuilderObject.GetPreBuilderByType(pObject->type);
//  if( pPreBuilder )
//  {
//    pPreBuilder->SetObjectItem(pObject);
//    if( pPreBuilder->GenerateTask(mVecTask)==false )
//      return false;
//    TGameObject* pGameObject = new TGameObject();
//    mListGameObject.push_back(pGameObject);
//
//    CollectTask(pPreBuilder);
//  }
//  return true;
//}
//--------------------------------------------------------------------------------------------
//void TBuilderGameMap::CalcStatisticForProgress()
//{
//  mProgressTask_Ogre.mCount    = mListTask_Ogre.size();
//  mProgressTask_Ogre.mCurIndex = 0;
//
//  mProgressTask_Bullet.mCount    = mListTask_Bullet.size();
//  mProgressTask_Bullet.mCurIndex = 0;
//
//  mProgressTask_OpenAL.mCount    = mListTask_OpenAL.size();
//  mProgressTask_OpenAL.mCurIndex = 0;
//
//  mAllCount = mProgressTask_Ogre.mCount + mProgressTask_Bullet.mCount + mProgressTask_OpenAL.mCount;
//}
//--------------------------------------------------------------------------------------------
//void TBuilderGameMap::PrepareIterator()
//{
//  mLastTask_Ogre   = mListTask_Ogre.begin();
//  mLastTask_Bullet = mListTask_Bullet.begin();
//  mLastTask_OpenAL = mListTask_OpenAL.begin();
//}
//--------------------------------------------------------------------------------------------
int TBuilderGameMap::GetPhysicWorldID()
{
  return mPhysicWorldID;
}
//--------------------------------------------------------------------------------------------
