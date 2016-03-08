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
#include "ResolverSelf_IP_v4.h"
#include "Logger.h"
#include <boost/smart_ptr/scoped_array.hpp>
#include <vector>
#include "HandlerMMO_Client.h"


#include "MakerXML.h"
#include "IXML.h"
#include "ScenarioStressTestClient.h"

void TScenarioStressTestClient::Init(int argc, char** argv)
{
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init("StressTestClient");
  GetLogger()->SetPrintf(false);
  GetLogger()->SetEnable(false);
  
  bool res = mInputCmd.SetArg(argc, argv);
  BL_ASSERT(res);

  mInputCmd.Get(mInputArg);

  for( int i = 0 ; i < mInputArg.count ; i++ , mInputArg.begin_port++, mInputArg.begin_id++)
  {
    TBehaviourClient* pClient = new TBehaviourClient;
    pClient->Init(&mMakerTransport, mInputArg);
    pArrClient.push_back(pClient);
  }

  unsigned int time_next_state = ht_GetMSCount() + eWaitForConnect;
  BOOST_FOREACH(TBehaviourClient* pClient, pArrClient)
  {
    pClient->SetTimeNextStep(time_next_state);
    time_next_state += 100;
  }
}
//-----------------------------------------------------------------------
void TScenarioStressTestClient::Work()
{
  while(true)
  {
    unsigned int startTime = ht_GetMSCount();

    // Work
    BOOST_FOREACH(TBehaviourClient* pClient, pArrClient)
      pClient->Work();

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
}
//-----------------------------------------------------------------------
