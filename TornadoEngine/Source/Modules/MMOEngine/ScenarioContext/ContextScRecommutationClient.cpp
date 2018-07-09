/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScRecommutationClient.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;

TContextScRecommutationClient::TContextScRecommutationClient()
{
  mClientKey        = -1;
  mSessionDonor     = INVALID_HANDLE_SESSION;
  mSessionRecipient = INVALID_HANDLE_SESSION;

  mID_SessionMasterSlave = INVALID_HANDLE_SESSION;

  mTypeSlave = eUndef;

  mTimeWaitAnswer = 0;

  mRandomNum = 0;
}
//------------------------------------------------------------------
TContextScRecommutationClient::~TContextScRecommutationClient()
{

}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetID_SessionClientSlave()
{
  return GetSessionID();
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetID_SessionClientSlave(unsigned int sessionID)
{
  SetSessionID(sessionID);
}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetID_SessionMasterSlave()
{
  return mID_SessionMasterSlave;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetID_SessionMasterSlave(unsigned int sessionID)
{
  mID_SessionMasterSlave = sessionID;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetClientKey(unsigned int v)
{
  mClientKey = v;
}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetClientKey()
{
  return mClientKey;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetSessionDonor(unsigned int v)
{
  mSessionDonor = v;
}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetSessionDonor()
{
  return mSessionDonor;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetSessionRecipient(unsigned int v)
{
  mSessionRecipient = v;
}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetSessionRecipient()
{
  return mSessionRecipient;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SaveContextData(char* p, int size)
{
  mContextData.SetDataByCount(p,size);
}
//------------------------------------------------------------------
char* TContextScRecommutationClient::GetContextDataPtr()
{
  return (char*)mContextData.GetPtr();
}
//------------------------------------------------------------------
int TContextScRecommutationClient::GetContextDataSize()
{
  return mContextData.GetSize();
}
//------------------------------------------------------------------
void TContextScRecommutationClient::CleanContextData()
{
  mContextData.Done();
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetRoleAsDonor()
{
  mTypeSlave = eDonor;
}
//------------------------------------------------------------------
bool TContextScRecommutationClient::IsDonor()
{
  return (mTypeSlave==eDonor);
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetRoleAsRecipient()
{
  mTypeSlave = eRecipient;
}
//------------------------------------------------------------------
bool TContextScRecommutationClient::IsRecipient()
{
  return (mTypeSlave==eRecipient);
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetTimeWait(unsigned int v)
{
  mTimeWaitAnswer = v;
}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetTimeWait()
{
  return mTimeWaitAnswer;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetIP_PortRecipient(TIP_Port& ip_port)
{
  mIP_PortRecipient = ip_port;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::GetIP_PortRecipient(TIP_Port& ip_port)
{
  ip_port = mIP_PortRecipient;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetRandomNum(unsigned int random_num)
{
  mRandomNum = random_num;
}
//------------------------------------------------------------------
unsigned int TContextScRecommutationClient::GetRandomNum()
{
  return mRandomNum;
}
//------------------------------------------------------------------
void TContextScRecommutationClient::SetLogin( std::string& login )
{
  mLogin = login;
}
//--------------------------------------------------------------
std::string TContextScRecommutationClient::GetLogin()
{
  return mLogin;
}
//--------------------------------------------------------------
void TContextScRecommutationClient::SetPassword( std::string& password )
{
  mPassword = password;
}
//--------------------------------------------------------------
std::string TContextScRecommutationClient::GetPassword()
{
  return mPassword;
}
//--------------------------------------------------------------
