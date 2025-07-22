/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <functional>

#include "Base/Common/TypeDef.h"
#include "Base/Common/BL_Debug.h"

#include "ECS/Include/Config.h"

namespace nsTornadoEngine
{
    template <typename T>
    struct DllExport THandlerPool
    {
        using Func = std::function<bool(nsECSFramework::TEntityID, const T*)>;

        void Add(Func func)
        {
            mFuncs.push_back(func);
        }

        void HandleByPool(nsECSFramework::TEntityID eid, const T* pC)
        {
            int counter = 0;
            for (auto& func : mFuncs) {
                auto result = func(eid, pC);
                if (result) {
                    counter++;
                }
            }

            BL_ASSERT(counter == 1);
        }
    private:
        std::list<Func> mFuncs;
    };
}