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
void TBehaviourPattern::SetGameObject(TGameObject* p)
{
  mGO = p;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetInternalStateMap(TMapItem::TMapStrStr& m)
{
  return false;
}
//------------------------------------------------------------------------
void TBehaviourPattern::GetInternalStateMap(TMapItem::TMapStrStr& m)
{

}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetInternalStateC(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPattern::GetInternalStateC()
{
  return TContainer();
}
//------------------------------------------------------------------------
bool TBehaviourPattern::GetNeedSynchro()
{
  return false;
}
//------------------------------------------------------------------------
bool TBehaviourPattern::SetModify(TContainer c)
{
  return true;
}
//------------------------------------------------------------------------
TContainer TBehaviourPattern::GetModify()
{
  return TContainer();
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
