/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include "BL_Debug.h"
#include "Client.h"
#include "CommonParam.h"
#include <string.h>
#include "InputCmdTestMMO_Client.h"
#include "MakerTransport.h"
#include "HiTimer.h"
#include "NetSystem.h"
#include "Logger.h"
#include <boost/smart_ptr/scoped_array.hpp>
#include <vector>
#include "HandlerMMO_Client.h"


#include "MakerXML.h"
#include "IXML.h"

int main(int argc, char** argv)
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init("Client_Test");
  GetLogger()->SetPrintf(false);
  GetLogger()->SetEnable(false);

  THandlerMMO_Client handler;

  TInputCmdTestMMO_Client inputCmd;
  bool res = inputCmd.SetArg(argc, argv);
  BL_ASSERT(res);

  TInputCmdTestMMO_Client::TInput inputArg;
  inputCmd.Get(inputArg);

  TMakerTransport makerTransport;
  std::vector<nsMMOEngine::TClient*> pArrClient;
  for( int i = 0 ; i < inputArg.count ; i++ )
  {
    nsMMOEngine::TClient* pClient = new nsMMOEngine::TClient;
    pClient->Init(&makerTransport);
    nsMMOEngine::TDescOpen descOpen;
    descOpen.port = inputArg.begin_port + i;
    pClient->Open(&descOpen); 
    pClient->SetDstObject(&handler);
    pClient->SetSelfID(descOpen.port);
    
    pArrClient.push_back(pClient);
  }
  
#ifdef WIN32
  char* sLocalHost = ns_getSelfIP(0);
#else
  char sLocalHost[100];
  get_ip_first_eth(sLocalHost);
#endif
  unsigned int masterIP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
  int indexClientOnLogin = 0;
  while(true)
  {
    unsigned int startTime = ht_GetMSCount();
    // Login
    int cnt = std::min(inputArg.count, indexClientOnLogin+STEP_LOGIN);
    for( int i = indexClientOnLogin ; i < cnt ; i++ )
    {
      char sLogin[100];
      sprintf(sLogin, "%d", inputArg.begin_id + i);
      pArrClient[i]->Login(masterIP, MASTER_PORT,
        sLogin, strlen(sLogin), PASSWORD_CLIENT, strlen(PASSWORD_CLIENT));
    }
    indexClientOnLogin = cnt;

    // Work
    for( int i = 0 ; i < indexClientOnLogin ; i++ )
      pArrClient[i]->Work();
    handler.Work();
    // burn rest time
    unsigned int deltaTime = ht_GetMSCount() - startTime;
    static int old_delta_time = -1;
    if((old_delta_time!=deltaTime)&&
       (deltaTime>70))
    {
      printf("dTime=%d\n", deltaTime);
      old_delta_time = deltaTime;
    }
    if(deltaTime < CLIENT_QUANT_TIME)
      ht_msleep(CLIENT_QUANT_TIME-deltaTime);
  }

  return 0;
}
//-----------------------------------------------------------------------
