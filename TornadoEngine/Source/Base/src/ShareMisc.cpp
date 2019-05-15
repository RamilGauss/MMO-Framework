/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ShareMisc.h"
#include "BL_Debug.h"
#include "FileOperation.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
//###
#include <boost/dll/runtime_symbol_info.hpp>
#include "BreakPacket.h"
//###
#ifdef WIN32
#include <windows.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include <wchar.h>
#include <stdio.h>
#include <intrin.h>
#else
#endif
//---------------------------------------------------------------------------
int GetCountCoreCPU()
{
  int countCore = 1;
#ifdef WIN32
  SYSTEM_INFO siSysInfo;
  GetSystemInfo( &siSysInfo );
  countCore = siSysInfo.dwNumberOfProcessors;
#else
  countCore = 1;// доделать
#endif
  return countCore;
}
//---------------------------------------------------------------------------
void cpuid_Crossplatform( int* CPUInfo, unsigned int inputVal )
{
#ifdef WIN32
  __cpuid( CPUInfo, inputVal );
  //__asm
  //{
  //  mov    eax, dword ptr [inputVal] 
  //  xor    ecx, ecx 
  //  cpuid       
  //  mov    esi, dword ptr [CPUInfo] 
  //  mov    dword ptr [esi],    eax 
  //  mov    dword ptr [esi+0x4],ebx 
  //  mov    dword ptr [esi+0x8],ecx 
  //  mov    dword ptr [esi+0xc],edx 
  //}
#else// linux
  //__asm
  {
    //mov    eax, dword ptr [inputVal] 
    //xor    ecx, ecx 
    //cpuid       
    //mov    esi, dword ptr [CPUInfo] 
    //mov    dword ptr [esi],    eax 
    //mov    dword ptr [esi+0x4],ebx 
    //mov    dword ptr [esi+0x8],ecx 
    //mov    dword ptr [esi+0xc],edx 
  }
#endif
}
//---------------------------------------------------------------------------
bool GetBrandCPU( std::string& CPUBrandString )
{
  int CPUInfo[4] = { -1 };
  const int sizeCPUInfo = sizeof( CPUInfo );
  char sCPUInfo[sizeCPUInfo + 1];
  cpuid_Crossplatform( &CPUInfo[0], 0x80000000 );
  unsigned nExIds = CPUInfo[0];
  if ( nExIds < 0x80000002 )
    return false;
  for ( unsigned int i = 0x80000002; i < nExIds; i++ )
  {
    cpuid_Crossplatform( &CPUInfo[0], i );
    memcpy( sCPUInfo, CPUInfo, sizeCPUInfo );
    sCPUInfo[sizeCPUInfo] = '\0';
    CPUBrandString += sCPUInfo;
  }
  int intel = CPUBrandString.find( "Intel" );
  if ( intel != -1 )
  {
    int findDog = CPUBrandString.find( "@" );
    if ( findDog != -1 )
    {
      boost::erase_tail( CPUBrandString, CPUBrandString.length() - findDog );
      boost::trim_right( CPUBrandString );
    }
  }
  return true;
}
//---------------------------------------------------------------------------
static bool g_flgConsoleExist = false;
void CreateConsole()
{
  if ( g_flgConsoleExist )
    return;
#ifdef WIN32
  BOOL resAllocConsole = AllocConsole();
  if ( resAllocConsole == false )
    return;
  // Out
  int hCrt = _open_osfhandle( (long) GetStdHandle( STD_OUTPUT_HANDLE ), _O_TEXT );
  FILE * hf = _fdopen( hCrt, "w" );
  *stdout = *hf;
#endif
  g_flgConsoleExist = true;
}
//--------------------------------------------------
void DeleteConsole()
{
#ifdef WIN32
  BOOL resFreeConsole = FreeConsole();
  BL_ASSERT( resFreeConsole );
#endif
  g_flgConsoleExist = false;
}
//--------------------------------------------------
bool IsConsoleExist()
{
  return g_flgConsoleExist;
}
//--------------------------------------------------
bool SetCurrentPathByFile( char* sPathFile )
{
  // иногда вызов происходит под отладкой, менять путь, чтобы был доступ к файлу с указанием ресурсов.
  char sAbsPath[1000];
  if ( FindAbsPath( sPathFile, sAbsPath, sizeof( sAbsPath ) ) == false )
  {
    BL_MessageBug( sPathFile );
    return false;
  }
  UpPath( sAbsPath );// нужен путь к папке, а не к файлу
  if ( SetCurrentPath( std::string( sAbsPath ) ) == false )
  {
    BL_MessageBug( sPathFile );
    return false;
  }
  return true;
}
//--------------------------------------------------
