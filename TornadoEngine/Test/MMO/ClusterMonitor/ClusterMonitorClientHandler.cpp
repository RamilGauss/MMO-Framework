/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClusterMonitorClientHandler.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "ClusterMonitorProtocol/MonitorEvents.h"

TClusterMonitorClientHandler::TClusterMonitorClientHandler( int argc, char** argv )
{
  cmi.Init();
  cmi.SetArg( argc, argv );

  client.SetDstObject( &handler );
  client.SetSelfID( 0 );

  client.Open( cmi.mInput.self_port, cmi.mInput.subnet );
  TIP_Port ip_port;
  ip_port.port = cmi.mInput.server_port;
  ip_port.ip = boost::asio::ip::address_v4::from_string( cmi.mInput.server_ip ).to_ulong();
  client.Connect( ip_port, cmi.mInput.login, cmi.mInput.password );
}
//-----------------------------------------------------------------------------------
TClusterMonitorClientHandler::~TClusterMonitorClientHandler()
{

}
//-----------------------------------------------------------------------------------
void TClusterMonitorClientHandler::Work()
{
  client.Work();

  while( true )
  {
    auto pEvent = handler.GetEvent();
    if( pEvent == nullptr )
      break;
    auto pBaseEvent = (nsClusterMonitorProtocol::nsEvents::TBaseEvent*)pEvent->pContainer->GetPtr();
    switch( pBaseEvent->type )
    {
      case nsClusterMonitorProtocol::nsEvents::TryConnect:
        BL_FIX_BUG();
        break;
      case nsClusterMonitorProtocol::nsEvents::Connect:
      {
        printf( "Connect\n" );
        nsClusterMonitorProtocol::nsPackets::TRq_SlaveCount rqs;
        client.Send( &rqs, sizeof( rqs ) );
      }
      break;
      case nsClusterMonitorProtocol::nsEvents::Packet:
      {
        printf( "Recv packet\n" );
        auto pPacketEvent = (nsClusterMonitorProtocol::nsEvents::TPacketEvent*)pBaseEvent;
        switch( pPacketEvent->pHeader->type )
        {
          case nsClusterMonitorProtocol::nsPackets::An_SlaveCount:
          {
            auto pAnswer = (nsClusterMonitorProtocol::nsPackets::TAn_SlaveCount*) pPacketEvent->pHeader;
            printf( "Slave cnt = %d\n", pAnswer->cnt );

            nsClusterMonitorProtocol::nsPackets::TCmd_CreateGroupAllClients cmdCreateGroup;
            client.Send( &cmdCreateGroup, sizeof( cmdCreateGroup ) );
          }
          break;
        }
      }
      break;
    }
    delete pEvent;
  }
}
//-----------------------------------------------------------------------------------