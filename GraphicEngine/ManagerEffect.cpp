/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerEffect.h"
#include "HiTimer.h"
#include "Logger.h"
#include "SaveOnHDD.h"
#include "IGraphicEngine.h"

#include <boost/foreach.hpp>

using namespace std;

TManagerEffect::TManagerEffect()
{

}
//----------------------------------------------------------------------------
TManagerEffect::~TManagerEffect()
{

}
//----------------------------------------------------------------------------
void* TManagerEffect::Load(const wchar_t* sPath)
{
  void* p = NULL;
  //HRESULT hr;
  TMapWStrPtr::iterator fit = mMapPathResource.find(wstring(sPath));
  TMapWStrPtr::iterator eit = mMapPathResource.end();
  if(fit==eit)// не нашли
  {
    // загрузить Shader
    ID3DXEffect* pEffect;

		DWORD dwShaderFlags = D3DX_PARAMETER_SHARED; 
		dwShaderFlags |= D3DXSHADER_DEBUG;
		LPD3DXBUFFER ppBufferError = NULL;
    D3DXCreateEffectFromFile( m_pd3dDevice, sPath, 
      NULL, NULL, dwShaderFlags, NULL, &pEffect, &ppBufferError );

		if(ppBufferError)
		{
			char* sError = (char*)ppBufferError->GetBufferPointer();
			int sizeError = ppBufferError->GetBufferSize();
			if(sizeError)
			{
				GetLogger(STR_NAME_GE)->Write(sError,sizeError);
			}

			SAFE_RELEASE(ppBufferError);
      BL_FIX_BUG();
		}

    p = pEffect;

    TMapWStrPtr::value_type val(wstring(sPath),pEffect);
    mMapPathResource.insert(val);
  }
  else// уже загружен
  {
    p = fit->second;
  } 
  return p;
}
//----------------------------------------------------------------------------
void TManagerEffect::Reset()
{
  HRESULT hr;
  BOOST_FOREACH(TMapWStrPtr::value_type& bit,mMapPathResource)
    V(bit.second->OnResetDevice());
}
//----------------------------------------------------------------------------
void TManagerEffect::Lost()
{
  HRESULT hr;
  BOOST_FOREACH(TMapWStrPtr::value_type& bit,mMapPathResource)
    V(bit.second->OnLostDevice());
}
//----------------------------------------------------------------------------
void TManagerEffect::Destroy()
{
  BOOST_FOREACH(TMapWStrPtr::value_type& bit,mMapPathResource)
    SAFE_RELEASE(bit.second);
  mMapPathResource.clear();
}
//----------------------------------------------------------------------------
bool TManagerEffect::Set(char* bufferIn)
{
  TShaderStack* pSS = (TShaderStack*)bufferIn;
  BOOST_FOREACH(TMapWStrPtr::value_type& bit,mMapPathResource)
    mExecShaderStack.Set(bit.second,pSS);
  return true;
}
//----------------------------------------------------------------------------