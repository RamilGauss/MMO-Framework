/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"

namespace nsClusterMonitorProtocol
{
  namespace nsPackets
  {
    enum Type
    {
      Rq_SlaveCount,
      An_SlaveCount,
      Cmd_CreateGroupAllClients,
      Cmd_DestroyAllGroups,
    };
#ifdef WIN32
#pragma pack(push, 1)
#endif
    struct DllExport THeader
    {
      unsigned short type;
    }_PACKED;

    struct DllExport TRq_SlaveCount : THeader
    {
      TRq_SlaveCount();
    }_PACKED;

    struct DllExport TAn_SlaveCount : THeader
    {
      int cnt = 0;
      TAn_SlaveCount();
    }_PACKED;

    struct DllExport TCmd_CreateGroupAllClients : THeader
    {
      TCmd_CreateGroupAllClients();
    }_PACKED;

    struct DllExport TCmd_DestroyAllGroups : THeader
    {
      TCmd_DestroyAllGroups();
    }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif
  }
}