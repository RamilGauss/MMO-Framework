/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/include/Master.h"
#include "Packets.h"
#include "BaseTransport.h"

namespace nsClusterMonitorProtocol
{
  class DllExport TServerTransport : public TBaseTransport
  {
    nsMMOEngine::TMaster mMaster;
  public:
    TServerTransport();
    virtual ~TServerTransport();

    void Accept( unsigned int id, std::string& password );
    void Reject( unsigned int id );

    void Send( unsigned int id, nsPackets::THeader* packet, int packetSize );

  private:
  };
}

