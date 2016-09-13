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

#include "PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"
#include "BehaviourPattern.h"

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
  mAllCount = 0;
  mState = eIdle;
  mListGameObject.clear();

  mMapItem = pMI;
  if( mMapItem==NULL )
    return false;
  mTableSound = 
    (TTableSoundItem*)mFactoryGameItem->Get( TFactoryGameItem::TableSound, mMapItem->mNameTableSound);

  mTask_Bullet.flgNeedInit = true;
  mTask_Ogre.flgNeedInit   = true;
  mTask_OpenAL.flgNeedInit = true;

  CalcStatisticForProgress();

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
  TCallBackRegistrator0 cbInit;
  cbInit.Register( &TBuilderGameMap::InitMapFrom_Ogre,this);
  TProgressTask progress;
  progress = mProgressTask_Ogre;
  BuildFromThread_XXX(mTask_Ogre, cbInit, progress, eOgreThread);
  mProgressTask_Ogre.mCurIndex = progress.mCurIndex;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Bullet()
{
  TCallBackRegistrator0 cbInit;
  cbInit.Register( &TBuilderGameMap::InitMapFrom_Bullet,this);
  TProgressTask progress;
  progress = mProgressTask_Bullet;
  BuildFromThread_XXX(mTask_Bullet, cbInit, progress, eBulletThread);
  mProgressTask_Bullet.mCurIndex = progress.mCurIndex;

  //### когда вывести из состояния паузы - решит логика
  //TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->Setup(mPhysicWorldID, TPhysicEngine_Bullet::eStatePause);
  //###
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_OpenAL()
{
  TCallBackRegistrator0 cbInit;
  cbInit.Register( &TBuilderGameMap::InitMapFrom_OpenAL,this);
  TProgressTask progress;
  progress = mProgressTask_OpenAL;
  BuildFromThread_XXX(mTask_OpenAL, cbInit, progress, eOpenALThread);
  mProgressTask_OpenAL.mCurIndex = progress.mCurIndex;
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
  if( mAllCount==0 )
    return 100;
  int cntComplete = mProgressTask_Ogre.mCurIndex + mProgressTask_Bullet.mCurIndex + mProgressTask_OpenAL.mCurIndex;
  return ( cntComplete * 100 ) / (3*mAllCount);// в сумме должно быть в 3 раза больше, Bullet+Ogre+OpenAL
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::CalcStatisticForProgress()
{
  mAllCount = mMapItem->mListObject.size();

  mProgressTask_Ogre.mCount    = mAllCount;
  mProgressTask_Ogre.mCurIndex = 0;

  mProgressTask_Bullet.mCount    = mAllCount;
  mProgressTask_Bullet.mCurIndex = 0;

  mProgressTask_OpenAL.mCount    = mAllCount;
  mProgressTask_OpenAL.mCurIndex = 0;
}
//--------------------------------------------------------------------------------------------
int TBuilderGameMap::GetPhysicWorldID()
{
  return mPhysicWorldID;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitMapFrom_Bullet()
{
  mAS_GravityVector->Set(mMapItem->mGravity);
  mAS_GravityVector->WorkFromThread_Bullet();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitMapFrom_Ogre()
{
  mAS_CameraUp->Set(mMapItem->mCameraUp);
  mAS_CameraUp->WorkFromThread_Ogre();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitMapFrom_OpenAL()
{
  mCTableSound->Set(mTableSound);
  mCTableSound->WorkFromThread_OpenAL();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_XXX( TTaskForThread& task, 
                                           TCallBackRegistrator0& cbInit, 
                                           TProgressTask& progress, 
                                           TypeThread typeThread)
{
  if( task.flgNeedInit )
  {
    cbInit.Notify();
    task.flgNeedInit = false;
  }

  int cntDone = 0;
  TGameObject** ppGO = NULL;
  while(1)
  {
    ppGO = task.pipe.GetFirst();
    if( ppGO==NULL )
    {
      ht_msleep(eTimeWaitObject);
      break;
    }

    TGameObject* pGO = *ppGO;
    switch(typeThread)
    {
      case eBulletThread:
        pGO->GetPattern()->LoadFromThread_Bullet();
        break;
      case eOgreThread:
        pGO->GetPattern()->LoadFromThread_Ogre();
        break;
      case eOpenALThread:
        pGO->GetPattern()->LoadFromThread_OpenAL();
        break;
    }
    task.pipe.RemoveFirst();
    cntDone++;
    progress.mCurIndex++;
    if( cntDone > eMaxCountBuildObject )
      break;
  }
}
//--------------------------------------------------------------------------------------------
