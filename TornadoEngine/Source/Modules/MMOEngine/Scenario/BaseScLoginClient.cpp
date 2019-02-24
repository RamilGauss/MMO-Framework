/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseScLoginClient.h"
#include "ContextScLoginClient.h"
#include "ScenarioLoginClient.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

//--------------------------------------------------------------
TBaseScLoginClient::TBaseScLoginClient( IScenario* pSc )
{
  mScenario = pSc;
}
//--------------------------------------------------------------
TBaseScLoginClient::~TBaseScLoginClient()
{

}
//--------------------------------------------------------------
TContextScLoginClient* TBaseScLoginClient::Context()
{
  return (TContextScLoginClient*) mScenario->GetContext();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetContext( TContextScLoginClient* pContext )
{
  mScenario->SetContext( pContext );
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionClientMaster()
{
  return Context()->GetID_SessionClientMaster();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetClientSessionID_Master( unsigned int id )
{
  Context()->SetID_SessionClientMaster( id );
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionClientSlave()
{
  return Context()->GetID_SessionClientSlave();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionClientSlave( unsigned int id )
{
  Context()->SetID_SessionClientSlave( id );
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionMasterSlave()
{
  return Context()->GetID_SessionMasterSlave();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionMasterSlave( unsigned int id )
{
  Context()->SetID_SessionMasterSlave( id );
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionMasterSS()
{
  return Context()->GetID_SessionMasterSS();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionMasterSS( unsigned int id )
{
  Context()->SetID_SessionMasterSS( id );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::Recv( TDescRecvSession* pDesc )
{
  RecvInherit( pDesc );
}
//---------------------------------------------------------------------
bool TBaseScLoginClient::Begin()
{
  return mScenario->Begin();
}
//---------------------------------------------------------------------
void TBaseScLoginClient::End()
{
  mScenario->End();
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextByClientKey( unsigned int clientKey )
{
  mScenario->NeedContextByClientKey( clientKey );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextByClientKey_SecondCallSlave( unsigned int clientKey )
{
  mScenario->Notify( TScenarioLoginClient::eContextByClientKey_SecondCallSlave, clientKey );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedNumInQueueByClientKey( unsigned int clientKey )
{
  mScenario->Notify( TScenarioLoginClient::eNumInQueueByClientKey, clientKey );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextByMasterSessionByClientKey( unsigned int masterSessionID, unsigned int clientKey )
{
  mScenario->Notify(
    TScenarioLoginClient::eContextByMasterSessionByClientKey, masterSessionID, clientKey );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::EventSetClientKey( unsigned int clientKey )
{
  mScenario->Notify( TScenarioLoginClient::eSetClientKey, clientKey );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextBySession( unsigned int sessionID )
{
  mScenario->NeedContextBySession( sessionID );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextByClientSessionByClientKey( unsigned int clientSessionID, unsigned int clientKey )
{
  mScenario->Notify(
    TScenarioLoginClient::eContextByClientSessionByClientKey, clientSessionID, clientKey );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextBySessionAfterAuthorised( unsigned int clientSessionID )
{
  mScenario->Notify(
    TScenarioLoginClient::eContextByClientSessionAfterAuthorised, clientSessionID );
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextBySessionLeaveQueue( unsigned int sessionID )
{
  mScenario->Notify(
    TScenarioLoginClient::eContextByClientSessionLeaveQueue, sessionID );
}
//--------------------------------------------------------------
//void TBaseScLoginClient::SetTimeWaitForNow()
//{
//  Context()->SetTimeWait( ht_GetMSCount() );
//}
////--------------------------------------------------------------
