/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ILoaderDLLH
#define ILoaderDLLH

#include "TypeDef.h"

// интерфейс - попытка кросплатформенной реализации работы с Dll

class SHARE_EI ILoaderDLL
{
public:
  ILoaderDLL(){};
  virtual ~ILoaderDLL(){};

  virtual bool Init(const char* sPath) = 0;
  virtual void* Get(const char* nameFunc) = 0;
  virtual void Done() = 0;
};

#endif
