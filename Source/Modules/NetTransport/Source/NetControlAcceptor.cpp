/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "NetTransport/Include/NetControlAcceptor.h"

#include <boost/asio/placeholders.hpp>
#include <boost/system/error_code.hpp>
#include <boost/bind.hpp>

#include "Base/Common/BL_Debug.h"
#include "Base/Common/GlobalEventHub.h"

#include "NetTransport/Include/NetTransport_Boost.h"
#include "NetTransport/Include/NetControlTCP.h"
#include "MMOEngine/include/EnumMMO.h"

using namespace std;

TNetControlAcceptor::TNetControlAcceptor(TNetTransport_Boost* pNTB, boost::asio::io_context* io_context) :
    INetControl(pNTB),
    mDevice(io_context)
{
    pNewControlTCP = nullptr;
    flgReadyAccept = false;
}
//------------------------------------------------------------------------------
TNetControlAcceptor::~TNetControlAcceptor()
{
}
//------------------------------------------------------------------------------
bool TNetControlAcceptor::Open(unsigned short port, unsigned char numNetWork)
{
    return mDevice.Open(port, numNetWork);
}
//------------------------------------------------------------------------------
bool TNetControlAcceptor::Connect(unsigned int ip, unsigned short port)
{
    return false;
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Send(unsigned int ip, unsigned short port, TBreakPacket& bp)
{

}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Close()
{
    mDevice.Close();
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::AcceptEvent(const boost::system::error_code& error)
{
    if (error.failed() == false) {
        TIP_Port ip_port;
        ip_port.port = pNewControlTCP->GetDevice()->GetSocket()->remote_endpoint().port();
        ip_port.ip = pNewControlTCP->GetDevice()->GetSocket()->remote_endpoint().address().to_v4().to_ulong();
        pNewControlTCP->GetDevice()->SetIP_Port(ip_port);
        GetNetBoost()->AddInMapTCP(ip_port, pNewControlTCP);
        pNewControlTCP->Init();// готов к чтению

        GetNetBoost()->GetCallbackConnectFrom()->Notify(&ip_port);// уведомить о подсоединившемся
    } else {
        delete pNewControlTCP;
        pNewControlTCP = nullptr;
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("Acceptor AcceptEvent FAIL: {}.", error.message().data());

        flgReadyAccept = false;
        return;
    }

    ReadyAccept();
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Done()
{

}
//------------------------------------------------------------------------------
void TNetControlAcceptor::ReadyAccept()
{
    // Get io_context via global
    auto pContext = GetNetBoost()->GetNetWorkThread()->GetIO_Context();

    pNewControlTCP = new TNetControlTCP(GetNetBoost(), pContext);
    auto newSocket = pNewControlTCP->GetDevice()->GetSocket();
    mDevice.GetSocket()->async_accept(*newSocket,
        boost::bind(&TNetControlAcceptor::AcceptEvent, this,
            boost::asio::placeholders::error));

    flgReadyAccept = true;
}
//------------------------------------------------------------------------------
void TNetControlAcceptor::Init()
{
    ReadyAccept();
}
//------------------------------------------------------------------------------
bool TNetControlAcceptor::IsReadyAccept()
{
    return flgReadyAccept;
}
//------------------------------------------------------------------------------
