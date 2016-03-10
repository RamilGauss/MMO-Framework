/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderGameMap.h"
#include "FactoryGameItem.h"
#include <boost\foreach.hpp>

TBuilderGameMap::TBuilderGameMap()
{
  mFactoryGameItem = NULL;

  mVecThread.push_back(eOGRE);
  mVecThread.push_back(eBullet);
  mVecThread.push_back(eOpenAL);
}
//--------------------------------------------------------------------------------------------
TBuilderGameMap::~TBuilderGameMap()
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::SetupListThread(std::vector<eTypeThread>& vec)
{
  mVecThread = vec;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::BeginLoad(std::string& nameMapItem, TFactoryGameItem* pFactoryGameItem)
{
  mNameMapItem     = nameMapItem;
  mFactoryGameItem = pFactoryGameItem;

  bool result = true;
  BOOST_FOREACH(eTypeThread& type, mVecThread)
  {
    switch(type)
    {
      case eOGRE:
        result &= PrepareTask_OGRE();
        break;
      case eBullet:
        result &= PrepareTask_Bullet();
        break;
      case eOpenAL:
        result &= PrepareTask_OpenAL();
        break;
    }
  }
  return result;
}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_OGRE(int& progress_procent)
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_Bullet(int& progress_procent)
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::BuildFromThread_OpenAL(int& progress_procent)
{

}
//--------------------------------------------------------------------------------------------
void TBuilderGameMap::Get(std::vector<TGameObject*>& vecPtrGameObject)
{

}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareTask_OGRE()
{
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareTask_Bullet()
{
  return true;
}
//--------------------------------------------------------------------------------------------
bool TBuilderGameMap::PrepareTask_OpenAL()
{
  return true;
}
//--------------------------------------------------------------------------------------------
