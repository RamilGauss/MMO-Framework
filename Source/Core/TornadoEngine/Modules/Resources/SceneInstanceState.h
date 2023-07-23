/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport TSceneInstanceState
    {
    public:
        enum Step
        {
            // Loading
            BEGIN,
            DESERIALIZING,
            SORTING,
            ENTITY_INSTANTIATING,
            PREFAB_INSTANTIATING,

            STABLE,
            
            DESTROYING,
        }

        std::string GetGuid() const;

        Step GetStep() const;

        float GetLoadingProgress();

        void Work();

    private:
        std::string mGuid;
        Step mStep;
    };
}