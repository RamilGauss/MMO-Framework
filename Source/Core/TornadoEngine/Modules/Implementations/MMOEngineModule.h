/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IMMOEngineModule.h"

#include "MMOEngine/include/Base.h"
#include "MMOEngine/include/INetTransport.h"
#include "NetTransport/MakerNetTransport.h"

namespace nsTornadoEngine
{
    class DllExport TMMOEngineModule : public IMMOEngineModule
    {
    public:
        bool ModuleStartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;
    };
}
