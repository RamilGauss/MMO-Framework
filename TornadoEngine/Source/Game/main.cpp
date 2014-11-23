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
#include <map>

#include "BL_Debug.h"
#include "GameEngine.h"
#include "InputCmdTornado.h"
#include "ShareMisc.h"
#include "cnvCoderText.h"
#include "ContainerTypes.h"
#include "FileOperation.h"

using namespace std;

// Назначение: упростить отладку игры разработчику (нет необходимости создавать с десяток
// исполняемых файлов, достаточно написать скрипт)
//-------------------------------------
typedef vector<string> TVectorStr;
void ViewHowUse();
bool GetArgvArgcConsole(int argc, char** argv, TVectorStr& vec_argv);
//-------------------------------------
#ifdef WIN32
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR cmdLine, INT){
  char** argv = __argv;
  int argc = __argc;
#else
int main(int argc, char** argv){
#endif
  SetCurrentPath(argv[0]);

  TVectorStr vec_argv;
  bool resGet = GetArgvArgcConsole(argc, argv, vec_argv);

  TInputCmdTornado cmdTornado;
  if((resGet==false)||
	   (cmdTornado.SetArg(vec_argv)==false))
  {
    ViewHowUse();
    return -1;
  }
  //-----------------------------------------------------------------  
  TInputCmdTornado::TInput inputTornado;
  cmdTornado.Get(inputTornado);
  //-----------------------------------------------------------------  
  if(inputTornado.useConsole)
  {
    CreateConsole();
    printf("Welcome to Tornado!\n");
    printf("----------------------------------------------\n");
  }
  //-----------------------------------------------------------------  
  TGameEngine *pGame = new TGameEngine;
  pGame->Work(inputTornado.variant_use, 
              inputTornado.libName.data(), 
              inputTornado.param);
  delete pGame;
  return 0;
}
//-------------------------------------------------------------------------------
bool GetArgvArgcConsole(int argc, char** argv, TVectorStr& vec_argv)
{
  for(int i = 0 ; i < argc ; i++)
    vec_argv.push_back(string(argv[i]));
  return bool(argc>0);
}
//-------------------------------------------------------------------------------
void ViewHowUse()
{
	// Ввиду того, что весь исходный код я переконвертировал в utf-8.
  char* sMsgUtf8 = 
		"Некорректный ввод параметров.\n"
    "Ключ -d имя загружаемой библиотеки (обязательный параметр).\n"
    "\n"
    "Ключ -p строка, адресованная воплощению игры.\n"
    "\n"
    "Ключ -v вариант, который будет использован из библиотеки,\n"
    "по-умолчанию используется 0, (см. GetXXXDeveloperTool(int variant).\n"
    "\n"
    "Ключ -c показывает консоль. Ключ актуален только для Windows.\n"
    "\n"
    "Например:\n"
    "Tornado.exe -v 0 -d ..\\Developer\\DLL\\DeveloperDLL.dll -p ip 192.168.23.226 port 1000\n";
#ifdef WIN32
  size_t lenMsgUtf8 = strlen(sMsgUtf8);
	TContainer cWin1251;
	cWin1251.SetData(NULL,lenMsgUtf8+1);
	memset(cWin1251.GetPtr(), 0, cWin1251.GetSize());
	convert_utf8_to_windows1251(sMsgUtf8, cWin1251.GetPtr(), lenMsgUtf8);
	BL_MessageBug(cWin1251.GetPtr());
#else
  BL_MessageBug(sMsgUtf8);
#endif
}
//-------------------------------------------------------------------------------
