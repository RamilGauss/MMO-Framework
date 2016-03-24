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

TBuilderGameMap::TBuilderGameMap()
{
  mFactoryGameItem = NULL;
  mMapItem    = NULL;
  mTableSound = NULL;
  mGameTableSound = NULL;
  mState = eIdle;
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::~TBuilderGameMap()
{
  delete mGameTableSound;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Init(std::vector<eTypeThread>& vec, TFactoryGameItem* pFactoryGameItem)
{
  mVecThread = vec;
  mFactoryGameItem = pFactoryGameItem;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BuildMap( TMapItem* pMI )
{
  if(CheckIdle()==false)
    return false;

  mMapItem = pMI;
  if( mMapItem==NULL )
    return false;
  mTableSound = 
    (TTableSoundItem*)mFactoryGameItem->Get( TFactoryGameItem::TableSound, mMapItem->mNameTableSound);
  if( mTableSound )
    mGameTableSound = new TGameTableSound;

/*  TPreBuilderCameraUp preBuilderCameraUp;
  preBuilderCameraUp.Set(mMapItem->mCameraUp);
  preBuilderCameraUp.Work();
  preBuilderCameraUp.GetTask();
  
  TPreBuilderGravityVector preBuilderGravityVector;
  preBuilderGravityVector.Set(mMapItem->mGravity);
  preBuilderGravityVector.Work();
  preBuilderGravityVector.GetTask();

  TPreBuilderGameObject preBuilderGameObject;
  preBuilderGameObject.Set(mMapItem->mListObject);
  preBuilderGameObject.Work();
  preBuilderGameObject.GetTask();
*/
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::AddObject( TMapItem::TObject* pObject )
{
  if(CheckIdle()==false)
    return false;

  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::DeleteObject( TGameObject* pObject )
{
  if(CheckIdle()==false)
    return false;

  return true;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Ogre()
{

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
void TBuilderGameMap::Get(std::vector<TGameObject*>& vecPtrGameObject)
{

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
     (mState==eObjectOperation))
    return false;
  return true;
}
//--------------------------------------------------------------------------------------------
