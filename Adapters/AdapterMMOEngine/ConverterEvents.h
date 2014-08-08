/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ConverterEventsH
#define ConverterEventsH

#include "PrototypeMMOEvents.h"
#include "Events.h"
#include "ConverterError.h"
#include "ConverterResultLogin.h"

class TConverterEvents
{
  TConverterError mConverterError;
  TConverterResultLogin nConverterResultLogin;
  TConverterResultLogin mConverterResultLogin;

public:
  TConverterEvents();
  virtual ~TConverterEvents();

  // return object making by operator new
  PrototypeMMOBaseEvent* Work(nsMMOEngine::TBaseEvent* pModuleEvent);
protected:
  PrototypeMMOEventConnectDown*    AssignConnectDown   (nsMMOEngine::TEventConnectDown*    pM);
  PrototypeMMOEventDisconnectDown* AssignDisconnectDown(nsMMOEngine::TEventDisconnectDown* pM);
  PrototypeMMOEventConnectUp*      AssignConnectUp     (nsMMOEngine::TEventConnectUp*      pM);
  PrototypeMMOEventDisconnectUp*   AssignDisconnectUp  (nsMMOEngine::TEventDisconnectUp*   pM);
  PrototypeMMOEventError*          AssignError         (nsMMOEngine::TEventError*          pM);
  PrototypeMMOEventRecvFromDown*   AssignRecvFromDown  (nsMMOEngine::TEventRecvFromDown*   pM);
  PrototypeMMOEventRecvFromUp*     AssignRecvFromUp    (nsMMOEngine::TEventRecvFromUp*     pM);
  PrototypeMMOEventSaveContext*    AssignSaveContext   (nsMMOEngine::TEventSaveContext*    pM);
  PrototypeMMOEventRestoreContext* AssignRestoreContext(nsMMOEngine::TEventRestoreContext* pM);
  PrototypeMMOEventTryLogin*       AssignTryLogin      (nsMMOEngine::TEventTryLogin*       pM);
  PrototypeMMOEventResultLogin*    AssignResultLogin   (nsMMOEngine::TEventResultLogin*    pM);
  PrototypeMMOEventDestroyGroup*   AssignDestroyGroup  (nsMMOEngine::TEventDestroyGroup*   pM);
  PrototypeMMOEventEnterInQueue*   AssignEnterInQueue  (nsMMOEngine::TEventEnterInQueue*   pM);
};

#endif
