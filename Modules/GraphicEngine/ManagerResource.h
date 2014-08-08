/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IManagerResourceH
#define IManagerResourceH

#include <map>
#include <string>
#include "BL_Debug.h"

template <class T>
class IManagerResource
{

protected:

  typedef std::map<std::wstring, T*> TMapWStrPtr;
  TMapWStrPtr mMapPathResource;
  
  IDirect3DDevice9* m_pd3dDevice;


public:

  IManagerResource(){m_pd3dDevice=NULL;}
  virtual ~IManagerResource(){BL_ASSERT(mMapPathResource.size()==0);}

  virtual void* Load(const wchar_t* sPath) = 0;
  virtual void Reset() = 0;
  virtual void Lost() = 0;
  virtual void Destroy() = 0;
  virtual bool Set(char* bufferIn) = 0;

  void SetDevice(IDirect3DDevice9* pd3dDevice){m_pd3dDevice=pd3dDevice;}

};

#endif