/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenarioRecommutationClient.h"
#include "SessionManager.h"

#pragma warning(disable:4355)

using namespace nsMMOEngine;

TScenarioRecommutationClient::TScenarioRecommutationClient() :
  mClient( this ), mSlave( this ), mMaster( this )
{
  mCurBehavior = nullptr;

  AddCallBack( eNeedContextByClientKeyForSlave,     &mCBNeedContextByClientKeyForSlave );
  AddCallBack( eNeedContextByClientSessionForSlave, &mCBNeedContextByClientSessionForSlave );
  AddCallBack( eNeedSessionDonor,                   &mCBNeedSessionDonorByClientKey );
  AddCallBack( eEventActivate,                      &mCBActivate );
  AddCallBack( eEventDisconnectClient,              &mCBDisconnectByClientKey );
  AddCallBack( eEventTimeClientElapsed,             &mCBTimeClientElapsed );
  AddCallBack( eNeedContextByRequestForRecipient,   &mCBNeedContextByRequestForRecipient );
}
//--------------------------------------------------------------
TScenarioRecommutationClient::~TScenarioRecommutationClient()
{

}
//--------------------------------------------------------------
void TScenarioRecommutationClient::Work()
{
  if( mCurBehavior )
  {
    unsigned int time_ms = ht_GetMSCount();
    mCurBehavior->Work( time_ms );
  }
}
//--------------------------------------------------------------
void TScenarioRecommutationClient::Start( unsigned int recipientSessionID, unsigned int clientKey )
{
  mMaster.Start( recipientSessionID, clientKey );
}
//--------------------------------------------------------------
void TScenarioRecommutationClient::DelayBegin()
{
  mMaster.DelayBegin();
}
//--------------------------------------------------------------
void TScenarioRecommutationClient::SaveContext( void* data, int size )
{
  mSlave.SaveContext( data, size );
}
//---------------------------------------------------------------------
void TScenarioRecommutationClient::Recv( TDescRecvSession* pDesc )
{
  mCurBehavior->Recv( pDesc );
}
//---------------------------------------------------------------------
void TScenarioRecommutationClient::SetBehavior( eBehavior v )
{
  switch( v )
  {
    case eClient:
      mCurBehavior = &mClient;
      break;
    case eSlave:
      mCurBehavior = &mSlave;
      break;
    case eMaster:
      mCurBehavior = &mMaster;
      break;
  }
}
//---------------------------------------------------------------------
void TScenarioRecommutationClient::DisconnectClient()
{
  mMaster.DisconnectClient();
}
//---------------------------------------------------------------------
void TScenarioRecommutationClient::DisconnectFromClient( unsigned char subNet )
{
  mClient.DisconnectClient( subNet );
}
//---------------------------------------------------------------------
void TScenarioRecommutationClient::SetClientLoginPassword( std::string& login, std::string& password )
{
  mClient.SetLoginPassword( login, password );
}
//---------------------------------------------------------------------
