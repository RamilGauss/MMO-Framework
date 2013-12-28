/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Session.h"
#include "HiTimer.h"

#include <time.h>

using namespace nsMMOEngine;

TSession::TSession(unsigned int time_live_ms )
{
  srand( (unsigned)time( NULL ) );

  mCounterIn  = 0;
  mCounterOut = rand();// чтобы избежать повторений содержимого пакета

  mTimeLive = time_live_ms;

  mLastTimeActive = ht_GetMSCount();
  mTransport = NULL;
}
//---------------------------------------------------------------------
TSession::~TSession()
{
  Close();
}
//---------------------------------------------------------------------
void TSession::Work()
{
  unsigned int now_ms = ht_GetMSCount();
  if(mLastTimeActive + mTimeLive < now_ms)
  {
    SendEcho();
    RefreshLastTime();
  }
}
//---------------------------------------------------------------------
void TSession::Send(TBreakPacket bp, bool check, bool use_crypt)
{
  if(use_crypt)
    check = true;
  SendData(ePacket, bp, check, use_crypt);
  // гаранти€ того что пакет дойдет
  // иначе сесси€ на той стороне не освежит врем€
  if(check)
    RefreshLastTime();
}
//---------------------------------------------------------------------
void TSession::SetTransport(INetTransport* pTransport)
{
  mTransport = pTransport;
}
//---------------------------------------------------------------------
void TSession::GetInfo(TIP_Port& pDesc)
{
  pDesc = mIP_Port;
}
//---------------------------------------------------------------------
void TSession::SetInfo(TIP_Port& pDesc)
{
  mIP_Port = pDesc;
}
//---------------------------------------------------------------------
void TSession::Recv()
{
  RefreshLastTime();
}
//---------------------------------------------------------------------
void TSession::SendEcho()
{
  TBreakPacket bp;
  SendData(eEcho, bp);
}
//---------------------------------------------------------------------
void TSession::RefreshLastTime()
{
  mLastTimeActive = ht_GetMSCount();
}
//---------------------------------------------------------------------
void TSession::SendData(char type, TBreakPacket& bp, bool check, bool use_crypt)
{
  THeader h(type);
  h.use_crypt = use_crypt;
  bp.PushFront((char*)&h, sizeof(THeader));
  mTransport->Send(mIP_Port.ip, mIP_Port.port, bp, check);
}
//---------------------------------------------------------------------
void TSession::Close()
{
  mTransport->Close(mIP_Port.ip, mIP_Port.port);
}
//---------------------------------------------------------------------
void TSession::SendKeyRSA(TContainer& c_keyRSA)
{
  TBreakPacket bp;
  bp.PushFront((char*)c_keyRSA.GetPtr(), c_keyRSA.GetSize());

  SendData(eKeyRSA, bp, true);
  RefreshLastTime();
}
//---------------------------------------------------------------------
void TSession::SendKeyAES(TContainer& c_keyAES)
{
  TBreakPacket bp;
  bp.PushFront((char*)c_keyAES.GetPtr(), c_keyAES.GetSize());

  SendData(eKeyAES, bp, true);
  RefreshLastTime();
}
//---------------------------------------------------------------------
unsigned int TSession::GetCounterOut()
{
  return mCounterOut;
}
//-------------------------------------------------------------------------
void TSession::IncrementCounterOut()
{
  mCounterOut++;
}
//-------------------------------------------------------------------------
unsigned int TSession::GetCounterIn()
{
  return mCounterIn;
}
//-------------------------------------------------------------------------
