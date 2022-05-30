/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Feature.h"
#include "BaseReactiveSystem.h"

#include "OnAddCollectReactiveSystem.h"
#include "OnUpdateCollectReactiveSystem.h"

#include "OnAddInstantReactiveSystem.h"
#include "OnUpdateInstantReactiveSystem.h"
#include "OnRemoveInstantReactiveSystem.h"

struct System : nsECSFramework::TSystem
{};


struct InitSystem : nsECSFramework::TInitSystem
{
    void Init() override {}
};

struct ExecuteSystem : nsECSFramework::TExecuteSystem
{
    void Execute() override {}
};

struct TearDownSystem : nsECSFramework::TTearDownSystem
{
    void TearDown() override {}
};


struct Feature : nsECSFramework::TFeature
{};

struct OnAddCollect : nsECSFramework::TOnAddCollectReactiveSystem<int, OnAddCollect>
{
    void Reactive(int eid, const int* pC) {}
};

struct OnUpdateCollect : nsECSFramework::TOnUpdateCollectReactiveSystem<int, OnUpdateCollect>
{
    void Reactive(int eid, const int* pC) {}
};


struct OnAddInstant : nsECSFramework::TOnAddInstantReactiveSystem<int, OnAddInstant>
{
    void Reactive(int eid, const int* pC) {}
};

struct OnUpdateInstant : nsECSFramework::TOnUpdateInstantReactiveSystem<int, OnUpdateInstant>
{
    void Reactive(int eid, const int* pC) {}
};

struct OnRemoveInstant : nsECSFramework::TOnRemoveInstantReactiveSystem<int, OnRemoveInstant>
{
    void Reactive(int eid, const int* pC) {}
};
