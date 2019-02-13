/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>

namespace nsGameEngine
{
  enum
  {
    eAfterCreateDevTool,
    eAfterCreateModules,
    eStartThreads,
    eStopThreads,
    eStopThreadsEnd,
    eParseFileConveyerError,
    eModuleNotMade,
    eThreadsNotExist,
  };

  extern bool GetStrEventsByID( int id, std::string& str );
}
