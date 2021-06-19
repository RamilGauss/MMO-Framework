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
#if defined( WIN32 )
#pragma pack(push, 1)
#endif
  struct DllExport TRecvEvent : public TBaseEvent
  {
    unsigned int sessionID = INVALID_HANDLE_SESSION;
    
    char* GetData();
    int GetSize();
    unsigned short GetShift();
    void SetShift( unsigned short val );
  private:
    unsigned short shift = 0;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TRecvFromDownEvent : public TRecvEvent
  {
    TRecvFromDownEvent();
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TRecvFromUpEvent : public TRecvEvent
  {
    TRecvFromUpEvent();
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TDisconnectUpEvent : public TBaseEvent
  {
    TDisconnectUpEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TDisconnectDownEvent : public TBaseEvent
  {
    TDisconnectDownEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TConnectUpEvent : public TBaseEvent
  {
    TConnectUpEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TTryConnectDownEvent : public TBaseEvent
  {
    TTryConnectDownEvent();
    unsigned int sessionID;
    void* hashLogin;
    int hashLoginSize;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TConnectDownEvent : public TBaseEvent
  {
    TConnectDownEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TDestroyGroupEvent : public TBaseEvent
  {
    TDestroyGroupEvent();
    unsigned int groupID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TResultLoginEvent : public TBaseEvent
  {
    TResultLoginEvent();
    TMaster::tResultLogin res;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TErrorEvent : public TBaseEvent
  {
    TErrorEvent();
    nsMMOEngine::ErrorCode code;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TRestoreContextEvent : public TBaseEvent
  {
    TRestoreContextEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TTryLoginEvent : public TBaseEvent
  {
    TTryLoginEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TLoginEvent : public TBaseEvent
  {
    TLoginEvent();
    unsigned int clientKey;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TLogoffEvent : public TBaseEvent
  {
    TLogoffEvent();
    unsigned int clientKey;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TSaveContextEvent : public TBaseEvent
  {
    TSaveContextEvent();
    unsigned int sessionID;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEnterInQueueEvent : public TBaseEvent
  {
    TEnterInQueueEvent();
    int numInQueue;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TLeaveQueueEvent : public TBaseEvent
  {
    TLeaveQueueEvent();
  }_PACKED;
  //-------------------------------------------------------------
#if defined( WIN32 )
#pragma pack(pop)
#endif

}
