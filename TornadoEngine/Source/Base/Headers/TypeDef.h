/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TypeDefH
#define TypeDefH

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
#else// Linux
  #ifndef DllExport_C
    #define DllExport_C
  #endif
  #ifndef DllExport
    #define DllExport
  #endif
#endif
//------------------------------------------------------------------------------
//-------------------   Управление байтовой упаковкой структур   ---------------
//------------------------------------------------------------------------------
#if defined( __GNUC__ )
  #define _PACKED  __attribute__ ((packed))
#elif defined ( WIN32 )
  #define _PACKED
#else
  #error unknown used _PACKED
#endif
//Использовать макрос следующим образом:
//    typedef struct {...} _PACKED name_strunt;
//    struct name_strunt {...} _PACKED;
//    struct _PACKED name_strunt {...};

//Для компиляторов под windows (Borland, Intel, MVC) использовать "сендвич"
//    #ifdef WIN32
//    #pragma pack(push, 1)
//    #endif
//    ...
//    #ifdef WIN32
//    #pragma pack(pop)
//    #endif
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
//-----------------------------------------------------------------------------
#endif