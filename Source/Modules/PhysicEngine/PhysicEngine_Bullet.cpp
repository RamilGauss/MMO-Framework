/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PhysicEngine_Bullet.h"
#include "Base/Common/HiTimer.h"

struct TWorld
{
    btDiscreteDynamicsWorld* pWorld = nullptr;
    btBroadphaseInterface* pBroadphase = nullptr;
    btCollisionDispatcher* pDispatcher = nullptr;
    btSequentialImpulseConstraintSolver* pSolver = nullptr;
    btDefaultCollisionConfiguration* pCollisionConfiguration = nullptr;

    TPhysicEngine_Bullet::eStateWorld state = TPhysicEngine_Bullet::eStateWorld::PAUSE;
    TPhysicEngine_Bullet::eStateWorld prevState = TPhysicEngine_Bullet::eStateWorld::PAUSE;

    float ratioRealTimeToControl = 1.0f;//  ratio > 1 - ускорение времени, ratio < 1 - замедление

    unsigned int prevTimeWork = 0;

    ~TWorld();
};
//----------------------------------------------------------------------------------------------
TWorld::~TWorld()
{
    delete pWorld;
    delete pBroadphase;
    delete pDispatcher;
    delete pSolver;
    delete pCollisionConfiguration;
}
//----------------------------------------------------------------------------------------------
TPhysicEngine_Bullet::TPhysicEngine_Bullet()
{
    mLastID = 0;
}
//----------------------------------------------------------------------------------------------
TPhysicEngine_Bullet::~TPhysicEngine_Bullet()
{
    for (auto& ID_World : mMapIDWorld) {
        delete ID_World.second;
    }
    mMapIDWorld.clear();
}
//----------------------------------------------------------------------------------------------
int TPhysicEngine_Bullet::AddWorld()
{
    mLastID++;
    auto pWorld = new TWorld();

    pWorld->pBroadphase = new btDbvtBroadphase;
    pWorld->pCollisionConfiguration = new btDefaultCollisionConfiguration;
    pWorld->pDispatcher = new btCollisionDispatcher(pWorld->pCollisionConfiguration);
    pWorld->pSolver = new btSequentialImpulseConstraintSolver;
    pWorld->pWorld = new btDiscreteDynamicsWorld(pWorld->pDispatcher, pWorld->pBroadphase,
        pWorld->pSolver, pWorld->pCollisionConfiguration);

    mMapIDWorld.insert({ mLastID, pWorld });
    return mLastID;
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::DeleteWorld(int worldId)
{
    auto pWorld = GetByID(worldId);
    delete pWorld;
    mMapIDWorld.erase(worldId);
}
//----------------------------------------------------------------------------------------------
btDiscreteDynamicsWorld* TPhysicEngine_Bullet::GetWorld(int worldId)
{
    auto pWorld = GetByID(worldId);
    if (pWorld) {
        return pWorld->pWorld;
    }

    return nullptr;
}
//----------------------------------------------------------------------------------------------
btBroadphaseInterface* TPhysicEngine_Bullet::GetBroadphase(int worldId)
{
    auto pWorld = GetByID(worldId);
    if (pWorld) {
        return pWorld->pBroadphase;
    }

    return nullptr;
}
//----------------------------------------------------------------------------------------------
btCollisionDispatcher* TPhysicEngine_Bullet::GetDispatcher(int id_world)
{
    auto pWorld = GetByID(id_world);
    if (pWorld) {
        return pWorld->pDispatcher;
    }

    return nullptr;
}
//----------------------------------------------------------------------------------------------
btSequentialImpulseConstraintSolver* TPhysicEngine_Bullet::GetSolver(int worldId)
{
    auto pWorld = GetByID(worldId);
    if (pWorld) {
        return pWorld->pSolver;
    }

    return nullptr;
}
//----------------------------------------------------------------------------------------------
btDefaultCollisionConfiguration* TPhysicEngine_Bullet::GetCollisionConfiguration(int worldId)
{
    auto pWorld = GetByID(worldId);
    if (pWorld) {
        return pWorld->pCollisionConfiguration;
    }

    return nullptr;
}
//----------------------------------------------------------------------------------------------
TWorld* TPhysicEngine_Bullet::GetByID(int worldId)
{
    auto fit = mMapIDWorld.find(worldId);
    if (fit == mMapIDWorld.end()) {
        return nullptr;
    }

    return fit->second;
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::Work()
{
    // делать замеры времени самостоятельно
    for (auto& ID_World : mMapIDWorld) {
        auto pWorld = ID_World.second;
        if (pWorld->state == eStateWorld::REAL_TIME || pWorld->state == eStateWorld::CONTROL_TIME) {
            unsigned int nowMs = ht_GetMSCount();
            unsigned int dt = nowMs - pWorld->prevTimeWork;

            float dtSec = dt / 1000.0f;

            if (pWorld->state == eStateWorld::CONTROL_TIME) {
                dtSec /= pWorld->ratioRealTimeToControl;
            }

            int maxSubSteps = 1000;
            float fixedTimeStep = 1 / 400.0f;//dt_sec/1;
            pWorld->pWorld->stepSimulation(dtSec, maxSubSteps, fixedTimeStep);

            pWorld->prevTimeWork = nowMs;
        }
    }
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::Setup(int worldId, eStateWorld state,
    float ratioRealTimeToControl)
{
    auto pWorld = GetByID(worldId);
    if (pWorld == nullptr) {
        return;
    }

    pWorld->prevState = pWorld->state;
    pWorld->state = state;
    pWorld->ratioRealTimeToControl = ratioRealTimeToControl;

    if (pWorld->prevState == eStateWorld::PAUSE) {
        if (pWorld->state == eStateWorld::REAL_TIME || pWorld->state == eStateWorld::CONTROL_TIME) {
            pWorld->prevTimeWork = ht_GetMSCount();
        }
    }
}
//----------------------------------------------------------------------------------------------
