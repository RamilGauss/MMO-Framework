/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#ifndef WIN32

#include "Base/Common/ILoaderDLL.h"

class TLoaderDLL_Unix : public ILoaderDLL
{

  void* pHandle;
public:
  TLoaderDLL_Unix();
  virtual ~TLoaderDLL_Unix();

  virtual bool Init( const char* sPath );
  virtual void* Get( const char* nameFunc );
  virtual void Done();
};

#endif
