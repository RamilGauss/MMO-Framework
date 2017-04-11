/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPatternModel.h"

#include <boost/foreach.hpp>

// вспомогательные классы для построения, разрушения и синхронизации игровых объектов
// Builder
static TBuilder_Ogre   g_BuilderOgre;
static TBuilder_Bullet g_BuilderBullet;
static TBuilder_OpenAL g_BuilderOpenAL;
// Destructor
static TDestructor_Ogre   g_DestructorOgre;
static TDestructor_Bullet g_DestructorBullet;
static TDestructor_OpenAL g_DestructorOpenAL;

TBehaviourPatternModel::TBehaviourPatternModel(TPatternConfigItem::TMapStrStr* pDefaultParameterMap)
{
	mGO            = NULL;
	mPhysicWorldID = -1;
	mPtrDefaultParameterMap = pDefaultParameterMap;
}
//------------------------------------------------------------------------
TBehaviourPatternModel::~TBehaviourPatternModel()
{

}
//------------------------------------------------------------------------
std::string TBehaviourPatternModel::GetName()
{ 
  return mName;
}
//----------------------------------------------------------------
void TBehaviourPatternModel::SetName(std::string v)
{ 
  mName = v;
}
//----------------------------------------------------------------
void TBehaviourPatternModel::SetPosition(nsMathTools::TVector3& v)
{
	mPosition = v;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::GetPosition(nsMathTools::TVector3& v)
{
	v = mPosition;
	return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SetOrientation(nsMathTools::TVector4& v)
{
	mOrientQuaternion = v;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::GetOrientation(nsMathTools::TVector4& v)
{
	v = mOrientQuaternion;
	return true;
}
//------------------------------------------------------------------------
TPatternConfigItem::TMapStrStr* TBehaviourPatternModel::GetParameterMap()
{
	return &mParameterMap;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SetParameterMap(TPatternConfigItem::TMapStrStr& m)
{
	mParameterMap = m;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SetGameObject(TGameObject* p)
{
	mGO = p;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SetNameMapItem(std::string nameMap)
{
	mNameMapItem = nameMap;
}
//------------------------------------------------------------------------
std::string TBehaviourPatternModel::GetNameMapItem()
{
	return mNameMapItem;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SetPhysicWorld(int id_physic_world)
{
	mPhysicWorldID = id_physic_world;
}
//------------------------------------------------------------------------
int TBehaviourPatternModel::GetPhysicWorld()
{
	return mPhysicWorldID;
}
//------------------------------------------------------------------------
const TPatternConfigItem::TMapStrStr* TBehaviourPatternModel::GetDefaultParameterMap()
{
	return mPtrDefaultParameterMap;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::SetParameterFromPattern(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPatternModel::GetParameterToPattern()
{
  return TContainer();
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::GetNeedSynchro()
{
  return true;//mStructParameterMap.flgMobility;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UpdateFromGameItem(bool updateByMapParam)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::LoadByModule_Logic()
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::LoadByModule_Graphic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::LoadByModule_Physic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::LoadByModule_Sound(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::UnloadByModule_Logic()
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UnloadByModule_Graphic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UnloadByModule_Physic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UnloadByModule_Sound(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroByModule_Logic()
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroByModule_Graphic()
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroByModule_Physic()
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroByModule_Sound()
{

}
//------------------------------------------------------------------------
TBuilder_Ogre* TBehaviourPatternModel::GetBuilderOgre()
{
  return &g_BuilderOgre;
}
//------------------------------------------------------------------------
TBuilder_Bullet* TBehaviourPatternModel::GetBuilderBullet()
{
  return &g_BuilderBullet;
}
//------------------------------------------------------------------------
TBuilder_OpenAL* TBehaviourPatternModel::GetBuilderOpenAL()
{
  return &g_BuilderOpenAL;
}
//------------------------------------------------------------------------
TDestructor_Ogre*   TBehaviourPatternModel::GetDestructorOgre()
{
  return &g_DestructorOgre;
}
//------------------------------------------------------------------------
TDestructor_Bullet* TBehaviourPatternModel::GetDestructorBullet()
{
  return &g_DestructorBullet;
}
//------------------------------------------------------------------------
TDestructor_OpenAL* TBehaviourPatternModel::GetDestructorOpenAL()
{
  return &g_DestructorOpenAL;
}
//------------------------------------------------------------------------
int TBehaviourPatternModel::GetBaseType()
{
	return 0;
}
//------------------------------------------------------------------------
