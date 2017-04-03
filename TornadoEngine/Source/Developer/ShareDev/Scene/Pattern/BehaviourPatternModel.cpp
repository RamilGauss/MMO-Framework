/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPatternModel.h"
#include "BehaviourPatternContext.h"

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


TBehaviourPatternModel::TBehaviourPatternModel()
{
	mCurCtx = NULL;
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
TBehaviourPatternContext* TBehaviourPatternModel::MakeNewConext()
{
  return new TBehaviourPatternContext(this);
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::GetDefaultParameterMap(TMapItem::TMapStrStr& m)
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::SetParameterFromPattern(TBehaviourPatternContext* pContext, TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPatternModel::GetParameterToPattern(TBehaviourPatternContext* pContext )
{
  return TContainer();
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::GetNeedSynchro(TBehaviourPatternContext* pContext)
{
  return true;//mStructParameterMap.flgMobility;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UpdateFromGameItem(TBehaviourPatternContext* pContext, TBaseItem* pBI)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::LoadFromThread_Logic(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::LoadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::LoadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::LoadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::UnloadFromThread_Logic(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UnloadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UnloadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//------------------------------------------------------------------------
bool TBehaviourPatternModel::UnloadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroFromThread_Logic(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroFromThread_Ogre(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroFromThread_Bullet(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::SynchroFromThread_OpenAL(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
TBuilder_Ogre*   TBehaviourPatternModel::GetBuilderOgre()
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
void TBehaviourPatternModel::SetContext(TBehaviourPatternContext* pContext)
{
	mCurCtx = pContext;
}
//------------------------------------------------------------------------
