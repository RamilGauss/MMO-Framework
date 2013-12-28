#include "share_test.h"
#include <conio.h>
#include <stdio.h>
#include <map>
#include <string>

#include "HiTimer.h"
#include "NetSystem.h"
#include "SaveOnHDD.h"
#include "Logger.h"

TAutoCreateVarT<TShareTest> g_ShareTest;

//-----------------------------------------------------------------------
TShareTest::TShareTest()
{
  flgDisconnect = false;

  freq_printf_recv_packet = 10.0f;// %
  limit_recv_packet = 0;          // %
  cntRecv   = 0;
  cntStream = 0;

  pTransport = mMakerNetTransport.New();

	mType  = eCountRecvPacket;
	mParam = 100;
}
//-----------------------------------------------------------------------
TShareTest::~TShareTest()
{
  mMakerNetTransport.Delete(pTransport);
}
//-----------------------------------------------------------------------
void TShareTest::SetParam(eType type, int param)
{
	mType  = type;
	mParam = param;

	mStartCollectActiveConection = ht_GetMSCount();
}
//-----------------------------------------------------------------------
INetTransport* TShareTest::GetTransport()
{
  return pTransport;
}
//-----------------------------------------------------------------------
void TShareTest::Init(char* nameLog)
{
  GetLogger()->Done();
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init(nameLog);
  GetLogger(STR_NAME_NET_TRANSPORT)->WriteF_time("Start.\n");

#ifdef TD_WINDOWS
  setlocale( LC_ALL, "Russian_russia.1251" );
#else
  setlocale( LC_ALL, "ru_RU.koi8r" );
#endif
  ns_Init();
}
//-----------------------------------------------------------------------
void TShareTest::RecvPacket(INetTransport::TDescRecv* p)
{
	cntRecv++;
	switch(mType)
	{
		case eCountRecvPacket:
			ViewCountRecvPacket(p);
			break;
		case eCountActiveConnectionPerTime:
			ViewCountActiveConnectionPerTime(p);
			break;
		case eTimePerActiveConnection:
			ViewTimePerActiveConnection(p);
			break;
	}
}
//-----------------------------------------------------------------------
void TShareTest::ViewCountRecvPacket(INetTransport::TDescRecv* p)
{
  static unsigned int startRecvPacket;
  if(cntRecv==0)
    startRecvPacket = ht_GetMSCount();
  if(float(cntRecv)/eCntRecvPacket*100>limit_recv_packet)
  {
    printf("RecvPacket, cnt=%d, size=%d, port=%u\n",cntRecv, 
      p->sizeData, p->ip_port.port);
    limit_recv_packet += freq_printf_recv_packet;
  }
  if(cntRecv==eCntRecvPacket)
  {
    unsigned int now = ht_GetMSCount();
    unsigned int time_recv = now - startRecvPacket;
    printf("Recv time=%u, v=%f\n", 
      time_recv, float(sizeof(packet)*eCntRecvPacket)/(time_recv*1000));
  }
}
//-----------------------------------------------------------------------
void TShareTest::ViewCountActiveConnectionPerTime(INetTransport::TDescRecv* p)
{
	IncreaseSetIP(p);
	unsigned int now = ht_GetMSCount();
	if(mStartCollectActiveConection+mParam<now)
	{
		printf("Count active connection=%d, dt=%d ms\n", mSetIP.size(), mParam);
		mStartCollectActiveConection = now;
		mSetIP.clear();
	}
}
//-----------------------------------------------------------------------
void TShareTest::ViewTimePerActiveConnection(INetTransport::TDescRecv* p)
{
	IncreaseSetIP(p);
	if(int(mSetIP.size())>=mParam)
	{
		// формировать строку
		unsigned int now = ht_GetMSCount();
		unsigned int dt = now - mStartCollectActiveConection;
		printf("Time per connection=%d, time=%u ms\n", mParam, dt);
		mStartCollectActiveConection = now;
		mSetIP.clear();
	}
}
//-----------------------------------------------------------------------
void TShareTest::IncreaseSetIP(INetTransport::TDescRecv*p)
{
	mSetIP.insert(TSetIP::value_type(p->ip_port));
}
//-----------------------------------------------------------------------
void TShareTest::RecvStream(INetTransport::TDescRecv* p)
{
  cntStream++;
  switch(mType)
  {
    case eCountRecvPacket:
      ViewCountRecvPacket(p);
      break;
    case eCountActiveConnectionPerTime:
      ViewCountActiveConnectionPerTime(p);
      break;
    case eTimePerActiveConnection:
      ViewTimePerActiveConnection(p);
      break;
  }
}
//-----------------------------------------------------------------------
void TShareTest::ViewCountStreamPacket(INetTransport::TDescRecv* p)
{
  static unsigned int startRecvStream;
  if(cntStream==0)
    startRecvStream = ht_GetMSCount();
  if(float(cntStream)/eCntRecvPacket*100>limit_recv_packet)
  {
    printf("RecvStream, cnt=%d\n",cntStream);
    limit_recv_packet += freq_printf_recv_packet;
  }
  if(cntStream==eCntRecvPacket)
  {
    unsigned int now = ht_GetMSCount();
    unsigned int time_recv = now - startRecvStream;
    printf("Recv time=%u, v=%f\n", time_recv, float(sizeof(packet)*eCntRecvPacket)/(time_recv*1000));
  }
}
//-----------------------------------------------------------------------
void TShareTest::Disconnect(TIP_Port* p)
{
  printf("Disconnect IP=0x%X port=%u\n", p->ip, p->port);
  flgDisconnect = true;
}
//-----------------------------------------------------------------------
void TShareTest::Recv(INetTransport::TDescRecv* p)
{
	switch(p->type)
	{
		case INetTransport::eTcp:
			RecvPacket(p);
			break;
		case INetTransport::eUdp:
			RecvStream(p);
			break;
	}
}
//-----------------------------------------------------------------------
void TShareTest::SetDisconnect()
{
  flgDisconnect = true;
}
//-----------------------------------------------------------------------
bool TShareTest::IsDisconnect()
{
  return flgDisconnect;
}
//-----------------------------------------------------------------------
int TShareTest::GetCountRecv()
{
  return cntRecv;
}
//-----------------------------------------------------------------------
int TShareTest::GetCountStream()
{
  return cntStream;
}
//-----------------------------------------------------------------------
void TShareTest::Register()
{
  pTransport->GetCallbackRecv()->Register(   &TShareTest::Recv,       this);
  pTransport->GetCallbackDisconnect()->Register(&TShareTest::Disconnect, this);
}
//-----------------------------------------------------------------------
void TShareTest::Unregister()
{
  pTransport->GetCallbackRecv()->Unregister(this);
  pTransport->GetCallbackDisconnect()->Unregister(this);
}
//-----------------------------------------------------------------------
