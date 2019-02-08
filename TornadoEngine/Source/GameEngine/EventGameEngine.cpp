/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EventGameEngine.h"
#include "TypeDef.h"

#include <map>
#include <string>

namespace nsGameEngine
{
  std::map<int, std::string> g_StrEvents =
  {
    {eAfterCreateDevTool,    "После создания инструмента разработчика"                        },
    {eAfterCreateModules,    "После создания всех модулей"                                    },
    {eStartThreads,          "Создание и настройка модулей завершена, запуск потоков модулей."},
    {eStopThreads,           "Остановка потоков, причина {}."                                 },
    {eStopThreadsEnd,        "Остановка потоков."                                             },
    {eParseFileConveyerError,"Ошибка формата файла конвейера: {}."                            },
    {eModuleNotMade,         "Модуль с именем {} не создан."                                  },
    {eThreadsNotExist,       "Не созданы потоки"                                              },
  };

  bool GetStrEventsByID( int id, std::string& str )
  {
    auto fit = g_StrEvents.find( id );
    if ( fit == g_StrEvents.end() )
      return false;
    str = fit->second;
    return true;
  }
}
