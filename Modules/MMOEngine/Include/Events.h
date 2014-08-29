/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EVENTS_H
#define EVENTS_H

#include "BaseEvent.h"
#include "Master.h"

// только Асинхронные события

namespace nsMMOEngine
{
#if defined( WIN32 )
#pragma pack(push, 1)
#endif

  struct DllExport TEventRecv : public TBaseEvent
	{
		TEventRecv();
		unsigned int id_session;
		void* data;
		int sizeData;
	};
	//-------------------------------------------------------------
  struct DllExport TEventRecvFromDown : public TEventRecv
  {
    TEventRecvFromDown();
  };
  //-------------------------------------------------------------
  struct DllExport TEventRecvFromUp : public TEventRecv
  {
    TEventRecvFromUp();
    ~TEventRecvFromUp();
  };
  //-------------------------------------------------------------
  struct DllExport TEventDisconnectUp : public TBaseEvent
  {
    TEventDisconnectUp();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport TEventDisconnectDown : public TBaseEvent
  {
    TEventDisconnectDown();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport TEventConnectUp : public TBaseEvent
  {
    TEventConnectUp();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport TEventConnectDown : public TBaseEvent
  {
    TEventConnectDown();
    unsigned int id_session;
		bool use_crypt;
  };
  //-------------------------------------------------------------
  struct DllExport TEventDestroyGroup : public TBaseEvent
  {
    TEventDestroyGroup();
    unsigned int id_group;
  };
  //-------------------------------------------------------------
  struct DllExport TEventResultLogin : public TBaseEvent
  {
    TEventResultLogin();
    TMaster::tResultLogin res;
  };
  //-------------------------------------------------------------
  struct DllExport TEventError : public TBaseEvent
  {
    TEventError();
    unsigned int code;
  };
  //-------------------------------------------------------------
  struct DllExport TEventRestoreContext : public TBaseEvent
  {
    TEventRestoreContext();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport TEventTryLogin : public TBaseEvent
  {
    TEventTryLogin();
    unsigned int id_session;
		bool use_crypt;
  };
  //-------------------------------------------------------------
  struct DllExport TEventSaveContext : public TBaseEvent
  {
    TEventSaveContext();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct DllExport TEventEnterInQueue : public TBaseEvent
  {
    TEventEnterInQueue();
    int numInQueue;
  };
  //-------------------------------------------------------------
#if defined( WIN32 )
#pragma pack(pop)
#endif

}
#endif