/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <functional>

#include "LinkToList.h"
#include "MemoryObjectPool.h"
#include "SingletonManager.h"

namespace nsECSFramework
{
    class DllExport IComponent
    {
    public:
        virtual bool IsLess(const IComponent* pOther) const
        {
            BL_FIX_BUG();
            return true;
        }
        virtual bool IsEqual(const IComponent* pOther) const
        {
            BL_FIX_BUG();
            return true;
        }
    };
}