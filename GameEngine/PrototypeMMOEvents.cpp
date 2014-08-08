/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PrototypeMMOEvents.h"

PrototypeMMOEventRecv::PrototypeMMOEventRecv()
{
  id_session = MMO_INVALID_HANDLE_SESSION;
	data = NULL;
	sizeData = 0;
}
//-------------------------------------------------------------
PrototypeMMOEventRecvFromDown::PrototypeMMOEventRecvFromDown()
{
  mType = eRecvFromDown;
}
//-------------------------------------------------------------
PrototypeMMOEventRecvFromUp::PrototypeMMOEventRecvFromUp()
{
  mType = eRecvFromUp;
}
//-------------------------------------------------------------
PrototypeMMOEventRecvFromUp::~PrototypeMMOEventRecvFromUp()
{

}
//-------------------------------------------------------------
PrototypeMMOEventDisconnectUp::PrototypeMMOEventDisconnectUp()
{
  mType = eDisconnectUp;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventDisconnectDown::PrototypeMMOEventDisconnectDown()
{
  mType = eDisconnectDown;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventConnectUp::PrototypeMMOEventConnectUp()
{
  mType = eConnectUp;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventConnectDown::PrototypeMMOEventConnectDown()
{
  mType = eConnectDown;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventDestroyGroup::PrototypeMMOEventDestroyGroup()
{
  mType = eDestroyGroup;
  id_group = 0;
}
//-------------------------------------------------------------
PrototypeMMOEventResultLogin::PrototypeMMOEventResultLogin()
{
  mType = eResultLogin;
}
//-------------------------------------------------------------
PrototypeMMOEventError::PrototypeMMOEventError()
{
  mType = eError;
  code = 0;
}
//-------------------------------------------------------------
PrototypeMMOEventRestoreContext::PrototypeMMOEventRestoreContext()
{
  mType = eRestoreContext;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventTryLogin::PrototypeMMOEventTryLogin()
{
  mType = eTryLogin;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventSaveContext::PrototypeMMOEventSaveContext()
{
  mType = eSaveContext;
  id_session = MMO_INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
PrototypeMMOEventEnterInQueue::PrototypeMMOEventEnterInQueue()
{
  mType = eEnterInQueue;
  numInQueue = 0;
}
//-------------------------------------------------------------
