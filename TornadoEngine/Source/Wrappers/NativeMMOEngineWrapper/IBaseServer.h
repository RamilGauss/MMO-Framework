/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperIBaseServerH
#define NativeMMOEngineWrapperIBaseServerH

namespace NativeMMOEngineWrapper
{
  class DllExport IBaseServer : public IBase
  {
  public:
    virtual bool IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword) = 0;
    virtual void DisconnectByKeyClient(unsigned int id_client) = 0;
    virtual void SendByClientKey(std::list<unsigned int>& l, char* p, int size ) = 0;
    virtual void SendDown(unsigned int id_session, char* p, int size, bool check = true ) = 0;
    virtual int  GetCountDown() = 0;
    virtual bool GetDescDown(int index, void* pDesc, int& sizeDesc) = 0;
  };
}

#endif