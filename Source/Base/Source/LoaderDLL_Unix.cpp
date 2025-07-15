/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef WIN32

#include <stddef.h>
#include "Base/Common/BL_Debug.h"
#include "Base/Common/LoaderDLL_Unix.h"

#include <dlfcn.h>

TLoaderDLL_Unix::TLoaderDLL_Unix()
{
  pHandle = nullptr;
}
//------------------------------------------------------------------
TLoaderDLL_Unix::~TLoaderDLL_Unix()
{
  Done();
}
//------------------------------------------------------------------
bool TLoaderDLL_Unix::Init( const char* sPath )
{
  pHandle = dlopen( sPath, RTLD_NOW );
  if ( pHandle == nullptr )
  {
    BL_MessageBug( dlerror() );
    return false;
  }
  return true;
}
//------------------------------------------------------------------
void* TLoaderDLL_Unix::Get( const char* nameFunc )
{
  void* ptrFunc = dlsym( pHandle, nameFunc );
  if ( ptrFunc == nullptr )
    BL_MessageBug( dlerror() );
  return ptrFunc;
}
//------------------------------------------------------------------
void TLoaderDLL_Unix::Done()
{
  int resClose = dlclose( pHandle );
  if ( resClose )
    BL_MessageBug( dlerror() );
  pHandle = nullptr;
}
//------------------------------------------------------------------

#endif
