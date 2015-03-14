/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EventGameEngine.h"
#include "TypeDef.h"

namespace nsGameEngine
{
#ifdef WIN32
#pragma pack(push, 1)
#endif
  struct TDescEvent 
  {
    int id; 
    std::string str;
  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif

  TDescEvent g_StrEvents[] = 
  {
    {eStartThreads,          "Создание и настройка модулей завершена, запуск потоков модулей."},
    {eStopThreads,           "Остановка потоков, причина %s."                                 },
    {eStopThreadsEnd,        "Остановка потоков."                                             },
    {eParseFileConveyerError,"Ошибка формата файла конвейера: %s."                            },
    {eModuleNotMade,         "Модуль с именем %s не создан."                                  },
    {eThreadsNotExist,       "Не созданы потоки"                                              },
  };
  
  bool GetStrEventsByID(int id, std::string& str)
  {
    int cnt = sizeof(g_StrEvents)/sizeof(TDescEvent);
    for( int i = 0 ; i < cnt ; i++ )
    {
      if(g_StrEvents[i].id==id)
      {
        str = g_StrEvents[i].str;
        return true;
      }
    } 
    return false;
  }
}
