/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerTexture.h"
#include <boost/foreach.hpp>

using namespace std;

TManagerTexture::TManagerTexture()
{

}
//--------------------------------------------------------------------------
TManagerTexture::~TManagerTexture()
{

}
//--------------------------------------------------------------------------
void* TManagerTexture::Load(const wchar_t* sPath)
{
  HRESULT hr;
  IDirect3DTexture9* pTexture = NULL;
  TMapWStrPtr::iterator fit = mMapPathResource.find(wstring(sPath));
  TMapWStrPtr::iterator eit = mMapPathResource.end();
  if(fit==eit)// не нашли
  {
    V( D3DXCreateTextureFromFile( m_pd3dDevice, sPath,
      &pTexture ) );

    TMapWStrPtr::value_type val(wstring(sPath),pTexture);
    mMapPathResource.insert(val);
  }
  else// дубликат
  {
    pTexture = fit->second;
  }
  return pTexture;
}
//--------------------------------------------------------------------------
void TManagerTexture::Reset()
{
  
}
//----------------------------------------------------------------------------
void TManagerTexture::Lost()
{

}
//----------------------------------------------------------------------------
void TManagerTexture::Destroy()
{
  BOOST_FOREACH(TMapWStrPtr::value_type& bit,mMapPathResource)
    SAFE_RELEASE(bit.second);
  mMapPathResource.clear();
}
//----------------------------------------------------------------------------
bool TManagerTexture::Set(char* bufferIn)
{
  return true;  
}
//----------------------------------------------------------------------------