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
	mContext = NULL;
}
//------------------------------------------------------------------------
TBehaviourPatternModel::~TBehaviourPatternModel()
{
	delete mContext;
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
const TPatternConfigItem::TMapStrStr* TBehaviourPatternModel::GetDefaultParameterMap()
{
	return NULL;
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
bool TBehaviourPatternModel::UpdateFromGameItem()
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
void TBehaviourPatternModel::SetContext()
{
	if( mContext )
		return;
	mContext = MakeNewConext();
	mContext->SetModel(this);
}
//------------------------------------------------------------------------
TBehaviourPatternContext* TBehaviourPatternModel::GetContext()
{
	return mContext;
}
//------------------------------------------------------------------------
