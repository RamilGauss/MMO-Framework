/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperIClientH
#define NativeMMOEngineWrapperIClientH

namespace NativeMMOEngineWrapper
{
  class DllExport IClient
  {
  public:
    virtual void Login(unsigned int ip, unsigned short port, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword) = 0;
    virtual void LeaveQueue() = 0;
  };
}

#endif