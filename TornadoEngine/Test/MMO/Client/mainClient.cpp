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

class TClientDesc
{
public:
  typedef std::shared_ptr<nsMMOEngine::TClient> TShared_PtrClient;
  TShared_PtrClient mClient = TShared_PtrClient( new nsMMOEngine::TClient );

  // ms
  unsigned int mIntervalSendMsg = 1000000000;
  unsigned int mLastTimeSendMsg = ht_GetMSCount();

  std::string mMsg = "Hello, from client";
};


int main( int argc, char** argv )
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
  std::vector<TClientDesc*> pArrClient;
  for( int i = 0; i < inputArg.count; i++ )
  {
    auto pClientDesc = new TClientDesc();
    pClientDesc->mClient->Init( &makerTransport );
    nsMMOEngine::TDescOpen descOpen;
    descOpen.port = inputArg.begin_port + i;
    pClientDesc->mClient->Open( &descOpen );
    pClientDesc->mClient->SetDstObject( &handler );
    pClientDesc->mClient->SetSelfID( descOpen.port );

    pArrClient.push_back( pClientDesc );
  }

  auto createClientTime = ht_GetMSCount() - start;
  GetLogger( ClientLog )->WriteF( "createClientTime = %d ms\n", createClientTime );

  const char* sLocalHost = inputArg.ip_server.data();
  unsigned int masterIP = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();
  int indexClientOnLogin = 0;
  TIP_Port masterIP_port( masterIP, MASTER_PORT );
  while( true )
  {
    unsigned int startTime = ht_GetMSCount();
    // Login
    int cnt = std::min( inputArg.count, indexClientOnLogin + STEP_LOGIN );
    for( int i = indexClientOnLogin; i < cnt; i++ )
    {
      char sLogin[100];
      sprintf( sLogin, "%d", inputArg.begin_id + i );
      std::string login = sLogin;
      std::string password = CLIENT_PASSWORD;
      pArrClient[i]->mClient->Login( masterIP_port, login, password );
    }
    indexClientOnLogin = cnt;

    // Work

    for( int i = 0; i < indexClientOnLogin; i++ )
    {
      auto pClient = pArrClient[i];
      pClient->mClient->Work();

      if( pClient->mLastTimeSendMsg + pClient->mIntervalSendMsg > startTime )
      {
        pClient->mClient->SendUp( (char*) pClient->mMsg.data(), pClient->mMsg.size() );
        pClient->mLastTimeSendMsg = startTime;
      }
    }
    handler.Work();
    // burn rest time
    unsigned int deltaTime = ht_GetMSCount() - startTime;
    static int old_delta_time = -1;
    if( (old_delta_time != deltaTime) &&
      (deltaTime > 70) )
    {
      GetLogger( ClientLog )->WriteF( "dTime=%d\n", deltaTime );
      old_delta_time = deltaTime;
    }
    if( deltaTime < CLIENT_QUANT_TIME )
      ht_msleep( 1 );
    //ht_msleep(CLIENT_QUANT_TIME-deltaTime);
  }

  return 0;
}
//-----------------------------------------------------------------------
