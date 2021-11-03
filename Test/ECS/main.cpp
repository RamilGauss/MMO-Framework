/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "Config.h"
#include "EntityManager.h"
#include "Feature.h"
#include "HiTimer.h"
#include "ExecuteSystem.h"
#include "InitSystem.h"
#include "OnAddInstantReactiveSystem.h"
#include "OnUpdateInstantReactiveSystem.h"
#include "OnRemoveInstantReactiveSystem.h"

using namespace nsECSFramework;

TEntityManager entMng;

TFeature mainFeature;

struct TNameComponent : IComponent
{
    std::string name;

    bool IsLess(const IComponent* pOther) const override
    {
        return name < ((const TNameComponent*)(pOther))->name;
    }
    bool IsEqual(const IComponent* pOther) const override
    {
        return name == ((const TNameComponent*) (pOther))->name;
    }
};

class TMyInitSystem : public TInitSystem
{
public:
    void Init() override
    {
        auto eid = mEntMng->CreateEntity();

        TNameComponent nameComponent;
        nameComponent.name = "42";
        mEntMng->SetComponent(eid, nameComponent);
    }
};

class TNameAddSystem : public TOnAddInstantReactiveSystem<TNameComponent>
{
public:
    void Reactive(TEntityID eid, IComponent* pC) override
    {
        fmt::print("name {} was added\n", ((TNameComponent*)pC)->name);
    }
};

class TNameUpdateSystem : public TOnUpdateInstantReactiveSystem<TNameComponent>
{
public:
    void Reactive(TEntityID eid, IComponent* pC) override
    {
        fmt::print("name {} was updated\n", ((TNameComponent*) pC)->name);
    }
};

class TNameRemoveSystem : public TOnRemoveInstantReactiveSystem<TNameComponent>
{
public:
    void Reactive(TEntityID eid, IComponent* pC) override
    {
        fmt::print("name {} was removed\n", ((TNameComponent*) pC)->name);
    }
};

class TMyExecuteSystem : public TExecuteSystem
{
    int mCounter = 0;
public:
    void Execute() override
    {
        if (mCounter == 10) {
            auto nameList = *(mEntMng->GetByHas<TNameComponent>());
            for (auto& eid : nameList) {
                mEntMng->RemoveComponent<TNameComponent>(eid);
            }
        } else {
            auto& nameList = *(mEntMng->GetByHas<TNameComponent>());
            for (auto& eid : nameList) {
                auto nameComponent = mEntMng->ViewComponent<TNameComponent>(eid);

                nameComponent->name = fmt::format("{}", mCounter);

                mEntMng->UpdateComponent(eid, nameComponent);
            }
        }

        mCounter++;
    }
};

class TMyFeature : public TFeature
{
    TMyInitSystem mInitSystem;
    TMyExecuteSystem mExecuteSystem;

    TNameAddSystem mNameAddSystem;
    TNameUpdateSystem mNameUpdateSystem;
    TNameRemoveSystem mNameRemoveSystem;

public:
    void SetEntMng(TEntityManager* entMng) override
    { 
        TFeature::SetEntMng(entMng);

        Add(&mInitSystem);
        Add(&mExecuteSystem);
        Add(&mNameAddSystem);
        Add(&mNameUpdateSystem);
        Add(&mNameRemoveSystem);
    }
};

TMyFeature myFeature;

int main()
{
    TNameComponent nameComponent;
    nameComponent.name = "asda";
    entMng.GetByUnique<TNameComponent>(nameComponent);
    entMng.GetByValue<TNameComponent>(nameComponent);


    entMng.Setup();
    printf("\n");

    mainFeature.SetEntMng(&entMng);

    mainFeature.Add(&myFeature);

    while (true) {
        mainFeature.Execute();
    }

    return 0;
}
