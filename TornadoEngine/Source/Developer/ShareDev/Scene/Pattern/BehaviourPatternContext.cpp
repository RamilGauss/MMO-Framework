/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPatternContext.h"
#include <boost/foreach.hpp>

#include "GameObjectComponent_Ogre.h"
#include "GameObjectComponent_Bullet.h"
#include "GameObjectComponent_OpenAL.h"
#include "BehaviourPatternModel.h"

TBehaviourPatternContext::TBehaviourPatternContext(TBehaviourPatternModel* pModel)
{
	mDefaultParameterMap = NULL;
  mModel = pModel;

  mGO  = NULL;
  mPhysicWorldID = -1;

  mPtrGraphic.reset(new TGameObjectComponent_Ogre);
  mPtrPhysic.reset(new  TGameObjectComponent_Bullet);
  mPtrSound.reset(new   TGameObjectComponent_OpenAL);
}
//------------------------------------------------------------------------
TBehaviourPatternContext::~TBehaviourPatternContext()
{

}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetPhysicWorld(int id_physic_world)
{
  mPhysicWorldID = id_physic_world;
}
//------------------------------------------------------------------------
int TBehaviourPatternContext::GetPhysicWorld()
{
	return mPhysicWorldID;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetModel(TBehaviourPatternModel* pModel)
{
  mModel = pModel;
	SetDefaultParameterMap(pModel->GetDefaultParameterMap());
}
//------------------------------------------------------------------------
TBehaviourPatternModel* TBehaviourPatternContext::GetModel()
{
  return mModel;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetGameObject(TGameObject* p)
{
  mGO = p;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetNameMapItem(std::string nameMap)
{
	mNameMapItem = nameMap;
}
//------------------------------------------------------------------------
std::string TBehaviourPatternContext::GetNameMapItem()
{
	return mNameMapItem;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetParameterMap(TPatternConfigItem::TMapStrStr& m)
{
  mParameterMap = m;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetPosition(nsMathTools::TVector3& v)
{
	mPosition = v;
}
//------------------------------------------------------------------------
bool TBehaviourPatternContext::GetPosition(nsMathTools::TVector3& v)
{
	v = mPosition;
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetOrientation(nsMathTools::TVector4& v)
{
	mOrientQuaternion = v;
}
//------------------------------------------------------------------------
bool TBehaviourPatternContext::GetOrientation(nsMathTools::TVector4& v)
{
	v = mOrientQuaternion;
  return true;
}
//------------------------------------------------------------------------
const TPatternConfigItem::TMapStrStr* TBehaviourPatternContext::GetParameterMap()
{
	return &mParameterMap;
}
//------------------------------------------------------------------------
void TBehaviourPatternContext::SetDefaultParameterMap(const TPatternConfigItem::TMapStrStr* pMap)
{
	mDefaultParameterMap = pMap;
}
//------------------------------------------------------------------------
