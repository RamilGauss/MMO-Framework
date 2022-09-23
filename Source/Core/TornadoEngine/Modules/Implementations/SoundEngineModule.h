/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ISoundEngineModule.h"

namespace nsTornadoEngine
{
    class DllExport TSoundEngineModule : public ISoundEngineModule
    {
    public:
        bool StartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;
    };
}