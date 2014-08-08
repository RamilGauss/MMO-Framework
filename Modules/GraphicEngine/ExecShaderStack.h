/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ExecShaderStackH
#define ExecShaderStackH

#include "DXUT.h"
#include <map>
#include <string>

class TShaderStack;

class TExecShaderStack
{

  typedef std::map<std::string, D3DXHANDLE > TMAP_HANDLE;
  typedef std::map<ID3DXEffect*, TMAP_HANDLE > TMAP_EFFECT;
  TMAP_EFFECT mMapEffect;

public:
  TExecShaderStack();
  ~TExecShaderStack();

  void Set(ID3DXEffect* pEffect, TShaderStack* shaderStack);



};

#endif