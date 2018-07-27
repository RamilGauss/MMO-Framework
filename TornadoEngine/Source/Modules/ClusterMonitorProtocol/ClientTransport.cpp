/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ClientTransport.h"

using namespace nsClusterMonitorProtocol;

TClientTransport::TClientTransport() : TBaseTransport( &mSlave )
{

}
//---------------------------------------------------------------------------------
TClientTransport::~TClientTransport()
{

}
//---------------------------------------------------------------------------------
void TClientTransport::Connect( TIP_Port& ip_port, std::string& login, std::string& password )
{
  mSlave.ConnectUp( ip_port, login, password, mSubNet );
}
//---------------------------------------------------------------------------------
void TClientTransport::Send( nsPackets::THeader* packet, int packetSize )
{
  mSlave.SendUp( (char*) packet, packetSize );
}
//---------------------------------------------------------------------------------
