/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPattern.h"

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
void TBehaviourPattern::SetOrientation(nsMathTools::TVector4& v)
{
	mOrientQuaternion = v;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::GetOrientation(nsMathTools::TVector4& v)
{
	v = mOrientQuaternion;
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
const TPatternConfigItem::TMapStrStr* TBehaviourPattern::GetDefaultParameterMap()
{
	return mPtrDefaultParameterMap;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetParameterFromPattern(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPattern::GetParameterToPattern()
{
  return TContainer();
}
//------------------------------------------------------------------------
bool TBehaviourPattern::GetNeedSynchro()
{
  return true;//mStructParameterMap.flgMobility;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::UpdateFromGameItem(bool updateByMapParam)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::LoadByModule_Logic()
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::LoadByModule_Graphic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::LoadByModule_Physic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::LoadByModule_Sound(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::UnloadByModule_Logic()
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::UnloadByModule_Graphic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::UnloadByModule_Physic(bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::UnloadByModule_Sound(bool fast)
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
TBuilder_Ogre* TBehaviourPattern::GetBuilderOgre()
{
  return &g_BuilderOgre;
}
//------------------------------------------------------------------------
TBuilder_Bullet* TBehaviourPattern::GetBuilderBullet()
{
  return &g_BuilderBullet;
}
//------------------------------------------------------------------------
TBuilder_OpenAL* TBehaviourPattern::GetBuilderOpenAL()
{
  return &g_BuilderOpenAL;
}
//------------------------------------------------------------------------
TDestructor_Ogre*   TBehaviourPattern::GetDestructorOgre()
{
  return &g_DestructorOgre;
}
//------------------------------------------------------------------------
TDestructor_Bullet* TBehaviourPattern::GetDestructorBullet()
{
  return &g_DestructorBullet;
}
//------------------------------------------------------------------------
TDestructor_OpenAL* TBehaviourPattern::GetDestructorOpenAL()
{
  return &g_DestructorOpenAL;
}
//------------------------------------------------------------------------
int TBehaviourPattern::GetBaseType()
{
	return 0;
}
//------------------------------------------------------------------------
