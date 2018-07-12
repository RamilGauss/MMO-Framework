/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "StateTimeWait.h"
#include "HiTimer.h"

void TStateTimeWait::AddOrUpdateState( State state, unsigned int waitTime, unsigned int errorCode )
{
  TDesc desc{ waitTime, errorCode };
  auto fit = mStateDescMap.find( state );
  if( fit == mStateDescMap.end() )
    mStateDescMap.insert( TMapIntDescVT( state, desc ) );
  else
    fit->second = desc;
}
//--------------------------------------------------------------------------------
unsigned int TStateTimeWait::TimeWait()
{
  return mStateDescMap[mCurrentState].waitTime;
}
//--------------------------------------------------------------------------------
unsigned int TStateTimeWait::ErrorCode()
{
  return mStateDescMap[mCurrentState].errorCode;
}
//--------------------------------------------------------------------------------
void TStateTimeWait::SetCurrentState( State state )
{
  mCurrentState = state;
  mCurrentStateTime = ht_GetMSCount();
}
//--------------------------------------------------------------------------------
void TStateTimeWait::SetCurrentStateToUndef()
{
  SetCurrentState( UndefState );
}
//--------------------------------------------------------------------------------
bool TStateTimeWait::IsStateTimeExpired( unsigned int now )
{
  if( mCurrentState == UndefState )
    return false;// когда не выставлено начальное состояние - время истечь не может

  return now > mCurrentStateTime + TimeWait();
}
//--------------------------------------------------------------------------------
