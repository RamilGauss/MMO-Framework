#include <conio.h>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <functional>

#include "MakerNetTransport.h"
#include "INetTransport.h"
#include "GlobalParams.h"
#include "HiTimer.h"
#include "NetSystem.h"
#include "SaveOnHDD.h"
#include "ListPtr.h"
#include "BreakPacket.h"
#include "share_test.h"

#include <boost\asio\ip\impl\address_v4.ipp>
#include "BL_Debug.h"

using namespace std;

int numNetWork = 0;

struct TArgData
{
	unsigned short port_client;
  unsigned int ip;
  int cnt;
  int time_sleep;
  TArgData()
  {
    port_client = TShareTest::ePortClient;
    ip = boost::asio::ip::address_v4::from_string(ns_getSelfIP(numNetWork)).to_ulong();
    cnt = 1;//190;
    time_sleep = 40;
  }
};
//-------------------------------------------------------------------
void GetByArg(int argc, char** argv, TArgData &d);
//-------------------------------------------------------------------
int main(int argc, char** argv)
{
#if 0
  // внутри MMOEngine
  nsMMOEngine::TEventTryLogin erfd;
  erfd.id_session = 1;
  erfd.sizeData   = 100;
  TContainer* pC  = new TContainer;
  pC->SetData(NULL, sizeof(nsMMOEngine::TEventTryLogin) + erfd.sizeData);
  memcpy(pC->GetPtr(), &erfd, sizeof(nsMMOEngine::TEventTryLogin));
  // внутри DeveloperDLL
  nsMMOEngine::TBaseEvent* pBE = (nsMMOEngine::TBaseEvent*)pC->GetPtr();
  switch(pBE->mType)
  {
    case nsMMOEngine::TBase::eTryLogin:
    {
      nsMMOEngine::TEventTryLogin* pERFD = (nsMMOEngine::TEventTryLogin*)pBE;
      break;
    }
    default:;
  }
  delete pC;
#endif
    g_ShareTest->Init("Client");

	TArgData d;
	GetByArg(argc,argv,d);
	printf("port=%u,TimeSleep=%d,cnt=%d\n",d.port_client, d.time_sleep, d.cnt);

  INetTransport* pNetTransport = g_ShareTest->GetTransport();

  bool res = pNetTransport->Open(d.port_client);
  g_ShareTest->Register();

	pNetTransport->Start();

  TBreakPacket packetForSend;
	if(pNetTransport->Connect(d.ip, TShareTest::ePortServer))
	{
		unsigned int start = ht_GetMSCount();
		for(int i = 0 ; i < TShareTest::eCntRecvPacket ;)
		{
			for(int j = 0 ; j < d.cnt ; j++ )
			{
        packetForSend.UnlinkPart();
        packetForSend.PushFront(g_ShareTest->GetPacket(), TShareTest::eSizePacket);
        pNetTransport->Send(d.ip, TShareTest::ePortServer, packetForSend, true);
				i++;
				if(i==TShareTest::eCntRecvPacket)
					break;
			}
			ht_msleep(d.time_sleep);
      if(g_ShareTest->IsDisconnect())
        break;
		}
		start = ht_GetMSCount() - start;
    printf("time=%d ms, v=%f \n",
      start,float(TShareTest::eSizePacket*TShareTest::eCntRecvPacket)/(start*1000));
	}
  pNetTransport->Close(d.ip,TShareTest::ePortServer);
	pNetTransport->Stop();
  BL_ASSERT(pNetTransport->IsActive()==false);
  g_ShareTest->Unregister();

  //_getch();
  return 0;
}
//-----------------------------------------------------------------------
void GetByArg(int argc, char** argv, TArgData &d)
{
	for( int i = 1 ; i < argc ; i++)
	{
		switch(i)
		{
			case 1:
				d.port_client = atoi(argv[i]);
				break;
			case 2:
			  d.time_sleep = atoi(argv[i]);
				break;
			case 3:
				d.cnt = atoi(argv[i]);
				break;
			case 4:
        d.ip = boost::asio::ip::address_v4::from_string(argv[i]).to_ulong();
				break;
			default:;
		}
	}
}
//-----------------------------------------------------------------------
