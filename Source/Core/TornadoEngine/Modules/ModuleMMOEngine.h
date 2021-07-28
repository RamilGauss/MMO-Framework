/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DstModule.h"

#include "SrcEvent_ex.h"

#include "MMOEngine/include/Base.h"
#include "MMOEngine/include/INetTransport.h"
#include "NetTransport/MakerNetTransport.h"

namespace nsTornadoEngine
{
    class DllExport TModuleMMOEngine : public TDstModule
    {
    public:
        void StartEvent() override;
        bool Work() override;
        void StopEvent() override;
    };
}
