/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/Include/INetTransport.h"

namespace nsMMOEngine
{
    class INetTransport;
    class TSessionManager;
    class TReceiverTransport
    {
        INetTransport* mTransport;
        TSessionManager* mMngSession;
    public:
        TReceiverTransport(INetTransport* pTransport, TSessionManager* pMS);
        ~TReceiverTransport();
    private:
        void Recv(INetTransport::TDescRecv* pDescRecv);
        void Disconnect(TIP_Port* ip_port);
        void ConnectFrom(TIP_Port* ip_port);
    };
}
