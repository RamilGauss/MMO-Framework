/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <vector>
#include <string.h>

#include <boost/asio/ip/impl/address_v4.ipp>
#include <boost/smart_ptr/scoped_array.hpp>
#include <boost/lexical_cast.hpp>

#include "BL_Debug.h"
#include "Client.h"
#include "CommonParam.h"
#include "InputCmdTestMMO_Client.h"
#include "HiTimer.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include "HandlerMMO_Client.h"
#include "MakerNetTransport.h"
#include "ClientDesc.h"

void StartClients( int argc, char** argv );

int main( int argc, char** argv )
{
  std::string title = "Title Client ";
  for( int i = 1; i < argc; i++ )
  {
    char s[1000];
    sprintf( s, "%s ", argv[i] );
    title += s;
  }
  system( title.data() );

  try
  {
    StartClients( argc, argv );
  }
  catch( ... )
  {
    printf( "exception!!!\n" );
    getchar();
  }
  return 0;
}

void StartClients( int argc, char** argv )
{
  TBreakPacket sendBP;
  InitLogger( ClientLog );

  auto start = ht_GetMSCount();

  THandlerMMO_Client handler;

  TInputCmdTestMMO_Client inputCmd;
  bool res = inputCmd.SetArg( argc, argv );
  BL_ASSERT( res );

  TInputCmdTestMMO_Client::TInput inputArg;
  inputCmd.Get( inputArg );

  TMakerNetTransport makerTransport;
  nsMMOEngine::TDescOpen descOpen;
  descOpen.subNet = inputArg.subnet;
  for( int i = 0; i < inputArg.count; i++ )
  {
    descOpen.port = inputArg.begin_port + i;
    auto pClientDesc = new TClientDesc();
    pClientDesc->mIntervalSendPing = inputArg.ping_time;
    pClientDesc->mPort = descOpen.port;
    pClientDesc->mClient->Init( &makerTransport );
    pClientDesc->mClient->Open( &descOpen );
    pClientDesc->mClient->SetDstObject( &handler );
    pClientDesc->mClient->SetSelfID( descOpen.port );

    handler.mArrClient.push_back( pClientDesc );
    handler.mClientDescMap.insert( THandlerMMO_Client::TPtrPtrMapVT( pClientDesc->mClient.get(), pClientDesc ) );

    auto procentage = (i + 1) * 100.0f / inputArg.count;
    printf( "\b\b\b\b\b\b\b\b\b%02.02f%%", procentage );
  }
  printf( "\n" );

  auto createClientTime = ht_GetMSCount() - start;
  GetLogger( ClientLog )->WriteF( "createClientTime = %d ms\n", createClientTime );

  const char* sLocalHost = inputArg.ip_server.data();
  unsigned int masterIP = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();
  int indexClientOnLogin = 0;
  TIP_Port masterIP_port( masterIP, MASTER_PORT );

  start = 0;
  unsigned int limitDeltaTime = 6000;// ms
  int iCycle = 0;
  bool flgNeedPrintEndLogin = true;

  while( true )
  {
    auto now = ht_GetMSCount();

    if( iCycle == 0 )// начало расчета скорости работы
      start = now;

    // Login
    std::string password = CLIENT_PASSWORD;
    int cnt = std::min( inputArg.count, indexClientOnLogin + STEP_LOGIN );
    for( int i = indexClientOnLogin; i < cnt; i++ )
    {
      char sLogin[100];
      sprintf( sLogin, "%d", inputArg.begin_id + i );
      std::string login = sLogin;
      handler.mArrClient[i]->mClient->Login( masterIP_port, login, password );
    }
    indexClientOnLogin = cnt;

    if( inputArg.count == indexClientOnLogin && flgNeedPrintEndLogin )
    {
      GetLogger( ClientLog )->WriteF( "End login ----------------------------------------------------\n" );
      flgNeedPrintEndLogin = false;
    }

    // Work
    for( auto pClient : handler.mArrClient )
      pClient->mClient->Work();

    handler.Work();

    iCycle++;
    auto delta = ht_GetMSCount() - start;
    if( delta >= limitDeltaTime )
    {
      auto speed_ms = delta * 1.0f / iCycle;
      if( handler.mPingCounter > 0 )
      {
        float meanPing = handler.mPingSumma * 1.0f / handler.mPingCounter;
        GetLogger( ClientLog )->WriteF( "time of cycle = %f ms, mean ping(worth) = %f(%u/%u), indexClientOnLogin = %d\n",
          speed_ms, meanPing, handler.mWorthPing, handler.mBestPing, indexClientOnLogin );
        handler.mWorthPing = 0;
        handler.mBestPing = 0xFFFFFFFF;
        handler.mPingSumma = 0;
        handler.mPingCounter = 0;
      }
      else
        GetLogger( ClientLog )->WriteF( "time of cycle = %f ms\n", speed_ms );

      iCycle = 0;
    }
  }
}
//-----------------------------------------------------------------------
