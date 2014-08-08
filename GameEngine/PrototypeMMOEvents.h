/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOEventsH
#define PrototypeMMOEventsH

#include "TypeDef.h"
#include "PrototypeMMOBaseEvent.h"
#include "PrototypeMMOMaster.h"

#if defined( WIN32 )
#pragma pack(push, 1)
#endif
  struct DllExport PrototypeMMOEventRecv : public PrototypeMMOBaseEvent
	{
		PrototypeMMOEventRecv();
		unsigned int id_session;
		void* data;
		int sizeData;
	};
	//-------------------------------------------------------------
  struct DllExport PrototypeMMOEventRecvFromDown : public PrototypeMMOEventRecv
  {
    PrototypeMMOEventRecvFromDown();
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventRecvFromUp : public PrototypeMMOEventRecv
  {
    PrototypeMMOEventRecvFromUp();
    ~PrototypeMMOEventRecvFromUp();
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventDisconnectUp : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventDisconnectUp();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventDisconnectDown : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventDisconnectDown();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventConnectUp : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventConnectUp();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventConnectDown : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventConnectDown();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventDestroyGroup : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventDestroyGroup();
    unsigned int id_group;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventResultLogin : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventResultLogin();
    PrototypeMMOMaster::tResultLogin res;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventError : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventError();
    unsigned int code;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventRestoreContext : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventRestoreContext();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventTryLogin : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventTryLogin();
    unsigned int id_session;
		bool use_crypt;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventSaveContext : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventSaveContext();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport PrototypeMMOEventEnterInQueue : public PrototypeMMOBaseEvent
  {
    PrototypeMMOEventEnterInQueue();
    int numInQueue;
  };
  //-------------------------------------------------------------
#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif