/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerEffectH
#define ManagerEffectH

#include "DXUT.h"
#include "ManagerResource.h"
#include "ExecShaderStack.h"


class TManagerEffect : public IManagerResource<ID3DXEffect>
{
  TExecShaderStack mExecShaderStack;

public:

  TManagerEffect();
  virtual ~TManagerEffect();

  virtual void* Load(const wchar_t* sPath);
  virtual void Reset();
  virtual void Lost();
  virtual void Destroy();

  virtual bool Set(char* bufferIn);
};


#endif

