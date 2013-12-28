/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#ifndef LoaderDLLH
#define LoaderDLLH

#include "ILoaderDLL.h"

#ifdef WIN32
  #include <windows.h>
#else

#endif

//------------------------------------------------------------------
class TLoaderDLL : public ILoaderDLL
{
#ifdef WIN32
  HMODULE hModule;
#else
#endif

public:
  TLoaderDLL();
  virtual ~TLoaderDLL();

  virtual bool Init(const char* sPath);
  virtual void* Get(const char* nameFunc);
  virtual void Done();
};

#endif
