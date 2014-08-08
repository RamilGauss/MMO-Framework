/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ShareMisc.h"
#ifdef WIN32
	#include <windows.h>
	#include <conio.h>
	#include <fcntl.h>
	#include <io.h>
	#include <wchar.h>
	#include <stdio.h>
#else
#endif

int GetCountCoreCPU()
{
	int countCore = 1;
#ifdef WIN32
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	countCore = siSysInfo.dwNumberOfProcessors;
#endif
	return countCore;
}
//--------------------------------------------------
static bool g_flgConsoleExist = false;
void CreateConsole()
{
  if(g_flgConsoleExist) 
    return;
#ifdef WIN32
	BOOL resAllocConsole = AllocConsole();
  if(resAllocConsole==false)
    return;
	// Out
  int hCrt = _open_osfhandle((long) GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	FILE *hf = _fdopen( hCrt, "w" );
	*stdout = *hf;
#endif
  g_flgConsoleExist = true;
}
//--------------------------------------------------
void DeleteConsole()
{
#ifdef WIN32
  BOOL resFreeConsole = FreeConsole(); 
#endif
  g_flgConsoleExist = false;
}
//--------------------------------------------------
bool IsConsoleExist()
{
  return g_flgConsoleExist;
}
//--------------------------------------------------
