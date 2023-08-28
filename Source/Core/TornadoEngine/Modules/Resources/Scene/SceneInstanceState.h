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
            FILE_LOADING,
            SCENE_DESERIALIZING,
            COMPONENTS_DESERIALIZING,
            SORTING_ENTITY_BY_RANK,
            ENTITY_INSTANTIATING,
            PREFAB_INSTANTIATING,

            STABLE,

            DESTROYING,
        };

        std::string GetGuid() const;

        Step GetStep() const;

        float GetLoadingProgress();

        void Work();

    private:
        std::string mGuid;
        Step mStep = Step::FILE_LOADING;

        int mPartCount = 1;
        int mPartProgress = 0;

        const int FILE_PART_SIZE = 10`000`000;
        const int COMPONENT_PART_SIZE = 100;
        const int SORTING_PART_SIZE = 100;
        const int ENTITY_INSTANTIATING_PART_SIZE = 1000;
        const int PREFAB_INSTANTIATING_PART_SIZE = 10;
    };
}
