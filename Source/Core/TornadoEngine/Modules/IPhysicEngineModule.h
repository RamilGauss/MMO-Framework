/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DstModule.h"
#include "PhysicEngine/PhysicEngine_Bullet.h"

namespace nsTornadoEngine
{
    class DllExport IPhysicEngineModule : public TDstModule
    {
    public:
        virtual TPhysicEngine_Bullet* GetPE() = 0;
        virtual void SetPE(TPhysicEngine_Bullet* pPE) = 0;
    };
}