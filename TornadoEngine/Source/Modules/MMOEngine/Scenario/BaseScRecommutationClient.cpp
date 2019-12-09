/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BaseScRecommutationClient.h"
#include "ContextScRecommutationClient.h"
#include "ScenarioRecommutationClient.h"

using namespace nsMMOEngine;
using namespace nsRecommutationClientStruct;

//--------------------------------------------------------------
TBaseScRecommutationClient::TBaseScRecommutationClient( IScenario* pSc )
{
  mScenario = pSc;
}
//--------------------------------------------------------------
TBaseScRecommutationClient::~TBaseScRecommutationClient()
{

}
//--------------------------------------------------------------
TContextScRecommutationClient* TBaseScRecommutationClient::Context()
{
  return (TContextScRecommutationClient*) mScenario->GetContext();
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::SetContext( TContextScRecommutationClient* pContext )
{
  mScenario->SetContext( pContext );
}
//--------------------------------------------------------------
unsigned int TBaseScRecommutationClient::GetID_SessionClientSlave()
{
  return Context()->GetID_SessionClientSlave();
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::SetID_SessionClientSlave( unsigned int id )
{
  Context()->SetID_SessionClientSlave( id );
}
//--------------------------------------------------------------
unsigned int TBaseScRecommutationClient::GetID_SessionMasterSlave()
{
  return Context()->GetID_SessionMasterSlave();
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::SetID_SessionMasterSlave( unsigned int id )
{
  Context()->SetID_SessionMasterSlave( id );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::Recv( TDescRecvSession* pDesc )
{
  RecvInherit( pDesc );
}
//---------------------------------------------------------------------
bool TBaseScRecommutationClient::Begin()
{
  return mScenario->Begin();
}
//---------------------------------------------------------------------
void TBaseScRecommutationClient::End()
{
  mScenario->End();
}
//---------------------------------------------------------------------
void TBaseScRecommutationClient::SetTimeWaitForNow()
{
  Context()->SetTimeWait( ht_GetMSCount() );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::NeedContextByClientKeyForSlave( unsigned int key, bool donor )
{
  mScenario->Notify<unsigned int, bool>(
    TScenarioRecommutationClient::eNeedContextByClientKeyForSlave,
    key, donor );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::NeedSessionDonorByClientKey( IScenario* pScenario )
{
  mScenario->Notify<IScenario*>(
    TScenarioRecommutationClient::eNeedSessionDonor, pScenario );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::EventActivate()
{
  mScenario->Notify<IScenario*>(
    TScenarioRecommutationClient::eEventActivate, mScenario );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::EventDisconnectClient( unsigned int key )
{
  mScenario->Notify<unsigned int>(
    TScenarioRecommutationClient::eEventDisconnectClient, key );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::NeedContextByClientSessionForSlave( unsigned int sessionID,
  bool donor )
{
  mScenario->Notify<unsigned int, bool>(
    TScenarioRecommutationClient::eNeedContextByClientSessionForSlave,
    sessionID, donor );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::NeedContextByClientKey( unsigned int key )
{
  mScenario->NeedContextByClientKey( key );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::NeedContextByRequestForRecipient( TDescRequestConnectForRecipient* pDesc )
{
  mScenario->Notify<TDescRequestConnectForRecipient*>(
    TScenarioRecommutationClient::eNeedContextByRequestForRecipient,
    pDesc );
}
//--------------------------------------------------------------
void TBaseScRecommutationClient::EventTimeClientElapsed( unsigned int key )
{
  mScenario->Notify<unsigned int>(
    TScenarioRecommutationClient::eEventTimeClientElapsed,
    key );
}
//--------------------------------------------------------------