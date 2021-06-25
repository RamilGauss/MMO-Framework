/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <conio.h>

#include "EntityManager.h"
#include "VectorRise.h"
#include "HiTimer.h"
#include "ExecuteSystem.h"
#include "SingletonManager.h"

#include <fmt/core.h>
#include <entt/entt.hpp>

const int OBJECT_COUNT =
#ifdef _DEBUG
3000;
#else
3000;
#endif

const int FRAME_COUNT =
#ifdef _DEBUG
10;
#else
10000;
#endif

using namespace nsECSFramework;

struct TBulletObject
{
    std::array<float, 16> m;
};

struct TOgreObject
{
    std::array<float, 16> m;
};

struct TPhysicComponent : IComponent
{
    std::shared_ptr<TBulletObject> p;
};

struct TGraphicComponent : IComponent
{
    std::shared_ptr<TOgreObject> p;
};

struct TTransformComponent : IComponent
{
    std::array<float, 16> m;
};
//------------------------------------------------------------------------------------
TEntityManager g_EntMng;

void EcsFrameworkInit()
{
    g_EntMng.Setup();

    TPhysicComponent pc;
    TGraphicComponent gc;
    TTransformComponent tc;

    for (int i = 0; i < OBJECT_COUNT; i++) {
        auto eid = g_EntMng.CreateEntity();
        pc.p.reset(new TBulletObject());
        g_EntMng.SetComponent(eid, pc);
        g_EntMng.SetComponent(eid, tc);
    }
    for (int i = 0; i < OBJECT_COUNT; i++) {
        auto eid = g_EntMng.CreateEntity();
        pc.p.reset(new TBulletObject());
        g_EntMng.SetComponent(eid, pc);

        gc.p.reset(new TOgreObject());
        g_EntMng.SetComponent(eid, gc);

        g_EntMng.SetComponent(eid, tc);
    }
    for (int i = 0; i < OBJECT_COUNT; i++) {
        auto eid = g_EntMng.CreateEntity();
        gc.p.reset(new TOgreObject());
        g_EntMng.SetComponent(eid, gc);
        g_EntMng.SetComponent(eid, tc);
    }
}

void EcsFrameworkDone()
{
    g_EntMng.Clear();
}

void EcsFrameworkPhysicToCore()
{
    auto& gp = *(g_EntMng.GetByHas<TGraphicComponent, TPhysicComponent>());
    for (auto& eid : gp) {
        auto pc = g_EntMng.ViewComponent<TPhysicComponent>(eid);
        auto tc = g_EntMng.ViewComponent<TTransformComponent>(eid);
        tc->m = pc->p->m;
        g_EntMng.UpdateComponent<TTransformComponent>(eid, tc);
    }
}

void EcsFrameworkCoreToGraphic()
{
    auto& gp = *(g_EntMng.GetByHas<TGraphicComponent, TPhysicComponent>());
    for (auto& eid : gp) {
        auto tc = g_EntMng.ViewComponent<TTransformComponent>(eid);
        auto gc = g_EntMng.ViewComponent<TGraphicComponent>(eid);
        gc->p->m = tc->m;
        g_EntMng.UpdateComponent<TGraphicComponent>(eid, gc);
    }
}

void EcsFrameworkBenchmark()
{
    for (int i = 0; i < FRAME_COUNT; i++) {
        EcsFrameworkPhysicToCore();
        EcsFrameworkCoreToGraphic();
    }
}
//------------------------------------------------------------------------------------
entt::basic_registry<uint64_t> registry;

void EnttInit()
{
    TPhysicComponent pc;
    TGraphicComponent gc;
    TTransformComponent tc;

    for (int i = 0; i < OBJECT_COUNT; i++) {
        auto eid = registry.create();
        pc.p.reset(new TBulletObject());
        registry.emplace<TPhysicComponent>(eid, pc);
        registry.emplace<TTransformComponent>(eid, tc);
    }
    for (int i = 0; i < OBJECT_COUNT; i++) {
        auto eid = registry.create();
        pc.p.reset(new TBulletObject());
        registry.emplace<TPhysicComponent>(eid, pc);

        gc.p.reset(new TOgreObject());
        registry.emplace<TGraphicComponent>(eid, gc);

        registry.emplace<TTransformComponent>(eid, tc);
    }
    for (int i = 0; i < OBJECT_COUNT; i++) {
        auto eid = registry.create();
        gc.p.reset(new TOgreObject());
        registry.emplace<TGraphicComponent>(eid, gc);
        registry.emplace<TTransformComponent>(eid, tc);
    }
}

void EnttDone()
{
    registry.clear();
}

void EnttPhysicToCore()
{
    auto gp = registry.view<TGraphicComponent, TPhysicComponent>();
    for (auto& eid : gp) {
        auto& pc = registry.get<TPhysicComponent>(eid);
        auto& tc = registry.get<TTransformComponent>(eid);
        tc.m = pc.p->m;
        registry.replace<TTransformComponent>(eid, tc);
    }
}

void EnttCoreToGraphic()
{
    auto gp = registry.view<TGraphicComponent, TPhysicComponent>();
    for (auto& eid : gp) {
        auto& tc = registry.get<TTransformComponent>(eid);
        auto& gc = registry.get<TGraphicComponent>(eid);
        gc.p->m = tc.m;
        registry.replace<TGraphicComponent>(eid, gc);
    }
}

void EnttBenchmark()
{
    for (int i = 0; i < FRAME_COUNT; i++) {
        EnttPhysicToCore();
        EnttCoreToGraphic();
    }
}
//------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    EcsFrameworkInit();

    auto start = ht_GetMSCount();
    EcsFrameworkBenchmark();
    auto delta = ht_GetMSCount() - start;

    EcsFrameworkDone();

    fmt::print("ecs framework:\n{} s\n", delta / 1000.0f);

    EnttInit();

    start = ht_GetMSCount();
    EnttBenchmark();
    delta = ht_GetMSCount() - start;

    EnttDone();

    fmt::print("entt:\n{} s\n", delta / 1000.0f);
    return 0;
}
