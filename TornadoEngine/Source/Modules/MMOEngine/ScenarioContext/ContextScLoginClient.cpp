/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScLoginClient.h"
#include "BL_Debug.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;
using namespace std;

namespace nsContextScLoginClient
{
  string strDataCommunicationClientMaster = "ClientMaster";
  string strDataCommunicationMasterSlave = "MasterSlave";
  string strDataCommunicationClientSlave = "ClientSlave";
  string strDataCommunicationMasterSS = "MasterSS";
};

using namespace nsContextScLoginClient;

TContextScLoginClient::TContextScLoginClient()
{
  const int WAIT_TIME = 400000;

  mStateTimeWait.AddOrUpdateState( MasterWaitDeveloper,            WAIT_TIME, LoginClient_MasterDeveloperNotActive );
  mStateTimeWait.AddOrUpdateState( MasterWaitSuperServer,          WAIT_TIME, LoginClient_MasterSuperServerNotActive );
  mStateTimeWait.AddOrUpdateState( MasterWaitSlave,                WAIT_TIME, LoginClient_MasterSlaveNotActive );
  mStateTimeWait.AddOrUpdateState( MasterWaitInQueue,              WAIT_TIME, LoginClient_MasterForgetUpdateQueue );
  mStateTimeWait.AddOrUpdateState( MasterWaitClient,               WAIT_TIME, LoginClient_MasterClientNotActive );
  mStateTimeWait.AddOrUpdateState( MasterWaitClientConnectToSlave, WAIT_TIME, LoginClient_MasterClientNotConnectToSlave );

  mStateTimeWait.AddOrUpdateState( ClientWaitMasterAnswer,         WAIT_TIME, LoginClient_ClientMasterNotActive );
  mStateTimeWait.AddOrUpdateState( ClientWaitSlaveAnswer,          WAIT_TIME, LoginClient_ClientSlaveNotActive );
  mStateTimeWait.AddOrUpdateState( ClientWaitSlaveInfo,            WAIT_TIME, LoginClient_ClientMasterNotSendSlaveInfo );
  mStateTimeWait.AddOrUpdateState( ClientWaitDisconnectFromMaster, WAIT_TIME, LoginClient_ClientMasterNotDisconnect );
  mStateTimeWait.AddOrUpdateState( ClientWaitInQueue,              WAIT_TIME, LoginClient_ClientMasterForgetUpdateQueue );

  mStateTimeWait.AddOrUpdateState( SlaveWaitClient,                WAIT_TIME, LoginClient_SlaveClientNotActive );
  mStateTimeWait.AddOrUpdateState( SlaveWaitMaster,                WAIT_TIME, LoginClient_SlaveMasterNotActive );

  mNumInQueue = 0;
  mTimeLastNeedNumInQueue = 0;
  mDeltaTimeWait_ms = 0;
  mState = eUndef;

  mClientKey = (unsigned int) -1;

  flgNeedLeaveQueue = false;

  flgWasBegin = false;
}
//------------------------------------------------------------------
TContextScLoginClient::~TContextScLoginClient()
{

}
//------------------------------------------------------------------
void TContextScLoginClient::SetTimeLastNeedNumInQueue( unsigned int v )
{
  mTimeLastNeedNumInQueue = v;
}
//------------------------------------------------------------------
unsigned int TContextScLoginClient::GetTimeLastNeedNumInQueue()
{
  return mTimeLastNeedNumInQueue;
}
//------------------------------------------------------------------
void TContextScLoginClient::Accept()
{
  mState = eAccept;
}
//------------------------------------------------------------------
void TContextScLoginClient::Reject()
{
  mState = eReject;
}
//------------------------------------------------------------------
void TContextScLoginClient::SetSessionID( std::string& name, unsigned int id )
{
  TMapStrUintIt fit = mMapStrID_Session.find( name );
  if( fit == mMapStrID_Session.end() )
    mMapStrID_Session.insert( TMapStrUint::value_type( name, id ) );
  else
    fit->second = id;
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetSessionID( std::string& name )
{
  TMapStrUintIt fit = mMapStrID_Session.find( name );
  if( fit == mMapStrID_Session.end() )
    return INVALID_HANDLE_SESSION;
  return fit->second;
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetID_SessionClientMaster()
{
  return GetSessionID( strDataCommunicationClientMaster );
}
//--------------------------------------------------------------
void TContextScLoginClient::SetID_SessionClientMaster( unsigned int id )
{
  SetSessionID( strDataCommunicationClientMaster, id );
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetID_SessionClientSlave()
{
  return GetSessionID( strDataCommunicationClientSlave );
}
//--------------------------------------------------------------
void TContextScLoginClient::SetID_SessionClientSlave( unsigned int id )
{
  SetSessionID( strDataCommunicationClientSlave, id );
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetID_SessionMasterSlave()
{
  return GetSessionID( strDataCommunicationMasterSlave );
}
//--------------------------------------------------------------
void TContextScLoginClient::SetID_SessionMasterSlave( unsigned int id )
{
  SetSessionID( strDataCommunicationMasterSlave, id );
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetID_SessionMasterSS()
{
  return GetSessionID( strDataCommunicationMasterSS );
}
//--------------------------------------------------------------
void TContextScLoginClient::SetID_SessionMasterSS( unsigned int id )
{
  SetSessionID( strDataCommunicationMasterSS, id );
}
//--------------------------------------------------------------
bool TContextScLoginClient::IsReject()
{
  return mState == eReject;
}
//--------------------------------------------------------------
bool TContextScLoginClient::IsAccept()
{
  return mState == eAccept;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetNumInQueue( int val )
{
  mNumInQueue = val;
}
//--------------------------------------------------------------
int TContextScLoginClient::GetNumInQueue()
{
  return mNumInQueue;
}
//--------------------------------------------------------------
void TContextScLoginClient::SaveAcceptData( void* resForClient, int sizeResClient )
{
  mAcceptData.SetDataByCount( (char*) resForClient, sizeResClient );
}
//--------------------------------------------------------------
void* TContextScLoginClient::GetSaveAcceptDataPtr()
{
  return mAcceptData.GetPtr();
}
//--------------------------------------------------------------
int TContextScLoginClient::GetSaveAcceptDataSize()
{
  return mAcceptData.GetSize();
}
//--------------------------------------------------------------
void TContextScLoginClient::SaveQueueData( void* resForClient, int sizeResClient )
{
  mQueueData.SetDataByCount( (char*) resForClient, sizeResClient );
}
//--------------------------------------------------------------
void* TContextScLoginClient::GetSaveQueueDataPtr()
{
  return mQueueData.GetPtr();
}
//--------------------------------------------------------------
int TContextScLoginClient::GetSaveQueueDataSize()
{
  return mQueueData.GetSize();
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetClientKey()
{
  return mClientKey;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetClientKey( unsigned int id )
{
  mClientKey = id;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetNeedLeaveQueue( bool val )
{
  flgNeedLeaveQueue = val;
}
//--------------------------------------------------------------
bool TContextScLoginClient::NeedLeaveQueue()
{
  return flgNeedLeaveQueue;
}
//--------------------------------------------------------------
TIP_Port TContextScLoginClient::GetSlaveIP_Port()
{
  return mIP_Port_slave;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetSlaveIP_Port( TIP_Port& ip_port )
{
  mIP_Port_slave = ip_port;
}
//--------------------------------------------------------------
bool TContextScLoginClient::GetFakeClient()
{
  return flgFakeClient;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetFakeClient( bool val )
{
  flgFakeClient = val;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetSubNet( unsigned char v )
{
  mSubNet = v;
}
//--------------------------------------------------------------
unsigned char TContextScLoginClient::GetSubNet()
{
  return mSubNet;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetLogin( std::string& login )
{
  mLogin = login;
}
//--------------------------------------------------------------
std::string TContextScLoginClient::GetLogin()
{
  return mLogin;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetPassword( std::string& password )
{
  mPassword = password;
}
//--------------------------------------------------------------
std::string TContextScLoginClient::GetPassword()
{
  return mPassword;
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetDeltaTimeWaitMS()
{
  return mDeltaTimeWait_ms;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetDeltaTimeWaitMS( unsigned int v )
{
  mDeltaTimeWait_ms = v;
}
//--------------------------------------------------------------
bool TContextScLoginClient::WasBegin()
{
  return flgWasBegin;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetWasBegin()
{
  flgWasBegin = true;
}
//--------------------------------------------------------------
bool TContextScLoginClient::IsConnectUp()
{
  return GetID_SessionClientSlave() != INVALID_HANDLE_SESSION ||
    GetID_SessionClientMaster() != INVALID_HANDLE_SESSION;
}
//--------------------------------------------------------------
void TContextScLoginClient::SetCurrentStateWait( StateWait state )
{
  if( state == NoWait )
    mStateTimeWait.SetCurrentStateToUndef();
  else
    mStateTimeWait.SetCurrentState( state );
}
//--------------------------------------------------------------
bool TContextScLoginClient::IsStateTimeExpired( unsigned int now )
{
  return mStateTimeWait.IsStateTimeExpired( now );
}
//--------------------------------------------------------------
unsigned int TContextScLoginClient::GetCurrentStateErrorCode()
{
  return mStateTimeWait.ErrorCode();
}
//--------------------------------------------------------------
