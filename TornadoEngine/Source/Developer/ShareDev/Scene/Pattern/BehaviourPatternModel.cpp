/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPatternModel.h"
#include "BehaviourPatternContext.h"

#include <boost/foreach.hpp>
//namespace nsBehaviourPatternModel
//{
//  const char* sMobility     = "Mobility";
//  const char* sNameGameItem = "NameGameItem";
//  const char* sVariant      = "Variant";
//};
//
//using namespace nsBehaviourPatternModel;

TBehaviourPatternModel::TBehaviourPatternModel()
{

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
  return new TBehaviourPatternContext(mName);
}
//------------------------------------------------------------------------
//void TBehaviourPatternModel::SetParameterMap(TMapItem::TMapStrStr& m)
//{
//  mParameterMap = m;
//}
////------------------------------------------------------------------------
//void TBehaviourPatternModel::GetDefualtParameterMap(TMapItem::TMapStrStr& m)
//{
//  m = mDefaultParameterMap;
//}
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
bool TBehaviourPatternModel::GetNeedSynchro()
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
void TBehaviourPatternModel::LoadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::LoadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::LoadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::UnloadFromThread_Logic(TBehaviourPatternContext* pContext)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::UnloadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::UnloadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast)
{

}
//------------------------------------------------------------------------
void TBehaviourPatternModel::UnloadFromThread_OpenAL(TBehaviourPatternContext* pContext, bool fast)
{

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

