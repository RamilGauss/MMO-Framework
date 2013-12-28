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

  struct MMO_ENGINE_EI TEventRecv : public TBaseEvent
	{
		TEventRecv();
		unsigned int id_session;
		void* data;
		int sizeData;
	};
	//-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventRecvFromDown : public TEventRecv
  {
    TEventRecvFromDown();
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventRecvFromUp : public TEventRecv
  {
    TEventRecvFromUp();
    ~TEventRecvFromUp();
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventDisconnectUp : public TBaseEvent
  {
    TEventDisconnectUp();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventDisconnectDown : public TBaseEvent
  {
    TEventDisconnectDown();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventConnectUp : public TBaseEvent
  {
    TEventConnectUp();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventConnectDown : public TBaseEvent
  {
    TEventConnectDown();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventDestroyGroup : public TBaseEvent
  {
    TEventDestroyGroup();
    unsigned int id_group;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventResultLogin : public TBaseEvent
  {
    TEventResultLogin();
    TMaster::tResultLogin res;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventError : public TBaseEvent
  {
    TEventError();
    unsigned int code;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventRestoreContext : public TBaseEvent
  {
    TEventRestoreContext();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventTryLogin : public TBaseEvent
  {
    TEventTryLogin();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventSaveContext : public TBaseEvent
  {
    TEventSaveContext();
    unsigned int id_session;
  };
  //-------------------------------------------------------------
  struct MMO_ENGINE_EI TEventEnterInQueue : public TBaseEvent
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