/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Master.h"
#include "ControlScenario.h"
#include "BL_Debug.h"
#include "Logger.h"

#include "ManagerContextMoreDownClientConnection.h"
#include "ManagerContextDownConnection_Slave.h"
#include "ManagerContextClientLogining.h"
#include "ManagerLoginingClientsOnSlave.h"
#include "ManagerGroupClient.h"
#include "ManagerRecommutation.h"
#include "SetOrderElement.h"
#include "StatisticaClientInGroup.h"

#include "Events.h"

#include "ScenarioLoginClient.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioLoginMaster.h"
#include "ScenarioFlow.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioSynchroSlave.h"
#include "ScenarioDisconnectClient.h"
#include "ScenarioSendToClient.h"

#include "ContainerContextSc.h"
#include "EnumMMO.h"
#include "SessionManager.h"

using namespace nsMMOEngine;

TMaster::TMaster()
{

  mControlSc->mLoginClient->SetBehavior( TScenarioLoginClient::eMaster );
  mControlSc->mRcm->SetBehavior( TScenarioRecommutationClient::eMaster );
}
//-------------------------------------------------------------------------
TMaster::~TMaster()
{

}
//-------------------------------------------------------------------------
bool TMaster::TryCreateGroup( std::list<unsigned int>& clientKeyList, unsigned int& groupID )
{
  //CreateEntity();
  //mWorld->Work();
  //auto ent = FindEntity();
  //groupID = ent.GroupID();
  //auto ret = ent.result;
  //DestroyEntity( ent );
  //return ret;
  return false;
}
//-------------------------------------------------------------------------
void TMaster::DestroyGroup( unsigned int groupID )
{
}
//-------------------------------------------------------------------------
void TMaster::LeaveGroup( unsigned int clientKey )
{
}
//-------------------------------------------------------------------------
void TMaster::GetListForGroup( unsigned int groupID, std::list<unsigned int>& clientKeyList )
{
}
//-------------------------------------------------------------------------
void TMaster::SetResultLogin( bool res, unsigned int clientSessionID,
  unsigned int clientKey, void* resForClient, int sizeResClient )
{
}
//-------------------------------------------------------------------------
bool TMaster::FindSlaveSessionByGroup( unsigned int groupID, unsigned int& sessionID )
{
  return false;
}
//-------------------------------------------------------------------------
void TMaster::DisconnectInherit( unsigned int sessionID )
{
}
//-------------------------------------------------------------------------
int TMaster::GetCountDown()
{
  return 0;
}
//-------------------------------------------------------------------------
bool TMaster::GetDescDown( int index, void* pDesc, int& sizeDesc )
{
  return false;
}
//-------------------------------------------------------------------------
void TMaster::ConnectUp( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet )
{
  mControlSc->mLoginMaster->ConnectToSuperServer( ip_port, login, password, subNet );
}
//-------------------------------------------------------------------------
void TMaster::EndLoginMaster( IScenario* pSc )
{
  // взять по этому контексту, задать всем контекстам
  mSessionUpID = pSc->GetContext()->GetSessionID();
  mContainerUp->SetSessionID( mSessionUpID );

  if ( IsConnectUp() )
  {
    // вход в кластер закончен
    TConnectUpEvent event;
    event.sessionID = mSessionUpID;
    AddEventCopy( &event, sizeof( event ) );
  }
}
//-------------------------------------------------------------------------
void TMaster::EndLoginSlave( IScenario* pSc )
{
}
//-------------------------------------------------------------------------
void TMaster::SendDown( unsigned int sessionID, char* p, int size, bool check )
{
}
//-------------------------------------------------------------------------
void TMaster::EndLoginClient( IScenario* pSc )
{

}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginSlave( unsigned int sessionID )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedContextSynchroSlave( unsigned int sessionID )
{

}
//-------------------------------------------------------------------------
void TMaster::EndSynchroSlave( IScenario* pSc )
{

}
//-------------------------------------------------------------------------
void TMaster::SendByClientKey( std::list<unsigned int>& clientKeyList, char* p, int size )
{
  SetupBP( p, size );
  mControlSc->mSendToClient->SendFromMaster( clientKeyList, mBP );
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySessionAfterAuthorised( unsigned int sessionID )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientBySession( unsigned int sessionID )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedContextLoginClientByClientKey( unsigned int clientKey )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedNumInQueueLoginClient( unsigned int sessionID )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedContextDisconnectClient( unsigned int clientKey )
{
}
//-------------------------------------------------------------------------
void TMaster::EndDisconnectClient( IScenario* pSc )
{

}
//-------------------------------------------------------------------------
void TMaster::NeedContextSendToClient( unsigned int clientKey )
{
}
//-------------------------------------------------------------------------
void TMaster::EndRcm( IScenario* pSc )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedContextByClientKeyRcm( unsigned int clientKey )
{
}
//-------------------------------------------------------------------------
void TMaster::NeedSlaveSessionDonorRcm( IScenario* pSc )
{
}
//-------------------------------------------------------------------------
void TMaster::EventActivateRcm( IScenario* pSc )
{
}
//-------------------------------------------------------------------------
