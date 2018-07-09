/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPattern.h"

#include "ModuleLogic.h"
#include "FactoryGameItem.h"

TBehaviourPattern::TBehaviourPattern(TPatternConfigItem::TMapStrStr* pDefaultParameterMap)
{
  mGO            = NULL;
  mPhysicWorldID = -1;
  mPtrDefaultParameterMap = pDefaultParameterMap;
}
//------------------------------------------------------------------------
TBehaviourPattern::~TBehaviourPattern()
{

}
//------------------------------------------------------------------------
const TPatternConfigItem::TMapStrStr* TBehaviourPattern::GetDefaultParameterMap()
{
  return mPtrDefaultParameterMap;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetPatternConfig(std::string& namePatternConfig, 
                                          std::string& nameVariantPatternConfig)
{
  mNamePatternConfig        = namePatternConfig;
  mNameVariantPatternConfig = nameVariantPatternConfig;

  // ищем настройку паттерна
  TPatternConfigItem* pPatternConfig = 
    (TPatternConfigItem*)TModuleLogic::Get()->GetFGI()->
    Get(TFactoryGameItem::PatternConfig, mNamePatternConfig);
  BL_ASSERT(pPatternConfig);
  // вариант из настроек
  if( pPatternConfig==NULL )
    return;

  TPatternConfigItem::TMapStrMapIt fitPC = 
    pPatternConfig->mMapVariant.find(mNameVariantPatternConfig);
  if( fitPC!=pPatternConfig->mMapVariant.end() )
    SetParameterMap( fitPC->second );
}
//------------------------------------------------------------------------
std::string TBehaviourPattern::GetNamePatternConfig()
{
  return mNamePatternConfig;
}
//------------------------------------------------------------------------
std::string TBehaviourPattern::GetNameVariantPatternConfig()
{
  return mNameVariantPatternConfig;
}
//------------------------------------------------------------------------
std::string TBehaviourPattern::GetName()
{ 
  return mName;
}
//----------------------------------------------------------------
void TBehaviourPattern::SetName(std::string v)
{ 
  mName = v;
}
//----------------------------------------------------------------
void TBehaviourPattern::SetPosition(nsMathTools::TVector3& v)
{
  mPosition = v;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::GetPosition(nsMathTools::TVector3& v)
{
  v = mPosition;
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetOrientation(nsMathTools::TMatrix16& v)
{
  mOrientation = v;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::GetOrientation(nsMathTools::TMatrix16& v)
{
  v = mOrientation;
  return true;
}
//------------------------------------------------------------------------
TPatternConfigItem::TMapStrStr* TBehaviourPattern::GetParameterMap()
{
  return &mParameterMap;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetParameterMap(TPatternConfigItem::TMapStrStr& m)
{
  mParameterMap = m;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetGameObject(TGameObject* p)
{
  mGO = p;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetNameMapItem(std::string nameMap)
{
  mNameMapItem = nameMap;
}
//------------------------------------------------------------------------
std::string TBehaviourPattern::GetNameMapItem()
{
  return mNameMapItem;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SetPhysicWorld(int id_physic_world)
{
  mPhysicWorldID = id_physic_world;
}
//------------------------------------------------------------------------
int TBehaviourPattern::GetPhysicWorld()
{
  return mPhysicWorldID;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetParameterFromPattern(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPattern::GetParameterToPattern(bool full)
{
  return TContainer();
}
//------------------------------------------------------------------------
void TBehaviourPattern::BuildByModule_Logic()
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::BuildByModule_Graphic(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::BuildByModule_Physic(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::BuildByModule_Sound(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::DestructByModule_Logic()
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::DestructByModule_Graphic(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::DestructByModule_Physic(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::DestructByModule_Sound(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroByModule_Logic()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroByModule_Graphic()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroByModule_Physic()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SynchroByModule_Sound()
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::UpdateGameItem(TFactoryGameItem::TypeGameItem type)
{
  return false;
}
//------------------------------------------------------------------------
void TBehaviourPattern::SaveGameItemOnHDD(TFactoryGameItem::TypeGameItem type)
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::SaveOutDataOnHDD(TFactoryGameItem::TypeGameItem type)
{

}
//------------------------------------------------------------------------
TPatternNameManager::eBaseType TBehaviourPattern::GetBaseType()
{
  return TPatternNameManager::eBase;
}
//------------------------------------------------------------------------
