/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetTransport_BoostH
#define NetTransport_BoostH

#include "INetTransport.h"
#include "GCS.h"
#include "NetWorkThread.h"

#include "NetControlTCP.h"
#include "NetControlAcceptor.h"
#include "NetControlUDP.h"

// Thread safe - Send поддерживает.

class TNetTransport_Boost : public INetTransport
{
  unsigned short mLocalPort;
  unsigned char  mNumNetWork;

  GCS mMutexSend;
  GCS mMutexMapIP_TCP;

  TNetWorkThread mNetWorkThread;

  TNetControlUDP      mUDP;
  TNetControlAcceptor mAcceptor;
  TNetControlTCP*     pTCP_Up;

  typedef std::map<TIP_Port,TNetControlTCP*> TMapIP_Ptr;
  typedef TMapIP_Ptr::iterator TMapIP_PtrIt;
  
  TMapIP_Ptr mMapIP_TCP;

public:
	TNetTransport_Boost();
	virtual ~TNetTransport_Boost();

  virtual bool Open(unsigned short port, unsigned char numNetWork = 0);

	virtual void Send(unsigned int ip, unsigned short port, 
                    TBreakPacket packet, bool check = true);

  virtual TCallBackRegistrator1<TDescRecv*>* GetCallbackRecv(){return INetControl::GetCallbackRecv();}
  virtual TCallBackRegistrator1<TIP_Port* >* GetCallbackDisconnect(){return INetControl::GetCallbackDisconnect();}

	virtual void Start();
	virtual void Stop();
	virtual bool IsActive();

  // синхронная функция
  virtual bool Connect(unsigned int ip, unsigned short port); // вызов только для клиента

	virtual void Close(unsigned int ip, unsigned short port);
public:

  void AddInMapTCP(TIP_Port& ip_port, TNetControlTCP* pNetControl);
	void RemoveFromMapTCP(TIP_Port* ip_port, TNetControlTCP* pControl);

protected:
  void CloseAll();
  void DeleteMapControlTCP();

  void CreateControlTcpUp();
  void DeleteControlTCP(TNetControlTCP* pControl);

  TNetControlTCP* GetTCP_ByIP(TIP_Port &ip_port);
  void Done();

  void ScenarioExchangeCryptKey(TIP_Port& ip_port, TNetControlTCP* pNetControl);// synchro
};


#endif
