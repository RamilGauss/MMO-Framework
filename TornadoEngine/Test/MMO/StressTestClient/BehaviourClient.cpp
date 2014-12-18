/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BehaviourClient.h"
#include <stdlib.h>
#include <time.h>
#include "MakerTransport.h"

TBehaviourClient::TBehaviourClient()
{
  srand((unsigned)time( NULL ));

  mState = eInit;
}
//------------------------------------------------------------------------------------
TBehaviourClient::~TBehaviourClient()
{

}
//------------------------------------------------------------------------------------
void TBehaviourClient::SetTimeNextStep(unsigned int timeNextState)
{
  mTimeNextState = (timeNextState!=-1) ? timeNextState : RandomTime();
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Init(TMakerTransport* pMakerTransport, TInputCmdTestMMO_Client::TInput &inputArg)
{
  mInputArg = inputArg;

  mClient.reset( new nsMMOEngine::TClient );

  mClient->Init(pMakerTransport);
  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = mInputArg.begin_port;
  bool resOpen = mClient->Open(&descOpen); 
  mClient->SetDstObject(&mHandler);
  mClient->SetSelfID(descOpen.port);

  if(resOpen==false)
    mState = eStop;
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Work()
{
  mClient->Work();
  mHandler.Work();

  unsigned int now = ht_GetMSCount();
  if(now < mTimeNextState)
    return;

  mTimeNextState = RandomTime();
  switch(mState)
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
  return ht_GetMSCount() + (unsigned int)(eDefTimeBegin + eDefTimeDelta * float(rand())/RAND_MAX);
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Connect()
{
  const char* sLocalHost = mInputArg.ip_server.data();
  unsigned int masterIP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();

  char sLogin[100];
  sprintf(sLogin, "%d", mInputArg.begin_id);

  mClient->Login(masterIP, MASTER_PORT,
    sLogin, strlen(sLogin), (void*)PASSWORD_CLIENT, strlen(PASSWORD_CLIENT));
}
//------------------------------------------------------------------------------------
void TBehaviourClient::Close()
{
  if(mClient->IsConnectUp())
  {
    mClient->DisconnectUp();
    mHandler.DecreaseCountConnection();
  }
}
//------------------------------------------------------------------------------------
