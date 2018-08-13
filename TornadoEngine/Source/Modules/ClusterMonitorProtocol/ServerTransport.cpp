/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ServerTransport.h"

using namespace nsClusterMonitorProtocol;

TServerTransport::TServerTransport() : TBaseTransport( &mMaster )
{

}
//--------------------------------------------------------------------------------
TServerTransport::~TServerTransport()
{

}
//--------------------------------------------------------------------------------
void TServerTransport::Accept( unsigned int id, std::string& password )
{
  mMaster.Accept( id, password );
}
//--------------------------------------------------------------------------------
void TServerTransport::Reject( unsigned int id )
{
  mMaster.Reject( id );
}
//--------------------------------------------------------------------------------
void TServerTransport::Send( unsigned int id, nsPackets::THeader* packet, int packetSize )
{
  mMaster.SendDown( id, (char*) packet, packetSize );
}
//--------------------------------------------------------------------------------