/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "Base/Common/ShareMisc.h"
#include "INetTransport.h"
#include "Base/Common/ContainerTypes.h"

namespace nsMMOEngine
{
    struct TBaseTransportEvent
    {
        enum Type
        {
            Recv, Disconnect, ConnectFrom
        };
        Type type = Recv;
        TIP_Port ip_port;

        virtual ~TBaseTransportEvent() {}
    };

    struct TRecvTransportEvent : public TBaseTransportEvent
    {
        TRecvTransportEvent()
        {
            type = TBaseTransportEvent::Recv;
            typeRecv = INetTransport::eTypeRecv::eTcp;
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

    using PBaseTransportEvent = std::shared_ptr<TBaseTransportEvent>;
}