/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    struct DllExport ISceneInstanceState
    {
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



        virtual float GetInstantiatingProgress() const = 0;
        virtual bool IsInstantiateCompleted() const = 0;

        virtual float GetDestroyingProgress() const = 0;
        virtual bool IsIDestroyCompleted() const = 0;

        virtual float GetSavingProgress() const = 0;
        virtual bool IsSaveCompleted() const = 0;
    };
}
