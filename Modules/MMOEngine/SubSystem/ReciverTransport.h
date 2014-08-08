/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef RECIVER_TRANSPORT_H
#define RECIVER_TRANSPORT_H

#include "INetTransport.h"

class INetTransport;

namespace nsMMOEngine
{
	class TManagerSession;
	class TReciverTransport
  {
		INetTransport*   mTransport;
		TManagerSession* mMngSession;
  public:
    TReciverTransport(INetTransport* pTransport, TManagerSession* pMS);
    ~TReciverTransport();
	private:
		void Recv( INetTransport::TDescRecv* pDescRecv);
		void Disconnect(TIP_Port* ip_port);
  };
}

#endif