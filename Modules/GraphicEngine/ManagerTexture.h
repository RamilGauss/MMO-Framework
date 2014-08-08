/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerTextureH
#define ManagerTextureH

#include "DXUT.h"
#include "ManagerResource.h"


class TManagerTexture : public IManagerResource<IDirect3DTexture9>
{

public:

  TManagerTexture();
  virtual ~TManagerTexture();

  virtual void* Load(const wchar_t* sPath);
  virtual void Reset();
  virtual void Lost();
  virtual void Destroy();

  virtual bool Set(char* bufferIn);

};


#endif

