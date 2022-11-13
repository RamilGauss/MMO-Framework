/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <btBulletDynamicsCommon.h>
#include <map>

#define STR_NAME_PHYSIC_ENGINE "PE"

struct TWorld;

class DllExport TPhysicEngine_Bullet
{
public:
    enum class eStateWorld
    {
        PAUSE,
        REAL_TIME,
        CONTROL_TIME,
    };
public:
    TPhysicEngine_Bullet();
    virtual ~TPhysicEngine_Bullet();

    void Work();
    void Setup(int worldId, eStateWorld state = eStateWorld::REAL_TIME,
        float ratioRealTimeToControl = 1.0f);

    int AddWorld();
    void DeleteWorld(int worldId);

    btDiscreteDynamicsWorld* GetWorld(int worldId);
    btBroadphaseInterface* GetBroadphase(int worldId);
    btCollisionDispatcher* GetDispatcher(int worldId);
    btSequentialImpulseConstraintSolver* GetSolver(int worldId);
    btDefaultCollisionConfiguration* GetCollisionConfiguration(int worldId);

private:
    using TMapIntPtrWorld = std::map<int, TWorld*>;
    TMapIntPtrWorld mMapIDWorld;

    int mLastID;

    TWorld* GetByID(int worldId);
};
