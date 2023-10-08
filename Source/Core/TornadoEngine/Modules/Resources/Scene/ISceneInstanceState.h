/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsTornadoEngine
{
    struct DllExport ISceneInstanceState
    {
        enum class State
        {
            ASYNC_INSTANTIATING,
            SYNC_INSTANTIATING,
            
            INSTANTIATED,

            ASYNC_DESTROYING,
            SYNC_DESTROYING,

            DESTROYED,

            SAVING,
        };

        virtual State GetState() const = 0;

        virtual float GetInstantiatingProgress() const = 0;
        virtual bool IsInstantiateCompleted() const = 0;

        virtual float GetDestroyingProgress() const = 0;
        virtual bool IsIDestroyCompleted() const = 0;

        virtual float GetSavingProgress() const = 0;
        virtual bool IsSaveCompleted() const = 0;
    };
}
