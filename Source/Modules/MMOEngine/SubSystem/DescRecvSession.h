/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "INetTransport.h"
#include "ContainerTypes.h"
#include "HiTimer.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
    struct TDescRecvSession : public INetTransport::TDescRecv
    {
        TContainer c;

        unsigned int time_ms;
        unsigned int sessionID;
        TDescRecvSession()
        {
            sessionID = INVALID_HANDLE_SESSION;
            time_ms = ht_GetMSCount();
        }
        void Assign(TDescRecvSession* p)
        {
            time_ms = p->time_ms;
            sessionID = p->sessionID;
            ip_port = p->ip_port;
            type = p->type;
            // копирование данных
            c.SetDataByCount(p->data, p->dataSize);
            dataSize = p->dataSize;
            data = (char*)c.GetPtr();
        }
    };
}