/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ExecuteSystem.h"
#include "TearDownSystem.h"

namespace nsECSFramework
{
    class DllExport TBaseCollectReactiveSystem : public TExecuteSystem, public TTearDownSystem
    {
    protected:
        int mReactiveId = -1;
    public:
        bool IsCollectReactive() const override final;

        virtual void ClearEvents() = 0;
    };
}
