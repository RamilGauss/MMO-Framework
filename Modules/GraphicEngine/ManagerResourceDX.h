/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerResourceDXH
#define ManagerResourceDXH

#include "ManagerEffect.h"
#include "ManagerTexture.h"


class TManagerResourceDX
{

  TManagerEffect  mManagerEffect;// хранение и загрузка шейдеров
  TManagerTexture mManagerTexture;

public:
  TManagerResourceDX();
  ~TManagerResourceDX();

  typedef 
    enum{eUndef       =-1,
         eTypeShader  = 0, 
         eTypeTexture = 1,
  }TypeResource;
  void Setup(IDirect3DDevice9* pd3dDevice);
  // настроить шейдеры движка

  bool Set(int type, void* bufferIn);

  void* Load(const wchar_t* sPath);

  void Reset();
  void Lost();
  void Destroy();

protected:
  TypeResource DefType(const wchar_t* sPath);
};


#endif