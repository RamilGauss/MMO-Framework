/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include <list>

namespace nsECSFramework
{
    class TSystem;
    class TFeature;

    class DllExport TSystemConveyorContainer
    {
        std::list<TSystem*> mSystems;

        std::list<TFeature*> mFeatures;

        std::list<TSystem*> mTopSystems;
    public:
        void AddSystem(TSystem* pSystem);
        void RemoveSystem(TSystem* pSystem);

        const std::list<TSystem*>& GetSystems() const;

        const std::list<TSystem*>& GetTopSystems() const;

    private:
        void TryAddToTopSystems(TSystem* pSystem);
    };
}
