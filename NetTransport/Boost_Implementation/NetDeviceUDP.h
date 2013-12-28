/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetDeviceUDPH
#define NetDeviceUDPH

#include "INetDevice.h"
#include <boost/asio/ip/udp.hpp>

class TNetDeviceUDP : public INetDevice
{
  boost::asio::ip::udp::socket mSocket;

public:
  TNetDeviceUDP(boost::asio::io_service& io_service);
  virtual ~TNetDeviceUDP();

  virtual bool Open( unsigned short port, unsigned char numNetWork = 0 );
  virtual void Close();

  virtual bool SetRecvBuffer(unsigned int size);
  virtual bool SetSendBuffer(unsigned int size);

  boost::asio::ip::udp::socket* GetSocket(){return &mSocket;}
};


#endif