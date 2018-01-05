/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperIActiveServerH
#define NativeMMOEngineWrapperIActiveServerH

namespace NativeMMOEngineWrapper
{
  class DllExport IActiveServer : public IBaseServer
  {
  public:
    virtual void ConnectUp(unsigned int ip, unsigned short port,  
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
      unsigned char subNet = 0) = 0;
  };
}

#endif