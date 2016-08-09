/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourPattern.h"

TBehaviourPattern::TBehaviourPattern()
{
  mGO = NULL;
}
//------------------------------------------------------------------------
TBehaviourPattern::~TBehaviourPattern()
{

}
//------------------------------------------------------------------------
std::string TBehaviourPattern::GetType()
{ 
  return mType;
}
//----------------------------------------------------------------
void TBehaviourPattern::SetType(std::string v)
{ 
  mType = v;
}
//----------------------------------------------------------------
void TBehaviourPattern::SetGameObject(TGameObject* p)
{
  mGO = p;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetParameterMap(TMapItem::TMapStrStr& m)
{
  return false;
}
//------------------------------------------------------------------------
void TBehaviourPattern::GetParameterMap(TMapItem::TMapStrStr& m)
{

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
  return false;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::LoadFromGameItem(TBaseItem* pBI, bool fast)
{
  return true;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::Unload(bool fast)
{
  return true;
}
//------------------------------------------------------------------------
void TBehaviourPattern::Thread_Logic()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::Thread_Ogre()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::Thread_Bullet()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::Thread_OpenAL()
{

}
//------------------------------------------------------------------------
int TBehaviourPattern::GetProgressLoad()
{
  return 0;
}
//------------------------------------------------------------------------
