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
#include <OgreEntity.h>

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
	mRootNode = NULL;

	pDefaultParameterMap->insert(TPatternConfigItem::TMapStrStrVT(sNameGameItem,""));
	pDefaultParameterMap->insert(TPatternConfigItem::TMapStrStrVT(sMobility,"true"));

	mTypeContent = TModelItem::eModel;

	mBuilderBullet.SetPattern(this);
	mBuilderOgre.SetPattern(this);

	//mDestructorBullet.SetPattern(this);
	//mDestructorOgre.SetPattern(this);

	//mModifyBullet.SetPattern(this);
	//mModifyOgre.SetPattern(this);

	//mUpdaterResourcesBullet.SetPattern(this);
	//mUpdaterResourcesOgre.SetPattern(this);
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
	// найти имя модели
  std::string nameGameItem = GetNameGameItem();
	TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();

  TModelItem* pModel = (TModelItem*)pFGI->Get(TFactoryGameItem::Model, nameGameItem);
  if( pModel==NULL )
    return;
  
  // задача: создать модели по имени. При синхронизации менять положение и ориентацию форм или моделей
  SetTypeContent(pModel->mTypeCollection);
  if( pModel->mTypeCollection==TModelItem::eModel )
    BuildModelsByModule_Logic(pModel->mMapNamePart);
  else
    BuildShapesByModule_Logic(pModel->mMapNamePart);
}
//---------------------------------------------------------------------------
bool TPattern_Model::BuildByModule_Graphic(bool fast)
{
  int cntPart = mMngNode_Collection.GetCountPart();
  for( int iPart = 0 ; iPart < cntPart ; iPart++ )
  {
    std::string namePart = mMngNode_Collection.GetNamePart(iPart);
    int cntVariant = mMngNode_Collection.GetCountVariant(namePart);
    for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
    {
      std::string nameVariant = mMngNode_Collection.GetNameVariant(namePart, iVariant);
      TBaseNode_Model* pNode = mMngNode_Collection.Get(namePart, nameVariant);
      if( pNode==NULL )
        continue;
      if( pNode->type==TModelItem::eModel )
      {
        TModelNode_Model* pModelNode = (TModelNode_Model*)pNode;
        //pModelNode->pModel->BuildByModule_Graphic();
      }
      else
      {
        TShapeNode_Model* pShapeNode = (TShapeNode_Model*)pNode;
        BuildShapeByModule_Graphic(pShapeNode);
      }
    }
  }
	PostBuildByModule_Graphic();
	return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::BuildByModule_Physic( bool fast )
{
	int cntPart = mMngNode_Collection.GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		std::string namePart = mMngNode_Collection.GetNamePart(iPart);
		int cntVariant = mMngNode_Collection.GetCountVariant(namePart);
		for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
		{
			std::string nameVariant = mMngNode_Collection.GetNameVariant(namePart, iVariant);
			TBaseNode_Model* pNode = mMngNode_Collection.Get(namePart, nameVariant);
			if( pNode==NULL )
				continue;
			if( pNode->type==TModelItem::eModel )
			{
				TModelNode_Model* pModelNode = (TModelNode_Model*)pNode;
				//pModelNode->pModel->BuildByModule_Physic();
			}
			else
			{
				TShapeNode_Model* pShapeNode = (TShapeNode_Model*)pNode;
				BuildShapeByModule_Physic(pShapeNode);
			}
		}
	}
	PostBuildByModule_Physic();
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

}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Graphic()
{
	// синхронизируем всё!
/*	int cntPart = GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		std::string namePart = GetNamePart(iPart);
		int cntVariant = GetCountVariant(namePart);
		for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
		{
			std::string nameVariant = GetNameVariant(namePart, iVariant);
			TBaseDesc* pDesc = GetDesc(namePart, nameVariant);
			if( pDesc==NULL )
				continue;
			if( pDesc->type==TModelItem::eModel )
			{
				TModelDesc* pDescModel = (TModelDesc*)pDesc;
				pDescModel->pModel->SynchroByModule_Graphic();
			}
			else
			{
				TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;

				btTransform& trans = pShapeDesc->pRigidBody->getWorldTransform();//###
				btVector3& posBullet = trans.getOrigin();
				
				Ogre::Entity* pEntity = pShapeDesc->pEntity;
	
				Ogre::Vector3 posOgre;
				posOgre.x = posBullet.x();
				posOgre.y = posBullet.y();
				posOgre.z = posBullet.z();
				pEntity->getParentSceneNode()->setPosition(posOgre);

				btQuaternion quat = trans.getRotation();
				Ogre::Real w = quat.w(); 
				Ogre::Real x = quat.x(); 
				Ogre::Real y = quat.y();
				Ogre::Real z = quat.z();
				pEntity->getParentSceneNode()->setOrientation( w, x, y, z);
			}
		}
	}*/
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Physic()
{
  // проверка на изменение позиции и ориентации
/*	int cntPart = GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		std::string namePart = GetNamePart(iPart);
		int cntVariant = GetCountVariant(namePart);
		for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
		{
			std::string nameVariant = GetNameVariant(namePart, iVariant);
			TBaseDesc* pDesc = GetDesc(namePart, nameVariant);
			if( pDesc==NULL )
				continue;
			if( pDesc->type==TModelItem::eShape )
			{
				TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;

				const btVector3& velocity = pShapeDesc->pRigidBody->getLinearVelocity();
				float speed = velocity.length();
				if( speed > 15.0f )
				{
					int a = 0;
				}
			}
		}
	}*/
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Sound()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::BuildModelsByModule_Logic(TModelItem::TMapStrPart& mapNamePart)
{
  TFactoryBehaviourPattern* pFBP = TModuleLogic::Get()->GetFBP();
  TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
  // создать другие модели и сохранить в контексте
  BOOST_FOREACH( TModelItem::TMapStrPartVT& vtPart, mapNamePart )
  {
    std::string namePart = vtPart.first;
    BOOST_FOREACH( TModelItem::TVariant& variant, vtPart.second.vecVariant )
    {
      TModelItem* pModel = (TModelItem*)pFGI->Get( TFactoryGameItem::Model, variant.nameItem);
      if( pModel==NULL )
        continue;
      TBehaviourPattern* pPattern = pFBP->GetPatternByName(pModel->mNamePattern);
      if( pPattern==NULL )
        continue;

/*      TModelDesc* pModelDesc = new TModelDesc;
      pModelDesc->namePart    = namePart;
      pModelDesc->nameVariant = variant.name;
			pModelDesc->pModel = (TPattern_Model*)pPattern;
      pModelDesc->pModel->SetNameGameItem(variant.nameItem);
      pModelDesc->pModel->SetMobility(GetMobility());// мобильность наследуется
  */    //AddDesc(pModelDesc);

      pPattern->BuildByModule_Logic();// дальше по итерации
    }
  }
}
//---------------------------------------------------------------------------
void TPattern_Model::BuildShapesByModule_Logic(TModelItem::TMapStrPart& mapNamePart)
{
  TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
  BOOST_FOREACH( TModelItem::TMapStrPartVT& vtPart, mapNamePart )
  {
    std::string namePart = vtPart.first;
    BOOST_FOREACH( TModelItem::TVariant& variant, vtPart.second.vecVariant )
    {
      // передача данных от Логики к Физике и Графике для каждого потока ( создание формы )
      TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get( TFactoryGameItem::Shape, variant.nameItem);
      if( pShapeItem==NULL )
        continue;

      TShapeNode_Model* pShape = new TShapeNode_Model;
      pShape->namePart         = namePart;
      pShape->nameVariant      = variant.name;
      pShape->nameShapeItem    = variant.nameItem;
      if( variant.redefinitionMaterial.length() )
        pShape->nameMaterial = variant.redefinitionMaterial;
      else
        pShape->nameMaterial = pShapeItem->mNameMaterial;
			// наполнить менеджер узлов данными (но не выделять память под физический и графический объекты)
			mMngNode_Collection.Add(pShape);
    }
  }
}
//---------------------------------------------------------------------------
void TPattern_Model::BuildShapeByModule_Graphic(TShapeNode_Model* pShapeNode)
{
  TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
  TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get(TFactoryGameItem::Shape,pShapeNode->nameShapeItem);
  if( pShapeItem==NULL )
    return;

  Ogre::Entity* pEntity = mBuilderOgre.GetShapeMaker()->Build( pShapeItem );
	pShapeNode->mPtrEntity = pEntity;

	//### TODO убрать, всё позиционирование производится после загрузки всех форм (PostLoad)
	// сделано временно для визуализации (отладка)
	nsMathTools::TVector3 pos;
	GetPosition(pos);
	Ogre::Vector3 vPos(pos.x, pos.y, pos.z);
	pEntity->getParentSceneNode()->setPosition(vPos);
	pEntity->setCastShadows(true);

	nsMathTools::TVector4 orient;
	GetOrientation(orient);
	pEntity->getParentSceneNode()->setOrientation(orient.w, orient.x, orient.y, orient.z);
	//###
}
//---------------------------------------------------------------------------
void TPattern_Model::BuildShapeByModule_Physic(TShapeNode_Model* pShapeNode)
{
	TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
	TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get(TFactoryGameItem::Shape,pShapeNode->nameShapeItem);
	if( pShapeItem==NULL )
		return;

	int id_world = GetPhysicWorld();

	btRigidBody* pRB = mBuilderBullet.GetShapeMaker()->Build( id_world, pShapeItem );
	pShapeNode->mPtrRigidBody = pRB;

	//### TODO убрать, всё позиционирование производится после загрузки всех форм (PostLoad)
	// сделано временно для визуализации (отладка)
	nsMathTools::TVector3 pos;
	GetPosition(pos);
	btTransform& trans = pShapeNode->mPtrRigidBody->getWorldTransform();
	btVector3& posBullet = trans.getOrigin();
	posBullet.setX(pos.x);
	posBullet.setY(pos.y);
	posBullet.setZ(pos.z);

	nsMathTools::TVector4 orient;
	GetOrientation(orient);
	btQuaternion quat;
	quat.setX(orient.x);
	quat.setY(orient.y);
	quat.setZ(orient.z);
	quat.setW(orient.w);
	trans.setRotation(quat);

	pShapeNode->mPtrRigidBody->setWorldTransform(trans);

	//###
	pShapeNode->mPtrRigidBody->setLinearVelocity(btVector3(0,0,0));
	//pShapeDesc->pRigidBody->setAngularVelocity(btVector3(0,10,0));

	//btDiscreteDynamicsWorld* pWorld = TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(id_world);
	//###
}
//---------------------------------------------------------------------------
void TPattern_Model::PostBuildByModule_Graphic()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::PostBuildByModule_Physic()
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
TManagerNamePattern::eBaseType TPattern_Model::GetBaseType()
{
	return TManagerNamePattern::eModel;
}
//------------------------------------------------------------------------
void TPattern_Model::ActivatePhysicBody()
{
/*	int cntPart = GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		std::string namePart = GetNamePart(iPart);
		int cntVariant = GetCountVariant(namePart);
		for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
		{
			std::string nameVariant = GetNameVariant(namePart, iVariant);
			TBaseDesc* pDesc = GetDesc(namePart, nameVariant);
			if( pDesc==NULL )
				continue;
			if( pDesc->type==TModelItem::eShape )
			{
				TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;
				if( pShapeDesc->pRigidBody )
					pShapeDesc->pRigidBody->activate(force);
			}
		}
	}*/
}
//------------------------------------------------------------------------
void TPattern_Model::SetPosition(nsMathTools::TVector3& v)
{
	TBehaviourPattern::SetPosition(v);
}
//---------------------------------------------------------------------------
bool TPattern_Model::GetPosition(nsMathTools::TVector3& v)
{
	// если есть корень, то выдать его позицию
/*	TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;
	btTransform& trans = pShapeDesc->pRigidBody->getWorldTransform();
	btVector3& posBullet = trans.getOrigin();
	v.x = posBullet.x();
	v.y = posBullet.y();
	v.z = posBullet.z();
	return true;//TBehaviourPattern::GetPosition(v);
*/
	// иначе выдать то что задали
	return TBehaviourPattern::GetPosition(v);
}
//---------------------------------------------------------------------------
void TPattern_Model::SetOrientation(nsMathTools::TVector4& v)
{
	TBehaviourPattern::SetOrientation(v);
}
//---------------------------------------------------------------------------
bool TPattern_Model::GetOrientation(nsMathTools::TVector4& v)
{
	/*TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;
	btTransform& trans = pShapeDesc->pRigidBody->getWorldTransform();
	btQuaternion quat = trans.getRotation();
	v.w = quat.w(); 
	v.x = quat.x(); 
	v.y = quat.y();
	v.z = quat.z();*/
	
	return TBehaviourPattern::GetOrientation(v);
}
//---------------------------------------------------------------------------
