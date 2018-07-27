/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifdef WIN32
#include <windows.h>
#include <atlconv.h>
#endif 

#include <string>
#include <vector>
#include <map>

#include "BL_Debug.h"
#include "GameEngine.h"
#include "InputCmdTornado.h"
#include "ShareMisc.h"
#include "ConverterLocale.h"
#include "ContainerTypes.h"
#include "FileOperation.h"

using namespace std;

// Назначение: упростить отладку игры разработчику (нет необходимости создавать с десяток
// исполняемых файлов, достаточно написать скрипт)
//-------------------------------------
typedef vector<string> TVectorStr;
void ViewHowUse();
bool GetArgvArgcConsole( int argc, char** argv, TVectorStr& vec_argv );
//-------------------------------------
#ifdef WIN32
INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR cmdLine, INT )
{
  char** argv = __argv;
  int argc = __argc;
#else
int main( int argc, char** argv )
{
#endif

  // установить текущую кодировку для мультибайтовой конвертации
  const char* sLocale = setlocale( LC_CTYPE/*LC_ALL*/, "" );
  sLocale = setlocale( LC_CTYPE, sLocale );
  if( sLocale == NULL )
  {
    BL_FIX_BUG();
  }

  SetCurrentPathByFile( argv[0] );

  TVectorStr vec_argv;
  bool resGet = GetArgvArgcConsole( argc, argv, vec_argv );

  TInputCmdTornado cmdTornado;
  cmdTornado.Init();
  cmdTornado.SetArg( vec_argv );
  if( resGet == false )
  {
    ViewHowUse();
    return -1;
  }
  //-----------------------------------------------------------------  
  auto pGame = new TGameEngine;
  if( cmdTornado.mInput.useConsole )
  {
    CreateConsole();
    printf( "%s\n", pGame->GetVersion().data() );
    printf( "----------------------------------------------\n" );
  }
  //-----------------------------------------------------------------  
  pGame->Work( cmdTornado.mInput.variant_use,
    cmdTornado.mInput.libName.data(), cmdTornado.mInput.param );
  delete pGame;
  return 0;
}
//-------------------------------------------------------------------------------
bool GetArgvArgcConsole( int argc, char** argv, TVectorStr& vec_argv )
{
  for( int i = 0; i < argc; i++ )
    vec_argv.push_back( string( argv[i] ) );
  return bool( argc > 0 );
}
//-------------------------------------------------------------------------------
void ViewHowUse()
{
  char* sMsgUtf8_En =
    "Invalid parameter input.\n"
    "The -d string is the name of the loadable library (required parameter).\n"
    "\n"
    "The -v string is option to be used from the library,\n"
    "by default use 0, (see GetDevTool(int variant)).\n"
    "\n"
    "The -c string is the key for showing console. The key is relevant only for Windows.\n"
    "\n"
    "The -p string is the key to the embodiment of the game.\n"
    "\n"
    "For example:\n"
    "Tornado.exe -v 0 -d GameImpl.dll -p port_src 1234 port_self 7777\n";

  // Ввиду того, что весь исходный код я переконвертировал в utf-8.
  char* sMsgUtf8_Ru =
    "Некорректный ввод параметров.\n"
    "Ключ -d имя загружаемой библиотеки (обязательный параметр).\n"
    "\n"
    "Ключ -v вариант, который будет использован из библиотеки,\n"
    "по-умолчанию используется 0, (см. GetDevTool(int variant)).\n"
    "\n"
    "Ключ -c показывает консоль. Ключ актуален только для Windows.\n"
    "\n"
    "Ключ -p строка, адресованная воплощению игры.\n"
    "\n"
    "Например:\n"
    "Tornado.exe -v 0 -d GameImpl.dll -p port_src 1234 port_self 7777\n";

  int ret = 0;
#ifdef WIN32  
  ret = GetSystemDefaultLangID();
#endif
  char* sMsgUtf8 = (ret == 1049) ? sMsgUtf8_Ru : sMsgUtf8_En;

#ifdef WIN32
  BL_MessageBug_Utf8( sMsgUtf8 );
#else
  BL_MessageBug( sMsgUtf8 );
#endif
}
//-------------------------------------------------------------------------------
