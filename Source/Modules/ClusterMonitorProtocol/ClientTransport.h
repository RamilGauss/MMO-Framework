/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/DstEvent.h"
#include "MMOEngine/Include/Slave.h"

#include "ClusterMonitorProtocol/Packets.h"
#include "ClusterMonitorProtocol/BaseTransport.h"

namespace nsClusterMonitorProtocol
{
    class DllExport TClientTransport : public TBaseTransport
    {
        nsMMOEngine::TSlave mSlave;
    public:
        TClientTransport();
        virtual ~TClientTransport();

        void Connect(TIP_Port& ip_port, std::string& login, std::string& password);
        void Send(nsPackets::THeader* packet, int packetSize);
    };
}

