/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ExecShaderStack.h"
#include "ShaderStack.h"
#include "BL_Debug.h"

using namespace std;

TExecShaderStack::TExecShaderStack()
{

}
//-----------------------------------------------------------------------------------------------------
TExecShaderStack::~TExecShaderStack()
{

}
//-----------------------------------------------------------------------------------------------------
void TExecShaderStack::Set(ID3DXEffect* pEffect, TShaderStack* shaderStack)
{
  HRESULT hr;
  // проверить есть ли такой шейдер
  TMAP_EFFECT::iterator fit = mMapEffect.find(pEffect);
  TMAP_EFFECT::iterator eit = mMapEffect.end();
  if(fit==eit)
  {
    // не нашли
    TMAP_HANDLE mS_D3H;
    TMAP_EFFECT::value_type val(pEffect,mS_D3H);
    mMapEffect.insert(val);
    fit = mMapEffect.find(pEffect);
  }

  TMAP_HANDLE* pMapStrHandle = &(fit->second);

  int cnt = shaderStack->Count();
  for(int i = 0 ; i < cnt ; i++)
  {
    string str = shaderStack->GetName(i);
    TMAP_HANDLE::iterator mip = pMapStrHandle->find(str);
    TMAP_HANDLE::iterator meip = pMapStrHandle->end();
    D3DXHANDLE handle;
    if(mip!=meip)
    {
      handle = mip->second;
    }
    else
    {
      handle = pEffect->GetParameterBySemantic(0,str.data());
      BL_ASSERT(handle);
      TMAP_HANDLE::value_type val_handle(str,handle);
      pMapStrHandle->insert(val_handle);
    }
    int sizeData;
    void* pData = shaderStack->GetData(i,sizeData);
    V(pEffect->SetValue(handle,pData,sizeData));
  }
}
//-----------------------------------------------------------------------------------------------------