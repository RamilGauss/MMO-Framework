/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "EntityManager.h"

namespace nsECSFramework
{
    class DllExport TSystem
    {
    protected:
        TEntityManager* mEntMng = nullptr;
    public:
        virtual void SetEntMng(TEntityManager* entMng);
        TEntityManager* GetEntMng();

        enum class Type
        {
            INIT, EXECUTE, REACTIVE
        };

        virtual Type GetType() const = 0;
    };
}
