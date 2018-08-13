/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "InputCmdTestMMO_ClusterMonitor.h"
#include "ClusterMonitorProtocol/ClientTransport.h"

class TClusterMonitorClientHandler
{
  TInputCmdTestMMO_ClusterMonitor cmi;

  nsClusterMonitorProtocol::TClientTransport client;
  TDstEvent handler;

public:
  TClusterMonitorClientHandler( int argc, char** argv );
  ~TClusterMonitorClientHandler();

  void Work();

};

