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
#include "MakerNetTransport.h"
#include "INetTransport.h"
#include "ListMultiThread.h"

INetTransport* g_pTransport = NULL;

class THandler
{
  int count_recv;
public:
  TListMultiThread<TIP_Port> mListDisc;

  THandler()
  {
    count_recv = 0;
  }
  void Recv(INetTransport::TDescRecv* p)
  {
    count_recv++;
    printf("Recv event from %u\n", p->ip_port.port);
    if(count_recv==1)
      g_pTransport->Close(p->ip_port.ip, p->ip_port.port);
  }
  void Disconnect(TIP_Port* p)
  {
    printf("Disconnect event from %u\n", p->port);
    
    TIP_Port* pNew = new TIP_Port;
    *pNew = *p;
    mListDisc.Add(pNew);
  }
};

THandler g_Handler;

int main(int argc, char** argv)
{
  SetCurrentPathByFile(argv[0]);

  TInputCmdTestTransport inputCmd;
  bool res = inputCmd.SetArg(argc, argv);
  BL_ASSERT(res);

  TInputCmdTestTransport::TInput inputArg;
  inputCmd.Get(inputArg);

  char sLog[100];
  sprintf(sLog, "TestTransport%d", inputArg.port_src);

  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init(sLog);
  GetLogger()->SetPrintf(false);

  TMakerNetTransport_Boost makerTransport;
  g_pTransport = makerTransport.New();

  std::string sLocalHost;
  TResolverSelf_IP_v4 resolver;
  resolver.Get(sLocalHost, 0);

  unsigned int IP = boost::asio::ip::address_v4::from_string(sLocalHost).to_ulong();

  g_pTransport->GetCallbackDisconnect()->Register( &THandler::Disconnect, &g_Handler);
  g_pTransport->GetCallbackRecv()->Register( &THandler::Recv, &g_Handler);

  g_pTransport->Open(inputArg.port_src);
  g_pTransport->Start();

  bool resConnect = g_pTransport->Connect(IP, inputArg.port_dst);

  unsigned int start = ht_GetMSCount();
  while(1)
  {
    ht_msleep(100);
    unsigned int now_ms = ht_GetMSCount();
    
    if(resConnect)
    if(now_ms > start + inputArg.timer_send)
    {
      inputArg.timer_send += 1000;
      char* msg = "1";
      TBreakPacket bp;
      bp.PushBack( msg, strlen(msg));
      g_pTransport->Send(IP, inputArg.port_dst, bp);
    }

    TIP_Port** ppFisrt = g_Handler.mListDisc.GetFirst();
    while(ppFisrt)
    {
      TIP_Port* pIP_Port = *ppFisrt;
      if(pIP_Port->port==inputArg.port_dst)
        resConnect = g_pTransport->Connect(IP, inputArg.port_dst);

      g_Handler.mListDisc.Remove(ppFisrt);
      ppFisrt = g_Handler.mListDisc.GetFirst();
    }
  }
  
  return 0;
}
//-----------------------------------------------------------------------
