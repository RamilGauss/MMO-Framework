/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ConverterEvents.h"
#include "PrototypeMMOEvents.h"

TConverterEvents::TConverterEvents()
{

}
//------------------------------------------------------------------------------
TConverterEvents::~TConverterEvents()
{

}
//------------------------------------------------------------------------------
PrototypeMMOBaseEvent* TConverterEvents::Work(nsMMOEngine::TBaseEvent* pModuleEvent)
{
  PrototypeMMOBaseEvent* pRes = NULL;
  switch(pModuleEvent->mType)
  {
    case nsMMOEngine::eConnectDown:
      pRes = AssignConnectDown((nsMMOEngine::TEventConnectDown*)pModuleEvent);
      break;
    case nsMMOEngine::eDisconnectDown:
      pRes = AssignDisconnectDown((nsMMOEngine::TEventDisconnectDown*)pModuleEvent);
      break;
    case nsMMOEngine::eConnectUp:
      pRes = AssignConnectUp((nsMMOEngine::TEventConnectUp*)pModuleEvent);
      break;
    case nsMMOEngine::eDisconnectUp:
      pRes = AssignDisconnectUp((nsMMOEngine::TEventDisconnectUp*)pModuleEvent);
      break;
    case nsMMOEngine::eError:
      pRes = AssignError((nsMMOEngine::TEventError*)pModuleEvent);
      break;
    case nsMMOEngine::eRecvFromDown:
      pRes = AssignRecvFromDown((nsMMOEngine::TEventRecvFromDown*)pModuleEvent);
      break;
    case nsMMOEngine::eRecvFromUp:
      pRes = AssignRecvFromUp((nsMMOEngine::TEventRecvFromUp*)pModuleEvent);
      break;
    case nsMMOEngine::eSaveContext:
      pRes = AssignSaveContext((nsMMOEngine::TEventSaveContext*)pModuleEvent);
      break;
    case nsMMOEngine::eRestoreContext:
      pRes = AssignRestoreContext((nsMMOEngine::TEventRestoreContext*)pModuleEvent);
      break;
    case nsMMOEngine::eTryLogin:
      pRes = AssignTryLogin((nsMMOEngine::TEventTryLogin*)pModuleEvent);
      break;
    case nsMMOEngine::eResultLogin:
      pRes = AssignResultLogin((nsMMOEngine::TEventResultLogin*)pModuleEvent);
      break;
    case nsMMOEngine::eDestroyGroup:
      pRes = AssignDestroyGroup((nsMMOEngine::TEventDestroyGroup*)pModuleEvent);
      break;
    case nsMMOEngine::eEnterInQueue:
      pRes = AssignEnterInQueue((nsMMOEngine::TEventEnterInQueue*)pModuleEvent);
      break;
  }

  pRes->c.Entrust(pModuleEvent->c.GetPtr(), pModuleEvent->c.GetSize());
  pModuleEvent->c.Unlink();

  return pRes;
}
//------------------------------------------------------------------------------
PrototypeMMOEventConnectDown* TConverterEvents::AssignConnectDown(nsMMOEngine::TEventConnectDown* pM)
{
  PrototypeMMOEventConnectDown* pP = new PrototypeMMOEventConnectDown;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventDisconnectDown* TConverterEvents::AssignDisconnectDown(nsMMOEngine::TEventDisconnectDown* pM)
{
  PrototypeMMOEventDisconnectDown* pP = new PrototypeMMOEventDisconnectDown;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventConnectUp*      TConverterEvents::AssignConnectUp     (nsMMOEngine::TEventConnectUp*      pM)
{
  PrototypeMMOEventConnectUp* pP = new PrototypeMMOEventConnectUp;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventDisconnectUp*   TConverterEvents::AssignDisconnectUp  (nsMMOEngine::TEventDisconnectUp*   pM)
{
  PrototypeMMOEventDisconnectUp* pP = new PrototypeMMOEventDisconnectUp;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventError*          TConverterEvents::AssignError         (nsMMOEngine::TEventError*          pM)
{
  PrototypeMMOEventError* pP = new PrototypeMMOEventError;
  pP->code = mConverterError.Work((nsMMOEngine::ErrorCode)(pM->code));
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventRecvFromDown*   TConverterEvents::AssignRecvFromDown  (nsMMOEngine::TEventRecvFromDown*   pM)
{
  PrototypeMMOEventRecvFromDown* pP = new PrototypeMMOEventRecvFromDown;
  pP->id_session = pM->id_session;
  pP->data       = pM->data;
  pP->sizeData   = pM->sizeData;

  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventRecvFromUp*     TConverterEvents::AssignRecvFromUp    (nsMMOEngine::TEventRecvFromUp*     pM)
{
  PrototypeMMOEventRecvFromUp* pP = new PrototypeMMOEventRecvFromUp;
  pP->id_session = pM->id_session;
  pP->data       = pM->data;
  pP->sizeData   = pM->sizeData;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventSaveContext*    TConverterEvents::AssignSaveContext   (nsMMOEngine::TEventSaveContext*    pM)
{
  PrototypeMMOEventSaveContext* pP = new PrototypeMMOEventSaveContext;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventRestoreContext* TConverterEvents::AssignRestoreContext(nsMMOEngine::TEventRestoreContext* pM)
{
  PrototypeMMOEventRestoreContext* pP = new PrototypeMMOEventRestoreContext;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventTryLogin*       TConverterEvents::AssignTryLogin      (nsMMOEngine::TEventTryLogin*       pM)
{
  PrototypeMMOEventTryLogin* pP = new PrototypeMMOEventTryLogin;
  pP->id_session = pM->id_session;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventResultLogin*    TConverterEvents::AssignResultLogin   (nsMMOEngine::TEventResultLogin*    pM)
{
  PrototypeMMOEventResultLogin* pP = new PrototypeMMOEventResultLogin;
  pP->res = mConverterResultLogin.Work(pM->res);
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventDestroyGroup*   TConverterEvents::AssignDestroyGroup  (nsMMOEngine::TEventDestroyGroup*   pM)
{
  PrototypeMMOEventDestroyGroup* pP = new PrototypeMMOEventDestroyGroup;
  pP->id_group = pM->id_group;
  return pP;
}
//------------------------------------------------------------------------------
PrototypeMMOEventEnterInQueue*   TConverterEvents::AssignEnterInQueue  (nsMMOEngine::TEventEnterInQueue*   pM)
{
  PrototypeMMOEventEnterInQueue* pP = new PrototypeMMOEventEnterInQueue;
  pP->numInQueue = pM->numInQueue;
  return pP;
}
//------------------------------------------------------------------------------
