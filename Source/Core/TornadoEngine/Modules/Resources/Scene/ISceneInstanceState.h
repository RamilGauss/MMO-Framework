/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"


namespace nsBase::nsZones
{
    struct IContext;
}

namespace nsTornadoEngine
{
    class DllExport ISceneInstanceState
    {
    public:
        ISceneInstanceState(nsBase::nsZones::IContext* pCtx) { mCtx = pCtx; }

        enum class State
        {
            INSTANTIATING,
            INSTANTIATED,
            SAVING,
            DESTROYING,
            DESTROYED,
        };

        virtual State GetState() const = 0;

        virtual float GetProgress() const = 0;

        virtual float GetStateProgress() const = 0;
        virtual bool IsCompleted() const = 0;

    protected:
        nsBase::nsZones::IContext* mCtx = nullptr;
    };
}
