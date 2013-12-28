/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetControlAcceptorH
#define NetControlAcceptorH

#include "INetControl.h"
#include "NetDeviceAcceptor.h"

class TNetControlTCP;

class TNetControlAcceptor : public INetControl
{
  TNetDeviceAcceptor mDevice;// слушающий сокет, ждет подключения от клиентов

  GCS gcsSendAccept;
  void lockSA(){gcsSendAccept.lock();}
  void unlockSA(){gcsSendAccept.unlock();}
public:

  TNetControlAcceptor(boost::asio::io_service& io_service);
  virtual ~TNetControlAcceptor();
  // TNetTransport_XXX
  virtual void Init();
  virtual bool Open( unsigned short port, unsigned char numNetWork = 0);
  virtual bool Connect(unsigned int ip, unsigned short port);              // blocking
  virtual void Send(unsigned int ip, unsigned short port, TBreakPacket bp);
  virtual void Close();
  
  virtual TNetDeviceAcceptor* GetDevice(){return &mDevice;}

protected:
  void Done();

  // asio event
  void AcceptEvent(const boost::system::error_code& error);

  void ReadyAccept();

  TNetControlTCP* pNewControlTCP;
};


#endif