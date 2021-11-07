/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Feature.h"
#include "MyInitSystem.h"
#include "MyExecuteSystem.h"
#include "NameAddSystem.h"
#include "NameUpdateSystem.h"
#include "NameRemoveSystem.h"
#include "TestAddCollectorReactiveSystem.h"
#include "TestUpdateCollectorReactiveSystem.h"


class TMyFeature : public nsECSFramework::TFeature
{
    TMyInitSystem mInitSystem;
    TMyExecuteSystem mExecuteSystem;

    TNameAddSystem mNameAddSystem;
    TNameUpdateSystem mNameUpdateSystem;
    TNameRemoveSystem mNameRemoveSystem;
    TTestAddCollectorReactiveSystem mTestAddCollectorReactiveSystem;
    TTestUpdateCollectorReactiveSystem mTestUpdateCollectorReactiveSystem;

public:
    void SetEntMng(nsECSFramework::TEntityManager* entMng) override
    {
        TFeature::SetEntMng(entMng);

        Add(&mInitSystem);
        Add(&mExecuteSystem);
        Add(&mNameAddSystem);
        Add(&mNameUpdateSystem);
        Add(&mNameRemoveSystem);
        Add(&mTestAddCollectorReactiveSystem);
        Add(&mTestUpdateCollectorReactiveSystem);
    }
};
