/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderGameMap_Object.h"
#include "BL_Debug.h"
#include "GameObject.h"
#include "FactoryBehaviourPattern.h"
#include "BehaviourPattern.h"

#include <boost/foreach.hpp>
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

TBuilderGameMap_Object::TBuilderGameMap_Object()
{

}
//------------------------------------------------------------------------------
TBuilderGameMap_Object::~TBuilderGameMap_Object()
{
	BOOST_FOREACH(TMapIntObjectVT& vt, mMapID_BuildObject)
	{
		TGameObject* pGameObject = vt.second.ptrGameObject;
		delete pGameObject;
	}

	mMapID_BuildObject.clear();
}
//------------------------------------------------------------------------------
void TBuilderGameMap_Object::Init(std::set<int>& useID_Module, 
				TFactoryBehaviourPattern* pFBP, int id_world)
{
	mID_World 		= id_world;
	mFBP      		= pFBP;
	mSetID_Module = useID_Module;
}
//------------------------------------------------------------------------------
void TBuilderGameMap_Object::SetNameMap(std::string nameMap)
{
	mNameMap = nameMap;
}
//------------------------------------------------------------------------------
int TBuilderGameMap_Object::Begin(TMapItem::TObject* pObj)
{
	BL_ASSERT(pObj);

	TGameObject* pGO = new TGameObject;
	pGO->SetID(pObj->id);
	TBehaviourPattern* pPattern = 
		mFBP->GetPatternByName(pObj->namePattern);
	pGO->SetPattern(pPattern);
	pPattern->SetPosition(pObj->position);
	pPattern->SetOrientation(pObj->rotationQuaternion);

	// ищем настройку паттерна
	TPatternConfigItem* pPatternConfig = 
		(TPatternConfigItem*)TModuleLogic::Get()->GetFGI()->
		Get(TFactoryGameItem::PatternConfig, pObj->patternConfig.name);
	BL_ASSERT(pPatternConfig);
	// вариант из настроек
	if( pPatternConfig )
	{
		TPatternConfigItem::TMapStrMapIt fitPC = 
			pPatternConfig->mMapVariant.find(pObj->patternConfig.nameVariant);
		if( fitPC!=pPatternConfig->mMapVariant.end() )
			pPattern->SetParameterMap( fitPC->second );
	}
	pPattern->SetNameMapItem(mNameMap);
	pPattern->SetPhysicWorld(mID_World);
	
	pGO->GetPattern()->LoadByModule_Logic();

	TObject object;
	object.ptrGameObject = pGO;
	object.ptrMapObject  = pObj;
	mMapID_BuildObject.insert(TMapIntObjectVT(pObj->id, object));
	return pObj->id;
}
//------------------------------------------------------------------------------
TGameObject* TBuilderGameMap_Object::Build(int idObject, bool fast)
{
	TMapIntObjectIt fit = mMapID_BuildObject.find(idObject);
	if( mMapID_BuildObject.end()==fit )
	{
		BL_FIX_BUG();
		return NULL;
	}
	TObject* pObj = &(fit->second);
	TBehaviourPattern* pPattern = pObj->ptrGameObject->GetPattern();
	if( pPattern==NULL )
	{
		BL_FIX_BUG();
		return NULL;
	}
	if( pObj->flgLoadPhysic==false )
		pObj->flgLoadPhysic = pPattern->LoadByModule_Physic(fast);
	if( pObj->flgLoadGraphic==false )
		pObj->flgLoadGraphic = pPattern->LoadByModule_Graphic(fast);
	if( pObj->flgLoadSound==false )
		pObj->flgLoadSound = pPattern->LoadByModule_Sound(fast);
	
	if( pObj->IsComplete() )
	{
		TGameObject* pGO = pObj->ptrGameObject;
		mMapID_BuildObject.erase(idObject);
		return pGO;
	}
	
	return NULL;
}
//------------------------------------------------------------------------------
TBuilderGameMap_Object::TObject::TObject()
{
	ptrGameObject = NULL;
	ptrMapObject  = NULL;

	flgLoadPhysic  = false;
	flgLoadGraphic = false;
	flgLoadSound   = false;
}
//------------------------------------------------------------------------------
bool TBuilderGameMap_Object::TObject::IsComplete()
{
	bool res = (flgLoadPhysic &&	flgLoadGraphic &&	flgLoadSound);
	return res;
}
//------------------------------------------------------------------------------
