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
#include <uv.h>
#include <errno.h>
#include "Handler.h"

nsMMOEngine::INetTransport* g_pTransport = nullptr;

THandler* g_Handler;

int main( int argc, char** argv )
{
  TBreakPacket g_BP;

  SetCurrentPathByFile( argv[0] );

  TInputCmdTestTransport inputCmd;
  bool res = inputCmd.SetArg( argc, argv );
  BL_ASSERT( res );

  TInputCmdTestTransport::TInput inputArg;
  inputCmd.Get( inputArg );

  char sLog[100];
  sprintf( sLog, "TestTransport%d", inputArg.self_port );

  GetLogger()->Register( "TestNetTransport" );
  GetLogger()->Init( sLog );
  GetLogger()->SetPrintf( false );

  TMakerNetTransport makerTransport;
  g_pTransport = makerTransport.New();
  g_Handler = new THandler( g_pTransport );

  g_pTransport->GetCallbackRecv()->Register( &THandler::Recv, g_Handler );
  g_pTransport->GetCallbackDisconnect()->Register( &THandler::Disconnect, g_Handler );
  g_pTransport->GetCallbackConnectFrom()->Register( &THandler::ConnectFrom, g_Handler );

  g_pTransport->Open( inputArg.self_port, inputArg.sub_net );
  g_pTransport->Start();

  bool resConnect = g_pTransport->Connect( inputArg.server_ip, inputArg.server_port );
  TIP_Port ip_port( inputArg.server_ip, inputArg.server_port);
  printf( "Connect to ip_port=%s, %s\n", ip_port.ToString(), resConnect ? "OK" : "FAIL" );

  unsigned int start = ht_GetMSCount();
  while( true )
  {
    unsigned int now_ms = ht_GetMSCount();

    if( resConnect && inputArg.ping_data.size() )
      if( now_ms > start + inputArg.ping_time )
      {
        inputArg.ping_time += 1000;

        g_BP.Reset();
        g_BP.PushBack( (char*)inputArg.ping_data.data(), inputArg.ping_data.size() );
        g_pTransport->Send( inputArg.server_ip, inputArg.server_port, g_BP );
      }

    TIP_Port** ppFisrt = g_Handler->mListDisc.GetFirst();
    while( ppFisrt )
    {
      TIP_Port* pIP_Port = *ppFisrt;
      if( pIP_Port->port == inputArg.server_port )
        resConnect = g_pTransport->Connect( inputArg.server_ip, inputArg.server_port );

      g_Handler->mListDisc.RemoveFirst();
      ppFisrt = g_Handler->mListDisc.GetFirst();
    }
  }

  return 0;
}
//-----------------------------------------------------------------------
