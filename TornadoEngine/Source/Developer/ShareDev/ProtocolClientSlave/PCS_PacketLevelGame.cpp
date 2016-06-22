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
TPacket_TryEnterGarage::TPacket_TryEnterGarage() : TBasePacket_PCS(ePacket_TryEnterGarage)
{

}
//-----------------------------------------------------------------
TPacket_EnterGarage::TPacket_EnterGarage() : TBasePacket_PCS(ePacket_EnterGarage)
{

}
//-----------------------------------------------------------------
TPacket_EnterQueue::TPacket_EnterQueue() : TBasePacket_PCS(ePacket_EnterQueue)
{

}
//-----------------------------------------------------------------
TPacket_EnterRoom::TPacket_EnterRoom() : TBasePacket_PCS(ePacket_EnterRoom)
{

}
//-----------------------------------------------------------------
TPacket_LoadMap::TPacket_LoadMap() : TBasePacket_PCS(ePacket_LoadMap)
{
  mID_Map = 0;
}
//-----------------------------------------------------------------
TPacket_CorrectGameObjects::TPacket_CorrectGameObjects() : TBasePacket_PCS(ePacket_CorrectGameObjects)
{
  mID_Object = 0;
}
//-----------------------------------------------------------------
TPacket_AddGameObjects::TPacket_AddGameObjects() : TBasePacket_PCS(ePacket_AddGameObjects)
{
  mID_Object = 0;
}
//-----------------------------------------------------------------
TPacket_EnableGameObjects::TPacket_EnableGameObjects() : TBasePacket_PCS(ePacket_EnableGameObjects)
{
  mID_Object = 0;
}
//-----------------------------------------------------------------
TPacket_DisableGameObjects::TPacket_DisableGameObjects() : TBasePacket_PCS(ePacket_DisableGameObjects)
{
  mID_Object = 0;
}
//-----------------------------------------------------------------
TPacket_DeleteGameObjects::TPacket_DeleteGameObjects() : TBasePacket_PCS(ePacket_DeleteGameObjects)
{
  mID_Object = 0;
}
//-----------------------------------------------------------------
TPacket_GameImpl::TPacket_GameImpl() : TBasePacket_PCS(ePacket_GameImpl)
{

}
//-----------------------------------------------------------------
