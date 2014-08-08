/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetDeviceAcceptorH
#define NetDeviceAcceptorH

#include "INetDevice.h"
#include <boost/asio/ip/tcp.hpp>

class TNetDeviceAcceptor : public INetDevice
{
  enum{
    eMaxCountListen = 20000,
  };

  boost::asio::ip::tcp::acceptor mSocket;

public:
  TNetDeviceAcceptor(boost::asio::io_service& io_service);
  virtual ~TNetDeviceAcceptor();

  virtual bool Open( unsigned short port, unsigned char numNetWork = 0 ); // ret local sock
  virtual void Close();

  virtual bool SetRecvBuffer(unsigned int size);
  virtual bool SetSendBuffer(unsigned int size);

  virtual boost::asio::ip::tcp::acceptor* GetSocket(){return &mSocket;}
protected:
  void OffNagl();
  void SetReUse();
  void Set_HardClose();
};


#endif