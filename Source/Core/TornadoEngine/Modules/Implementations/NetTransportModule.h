/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/Modules/Interfaces/INetTransportModule.h"

namespace nsTornadoEngine
{
    class DllExport TNetTransportModule : public INetTransportModule
    {
    public:
        bool ModuleStartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;
    };
}