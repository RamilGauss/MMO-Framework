/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/Include/INetTransport.h"

namespace nsMMOEngine
{
    class DllExport IMakerTransport
    {
    public:
        virtual INetTransport* New() = 0;
        virtual void Delete(INetTransport* pTransport) = 0;
    };
}
