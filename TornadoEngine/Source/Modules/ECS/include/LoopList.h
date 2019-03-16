/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <list>
#include "TypeDef.h"

template<typename Type>
class DllExport TLoopList
{
public:
  typedef std::list<Type> List;
  typename typedef List::iterator Iterator;
private:
  List* mList;
  Iterator mCurrentIt;
public:
  TLoopList( List& tl )
  {
    mList = &tl;
    Reset();
  }
  bool Next( Type& t )
  {
    if ( mCurrentIt == mList->end() )
      return false;
    t = *mCurrentIt;
    mCurrentIt++;
    return true;
  }
  void Reset()
  {
    mCurrentIt = mList->begin();
  }
};
