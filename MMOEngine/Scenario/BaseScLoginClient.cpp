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
TBaseScLoginClient::TBaseScLoginClient(IScenario* pSc)
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
  return (TContextScLoginClient*)mScenario->GetContext();
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionClientMaster()
{
  return Context()->GetID_SessionClientMaster();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionClientMaster(unsigned int id)
{
  Context()->SetID_SessionClientMaster(id);
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionClientSlave()
{
  return Context()->GetID_SessionClientSlave();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionClientSlave(unsigned int id)
{
  Context()->SetID_SessionClientSlave(id);
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionMasterSlave()
{
  return Context()->GetID_SessionMasterSlave();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionMasterSlave(unsigned int id)
{
  Context()->SetID_SessionMasterSlave(id);
}
//--------------------------------------------------------------
unsigned int TBaseScLoginClient::GetID_SessionMasterSS()
{
  return Context()->GetID_SessionMasterSS();
}
//--------------------------------------------------------------
void TBaseScLoginClient::SetID_SessionMasterSS(unsigned int id)
{
  Context()->SetID_SessionMasterSS(id);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::Recv(TDescRecvSession* pDesc)
{
  RecvInherit(pDesc);
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
void TBaseScLoginClient::NeedContextByClientKey(unsigned int id_client)
{
  mScenario->NeedContextByClientKey(id_client);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedNumInQueueByClientKey(unsigned int id_client)
{
  mScenario->Notify<unsigned int>(TScenarioLoginClient::eNumInQueueByClientKey,id_client);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextByMasterSessionByClientKey(unsigned int id_session_master,unsigned int id_client)
{
  mScenario->Notify<unsigned int,unsigned int>(TScenarioLoginClient::eContextByMasterSessionByClientKey,
                                               id_session_master,
                                               id_client);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::EventSetClientKey(unsigned int id_client)
{
  mScenario->Notify<unsigned int>(TScenarioLoginClient::eSetClientKey,id_client);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextBySession(unsigned int id_session)
{
  mScenario->NeedContextBySession(id_session);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::NeedContextByClientSessionByClientKey(unsigned int id_session_client,
                                                               unsigned int id_client)
{
  mScenario->Notify<unsigned int,unsigned int>(TScenarioLoginClient::eContextByClientSessionByClientKey,
                                               id_session_client, id_client);
}
//---------------------------------------------------------------------
void TBaseScLoginClient::SetTimeWaitForNow()
{
  Context()->SetTimeWait(ht_GetMSCount());
}
//--------------------------------------------------------------
