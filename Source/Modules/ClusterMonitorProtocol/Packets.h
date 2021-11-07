/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
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
#pragma pack(push, 1)
        struct DllExport THeader
        {
            unsigned short type;
        };

        struct DllExport TRq_SlaveCount : THeader
        {
            TRq_SlaveCount();
        };

        struct DllExport TAn_SlaveCount : THeader
        {
            int cnt = 0;
            TAn_SlaveCount();
        };

        struct DllExport TCmd_CreateGroupAllClients : THeader
        {
            TCmd_CreateGroupAllClients();
        };

        struct DllExport TCmd_DestroyAllGroups : THeader
        {
            TCmd_DestroyAllGroups();
        };
#pragma pack(pop)
    }
}