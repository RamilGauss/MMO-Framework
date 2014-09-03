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
#include "HandlerMMO.h"
#include "Logger.h"
#include "Slave.h"
#include "Master.h"
#include "SuperServer.h"

int main(int argc, char** argv)
{
  // обязательно инициализировать лог
  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init("Server_Test");
  GetLogger()->SetPrintf(false);
  GetLogger()->SetEnable(false);

  THandlerMMO handler;

  TMakerTransport makerTransport;
  // создать основные элементы сервера
  boost::scoped_ptr<nsMMOEngine::TSlave> pSlave(new nsMMOEngine::TSlave);
  boost::scoped_ptr<nsMMOEngine::TMaster> pMaster(new nsMMOEngine::TMaster);
  boost::scoped_ptr<nsMMOEngine::TSuperServer> pSuperServer(new nsMMOEngine::TSuperServer);
  handler.SetServerMMO(pMaster.get(), pSlave.get());

  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = SLAVE_PORT;
  pSlave->Init(&makerTransport);
  pSlave->Open(&descOpen); 
  pSlave->SetDstObject(&handler);
  pSlave->SetSelfID(descOpen.port);// можно назначить любое число, это нужно для определения типа объекта

  descOpen.port = MASTER_PORT;
  pMaster->Init(&makerTransport);
  pMaster->Open(&descOpen); 
  pMaster->SetDstObject(&handler);
  pMaster->SetSelfID(descOpen.port);

  descOpen.port = SUPER_SERVER_PORT;
  pSuperServer->Init(&makerTransport);
  pSuperServer->Open(&descOpen); 
  pSuperServer->SetDstObject(&handler);
  pSuperServer->SetSelfID(descOpen.port);
  
#ifdef WIN32
  char* sLocalHost = ns_getSelfIP(0);
#else
  char sLocalHost[100];
  get_ip_first_eth(sLocalHost);
#endif
  // сначала мастер цепляется к суперсерверу,
  // slave прицепится к мастеру потом
  unsigned int superserverIP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();
  pMaster->ConnectUp(superserverIP, SUPER_SERVER_PORT, 
    LOGIN_MASTER, strlen(LOGIN_MASTER), 
    PASSWORD_MASTER, strlen(PASSWORD_MASTER));
  while(true)
  {
    unsigned int startTime = ht_GetMSCount();
    // Work
    pSlave->Work();
    // замер времени слэйва
    unsigned int deltaTime = ht_GetMSCount() - startTime;
    int load = int(100.0f*float(deltaTime)/SERVER_QUANT_TIME);
    pSlave->SetLoad(load);
    if(deltaTime>20)
      printf("dTime=%d\n", deltaTime);
    // реакции мастера и суперсервера
    pMaster->Work();
    pSuperServer->Work();
    // Handle
    handler.Work();
    // burn rest time
    if(deltaTime < SERVER_QUANT_TIME)
      ht_msleep(SERVER_QUANT_TIME-deltaTime);
  }

  return 0;
}
//-----------------------------------------------------------------------
