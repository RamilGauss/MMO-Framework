/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "SingletonManager.h"
#include "Config.h"

namespace nsReflectionCodeGenerator
{
  class TConfigContainer
  {
  protected:
    TConfigContainer() { }
    friend class TSingletonManager;
  public:
    TConfig mConfig;
    std::string absPathDirJson;

    TConfig* Config() { return &mConfig; }
  };
}
