/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClusterMonitorServerHandler.h"
#include "CommonParam.h"
#include "HandlerMMO.h"

TClusterMonitorServerHandler::TClusterMonitorServerHandler( unsigned char subNet, nsMMOEngine::TMaster* pMaster )
{
  mMaster = pMaster;

  mServerTransport.SetDstObject( &mHandler );
  mServerTransport.SetSelfID( 0 );

  mServerTransport.Open( SERVER_MONITOR_PORT, subNet );
}
//----------------------------------------------------------------------------------------------
void TClusterMonitorServerHandler::Work()
{
  mServerTransport.Work();

  while( true )
  {
    auto pEvent = mHandler.GetEvent();
    if( pEvent == nullptr )
      break;

    auto pBaseEvent = (nsClusterMonitorProtocol::nsEvents::TBaseEvent*)pEvent->pContainer->GetPtr();
    switch( pBaseEvent->type )
    {
      case nsClusterMonitorProtocol::nsEvents::TryConnect:
      {
        printf( "Try connect\n" );
        auto pTryConnectEvent = (nsClusterMonitorProtocol::nsEvents::TTryConnectEvent*)pBaseEvent;
        std::string password = "1";
        mServerTransport.Accept( pTryConnectEvent->clientKey, password );
      }
      break;
      case nsClusterMonitorProtocol::nsEvents::Connect:
        printf( "Connect\n" );
        break;
      case nsClusterMonitorProtocol::nsEvents::Packet:
      {
        printf( "Recv packet\n" );
        RecvPacketHandler( (nsClusterMonitorProtocol::nsEvents::TPacketEvent*)pBaseEvent );
      }
      break;
    }
    delete pEvent;
  }
}
//----------------------------------------------------------------------------------------------
void TClusterMonitorServerHandler::RecvPacketHandler( nsClusterMonitorProtocol::nsEvents::TPacketEvent* pPacketEvent )
{
  switch( pPacketEvent->pHeader->type )
  {
    case nsClusterMonitorProtocol::nsPackets::Rq_SlaveCount:
    {
      nsClusterMonitorProtocol::nsPackets::TAn_SlaveCount an;
      an.cnt = mMaster->GetCountDown();
      mServerTransport.Send( pPacketEvent->clientKey, &an, sizeof( an ) );
    }
    break;
    case nsClusterMonitorProtocol::nsPackets::Cmd_CreateGroupAllClients:
    {
      std::list<unsigned int> clientIDList;
      unsigned int groupID;
      auto& s = *(THandlerMMO::GetClientKeySet());
      for( auto id : s )
      {
        clientIDList.push_back( id );
      }
      printf( "Clients count = %u\n", clientIDList.size() );
      if( clientIDList.size() )
      {
        printf( "Try create group\n" );
        mMaster->TryCreateGroup( clientIDList, groupID );
      }
    }
  }
}
//----------------------------------------------------------------------------------------------
