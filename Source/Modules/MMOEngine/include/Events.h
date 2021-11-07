/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseEvent.h"
#include "Master.h"

// только Асинхронные события

namespace nsMMOEngine
{
#pragma pack(push, 1)
  struct DllExport TRecvEvent : public TBaseEvent
  {
    unsigned int sessionID = INVALID_HANDLE_SESSION;
    
    char* GetData();
    int GetSize();
    unsigned short GetShift();
    void SetShift( unsigned short val );
  private:
    unsigned short shift = 0;
  };
  //-------------------------------------------------------------
  struct DllExport TRecvFromDownEvent : public TRecvEvent
  {
    TRecvFromDownEvent();
  };
  //-------------------------------------------------------------
  struct DllExport TRecvFromUpEvent : public TRecvEvent
  {
    TRecvFromUpEvent();
  };
  //-------------------------------------------------------------
  struct DllExport TDisconnectUpEvent : public TBaseEvent
  {
    TDisconnectUpEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TDisconnectDownEvent : public TBaseEvent
  {
    TDisconnectDownEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TConnectUpEvent : public TBaseEvent
  {
    TConnectUpEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TTryConnectDownEvent : public TBaseEvent
  {
    TTryConnectDownEvent();
    unsigned int sessionID;
    void* hashLogin;
    int hashLoginSize;
  };
  //-------------------------------------------------------------
  struct DllExport TConnectDownEvent : public TBaseEvent
  {
    TConnectDownEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TDestroyGroupEvent : public TBaseEvent
  {
    TDestroyGroupEvent();
    unsigned int groupID;
  };
  //-------------------------------------------------------------
  struct DllExport TResultLoginEvent : public TBaseEvent
  {
    TResultLoginEvent();
    TMaster::tResultLogin res;
  };
  //-------------------------------------------------------------
  struct DllExport TErrorEvent : public TBaseEvent
  {
    TErrorEvent();
    nsMMOEngine::ErrorCode code;
  };
  //-------------------------------------------------------------
  struct DllExport TRestoreContextEvent : public TBaseEvent
  {
    TRestoreContextEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TTryLoginEvent : public TBaseEvent
  {
    TTryLoginEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TLoginEvent : public TBaseEvent
  {
    TLoginEvent();
    unsigned int clientKey;
  };
  //-------------------------------------------------------------
  struct DllExport TLogoffEvent : public TBaseEvent
  {
    TLogoffEvent();
    unsigned int clientKey;
  };
  //-------------------------------------------------------------
  struct DllExport TSaveContextEvent : public TBaseEvent
  {
    TSaveContextEvent();
    unsigned int sessionID;
  };
  //-------------------------------------------------------------
  struct DllExport TEnterInQueueEvent : public TBaseEvent
  {
    TEnterInQueueEvent();
    int numInQueue;
  };
  //-------------------------------------------------------------
  struct DllExport TLeaveQueueEvent : public TBaseEvent
  {
    TLeaveQueueEvent();
  };
  //-------------------------------------------------------------
#pragma pack(pop)
}
