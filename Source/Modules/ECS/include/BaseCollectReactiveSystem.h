/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ExecuteSystem.h"

namespace nsECSFramework
{
    class DllExport TBaseCollectReactiveSystem : virtual public TExecuteSystem
    {
    protected:
        int mReactiveId = 0;
    public:
        virtual void Reactive(TEntityID eid, IComponent* pC) = 0;
    };
}
