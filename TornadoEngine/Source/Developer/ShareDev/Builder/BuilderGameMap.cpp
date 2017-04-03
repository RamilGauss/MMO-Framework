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
#include "ApplySetup_MapGraphicConfig.h"

#include "PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ModulePhysicEngine.h"

#include "FactoryBehaviourPatternModel.h"

#include "BehaviourPatternModel.h"
#include "BehaviourPatternContext.h"

TBuilderGameMap::TBuilderGameMap()
{
  mPhysicWorldID    = -1;
  flgNeedInitPhysic = true;

  mUsePattern      = NULL;

  mMapItem         = NULL;
  mTableSound      = NULL;
  mState           = eIdle;

  mCTableSound.reset(new TCacheTableSound);
  mAS_GravityVector.reset(new TApplySetup_GravityVector);
  mAS_CameraUp.reset(new TApplySetup_MapGraphicConfig);
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Init(std::set<int>& useID_Module, TFactoryBehaviourPatternModel* pFBP)
{
  mUseID_Module            = useID_Module;
  mFactoryBehaviourPattern = pFBP;
  mFactoryGameItem         = TModuleLogic::Get()->GetFGI();

  InitPhysic();
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::~TBuilderGameMap()
{
  // прежде чем уничтожать мир, деструктор должен уничтожить все объекты, связанные с ним!
  //TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->DeleteWorld(mPhysicWorldID);
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitPhysic()
{
  // Создание физического мира.
  if( mPhysicWorldID==-1 )
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

  mBeginIteratorMapObject = mMapItem->mListObject.begin();

  mTask_Bullet.flgNeedInit = true;
  mTask_Ogre.flgNeedInit   = true;
  mTask_OpenAL.flgNeedInit = true;

  CalcStatisticForProgress();
  return true;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildByModule_Logic()
{
  int cnt = 0;
  // создание и настройка игровых объектов
  TMapItem::TListObject::iterator eit = mMapItem->mListObject.end();
  while( mBeginIteratorMapObject!=eit )
  {
    TGameObject* pGO = new TGameObject;
    pGO->SetID(mBeginIteratorMapObject->id);
    TBehaviourPatternModel* pModel = 
      mFactoryBehaviourPattern->GetPatternByName(mBeginIteratorMapObject->namePattern);
    pGO->SetModel(pModel);
    pGO->SetContext( pGO->GetModel()->MakeNewConext() );
    pGO->GetContext()->SetPosition(mBeginIteratorMapObject->position);
    pGO->GetContext()->SetOrientation(mBeginIteratorMapObject->rotationQuaternion);
    pGO->GetContext()->SetParameterMap(mBeginIteratorMapObject->parameterMap);
		pGO->GetContext()->SetNameMap(mMapItem->mName);
		pGO->GetContext()->SetPhysicWorld(mPhysicWorldID);
    pGO->GetModel()->LoadFromThread_Logic(pGO->GetContext());

    mListGameObject.push_back(pGO);

		if( mUseID_Module.find(nsListModules::GraphicEngine)!=mUseID_Module.end() )
			mTask_Ogre.pipe.Add(pGO);

		if( mUseID_Module.find(nsListModules::PhysicEngine)!=mUseID_Module.end() )
	    mTask_Bullet.pipe.Add(pGO);
    
		if( mUseID_Module.find(nsListModules::SoundEngine)!=mUseID_Module.end() )
			mTask_OpenAL.pipe.Add(pGO);

    mBeginIteratorMapObject++;
    cnt++;
    if( cnt > eMaxCountBuildObject )
      break;
  }
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildByModule_Ogre()
{
  TCallBackRegistrator0 cbInit;
  cbInit.Register( &TBuilderGameMap::InitMapFrom_Ogre,this);
  TProgressTask progress;
  progress = mProgressTask_Ogre;
  BuildByModule_XXX(mTask_Ogre, cbInit, progress, nsListModules::GraphicEngine);
  mProgressTask_Ogre.mCurIndex = progress.mCurIndex;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildByModule_Bullet()
{
  TCallBackRegistrator0 cbInit;
  cbInit.Register( &TBuilderGameMap::InitMapFrom_Bullet,this);
  TProgressTask progress;
  progress = mProgressTask_Bullet;
  BuildByModule_XXX(mTask_Bullet, cbInit, progress, nsListModules::PhysicEngine);
  mProgressTask_Bullet.mCurIndex = progress.mCurIndex;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildByModule_OpenAL()
{
  TCallBackRegistrator0 cbInit;
  cbInit.Register( &TBuilderGameMap::InitMapFrom_OpenAL,this);
  TProgressTask progress;
  progress = mProgressTask_OpenAL;
	BuildByModule_XXX(mTask_OpenAL, cbInit, progress, nsListModules::SoundEngine);
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
  mAS_GravityVector->Set(mMapItem->mGravity, mPhysicWorldID);
  mAS_GravityVector->WorkFromThread_Bullet();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitMapFrom_Ogre()
{
  mAS_CameraUp->Set(mMapItem->mBackgroundColour, mMapItem->mFog, mMapItem->mAmbientLight);
  mAS_CameraUp->WorkFromThread_Ogre();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::InitMapFrom_OpenAL()
{
  mCTableSound->Set(mTableSound);
  mCTableSound->WorkFromThread_OpenAL();
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildByModule_XXX( TTaskForModule& task, 
                                         TCallBackRegistrator0& cbInit, 
                                         TProgressTask& progress, 
																				 nsListModules::ID_Modules id_module)
{
  if( task.flgNeedInit )
  {
    cbInit.Notify();
    task.flgNeedInit = false;
  }

  TGameObject** ppGO = task.pipe.GetFirst();
  if( ppGO==NULL )
		return;

  TGameObject* pGO = *ppGO;
  TBehaviourPatternContext* pContext = pGO->GetContext();
	bool resultLoad = true;
  switch( id_module )
  {
		case nsListModules::PhysicEngine:
      resultLoad = pGO->GetModel()->LoadFromThread_Bullet(pContext);
      break;
    case nsListModules::GraphicEngine:
      resultLoad = pGO->GetModel()->LoadFromThread_Ogre(pContext);
      break;
    case nsListModules::SoundEngine:
      resultLoad = pGO->GetModel()->LoadFromThread_OpenAL(pContext);
      break;
  }
	if( resultLoad )
	{
		task.pipe.UnlinkData(ppGO);// отцепиться прежде, чем уничтожить первый из списка
		task.pipe.RemoveFirst();
		progress.mCurIndex++;
	}
}
//--------------------------------------------------------------------------------------------
