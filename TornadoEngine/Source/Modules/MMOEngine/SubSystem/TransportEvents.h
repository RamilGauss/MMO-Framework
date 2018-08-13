/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "ShareMisc.h"
#include "INetTransport.h"
#include "ContainerTypes.h"

namespace nsMMOEngine
{
  struct TBaseTransportEvent
  {
    enum Type
    {
      Recv, Disconnect, ConnectFrom
    };
    Type type;
    TIP_Port ip_port;
  };

  struct TRecvTransportEvent : public TBaseTransportEvent
  {
    TRecvTransportEvent()
    {
      type = TBaseTransportEvent::Recv;
    }

    INetTransport::eTypeRecv typeRecv;
    TContainer data;
  };
  struct TDisconnectTransportEvent : public TBaseTransportEvent
  {
    TDisconnectTransportEvent()
    {
      type = TBaseTransportEvent::Disconnect;
    }
  };
  struct TConnectFromTransportEvent : public TBaseTransportEvent
  {
    INetTransport* pTransport = nullptr;
    TConnectFromTransportEvent()
    {
      type = TBaseTransportEvent::ConnectFrom;
    }
  };
}