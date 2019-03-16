/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <list>
#include "LoopList.h"

namespace nsECSFramework
{
  typedef unsigned int TEntityID;
  const TEntityID None = 0;

  typedef std::list<TEntityID> TEntityList;
  typedef TLoopList<TEntityID> TEntityLoopList;
}