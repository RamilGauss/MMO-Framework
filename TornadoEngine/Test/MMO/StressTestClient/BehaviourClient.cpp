/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourClient.h"
#include <stdlib.h>
#include <time.h>
#include "MakerNetTransport.h"

TBehaviourClient::TBehaviourClient()
{
  srand( (unsigned) time( NULL ) );

  mState = eInit;
}
//------------------------------------------------------------------------------------
TBehaviourClient::~TBehaviourClient()
{

}
//------------------------------------------------------------------------------------
void TBehaviourClient::SetTimeNextStep( unsigned int timeNextState )
{
  mTimeNextState = (timeNextState != -1) ? timeNextState : RandomTime();
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Init( TMakerNetTransport* pMakerTransport, TInputCmdTestMMO_Client::TInput &inputArg )
{
  mInputArg = inputArg;

  mClient.reset( new nsMMOEngine::TClient );

  mClient->Init( pMakerTransport );
  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = mInputArg.begin_port;
  bool resOpen = mClient->Open( &descOpen );
  mClient->SetDstObject( &mHandler );
  mClient->SetSelfID( descOpen.port );

  if( resOpen == false )
    mState = eStop;
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Work()
{
  mClient->Work();
  mHandler.Work();

  unsigned int now = ht_GetMSCount();
  if( now < mTimeNextState )
    return;

  mTimeNextState = RandomTime();
  switch( mState )
  {
    case eInit:
    case eIdle:
      Connect();
      mState = eConnect;
      break;
    case eConnect:
      Close();
      mState = eIdle;
      break;
    case eStop:
      break;
  }
}
//------------------------------------------------------------------------------------
unsigned int TBehaviourClient::RandomTime()
{
  return ht_GetMSCount() + (unsigned int) (eDefTimeBegin + eDefTimeDelta * float( rand() ) / RAND_MAX);
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Connect()
{
  const char* sLocalHost = mInputArg.ip_server.data();
  unsigned int masterIP = boost::asio::ip::address_v4::from_string( sLocalHost ).to_ulong();
  TIP_Port ip_port( masterIP, MASTER_PORT );

  char sLogin[100];
  sprintf( sLogin, "%d", mInputArg.begin_id );
  std::string login = sLogin;
  std::string password = CLIENT_PASSWORD;

  mClient->Login( ip_port, login, password );
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Close()
{
  if( mClient->IsConnectUp() )
  {
    mClient->DisconnectUp();
    mHandler.IncreaseDisconnectUpCount();
  }
}
//------------------------------------------------------------------------------------
