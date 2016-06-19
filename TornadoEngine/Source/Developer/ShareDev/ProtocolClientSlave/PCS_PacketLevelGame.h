/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PCS_PacketLevelGameH
#define PCS_PacketLevelGameH

#include "PCS_TypePacket.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsPCS
{
  //-----------------------------------------------------------------
  struct DllExport TPacket_TryEnterRoom : public TBasePacket_PCS
  {
    TPacket_TryEnterRoom();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_TryLeaveRoom : public TBasePacket_PCS
  {
    TPacket_TryLeaveRoom();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_TryLeaveQueue : public TBasePacket_PCS
  {
    TPacket_TryLeaveQueue();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_CorrectGameObjects : public TBasePacket_PCS
  {
    TPacket_CorrectGameObjects();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_EnterQueueRoom : public TBasePacket_PCS
  {
    TPacket_EnterQueueRoom();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_LeaveQueueRoom : public TBasePacket_PCS
  {
    TPacket_LeaveQueueRoom();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_EnterRoom : public TBasePacket_PCS
  {
    TPacket_EnterRoom();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_LeaveRoom : public TBasePacket_PCS
  {
    TPacket_LeaveRoom();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_LoadMap : public TBasePacket_PCS
  {
    TPacket_LoadMap();
    unsigned int id_map;
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_AddGameObjects : public TBasePacket_PCS
  {
    TPacket_AddGameObjects();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_EnableGameObjects : public TBasePacket_PCS
  {
    TPacket_EnableGameObjects();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_DisableGameObjects : public TBasePacket_PCS
  {
    TPacket_DisableGameObjects();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_DeleteGameObjects : public TBasePacket_PCS
  {
    TPacket_DeleteGameObjects();
  }_PACKED;
  //-----------------------------------------------------------------
  struct DllExport TPacket_GameImpl : public TBasePacket_PCS
  {
    TPacket_GameImpl();
    // empty! add some members!
  }_PACKED;
  //-----------------------------------------------------------------
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
