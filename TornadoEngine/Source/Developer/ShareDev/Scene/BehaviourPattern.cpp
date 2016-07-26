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
bool TBehaviourPattern::SetInternalState(TContainer c)
{
  return false;
}
//------------------------------------------------------------------------
TContainer TBehaviourPattern::GetInternalState()
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
void TBehaviourPattern::ThreadLogica()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::ThreadOgre()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::ThreadBullet()
{

}
//------------------------------------------------------------------------
void TBehaviourPattern::ThreadOpenAL()
{

}
//------------------------------------------------------------------------
