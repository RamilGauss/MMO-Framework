/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NetControlUDP.h"
#include "BL_Debug.h"
#include "common_defs.h"

#include "Logger.h"
#include <boost\asio\placeholders.hpp>
#include <boost\asio\buffer.hpp>
#include "HiTimer.h"

using namespace std;
using namespace boost::asio;

TNetControlUDP::TNetControlUDP(boost::asio::io_service& io_service):
mDevice(io_service)
{

}
//------------------------------------------------------------------------------
TNetControlUDP::~TNetControlUDP()
{
  Done();
}
//------------------------------------------------------------------------------
bool TNetControlUDP::Open( unsigned short port, unsigned char numNetWork )
{
  bool res = mDevice.Open(port, numNetWork);
  if(res==false)
    return false;

	res &= mDevice.SetRecvBuffer(eSystemSizeForRecvBuffer_Socket);
  res &= mDevice.SetSendBuffer(eSystemSizeForSendBuffer_Socket);

  return res;
}
//------------------------------------------------------------------------------
bool TNetControlUDP::Connect(unsigned int ip, unsigned short port)
{
  GetLogger(STR_NAME_NET_TRANSPORT)->WriteF_time("Try connect on UDP.\n");
  return false;// нельзя, только TCP
}
//------------------------------------------------------------------------------
bool TNetControlUDP::IsStreamFresh( TIP_Port& ip_port)
{
	TInfoConnect infoConnect;
	GetInfoConnect(ip_port, infoConnect);

	unsigned short cnt_in = ((unsigned short*)mBuffer)[0];
	if(A_more_B( cnt_in, infoConnect.cnt_in))
	{
		SetCntInByIP_Port(ip_port, cnt_in);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------------
bool TNetControlUDP::A_more_B(unsigned short A, unsigned short B)
{
	return ::A_more_B_cycle<unsigned short>(A,B);
}
//----------------------------------------------------------------------------------
void TNetControlUDP::GetInfoConnect(TIP_Port& ip_port, TInfoConnect& info_out)
{
	TMapIP_ICIt fit = mMapInfoConnect.find(ip_port);
	if(fit==mMapInfoConnect.end())
	{
		mMapInfoConnect.insert(TMapIP_IC::value_type(ip_port,TInfoConnect()));
		fit = mMapInfoConnect.find(ip_port);
	}
	info_out = fit->second;
}
//----------------------------------------------------------------------------------
void TNetControlUDP::SetCntInByIP_Port(TIP_Port& ip_port, unsigned short cnt_in)
{
	TMapIP_ICIt fit = mMapInfoConnect.find(ip_port);
	if(fit==mMapInfoConnect.end())
	{
    GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("SetCntInByIP_Port not found info connect.\n");
		return;
	}
	fit->second.cnt_in = cnt_in;
}
//----------------------------------------------------------------------------------
unsigned short TNetControlUDP::IncreaseCntOut(TIP_Port& ip_port)
{
  TMapIP_ICIt fit = mMapInfoConnect.find(ip_port);
  if(fit==mMapInfoConnect.end())
  {
    mMapInfoConnect.insert(TMapIP_IC::value_type(ip_port,TInfoConnect()));
    fit = mMapInfoConnect.find(ip_port);
  }
  return fit->second.cnt_out++;
}
//----------------------------------------------------------------------------------
void TNetControlUDP::Init()
{
  ReadyRecvFrom();
}
//----------------------------------------------------------------------------------
void TNetControlUDP::Done()
{
  mDevice.Close();
}
//----------------------------------------------------------------------------------
void TNetControlUDP::Send(unsigned int ip, unsigned short port, TBreakPacket bp)
{
  // формируем заголовок
  unsigned short count_out = IncreaseCntOut(TIP_Port(ip,port));
  bp.PushFront( (char*)&count_out, sizeof(count_out));
  bp.Collect();

  char* data = (char*)bp.GetCollectPtr();
  int size   = bp.GetSize();
  RequestSendTo(data, size, TIP_Port(ip, port));
}
//----------------------------------------------------------------------------------
void TNetControlUDP::Close()
{
  mDevice.Close();
}
//----------------------------------------------------------------------------------
void TNetControlUDP::RecvFromEvent(const boost::system::error_code& error,size_t bytes_transferred)
{
  if((error==0)&&(bytes_transferred))
  {
    TIP_Port ip_port;
    ip_port.ip   = mSenderEndpoint.address().to_v4().to_ulong();
    ip_port.port = mSenderEndpoint.port();
    if(IsStreamFresh(ip_port))
    {
      INetTransport::TDescRecv descRecv;
      descRecv.ip_port      = ip_port;
      descRecv.type					= INetTransport::eUdp;
      descRecv.data         = mBuffer   + sizeof(unsigned short);
      descRecv.sizeData     = mReadSize - sizeof(unsigned short);
      NotifyRecv(&descRecv);
    }
    else
    {
      GetLogger(STR_NAME_NET_TRANSPORT)->
        WriteF_time("ReadFromEvent UDP recv not fresh packet.\n");
    }
    ReadyRecvFrom();
  }
  else
  {
    GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("ReadFromEvent UDP error=%s.\n",error.message().data());
  }
}
//----------------------------------------------------------------------------------
void TNetControlUDP::SendToEvent(const boost::system::error_code& error, size_t bytes_transferred)
{
  if(error)
    GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("SendToEvent UDP error=%s.\n",error.message().data());
  
  mSended = bytes_transferred;
  flgWaitSend = false;
}
//----------------------------------------------------------------------------------
void TNetControlUDP::ReadyRecvFrom()
{
  mDevice.GetSocket()->async_receive_from(
    boost::asio::buffer(&mBuffer[0], eSizeBuffer), mSenderEndpoint,
    boost::bind(&TNetControlUDP::RecvFromEvent, this,
    boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}
//----------------------------------------------------------------------------------
void TNetControlUDP::RequestSendTo(char* data, int size, TIP_Port& ip_port)
{
l_repeat:
  boost::asio::socket_base::message_flags flags = 0;
  boost::system::error_code ec;
  ip::udp::endpoint sender_end_point(boost::asio::ip::address_v4(ip_port.ip),ip_port.port);
  int resSend = mDevice.GetSocket()->send_to(boost::asio::buffer(data, size),sender_end_point,flags, ec);
	if(ec||resSend==0)
    GetLogger(STR_NAME_NET_TRANSPORT)->
      WriteF_time("RequestSendTo UDP error=%s.\n",ec.message().data());
	if(resSend<size)
	{
		ht_msleep(eTimeRepeatSend);
		size -= resSend;
		data += resSend;
		goto l_repeat;
	}
}
//----------------------------------------------------------------------------------

