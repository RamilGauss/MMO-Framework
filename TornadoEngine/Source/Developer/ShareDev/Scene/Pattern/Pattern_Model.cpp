/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Model.h"

#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "ModulePhysicEngine.h"
#include "FactoryGameItem.h"
#include "FactoryBuilderTool_Shape_Ogre.h"
#include "FactoryBuilderTool_Shape_Bullet.h"

#include "ShapeItem.h"
#include "ShapeNode_Model.h"
#include "ModelNode_Model.h"

#include <btBulletDynamicsCommon.h>
#include <Dynamics/btDiscreteDynamicsWorld.h>
#include <boost/foreach.hpp>
#include <OgreRoot.h>

namespace nsPattern_Model
{
  const char* sNameGameItem = "NameGameItem";
  const char* sMobility     = "Mobility";

  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Model;

TPattern_Model::TPattern_Model() : 
  TBehaviourPattern(&g_DefaultParameterMap)
{
  Init(&g_DefaultParameterMap);
}
//---------------------------------------------------------------------------
TPattern_Model::TPattern_Model(TPatternConfigItem::TMapStrStr* pDefaultParameterMap) : 
  TBehaviourPattern(pDefaultParameterMap)
{
  Init(pDefaultParameterMap);
}
//---------------------------------------------------------------------------
TPattern_Model::~TPattern_Model()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::Init(TPatternConfigItem::TMapStrStr* pDefaultParameterMap)
{
  pDefaultParameterMap->insert(TPatternConfigItem::TMapStrStrVT(sNameGameItem,""));
  pDefaultParameterMap->insert(TPatternConfigItem::TMapStrStrVT(sMobility,"true"));

  mTypeContent = TModelItem::eModel;

  mBuilderBullet.SetPattern(this);
  mBuilderOgre.SetPattern(this);
  mBuilderLogic.SetPattern(this);

  //mDestructorBullet.SetPattern(this);
  //mDestructorOgre.SetPattern(this);

  //mModifyBullet.SetPattern(this);
  //mModifyOgre.SetPattern(this);

  //mUpdaterGIBullet.SetPattern(this);
  //mUpdaterGIOgre.SetPattern(this);

  mSynchronizerBullet.SetPattern(this);
  mSynchronizerLogic.SetPattern(this);
  mSynchronizerOgre.SetPattern(this);

  mIsGameObject = true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::SetParameterFromPattern(TContainer c)
{
  return true;
}
//---------------------------------------------------------------------------
TContainer TPattern_Model::GetParameterToPattern()
{
  TContainer c;
  return c;
}
//---------------------------------------------------------------------------
void TPattern_Model::BuildByModule_Logic()
{
  mBuilderLogic.Build();
}
//---------------------------------------------------------------------------
bool TPattern_Model::BuildByModule_Graphic(bool fast)
{
  mBuilderOgre.Build();
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::BuildByModule_Physic( bool fast )
{
  mBuilderBullet.Build();
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::BuildByModule_Sound( bool fast )
{
  return true;
}
//---------------------------------------------------------------------------
void TPattern_Model::DestructByModule_Logic()
{

}
//---------------------------------------------------------------------------
bool TPattern_Model::DestructByModule_Graphic( bool fast )
{
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::DestructByModule_Physic( bool fast )
{
  return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::DestructByModule_Sound( bool fast )
{
  return true;
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Logic()
{
  mSynchronizerLogic.Synchro();
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Graphic()
{
  mSynchronizerOgre.Synchro();
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Physic()
{
  mSynchronizerBullet.Synchro();
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Sound()
{

}
//---------------------------------------------------------------------------
TModelItem::eType TPattern_Model::GetTypeContent()
{
  return mTypeContent;
}
//--------------------------------------------------------------------------
void TPattern_Model::SetTypeContent(TModelItem::eType type)
{
  mTypeContent = type;
}
//--------------------------------------------------------------------------
void TPattern_Model::SetNameGameItem(std::string& name)
{
  SetFromParameterMap<std::string>(sNameGameItem, name);
}
//--------------------------------------------------------------------------
std::string TPattern_Model::GetNameGameItem()
{
  return GetFromParameterMap<std::string>(sNameGameItem);
}
//--------------------------------------------------------------------------
void TPattern_Model::SetMobility(bool v)
{
  std::string mobility = v ? "true" : "false";
  SetFromParameterMap<std::string>(sMobility, mobility);
}
//--------------------------------------------------------------------------
bool TPattern_Model::GetMobility()
{
  std::string mobility = GetFromParameterMap<std::string>(sMobility);
  bool flgMobility = mobility=="true" ? true : false;
  return flgMobility;
}
//--------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Model::GetBaseType()
{
  return TPatternNameManager::eModel;
}
//------------------------------------------------------------------------
void TPattern_Model::ActivatePhysicBody(bool force)
{
  int cntPart = mHierarchy.GetCount();
  for( int iPart = 0 ; iPart < cntPart ; iPart++ )
  {
    TBaseNode_Model* pNode = mHierarchy.Get(iPart);
    if( pNode==NULL )
      continue;
    if( GetTypeContent()==TModelItem::eShape )
    {
      TShapeNode_Model* pShapeNode = (TShapeNode_Model*)pNode;
      if( pShapeNode->mPtrRigidBody )
        pShapeNode->mPtrRigidBody->activate(force);
    }
    else
    {
      TModelNode_Model* pModelNode = (TModelNode_Model*)pNode;
      pModelNode->mPtrModel->ActivatePhysicBody();
    }
  }
}
//------------------------------------------------------------------------
void TPattern_Model::SetIsGameObject(bool v)
{
  mIsGameObject = v;
}
//---------------------------------------------------------------------------
bool TPattern_Model::IsGameObject()
{
  return mIsGameObject;
}
//---------------------------------------------------------------------------
void TPattern_Model::CalcGlobalLocation_Parts()
{
  mBuilderLogic.CalcGlobalLocation();
}
//---------------------------------------------------------------------------
void TPattern_Model::RankGlobalLocationCorrection()
{
  mBuilderLogic.RankGlobalLocationCorrection();
}
//---------------------------------------------------------------------------
void TPattern_Model::Event_AddModelNode(TModelNode_Model* p)
{  
  // сам паттерн должен подобрать своим частям настройки
  //p->mPtrModel->SetPatternConfig(patternConfig.name, patternConfig.nameVariant);
}
//---------------------------------------------------------------------------
