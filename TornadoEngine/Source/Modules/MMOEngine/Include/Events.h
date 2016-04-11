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
	}_PACKED;
	//-------------------------------------------------------------
  struct DllExport TEventRecvFromDown : public TEventRecv
  {
    TEventRecvFromDown();
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventRecvFromUp : public TEventRecv
  {
    TEventRecvFromUp();
    ~TEventRecvFromUp();
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventDisconnectUp : public TBaseEvent
  {
    TEventDisconnectUp();
    unsigned int id_session;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventDisconnectDown : public TBaseEvent
  {
    TEventDisconnectDown();
    unsigned int id_session;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventConnectUp : public TBaseEvent
  {
    TEventConnectUp();
    unsigned int id_session;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventConnectDown : public TBaseEvent
  {
    TEventConnectDown();
    unsigned int id_session;
		bool use_crypt;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventDestroyGroup : public TBaseEvent
  {
    TEventDestroyGroup();
    unsigned int id_group;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventResultLogin : public TBaseEvent
  {
    TEventResultLogin();
    TMaster::tResultLogin res;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventError : public TBaseEvent
  {
    TEventError();
    unsigned int code;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventRestoreContext : public TBaseEvent
  {
    TEventRestoreContext();
    unsigned int id_session;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventTryLogin : public TBaseEvent
  {
    TEventTryLogin();
    unsigned int id_session;
		bool use_crypt;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventSaveContext : public TBaseEvent
  {
    TEventSaveContext();
    unsigned int id_session;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventEnterInQueue : public TBaseEvent
  {
    TEventEnterInQueue();
    int numInQueue;
  }_PACKED;
  //-------------------------------------------------------------
  struct DllExport TEventLeaveQueue : public TBaseEvent
  {
    TEventLeaveQueue();
  }_PACKED;
  //-------------------------------------------------------------
#if defined( WIN32 )
#pragma pack(pop)
#endif

}
#endif