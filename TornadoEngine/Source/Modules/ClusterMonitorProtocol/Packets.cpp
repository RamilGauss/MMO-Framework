/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Packets.h"

using namespace nsClusterMonitorProtocol::nsPackets;

TRq_SlaveCount::TRq_SlaveCount()
{
  type = Rq_SlaveCount;
}
//---------------------------------------------------------------------------------------------
TAn_SlaveCount::TAn_SlaveCount()
{
  type = An_SlaveCount;
}
//---------------------------------------------------------------------------------------------
TCmd_CreateGroupAllClients::TCmd_CreateGroupAllClients()
{
  type = Cmd_CreateGroupAllClients;
}
//---------------------------------------------------------------------------------------------
TCmd_DestroyAllGroups::TCmd_DestroyAllGroups()
{
  type = Cmd_DestroyAllGroups;
}
//---------------------------------------------------------------------------------------------