/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "PhysicEngine/PhysicEngine_Bullet.h"

#include "TornadoEngine/Modules/Common/LogicWrapperModule.h"

namespace nsTornadoEngine
{
    class DllExport IPhysicEngineModule : public TLogicWrapperModule
    {
    public:
        virtual TPhysicEngine_Bullet* GetPE() = 0;
        virtual void SetPE(TPhysicEngine_Bullet* pPE) = 0;
    };
}