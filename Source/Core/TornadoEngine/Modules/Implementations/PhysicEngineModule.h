/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>

#include "Modules/Interfaces/IPhysicEngineModule.h"

namespace nsTornadoEngine
{
    class DllExport TPhysicEngineModule : public IPhysicEngineModule
    {
        std::shared_ptr<TPhysicEngine_Bullet> mPE;
    public:
        TPhysicEngineModule();

        bool ModuleStartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;

        TPhysicEngine_Bullet* GetPE() override;
        void SetPE(TPhysicEngine_Bullet* pPE) override;
    };
}