/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HiTimerH
#define HiTimerH

#include "TypeDef.h"

#include <boost/cstdint.hpp>

//------------------------------------------------------------------------------
// Модуль работы с таймером высокого разрешения
//------------------------------------------------------------------------------

// Получение тиков процессора (с тактовой частотой процессора)
boost::uint64_t DllExport ht_GetUSCount();

boost::uint64_t DllExport ht_GetCycleCPUCount();

// Задержка на микросекунды
void DllExport ht_usleep( unsigned int us );

// Задержка на миллисекунды
void DllExport ht_msleep( unsigned int ms );

// Задержка на микросекунды c дополнительной проверкой состояния
// Результат: true - выход по результату func, false - выход по таймауту
typedef bool (*THT_CheckFunc)(void);
bool DllExport ht_sleep( unsigned int us, THT_CheckFunc func );

// Время в миллисекундах с момента запуска ЭВМ или программы.
// Точность от 55 мсек и выше
unsigned int DllExport ht_GetMSCount();
//------------------------------------------------------------------------------

#endif
