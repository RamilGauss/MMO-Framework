/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifdef WIN32

#include <stddef.h>
#include "BL_Debug.h"
#include "LoaderDLL_Win32.h"

#pragma warning(disable:4800)


TLoaderDLL_Win32::TLoaderDLL_Win32()
{
  hModule = nullptr;
}
//------------------------------------------------------------------
TLoaderDLL_Win32::~TLoaderDLL_Win32()
{
  Done();
}
//------------------------------------------------------------------
bool TLoaderDLL_Win32::Init( const char* sPath )
{
  hModule = LoadLibraryA( sPath );
  if( hModule == nullptr )
  {
    BL_FIX_BUG();
    return false;
  }
  return true;
}
//------------------------------------------------------------------
void* TLoaderDLL_Win32::Get( const char* nameFunc )
{
  void* ptrFunc = GetProcAddress( hModule, nameFunc );
  if( ptrFunc == nullptr )
  {
    BL_FIX_BUG();
  }
  return ptrFunc;
}
//------------------------------------------------------------------
void TLoaderDLL_Win32::Done()
{
  bool res = (bool) FreeLibrary( hModule );

  BL_ASSERT( res );
  hModule = nullptr;
}
//------------------------------------------------------------------

#endif