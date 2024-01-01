/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/HiTimer.h"
#include <thread>
#include <chrono>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include <sys/timeb.h>
#include <algorithm>

#ifdef WIN32
#include <windows.h>
#else
#include <time.h>
#endif

//------------------------------------------------------------------------------
uint64_t ht_GetUSCount()
{
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(now).count();
}
//------------------------------------------------------------------------------
// Задержка на миллисекунды
void ht_msleep(unsigned int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
//------------------------------------------------------------------------------
unsigned int ht_GetMSCount()
{
#ifdef WIN32
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
#else
    timespec v;
    clock_gettime(CLOCK_REALTIME, &v);
    return (unsigned int)(v.tv_sec * 1000 + v.tv_nsec / 1000000);
#endif
}
//------------------------------------------------------------------------------
std::string ht_GetTimeStr()
{
#ifdef WIN32
    struct _timeb timebuffer;
    _ftime(&timebuffer);
#else
    struct timeb timebuffer;
    ftime(&timebuffer);
#endif

    time_t time1;
    unsigned short millitm1;

    time1 = timebuffer.time;
    millitm1 = timebuffer.millitm;

    char str_time[1000];
    // формируем время в строку
    struct tm* my_time = localtime(&time1);

    sprintf(str_time, "%04d_%02d_%02d %02d:%02d:%02d.%03d\n\t",
        my_time->tm_year + 1900, my_time->tm_mon + 1, my_time->tm_mday,
        my_time->tm_hour, my_time->tm_min, my_time->tm_sec, millitm1);
    return str_time;
}
//------------------------------------------------------------------------------
// Задержка на микросекунды
void ht_usleep(unsigned int us)
{
    bool ht_usleep(unsigned int us, THT_CheckFunc func);
    ht_usleep(us, (THT_CheckFunc)NULL);
}
//------------------------------------------------------------------------------
// Задержка на микросекунды c дополнительной проверкой состояния
// Результат: true - выход по результату func, false - выход по таймауту
bool ht_usleep(unsigned int us, THT_CheckFunc func)
{
    uint64_t start = ht_GetUSCount();
    uint64_t finish = start + us;
    for (; ht_GetUSCount() < finish; )
        if (func)
            if (func())
                return true;
    return false;
}
//------------------------------------------------------------------------------

