/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Events.h"
#include "SessionManager.h"

using namespace nsMMOEngine;

char* TRecvEvent::GetData()
{
  return c.GetPtr() + shift;
}
//-------------------------------------------------------------
int TRecvEvent::GetSize()
{
  return c.GetSize() - shift;
}
//-------------------------------------------------------------
unsigned short TRecvEvent::GetShift()
{
  return shift;
}
//-------------------------------------------------------------
void TRecvEvent::SetShift( unsigned short val )
{
  shift = val;
}
//-------------------------------------------------------------
TRecvFromDownEvent::TRecvFromDownEvent()
{
  mType = eRecvFromDown;
}
//-------------------------------------------------------------
TRecvFromUpEvent::TRecvFromUpEvent()
{
  mType = eRecvFromUp;
}
//-------------------------------------------------------------
TDisconnectUpEvent::TDisconnectUpEvent()
{
  mType = eDisconnectUp;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TDisconnectDownEvent::TDisconnectDownEvent()
{
  mType = eDisconnectDown;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TConnectUpEvent::TConnectUpEvent()
{
  mType = eConnectUp;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TTryConnectDownEvent::TTryConnectDownEvent()
{
  mType = eTryConnectDown;
  sessionID = INVALID_HANDLE_SESSION;
  hashLogin = nullptr;
  hashLoginSize = 0;
}
//-------------------------------------------------------------
TConnectDownEvent::TConnectDownEvent()
{
  mType = eConnectDown;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TDestroyGroupEvent::TDestroyGroupEvent()
{
  mType = eDestroyGroup;
  groupID = 0;
}
//-------------------------------------------------------------
TResultLoginEvent::TResultLoginEvent()
{
  mType = eResultLogin;
}
//-------------------------------------------------------------
TErrorEvent::TErrorEvent()
{
  mType = eError;
  //code = 0;
}
//-------------------------------------------------------------
TRestoreContextEvent::TRestoreContextEvent()
{
  mType = eRestoreContext;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TTryLoginEvent::TTryLoginEvent()
{
  mType = eTryLogin;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TLoginEvent::TLoginEvent()
{
  mType = eLogin;
  clientID = 0;
}
//-------------------------------------------------------------
TLogoffEvent::TLogoffEvent()
{
  mType = eLogoff;
  clientID = 0;
}
//-------------------------------------------------------------
TSaveContextEvent::TSaveContextEvent()
{
  mType = eSaveContext;
  sessionID = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TEnterInQueueEvent::TEnterInQueueEvent()
{
  mType = eEnterInQueue;
  numInQueue = 0;
}
//-------------------------------------------------------------
TLeaveQueueEvent::TLeaveQueueEvent()
{
  mType = eLeaveQueue;
}
//-------------------------------------------------------------
