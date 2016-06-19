/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PCS_PacketLevelGame.h"

using namespace nsPCS;

TPacket_TryEnterRoom::TPacket_TryEnterRoom() : TBasePacket_PCS(ePacket_TryEnterRoom)
{

}
//-----------------------------------------------------------------
TPacket_TryLeaveRoom::TPacket_TryLeaveRoom() : TBasePacket_PCS(ePacket_TryLeaveRoom)
{

}
//-----------------------------------------------------------------
TPacket_TryLeaveQueue::TPacket_TryLeaveQueue() : TBasePacket_PCS(ePacket_TryLeaveQueue)
{

}
//-----------------------------------------------------------------
TPacket_CorrectGameObjects::TPacket_CorrectGameObjects() : TBasePacket_PCS(ePacket_CorrectGameObjects)
{

}
//-----------------------------------------------------------------
TPacket_EnterQueueRoom::TPacket_EnterQueueRoom() : TBasePacket_PCS(ePacket_EnterQueueRoom)
{

}
//-----------------------------------------------------------------
TPacket_LeaveQueueRoom::TPacket_LeaveQueueRoom() : TBasePacket_PCS(ePacket_LeaveQueueRoom)
{

}
//-----------------------------------------------------------------
TPacket_EnterRoom::TPacket_EnterRoom() : TBasePacket_PCS(ePacket_EnterRoom)
{

}
//-----------------------------------------------------------------
TPacket_LeaveRoom::TPacket_LeaveRoom() : TBasePacket_PCS(ePacket_LeaveRoom)
{

}
//-----------------------------------------------------------------
TPacket_LoadMap::TPacket_LoadMap() : TBasePacket_PCS(ePacket_LoadMap)
{
  id_map = 0;
}
//-----------------------------------------------------------------
TPacket_AddGameObjects::TPacket_AddGameObjects() : TBasePacket_PCS(ePacket_AddGameObjects)
{

}
//-----------------------------------------------------------------
TPacket_EnableGameObjects::TPacket_EnableGameObjects() : TBasePacket_PCS(ePacket_EnableGameObjects)
{

}
//-----------------------------------------------------------------
TPacket_DisableGameObjects::TPacket_DisableGameObjects() : TBasePacket_PCS(ePacket_DisableGameObjects)
{

}
//-----------------------------------------------------------------
TPacket_DeleteGameObjects::TPacket_DeleteGameObjects() : TBasePacket_PCS(ePacket_DeleteGameObjects)
{

}
//-----------------------------------------------------------------
TPacket_GameImpl::TPacket_GameImpl() : TBasePacket_PCS(ePacket_GameImpl)
{

}
//-----------------------------------------------------------------
