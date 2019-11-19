/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include "BL_Debug.h"
#include <string.h>
#include "InputCmdTestTransport.h"
#include "HiTimer.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include "ShareMisc.h"
#include "NetTransport/MakerNetTransport.h"
#include "MMOEngine/include/INetTransport.h"
#include "DataExchange2Thread.h"

#include "CryptoAES_Impl.h"
#include "SHA256.h"
#include "NetTransport/HistoryPacketTCP.h"
#include <errno.h>
#include "Handler.h"

#define SEND_COUNT 10000000

nsMMOEngine::INetTransport* g_pServerTransport = nullptr;
std::vector<nsMMOEngine::INetTransport*> g_pClientTransportVec;

unsigned short g_BeginPort = 30000;

THandler* g_Handler;

int main( int argc, char** argv )
{
  TInputCmdTestTransport inputCmd;
  bool res = inputCmd.SetArg( argc, argv );
  BL_ASSERT( res );

  TInputCmdTestTransport::TInput inputArg;
  inputCmd.Get( inputArg );

  GetLogger()->Register( "TestTransport" );
  GetLogger()->Init( "TestTransport" );
  GetLogger()->SetPrintf( false );

  TMakerNetTransport makerTransport;
  g_pServerTransport = makerTransport.New();
  g_Handler = new THandler( g_pServerTransport );

  g_pServerTransport->Open( g_BeginPort, inputArg.sub_net );
  g_pServerTransport->Start();

  // обязательно инициализировать лог
  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  resolver.Get( sLocalHost, inputArg.sub_net );
  auto server_ip = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();

  for ( int i = 0; i < inputArg.client_count; i++ )
  {
    auto pClient = makerTransport.New();

    //pClient->GetCallbackRecv()->Register( &THandler::Recv, g_Handler );
    //pClient->GetCallbackDisconnect()->Register( &THandler::Disconnect, g_Handler );
    //pClient->GetCallbackConnectFrom()->Register( &THandler::ConnectFrom, g_Handler );

    auto port = g_BeginPort + i + 1;
    pClient->Open( port, inputArg.sub_net );

    bool resConnect = pClient->Connect( server_ip, g_BeginPort );
    if ( resConnect == false )
      printf( "Connect fails port = %u\n", port );

    pClient->Start();
    g_pClientTransportVec.push_back( pClient );
  }

  auto pPacket = new char[inputArg.packet_size];

  TBreakPacket g_BP;
  while ( true )
  {
    unsigned int start = ht_GetMSCount();
    auto sendCount = SEND_COUNT / inputArg.client_count;
    int sent = 0;
    for ( int j = 0; j < sendCount; j++ )
    {
      for ( int i = 0; i < inputArg.client_count; i++ )
      {
        g_BP.Reset();
        g_BP.PushBack( pPacket, inputArg.packet_size );

        g_pServerTransport->Send( server_ip, g_BeginPort + i + 1, g_BP, false );
        sent++;
      }
    }
    unsigned int now_ms = ht_GetMSCount();

    auto delta = now_ms - start;
    float timePerPacket = ( delta * 1000.0f ) / sent;
    printf( "%f us\n", timePerPacket );

    ht_msleep( 2000 );
  }

  return 0;
}
//-----------------------------------------------------------------------
