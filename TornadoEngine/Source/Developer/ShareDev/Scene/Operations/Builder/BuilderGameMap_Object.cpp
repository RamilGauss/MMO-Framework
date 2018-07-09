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

#include "ModuleLogic.h"
#include "FactoryGameItem.h"

TBuilderGameMap_Object::TBuilderGameMap_Object()
{

}
//------------------------------------------------------------------------------
TBuilderGameMap_Object::~TBuilderGameMap_Object()
{
  for( auto& vt : mMapID_BuildObject)
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
  mID_World     = id_world;
  mFBP          = pFBP;
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
  if( mMapID_BuildObject.find(pObj->id)!=mMapID_BuildObject.end() )
  {
    BL_FIX_BUG();
    return -1;
  }
  BL_ASSERT(pObj);

  // неизменяемые параметры
  TGameObject* pGO = new TGameObject;
  pGO->SetID(pObj->id);
  TBehaviourPattern* pPattern = mFBP->GetPatternByName(pObj->namePattern);
  pGO->SetPattern(pPattern);
  pPattern->SetNameMapItem(mNameMap);
  pPattern->SetPhysicWorld(mID_World);

  // далее идут параметры, которые могут меняться в процессе
  pPattern->SetPatternConfig(pObj->patternConfig.name, pObj->patternConfig.nameVariant);
  pPattern->SetPosition(pObj->position);
  pPattern->SetOrientation(pObj->orientation);

  pPattern->BuildByModule_Logic();

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
  if( pObj->flgLoadPhysic==false )
    pObj->flgLoadPhysic = pPattern->BuildByModule_Physic(fast);
  if( pObj->flgLoadGraphic==false )
    pObj->flgLoadGraphic = pPattern->BuildByModule_Graphic(fast);
  if( pObj->flgLoadSound==false )
    pObj->flgLoadSound = pPattern->BuildByModule_Sound(fast);
  
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
  bool res = (flgLoadPhysic &&  flgLoadGraphic &&  flgLoadSound);
  return res;
}
//------------------------------------------------------------------------------
