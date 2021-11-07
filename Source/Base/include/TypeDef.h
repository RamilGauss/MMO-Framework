/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

//------------------------------------------------------------------------------
//-----------   Определение макросов экспорта/импорта функций    ---------------
//------------------------------------------------------------------------------
#ifdef WIN32
  #ifndef DllExport_C
    #define DllExport_C extern "C" __declspec( dllexport )
  #endif
  #ifndef DllExport
    #define DllExport __declspec( dllexport )
  #endif
  #ifndef NoInline
    #define NoInline
  #endif
#else// Linux
  #ifndef DllExport_C
    #define DllExport_C
  #endif
  #ifndef DllExport
    #define DllExport
  #endif
  #ifndef NoInline
    #define NoInline __attribute__ ((noinline))
  #endif
#endif
//------------------------------------------------------------------------------
//-------------------   Управление байтовой упаковкой структур   ---------------
//------------------------------------------------------------------------------
//Для компиляторов под windows (Borland, Intel, MVC) использовать "сендвич"
//    #pragma pack(push, 1)
//    ...
//    #pragma pack(pop)
//------------------------------------------------------------------------------
//---------------          Сервисные макросы          --------------------------
//------------------------------------------------------------------------------
#ifndef MAX_PATH      // Мах допустимая длина полного имени файла (с путем)
  #define MAX_PATH 260           // Вместо определенного в Linux PATH_MAX = 4096
#endif
//-----------------------------------------------------------------------------
#ifdef WIN32
  #if _MSC_VER < 2000 
    #define USE_VOLATILE
  #else
    #define USE_NATIVE_ATOMIC_CXX11
  #endif
#endif
