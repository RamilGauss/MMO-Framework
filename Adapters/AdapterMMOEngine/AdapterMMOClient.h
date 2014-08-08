/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterMMOClientH
#define AdapterMMOClientH

#include "PrototypeMMOClient.h"

#include "DstEvent.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

class TConverterEvents;
class TWrapperMakerTransport;

class DllExport AdapterMMOClient : public PrototypeMMOClient, public TDstEvent
{
  boost::scoped_ptr<TConverterEvents>       mConverter;
  boost::scoped_ptr<TWrapperMakerTransport> mMakerTransport;
  void* mPtrClient;

  enum{ID_Client=0};
public:
  AdapterMMOClient();
  virtual ~AdapterMMOClient();
  // base
  virtual bool Open(PrototypeMMODescOpen* pDesc, int count = 1);
  virtual void DisconnectUp();
  virtual void SendUp(TBreakPacket bp, bool check = true);
  virtual bool IsConnectUp();
  virtual bool IsConnect(unsigned int id);
  virtual void SetLoad(int procent);
  virtual void SetTimeLiveSession(unsigned int time_ms);
  virtual bool GetInfoSession(unsigned int id_session, TIP_Port& ip_port);
  // client
  virtual void Login(unsigned int ip, unsigned short port, void* data, int size);
  virtual void LeaveQueue();

  // prototype
  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);

  virtual int GetVersionAdapter();
  virtual bool Work();
};

#endif
