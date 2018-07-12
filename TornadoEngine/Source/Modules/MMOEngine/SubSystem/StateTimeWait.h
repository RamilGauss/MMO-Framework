/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include <map>

/// 

class TStateTimeWait
{
  typedef short State;

  struct TDesc
  {
    unsigned int waitTime = 0;
    unsigned int errorCode = 0;
  };

  typedef std::map<State, TDesc> TMapIntDesc;
  typedef TMapIntDesc::value_type TMapIntDescVT;

  TMapIntDesc mStateDescMap;

  enum
  {
    MaxState = std::numeric_limits<State>::max(),
    UndefState = MaxState
  };
  State mCurrentState = UndefState;
  // начало нахождения в текущем состоянии
  unsigned int mCurrentStateTime = 0;

public:
  void AddOrUpdateState( State state, unsigned int waitTime, unsigned int errorCode = 0 );
  void SetCurrentState( State state );
  void SetCurrentStateToUndef();
  // for current state                                                      
  bool IsStateTimeExpired( unsigned int now );

  unsigned int ErrorCode();
protected:
  unsigned int TimeWait();
};
