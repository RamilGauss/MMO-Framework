/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HiTimerH
#define HiTimerH

#include "TypeDef.h"

//------------------------------------------------------------------------------
// Модуль работы с таймером высокого разрешения
//------------------------------------------------------------------------------

// Получение тиков процессора (с тактовой частотой процессора)
unsigned __int64 SHARE_EI ht_GetUSCount();

// Задержка на микросекунды
void SHARE_EI ht_usleep( unsigned int us );

// Задержка на миллисекунды
void SHARE_EI ht_msleep( unsigned int ms );

// Задержка на микросекунды c дополнительной проверкой состояния
// Результат: true - выход по результату func, false - выход по таймауту
typedef bool (*THT_CheckFunc)(void);
bool SHARE_EI ht_sleep( unsigned int us, THT_CheckFunc func );

// Время в миллисекундах с момента запуска ЭВМ или программы.
// Точность от 55 мсек и выше
unsigned int SHARE_EI ht_GetMSCount();
//------------------------------------------------------------------------------

#endif
