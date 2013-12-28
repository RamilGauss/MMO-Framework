#ifndef SHARE_TESTH
#define SHARE_TESTH

#include "INetTransport.h"
#include "MakerNetTransport.h"
#include "AutoCreateVar.h"
#include <set>

class TShareTest
{
  TMakerNetTransport_Boost
  //TMakerNetTransport_TCP_UDP 
  mMakerNetTransport;
  
  INetTransport* pTransport;

  float freq_printf_recv_packet;// %
  float limit_recv_packet;// %

  volatile bool flgDisconnect;

  int cntRecv;
  int cntStream;
public:
  enum{
      ePortClient    = 1234,
      ePortServer    = 1235,
      eSizePacket    = 1000,//2019123,//1350
      eCntRecvPacket = 10,//100000
  };
	typedef enum{
		eCountRecvPacket = 0,
		eCountActiveConnectionPerTime,
		eTimePerActiveConnection,
	}eType;

  TShareTest();
  ~TShareTest();

	void SetParam(eType type, int param);

  INetTransport* GetTransport();

  void Init(char* nameLog);

  void Recv(INetTransport::TDescRecv* p);
  void Disconnect(TIP_Port* pIP);

  bool IsDisconnect();

  int GetCountRecv();
  int GetCountStream();

  char* GetPacket(){return &packet[0];}

  void Register();
  void Unregister();
protected:
  char packet[eSizePacket];

  void SetDisconnect();


  void RecvPacket(INetTransport::TDescRecv* p);
  void RecvStream(INetTransport::TDescRecv* p);

	eType mType;
	int   mParam;// либо кол-во активных соединений, которое нужно достичь, либо время за которое измеряется кол-во активных

	typedef std::set<TIP_Port> TSetIP;

	TSetIP mSetIP;
	unsigned int mStartCollectActiveConection;// мс

  void ViewCountStreamPacket(INetTransport::TDescRecv* p);
	void ViewCountRecvPacket(INetTransport::TDescRecv* p);
	void ViewCountActiveConnectionPerTime(INetTransport::TDescRecv* p);
	void ViewTimePerActiveConnection(INetTransport::TDescRecv* p);

	void IncreaseSetIP(INetTransport::TDescRecv*p);
};

extern TAutoCreateVarT<TShareTest> g_ShareTest;

#endif

