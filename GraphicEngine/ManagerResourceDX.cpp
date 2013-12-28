/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <atlconv.h>
#include <algorithm>

#include "ManagerResourceDX.h"
#include "Logger.h"
#include "IGraphicEngine.h"

using namespace std;

TManagerResourceDX::TManagerResourceDX()
{

}
//--------------------------------------------------------------------
TManagerResourceDX::~TManagerResourceDX()
{

}
//--------------------------------------------------------------------
bool TManagerResourceDX::Set(int type, void* bufferIn)
{
  bool res = false;
  switch(type)
  {
    case eTypeShader:
      res = mManagerEffect.Set((char*)bufferIn);
      break;
    case eTypeTexture:
      break;
    default:;
  }
  return res;
}
//--------------------------------------------------------------------
void* TManagerResourceDX::Load(const wchar_t* sPath)
{
  void* pResult = NULL;
  int code_ext = DefType(sPath);
  switch(code_ext)
  {
    case eTypeShader:
      pResult = mManagerEffect.Load(sPath);
      break;
    case eTypeTexture:
      pResult = mManagerTexture.Load(sPath);
      break;
    default:;
  }
  return pResult;
}
//--------------------------------------------------------------------
void TManagerResourceDX::Reset()
{
  mManagerEffect.Reset();
  mManagerTexture.Reset();
}
//--------------------------------------------------------------------
void TManagerResourceDX::Lost()
{
  mManagerEffect.Lost();
  mManagerTexture.Lost();
}
//--------------------------------------------------------------------
void TManagerResourceDX::Destroy()
{
  mManagerEffect.Destroy();
  mManagerTexture.Destroy();
}
//--------------------------------------------------------------------
TManagerResourceDX::TypeResource TManagerResourceDX::DefType(const wchar_t* sPath)
{
  wstring ws = sPath;
  int off = ws.rfind(L".");
  int size = ws.size();
  if(size>off+1)
  {
    const wchar_t* pExtension = ws.data()+off+1;
    if((wcscmp(pExtension,L"fx") ==0)||
       (wcscmp(pExtension,L"fxo")==0))
      return eTypeShader;
    if((wcscmp(pExtension,L"dds") ==0)||
       (wcscmp(pExtension,L"jpg") ==0)||
       (wcscmp(pExtension,L"bmp") ==0)||
       (wcscmp(pExtension,L"png") ==0)||
       (wcscmp(pExtension,L"jpeg")==0))
      return eTypeTexture;
  }

  USES_CONVERSION;
  
  GetLogger(STR_NAME_GE)->WriteF_time("Загрузчик ресурсов. Неопределенное расширение. %s\n",W2A(sPath));
  return eUndef;
}
//--------------------------------------------------------------------
void TManagerResourceDX::Setup(IDirect3DDevice9* pd3dDevice)
{
  mManagerEffect.SetDevice(pd3dDevice);
  mManagerTexture.SetDevice(pd3dDevice);
}
//--------------------------------------------------------------------
