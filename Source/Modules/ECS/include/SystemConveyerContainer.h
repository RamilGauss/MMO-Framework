/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <set>

namespace nsECSFramework
{
    class TSystem;

    class DllExport TSystemConveyerContainer
    {
        std::set<TSystem*> mSystems;
    public:
        void AddSystem(TSystem* pSystem);
        void RemoveSystem(TSystem* pSystem);

        const std::set<TSystem*>& GetSystems() const;
    };
}
