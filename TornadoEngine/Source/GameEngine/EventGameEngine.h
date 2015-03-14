/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EventGameEngineH
#define EventGameEngineH

#include <string>

namespace nsGameEngine
{
  enum
  {
    eStartThreads,
    eStopThreads,
    eStopThreadsEnd,
    eParseFileConveyerError,
    eModuleNotMade,
    eThreadsNotExist,
  };

  extern bool GetStrEventsByID(int id, std::string& str);
}

#endif
