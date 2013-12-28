/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

//------------------------------------------------------------------------------
// Тип целевой платформы:
#define TD_WIN_NATIVE 0   // windows, разрешено применение WinAPI
#define TD_WIN_CROSS  1   // windows, кроссплатформенная реализация
#define TD_LINUX      2   // Linux

//------------------------------------------------------------------------------
//-------   Определение платформы сборки и выполнения библиотек BaseLib --------
//------------------------------------------------------------------------------
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)

  #define TD_WINDOWS

  #if defined(TD_CROSSPLATFORM)
              #define TD_TARGET TD_WIN_CROSS
  #else
              #define TD_TARGET TD_WIN_NATIVE
  #endif
#else //WIN32

  #define   TD_TARGET TD_LINUX

#endif

//------------------------------------------------------------------------------
//-----------   Определение макросов экспорта/импорта функций    ---------------
//------------------------------------------------------------------------------
#if defined(TD_WINDOWS)

  #ifndef SHARE_EI
    #define SHARE_EI            __declspec( dllimport )
  #endif
  #ifndef MMO_ENGINE_EI
    #define MMO_ENGINE_EI       __declspec( dllimport )
  #endif
	#ifndef NET_TRANSPORT_EI
		#define NET_TRANSPORT_EI    __declspec( dllimport )
	#endif
  #ifndef QTLIB_EI
    #define QTLIB_EI            __declspec( dllimport )
  #endif
  #ifndef GUI_EI
    #define GUI_EI              __declspec( dllimport )
  #endif
  #ifndef GRAPHIC_ENGINE_EI
    #define GRAPHIC_ENGINE_EI   __declspec( dllimport )
  #endif
  #ifndef PHYSIC_ENGINE_EI
    #define PHYSIC_ENGINE_EI    __declspec( dllimport )
  #endif
#else //TD_WINDOWS
  
  #define   SHARE_EI
  #define   MMO_ENGINE_EI
  #define   NET_TRANSPORT_EI
  #define   QTLIB_EI
  #define   GUI_EI
  #define   GRAPHIC_ENGINE_EI
  #define   PHYSIC_ENGINE_EI

#endif //TD_WINDOWS

//------------------------------------------------------------------------------
//-------------------   Управление байтовой упаковкой структур   ---------------
//------------------------------------------------------------------------------

#if defined( __GNUC__ )
  #define _PACKED  __attribute__ ((packed))
#elif defined( TD_WINDOWS ) //defined( __ICL ) || defined( _MSC_VER ) || defined(__BORLANDC__)
  #define _PACKED                     
#else
  #error unknown used _PACKED
#endif

//#define _PACKED  _PACKED

//Использовать макрос следующим образом:
//    typedef struct {...} _PACKED name_strunt;
//    or
//    struct name_strunt {...} _PACKED;
//    or
//    struct _PACKED name_strunt {...};
//
//Для компиляторов под windows (Borlad, Intel, MVC) использовать "сендвич"
//    #if defined( TD_WINDOWS )
//    #pragma pack(push, 1)
//    ...
//    #pragma pack(pop)
//    #endif


//------------------------------------------------------------------------------

#define DECLARE_TYPE( name )  \
              typedef T##name* P##name;         /*указатель на объект*/\
              typedef T##name& R##name;         /*ссылка на объект*/\
              typedef const T##name * PC##name; /*изменяемый указатель на const объект*/\
              typedef const T##name & RC##name; /*изменяемая ссылка на const объект*/
              //typedef T##name * const CP##name; /*const указатель на изменяемый объект*/
              //typedef T##name & const CR##name; /*const ссылка на изменяемый объект*/

#define DECLARE_CLASS( name )   class  T##name;   DECLARE_TYPE( name )
#define DECLARE_STRUCT( name )  struct T##name;   DECLARE_TYPE( name )


//------------------------------------------------------------------------------
//---------------          Сервисные макросы          --------------------------
//------------------------------------------------------------------------------
#define NO_TIME     -1              // не действительное значение времени (time_t)

#define PARAM( name, value )  value // Связывание в тексте названия параметра и его значения

#ifdef WIN32      // Мах допустимая длина полного имени файла (с путем)
  #define MAX_PATH    260           // Вместо определенного в Linux PATH_MAX = 4096
#endif

//-----------------------------------------------------------------------------

#endif

