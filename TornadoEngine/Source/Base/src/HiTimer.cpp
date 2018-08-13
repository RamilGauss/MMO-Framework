/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HiTimer.h"
#include <thread>
#include <chrono>

#ifdef WIN32
  #include <windows.h>
#else
  #include <time.h>
#endif

//#include <boost/thread/thread.hpp>
#include <boost/chrono/include.hpp>
#include <boost/chrono/time_point.hpp>

using namespace boost;

//------------------------------------------------------------------------------
uint64_t ht_GetUSCount()
{
  typedef chrono::process_real_cpu_clock type_clock;

  type_clock::time_point t = type_clock::now();
  return t.time_since_epoch().count();
}
//------------------------------------------------------------------------------
uint64_t ht_GetCycleCPUCount()
{
  typedef chrono::high_resolution_clock type_clock;

  type_clock::time_point t = type_clock::now();
  return t.time_since_epoch().count();
}
//------------------------------------------------------------------------------
// Задержка на миллисекунды
void ht_msleep( unsigned int ms )
{
  std::this_thread::sleep_for( std::chrono::milliseconds( ms ) );
//  // в силу того что под Windows XP boost кидается ассертом (см. chrono)
//#ifdef WIN32
//  Sleep(ms);
//#else
//  chrono::milliseconds time_sleep(ms);
//  this_thread::sleep_for( time_sleep );
//#endif
}
//------------------------------------------------------------------------------
unsigned int ht_GetMSCount()
{
#ifdef WIN32
  typedef chrono::process_real_cpu_clock type_clock;

  type_clock::time_point t = type_clock::now();
  return (unsigned int)(t.time_since_epoch().count()/1000000);
#else
  timespec v;
  clock_gettime(CLOCK_REALTIME, &v);
  return (unsigned int)(v.tv_sec*1000+v.tv_nsec/1000000);
#endif
}
//------------------------------------------------------------------------------
// Задержка на микросекунды
void ht_usleep( unsigned int us )
{
  bool ht_usleep( unsigned int us, THT_CheckFunc func );
  ht_usleep( us, (THT_CheckFunc)NULL );
}
//------------------------------------------------------------------------------
// Задержка на микросекунды c дополнительной проверкой состояния
// Результат: true - выход по результату func, false - выход по таймауту
bool ht_usleep( unsigned int us, THT_CheckFunc func )
{
  uint64_t start  = ht_GetUSCount();
  uint64_t finish = start + us;
  for( ; ht_GetUSCount() < finish; )
    if( func )
      if( func() )
        return true;
  return false;
}
//------------------------------------------------------------------------------

