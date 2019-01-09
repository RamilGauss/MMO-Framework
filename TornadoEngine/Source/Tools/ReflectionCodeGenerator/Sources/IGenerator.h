/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "Config.h"
#include "TypeManager.h"
#include "ProgramInfo.h"
#include <string>

namespace nsReflectionCodeGenerator
{
  class IGenerator
  {
  protected:
    nsReflectionCodeGenerator::TConfig* mConfig = nullptr;
    TTypeManager* mTypeMng = nullptr;
  public:
    typedef std::list<std::string> TStrList;
    typedef std::pair<std::string, TStrList> TStrListPair;
    typedef std::list<TStrListPair> TPairList;
  public:
    IGenerator();
  };
}