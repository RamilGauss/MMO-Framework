/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <stddef.h>
#include "BL_Debug.h"
#include "LoaderDLL.h"

#ifdef WIN32
  #pragma warning(disable:4800)
#else

#endif

TLoaderDLL::TLoaderDLL()
{
#ifdef WIN32
  hModule = NULL;
#else
#endif
}
//------------------------------------------------------------------
TLoaderDLL::~TLoaderDLL()
{
  Done();
}
//------------------------------------------------------------------
bool TLoaderDLL::Init(const char* sPath)
{
#ifdef WIN32
  hModule = LoadLibraryA(sPath);
  if(hModule==NULL)
  {
    BL_FIX_BUG();
    return false;
  }
#else
#endif
  return true;
}
//------------------------------------------------------------------
void* TLoaderDLL::Get(const char* nameFunc)
{
  void* ptrFunc = NULL;
#ifdef WIN32
  ptrFunc = GetProcAddress(hModule, nameFunc);
  if(ptrFunc==NULL)
    BL_FIX_BUG();
#else
#endif
  return ptrFunc;
}
//------------------------------------------------------------------
void TLoaderDLL::Done()
{
  bool res = false;
#ifdef WIN32
  res = (bool)FreeLibrary(hModule);
#else
#endif
  BL_ASSERT(res);
  hModule = NULL;
}
//------------------------------------------------------------------
