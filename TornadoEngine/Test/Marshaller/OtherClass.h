/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "GeneratedClass.h"

class TOtherClass : public TGeneratedClass
{
public:
  bool operator < ( const TOtherClass& right ) const
  {
    if( mID < right.mID )
      return true;
    return false;
  }
};
