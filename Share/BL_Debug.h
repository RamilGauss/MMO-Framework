/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BL_DebugH
#define BL_DebugH

#include "TypeDef.h"

/*
  Warning!
  Никогда так не делай(под релизом будут проблемы, код не выполнится):
    BL_ASSERT(Func());
  Правильно:
    expression = Func();
    BL_ASSERT(expression);
*/


// Вывести на экран сообщение об отказе.
SHARE_EI bool BL_MessageBug( const char* lpszMsg );

// Вывести на экран сообщение об отказе.
SHARE_EI void BL_MessageBug( const char* lpszFileName, int nLine );

#ifdef _DEBUG
  // Проверить выражение <f> и вывести на экран сообщение об отказе в случае его ложности
  #define BL_ASSERT(f)          (void) ( (f) || (BL_MessageBug(__FILE__, __LINE__),0) )

  // Выполнить действие описываемое выражением <f>
  #define BL_DEBUG(f)           f

  // Вывести на экран сообщение об отказе. Глюк уже наступил
  #define BL_FIX_BUG()          BL_MessageBug(__FILE__, __LINE__)

#else
  #define BL_ASSERT(f) {}
  #define BL_DEBUG(f)  {}
  #define BL_FIX_BUG() {}
#endif  //_DEBUG


#endif  //BL_DebugH

