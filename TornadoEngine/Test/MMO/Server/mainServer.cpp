/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/asio/ip/impl/address_v4.ipp>
#include "BL_Debug.h"
#include "CommonParam.h"
#include <string.h>
#include "MakerTransport.h"
#include "HiTimer.h"
#include "NetSystem.h"
#include "Logger.h"
#include "Slave.h"
#include "Master.h"
#include "SuperServer.h"
#include "HandlerMMO_Slave.h"
#include "HandlerMMO_Master.h"
#include "HandlerMMO_SuperServer.h"


#define COUNT_SLAVE 2
//----------------------------------------------
int main(int argc, char** argv)
{
  // обязательно инициализировать лог
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init("Server_Test");
  GetLogger()->SetPrintf(false);
  GetLogger()->SetEnable(false);

  std::vector<THandlerMMO*> arrHandlerSlave;

  TMakerTransport makerTransport;

  nsMMOEngine::TDescOpen descOpen;
  std::vector<nsMMOEngine::TSlave*> arrSlave;
  for( int i = 0 ; i < COUNT_SLAVE ; i++ )
  {
    THandlerMMO_Slave* pHandlerSlave = new THandlerMMO_Slave;
    nsMMOEngine::TSlave* pSlave = new nsMMOEngine::TSlave;
    pSlave->Init(&makerTransport);
    descOpen.port = SLAVE_PORT + i;
    pSlave->Open(&descOpen); 
    pSlave->SetLoad(0);// всегда в начале нет нагрузки
    pSlave->SetDstObject(pHandlerSlave);
    pSlave->SetSelfID(descOpen.port);
    arrSlave.push_back(pSlave);
    arrHandlerSlave.push_back(pHandlerSlave);
  }

  boost::scoped_ptr<nsMMOEngine::TMaster>      pMaster(new nsMMOEngine::TMaster);
  boost::scoped_ptr<nsMMOEngine::TSuperServer> pSuperServer(new nsMMOEngine::TSuperServer);
  boost::scoped_ptr<THandlerMMO> handlerMaster(new THandlerMMO_Master);
  boost::scoped_ptr<THandlerMMO> handlerSuperServer(new THandlerMMO_SuperServer);

  descOpen.port = MASTER_PORT;
  pMaster->Init(&makerTransport);
  pMaster->Open(&descOpen); 
  pMaster->SetDstObject(handlerMaster.get());
  pMaster->SetSelfID(descOpen.port);

  descOpen.port = SUPER_SERVER_PORT;
  pSuperServer->Init(&makerTransport);
  pSuperServer->Open(&descOpen); 
  pSuperServer->SetDstObject(handlerSuperServer.get());
  pSuperServer->SetSelfID(descOpen.port);
  
#ifdef WIN32
  char* sLocalHost = ns_getSelfIP(0);
#else
  char sLocalHost[100];
  get_ip_first_eth(sLocalHost);
#endif
  // сначала мастер цепляется к суперсерверу,
  // потом slave-ы
  unsigned int superserverIP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
  pMaster->ConnectUp(superserverIP, SUPER_SERVER_PORT, 
    (void*)LOGIN_MASTER, strlen(LOGIN_MASTER), 
    (void*)PASSWORD_MASTER, strlen(PASSWORD_MASTER));
  unsigned int masterIP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
  for( int i = 0 ; i < COUNT_SLAVE ; i++ )
  {
    char sLogin[100];
    sprintf(sLogin, "%d", i);
    arrSlave[i]->ConnectUp(masterIP, MASTER_PORT, 
      sLogin, strlen(sLogin), (void*)PASSWORD_SLAVE, strlen(PASSWORD_SLAVE));
  }
  while(true)
  {
    unsigned int startTime = ht_GetMSCount();
    // Work
    BOOST_FOREACH(nsMMOEngine::TSlave* pSlave, arrSlave)
      pSlave->Work();
    // реакции мастера и суперсервера
    pMaster->Work();
    pSuperServer->Work();
    // Handle
    handlerMaster->Work();
    handlerSuperServer->Work();
    BOOST_FOREACH(THandlerMMO* pHandlerSlave, arrHandlerSlave)
      pHandlerSlave->Work();
    // burn rest time
    // замер времени слэйва
    unsigned int deltaTime = ht_GetMSCount() - startTime;
    if(deltaTime>20)
      printf("dTime=%d\n", deltaTime);
    if(deltaTime < SERVER_QUANT_TIME)
      ht_msleep(SERVER_QUANT_TIME-deltaTime);
  }
  return 0;
}
//-----------------------------------------------------------------------
