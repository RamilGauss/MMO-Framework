/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MMOEngineReciverTransportH
#define MMOEngineReciverTransportH

#include "INetTransport.h"

namespace nsMMOEngine
{
  class INetTransport;
  class TSessionManager;
  class TReciverTransport
  {
    INetTransport*   mTransport;
    TSessionManager* mMngSession;
  public:
    TReciverTransport(INetTransport* pTransport, TSessionManager* pMS);
    ~TReciverTransport();
  private:
    void Recv( INetTransport::TDescRecv* pDescRecv);
    void Disconnect(TIP_Port* ip_port);
  };
}

#endif