/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Events.h"
#include "ManagerSession.h"

using namespace nsMMOEngine;

TEventRecv::TEventRecv()
{
  id_session = INVALID_HANDLE_SESSION;
	data = NULL;
	sizeData = 0;
}
//-------------------------------------------------------------
TEventRecvFromDown::TEventRecvFromDown()
{
  mType = eRecvFromDown;
}
//-------------------------------------------------------------
TEventRecvFromUp::TEventRecvFromUp()
{
  mType = eRecvFromUp;
}
//-------------------------------------------------------------
TEventRecvFromUp::~TEventRecvFromUp()
{

}
//-------------------------------------------------------------
TEventDisconnectUp::TEventDisconnectUp()
{
  mType = eDisconnectUp;
  id_session = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TEventDisconnectDown::TEventDisconnectDown()
{
  mType = eDisconnectDown;
  id_session = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TEventConnectUp::TEventConnectUp()
{
  mType = eConnectUp;
  id_session = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TEventConnectDown::TEventConnectDown()
{
  mType = eConnectDown;
  id_session = INVALID_HANDLE_SESSION;
	use_crypt = true;
}
//-------------------------------------------------------------
TEventDestroyGroup::TEventDestroyGroup()
{
  mType = eDestroyGroup;
  id_group = 0;
}
//-------------------------------------------------------------
TEventResultLogin::TEventResultLogin()
{
  mType = eResultLogin;
}
//-------------------------------------------------------------
TEventError::TEventError()
{
  mType = eError;
  code = 0;
}
//-------------------------------------------------------------
TEventRestoreContext::TEventRestoreContext()
{
  mType = eRestoreContext;
  id_session = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TEventTryLogin::TEventTryLogin()
{
  mType = eTryLogin;
  id_session = INVALID_HANDLE_SESSION;
	use_crypt = true;
}
//-------------------------------------------------------------
TEventSaveContext::TEventSaveContext()
{
  mType = eSaveContext;
  id_session = INVALID_HANDLE_SESSION;
}
//-------------------------------------------------------------
TEventEnterInQueue::TEventEnterInQueue()
{
  mType = eEnterInQueue;
  numInQueue = 0;
}
//-------------------------------------------------------------
