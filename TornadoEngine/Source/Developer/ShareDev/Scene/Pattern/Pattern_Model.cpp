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

#include "ShapeItem.h"

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
	pDefaultParameterMap->insert(TPatternConfigItem::TMapStrStrVT(sNameGameItem,""));
	pDefaultParameterMap->insert(TPatternConfigItem::TMapStrStrVT(sMobility,"true"));

	mTypeContent = TModelItem::eModel;
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
bool TPattern_Model::UpdateFromGameItem(TBaseItem* pBI)
{
  return true;
}
//---------------------------------------------------------------------------
void TPattern_Model::LoadByModule_Logic()
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
    LoadModelsByModule_Logic(pModel->mMapNamePart);
  else
    LoadShapesByModule_Logic(pModel->mMapNamePart);
}
//---------------------------------------------------------------------------
bool TPattern_Model::LoadByModule_Graphic(bool fast)
{
  int cntPart = GetCountPart();
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
        TModelDesc* pModelDesc = (TModelDesc*)pDesc;
        pModelDesc->pModel->LoadByModule_Graphic();
      }
      else
      {
        TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;
        LoadShapeByModule_Graphic(pShapeDesc);
      }
    }
  }
	PostLoadByModule_Graphic();
	return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::LoadByModule_Physic( bool fast )
{
	int cntPart = GetCountPart();
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
				TModelDesc* pModelDesc = (TModelDesc*)pDesc;
				pModelDesc->pModel->LoadByModule_Physic();
			}
			else
			{
				TShapeDesc* pShapeDesc = (TShapeDesc*)pDesc;
				LoadShapeByModule_Physic(pShapeDesc);
			}
		}
	}
	PostLoadByModule_Physic();
	return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::LoadByModule_Sound( bool fast )
{
	return true;
}
//---------------------------------------------------------------------------
void TPattern_Model::UnloadByModule_Logic()
{

}
//---------------------------------------------------------------------------
bool TPattern_Model::UnloadByModule_Graphic( bool fast )
{
	return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::UnloadByModule_Physic( bool fast )
{
	return true;
}
//---------------------------------------------------------------------------
bool TPattern_Model::UnloadByModule_Sound( bool fast )
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
	int cntPart = GetCountPart();
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

				btMotionState* pMS = pShapeDesc->pRigidBody->getMotionState();
				btTransform trans;
				pMS->getWorldTransform(trans);
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
	}
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Physic()
{
  // проверка на изменение позиции и ориентации
	int cntPart = GetCountPart();
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
	}
}
//---------------------------------------------------------------------------
void TPattern_Model::SynchroByModule_Sound()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::LoadModelsByModule_Logic(TModelItem::TMapStrPart& mapNamePart)
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

      TModelDesc* pModelDesc = new TModelDesc;
      pModelDesc->namePart    = namePart;
      pModelDesc->nameVariant = variant.name;
			pModelDesc->pModel = (TPattern_Model*)pPattern;
      pModelDesc->pModel->SetNameGameItem(variant.nameItem);
      pModelDesc->pModel->SetMobility(GetMobility());// мобильность наследуется
      AddDesc(pModelDesc);

      pPattern->LoadByModule_Logic();// дальше по итерации
    }
  }
}
//---------------------------------------------------------------------------
void TPattern_Model::LoadShapesByModule_Logic(TModelItem::TMapStrPart& mapNamePart)
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

      TShapeDesc* pShape = new TShapeDesc;
      pShape->namePart      = namePart;
      pShape->nameVariant   = variant.name;
      pShape->nameShapeItem = variant.nameItem;
      if( variant.redefinitionMaterial.length() )
        pShape->nameMaterial = variant.redefinitionMaterial;
      else
        pShape->nameMaterial = pShapeItem->mNameMaterial;
      AddDesc(pShape);
    }
  }
}
//---------------------------------------------------------------------------
void TPattern_Model::LoadShapeByModule_Graphic(TShapeDesc* pShapeDesc)
{
  TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
  TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get(TFactoryGameItem::Shape,pShapeDesc->nameShapeItem);
  if( pShapeItem==NULL )
    return;

  TBuilder_Ogre* pBOgre = GetBuilderOgre();

  Ogre::Entity* pEntity = pBOgre->GetShapeMaker()->Build( pShapeItem );
	pShapeDesc->pEntity = pEntity;

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
void TPattern_Model::LoadShapeByModule_Physic(TShapeDesc* pShapeDesc)
{
	TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
	TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get(TFactoryGameItem::Shape,pShapeDesc->nameShapeItem);
	if( pShapeItem==NULL )
		return;

	int id_world = GetPhysicWorld();

	TBuilder_Bullet* pBBullet = GetBuilderBullet();
	btRigidBody* pRB = pBBullet->GetShapeMaker()->Build( id_world, pShapeItem );
	pShapeDesc->pRigidBody = pRB;

	//### TODO убрать, всё позиционирование производится после загрузки всех форм (PostLoad)
	// сделано временно для визуализации (отладка)
	nsMathTools::TVector3 pos;
	GetPosition(pos);
	btTransform& trans = pShapeDesc->pRigidBody->getWorldTransform();
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

	pShapeDesc->pRigidBody->setWorldTransform(trans);

	pShapeDesc->pRigidBody->setLinearVelocity(btVector3(0,-10,0));
	//pShapeDesc->pRigidBody->setAngularVelocity(btVector3(0,10,0));

	//btDiscreteDynamicsWorld* pWorld = TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(id_world);
	//###
}
//---------------------------------------------------------------------------
void TPattern_Model::PostLoadByModule_Graphic()
{

}
//---------------------------------------------------------------------------
void TPattern_Model::PostLoadByModule_Physic()
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
void TPattern_Model::AddDesc(TBaseDesc* pDesc)
{
	TMapStrPtrDesc* pMap = FindMapByNamePart(pDesc->namePart);
	if( pMap==NULL )
	{
		mMapNamePart_NameVariantDesc.insert(TMapStr_StrPtrDescVT(pDesc->namePart, TMapStrPtrDesc()));
		pMap = FindMapByNamePart(pDesc->namePart);
	}
	if( pMap->find(pDesc->nameVariant)==pMap->end() )
		pMap->insert(TMapStrPtrDescVT(pDesc->nameVariant, pDesc));
	else
	{
		BL_FIX_BUG();
	}
}
//--------------------------------------------------------------------------
TPattern_Model::TBaseDesc* TPattern_Model::GetDesc(std::string& namePart, std::string& nameVariant)
{
	TMapStrPtrDesc* pMap = FindMapByNamePart(namePart);
	if( pMap==NULL )
		return NULL;
	TMapStrPtrDescIt fitVariant = pMap->find(nameVariant);
	if( fitVariant==pMap->end() )
		return NULL;
	return fitVariant->second;
}
//--------------------------------------------------------------------------
void TPattern_Model::SetNameGameItem(std::string& name)
{
	SetFromParameterMap<std::string>(sNameGameItem, name);
}
//--------------------------------------------------------------------------
std::string TPattern_Model::GetNameGameItem()
{
	std::string nameGameItem;
	GetFromParameterMap<std::string>(sNameGameItem,nameGameItem);
	return nameGameItem;
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
	std::string mobility;
	GetFromParameterMap<std::string>(sMobility, mobility);
  bool flgMobility = mobility=="true" ? true : false;
	return flgMobility;
}
//--------------------------------------------------------------------------
int TPattern_Model::GetCountPart()
{
	return mMapNamePart_NameVariantDesc.size();
}
//--------------------------------------------------------------------------
std::string TPattern_Model::GetNamePart(int index)
{
	std::string namePart = "";
	if( index >= GetCountPart() || index < 0 )
		return namePart;
	TMapStr_StrPtrDescIt bit = mMapNamePart_NameVariantDesc.begin();
	for( int i = 0 ; i < index ; i++ )
		bit++;
	namePart = bit->first;
	return namePart;
}
//--------------------------------------------------------------------------
int TPattern_Model::GetCountVariant(std::string& namePart)
{
	TMapStrPtrDesc* pMap = FindMapByNamePart(namePart);
	if( pMap==NULL )
		return 0;
	return pMap->size();
}
//--------------------------------------------------------------------------
std::string TPattern_Model::GetNameVariant(std::string& namePart, int index)
{
	std::string nameVariant = "";
	TMapStrPtrDesc* pMap = FindMapByNamePart(namePart);
	if( pMap==NULL )
		return nameVariant;
	if( index >= GetCountVariant(namePart) || index < 0 )
		return nameVariant;

	TMapStrPtrDescIt bit = pMap->begin();
	for( int i = 0 ; i < index ; i++ )
		bit++;
	nameVariant = bit->first;
	return nameVariant;
}
//--------------------------------------------------------------------------
TPattern_Model::TMapStrPtrDesc* TPattern_Model::FindMapByNamePart(std::string& namePart)
{
	TMapStr_StrPtrDescIt fit = mMapNamePart_NameVariantDesc.find(namePart);
	if( fit==mMapNamePart_NameVariantDesc.end() )
		return NULL;
	return &(fit->second);
}
//--------------------------------------------------------------------------
TPattern_Model::TModelDesc::~TModelDesc()
{
	delete pModel;
}
//--------------------------------------------------------------------------
