/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include <string>

#include "BL_Debug.h"
#include "CommonParam.h"
#include "MakerNetTransport.h"
#include "HiTimer.h"
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include "Slave.h"
#include "Master.h"
#include "SuperServer.h"
#include "HandlerMMO_Slave.h"
#include "HandlerMMO_Master.h"
#include "HandlerMMO_SuperServer.h"
#include <iostream>

#define COUNT_SLAVE 1

int main( int argc, char** argv )
{
  // обязательно инициализировать лог
  InitLogger( ServerLog );
  {
    std::string sLocalHost;
    TResolverSelf_IP_v4 resolver;
    int countIP_v4 = resolver.GetCount();
    for( int i = 0; i < countIP_v4; i++ )
    {
      if( resolver.Get( sLocalHost, i ) == false )
        continue;
      GetLogger( ServerLog )->WriteF( "ip=%s\n", sLocalHost.data() );
    }
  }

  std::vector<THandlerMMO_Slave*> arrHandlerSlave;

  TMakerNetTransport makerTransport;

  nsMMOEngine::TDescOpen descOpen;
  typedef std::shared_ptr<nsMMOEngine::TSlave> TShared_Ptr_Slave;
  std::vector<TShared_Ptr_Slave> arrSlave;
  for( int i = 0; i < COUNT_SLAVE; i++ )
  {
    THandlerMMO_Slave* pHandlerSlave = new THandlerMMO_Slave;
    TShared_Ptr_Slave pSlave = TShared_Ptr_Slave( new nsMMOEngine::TSlave );
    pSlave->Init( &makerTransport );
    descOpen.port = SLAVE_PORT + i;
    pSlave->Open( &descOpen );
    pSlave->SetLoad( 0 );// всегда в начале нет нагрузки
    pSlave->SetDstObject( pHandlerSlave );
    pSlave->SetSelfID( descOpen.port );
    arrSlave.push_back( pSlave );
    arrHandlerSlave.push_back( pHandlerSlave );
  }

  std::shared_ptr<nsMMOEngine::TMaster>      pMaster( new nsMMOEngine::TMaster );
  std::shared_ptr<nsMMOEngine::TSuperServer> pSuperServer( new nsMMOEngine::TSuperServer );
  std::shared_ptr<THandlerMMO> handlerMaster( new THandlerMMO_Master );
  std::shared_ptr<THandlerMMO> handlerSuperServer( new THandlerMMO_SuperServer );

  descOpen.port = MASTER_PORT;
  pMaster->Init( &makerTransport );
  pMaster->Open( &descOpen );
  pMaster->SetDstObject( handlerMaster.get() );
  pMaster->SetSelfID( descOpen.port );

  descOpen.port = SUPER_SERVER_PORT;
  pSuperServer->Init( &makerTransport );
  pSuperServer->Open( &descOpen );
  pSuperServer->SetDstObject( handlerSuperServer.get() );
  pSuperServer->SetSelfID( descOpen.port );

  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  if( resolver.Get( sLocalHost, 0 ) == false )
    return -1;

  // сначала мастер цепляется к суперсерверу,
  // потом slave-ы
  TIP_Port ssIP_Port;
  ssIP_Port.ip = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();
  ssIP_Port.port = SUPER_SERVER_PORT;
  std::string login = MASTER_LOGIN;
  std::string password = MASTER_PASSWORD;
  pMaster->ConnectUp( ssIP_Port, login, password );
  TIP_Port masterIP_Port;
  masterIP_Port.ip = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();
  masterIP_Port.port = MASTER_PORT;
  password = SLAVE_PASSWORD;
  for( int i = 0; i < COUNT_SLAVE; i++ )
  {
    char sLogin[100];
    sprintf( sLogin, "%d", i );
    login = SLAVE_LOGIN;// sLogin;
    arrSlave[i]->ConnectUp( masterIP_Port, login, password );
  }

  const unsigned int printInterval = 3000;
  auto printTime = ht_GetMSCount() + printInterval;
  while( true )
  {
    auto now = ht_GetMSCount();
    if( printTime < now )
    {
      THandlerMMO::PrintCC( ServerLog );
      printTime = now + printInterval;
    }

    unsigned int startTime = now;
    // Work
    // реакции мастера и суперсервера
    pSuperServer->Work();
    pMaster->Work();
    for( auto pSlave : arrSlave )
      pSlave->Work();
    // Handle
    handlerMaster->Work();
    handlerSuperServer->Work();
    for( auto pHandlerSlave : arrHandlerSlave )
      pHandlerSlave->Work();
    // burn rest time
    // замер времени слэйва
    unsigned int deltaTime = ht_GetMSCount() - startTime;
    if( deltaTime > 20 )
      GetLogger( ServerLog )->WriteF( "dTime=%d\n", deltaTime );
    if( deltaTime < SERVER_QUANT_TIME )
      ht_msleep( 1 );
  }
  return 0;
}
//-----------------------------------------------------------------------
