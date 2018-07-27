/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ServerTransport.h"
#include "MonitorEvents.h"

class TClusterMonitorServerHandler
{
  nsClusterMonitorProtocol::TServerTransport mServerTransport;

  TDstEvent mHandler;

  nsMMOEngine::TMaster* mMaster = nullptr;
public:
  TClusterMonitorServerHandler( unsigned char subNet, nsMMOEngine::TMaster* pMaster );

  void Work();

protected:
  void RecvPacketHandler( nsClusterMonitorProtocol::nsEvents::TPacketEvent* pPacketEvent );
};