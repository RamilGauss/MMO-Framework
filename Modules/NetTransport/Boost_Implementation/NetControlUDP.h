/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NetControlUDPH
#define NetControlUDPH

#include <map>
#include <boost/shared_array.hpp>
#include <boost/asio/ip/udp.hpp>

#include "INetControl.h"
#include "NetDeviceUDP.h"

class TNetControlUDP : public INetControl
{
	enum{
		eSizeBuffer = 64000,
		eTimeRepeatSend = 20,
	};

	int mReadSize;
	char mBuffer[eSizeBuffer];

  volatile bool flgWaitSend;
  int mSended;

  TNetDeviceUDP mDevice;
	//-----------------------------------------------------------------------------
  struct TInfoConnect
  {
    unsigned short cnt_in; // определить свежесть пакета по входным данным
    unsigned short cnt_out;// посылать наружу
    TInfoConnect()
    {
      cnt_in  = -1;
      cnt_out = 0;
    }
  };
	typedef std::map<TIP_Port, TInfoConnect> TMapIP_IC;
	typedef TMapIP_IC::iterator TMapIP_ICIt;

	TMapIP_IC mMapInfoConnect;
public:

  TNetControlUDP(boost::asio::io_service& io_service);
  virtual ~TNetControlUDP();
  // TNetTransport_XXX
  virtual void Init();
  virtual bool Open( unsigned short port, unsigned char numNetWork = 0);
  virtual bool Connect(unsigned int ip, unsigned short port);              // blocking
  virtual void Send(unsigned int ip, unsigned short port, TBreakPacket bp);
  virtual void Close();

  virtual TNetDeviceUDP* GetDevice(){return &mDevice;}

  virtual char* GetBuffer(){return &mBuffer[0];}
  virtual int   GetSize()  {return eSizeBuffer;}
protected:
	bool IsStreamFresh(TIP_Port& ip_port);
	bool A_more_B(unsigned short A, unsigned short B);

  unsigned short IncreaseCntOut(TIP_Port& ip_port);
	void GetInfoConnect(TIP_Port& v, TInfoConnect& info_out);
	void SetCntInByIP_Port(TIP_Port& ip_port, unsigned short cnt_in);

  void Done();
  // asio event
  void RecvFromEvent(const boost::system::error_code& error,size_t bytes_transferred);
  void SendToEvent(const boost::system::error_code& error,size_t bytes_transferred);

  void ReadyRecvFrom();
  // данные по указателю data будут удалены самостоятельно!
  void RequestSendTo(char* data, int size, TIP_Port& ip_port);

private:
  boost::asio::ip::udp::endpoint mSenderEndpoint;

};


#endif