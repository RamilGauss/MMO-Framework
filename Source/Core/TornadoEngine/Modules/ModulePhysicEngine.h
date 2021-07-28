/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>

#include "DstModule.h"
#include "PhysicEngine/PhysicEngine_Bullet.h"

namespace nsTornadoEngine
{
    class DllExport TModulePhysicEngine : public TDstModule
    {
        std::shared_ptr<TPhysicEngine_Bullet> mPE;
    public:
        TModulePhysicEngine();

        void StartEvent() override;
        bool Work() override;
        void StopEvent() override;

        TPhysicEngine_Bullet* GetPE();
    };
}