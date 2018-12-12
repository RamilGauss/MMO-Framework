/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>
#include <functional>
#include "TypeDef.h"

class DllExport TStateMachine
{
  int* mStatePtr;

  std::list<int> mHistory;

public:
  typedef std::function<bool()> TCallBackFunc;
  typedef std::function<bool()> TActionFunc;

private:
  typedef std::map<int, TActionFunc> TIntFuncMap;
  TIntFuncMap mStateActionMap;
public:
  TStateMachine( int* pState ) : mStatePtr( pState ) { }

  template<typename TFunc, typename Type>
  void AddAction( int state, TFunc pFunc, Type pThis );

  void Work( TCallBackFunc beforeAction = nullptr, TCallBackFunc afterAction = nullptr )
  {
    while ( true )
    {
      if ( beforeAction && beforeAction() == false )
        return;
      auto state = mStatePtr [0];
      auto result = mStateActionMap [state]();
      if ( mStatePtr [0] != state )
        mHistory.push_back( state );
      if ( result == false )
        return;
      if ( afterAction && afterAction() == false )
        return;
    }
  }
};
//---------------------------------------------------------------------------------------
template<typename TFunc, typename Type>
void TStateMachine::AddAction( int state, TFunc pFunc, Type pThis )
{
  auto func = std::bind( pFunc, pThis );
  auto vt = TIntFuncMap::value_type( state, func );
  mStateActionMap.insert( vt );
}
//---------------------------------------------------------------------------------------


