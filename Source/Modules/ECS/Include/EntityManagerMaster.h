/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include <vector>

namespace nsECSFramework
{
    class TEntityManager;

    class DllExport TEntityManagerMaster
    {
        std::vector<TEntityManager*> mEntMngs;
    public:
        void AddEntityManager(TEntityManager* pEntMng);
        void RemoveEntityManager(TEntityManager* pEntMng);

        const std::vector<TEntityManager*>& GetEntityManager() const;

        TEntityManagerMaster() = default;
    };
}
