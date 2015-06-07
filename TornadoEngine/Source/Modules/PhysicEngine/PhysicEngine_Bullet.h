/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PhysicEngine_BulletH
#define PhysicEngine_BulletH

#include "TypeDef.h"

#include <btBulletDynamicsCommon.h>
#include <map>

#define STR_NAME_PHYSIC_ENGINE "PE"

class DllExport TPhysicEngine_Bullet
{
  struct TWorld
  {
    btDiscreteDynamicsWorld*             pWorld;
    btBroadphaseInterface*               pBroadphase;
    btCollisionDispatcher*               pDispatcher;
    btSequentialImpulseConstraintSolver* pSolver;
    btDefaultCollisionConfiguration*     pCollisionConfiguration;

    TWorld()
    {
      pWorld = NULL;
      pBroadphase = NULL;
      pDispatcher = NULL;
      pSolver = NULL;
      pCollisionConfiguration = NULL;
    }
    void Done()
    {
      delete pWorld;
      delete pBroadphase;
      delete pDispatcher;
      delete pSolver;
      delete pCollisionConfiguration;
    }
  };

  typedef std::map<int,TWorld> TMapIntWorld;
  typedef TMapIntWorld::iterator   TMapIntWorldIt;
  typedef TMapIntWorld::value_type TMapIntWorldVT;
  
  TMapIntWorld mMapIDWorld;

  int mLastID;
  
  unsigned int mPrevTimeWork;

public:
  TPhysicEngine_Bullet();
  virtual ~TPhysicEngine_Bullet();

  void Work(bool first_start = false);// реальное время
  void Work(btScalar timeStep, int maxSubSteps = 1, btScalar fixedTimeStep = btScalar(1.)/btScalar(60.));

  int AddWorld();
  void DeleteWorld(int id_world);

  btDiscreteDynamicsWorld* GetWorld(int id_world);
  btBroadphaseInterface* GetBroadphase(int id_world);
  btCollisionDispatcher* GetDispatcher(int id_world);
  btSequentialImpulseConstraintSolver* GetSolver(int id_world);
  btDefaultCollisionConfiguration* GetCollisionConfiguration(int id_world);

private:

  bool GetByID(int id_world, TPhysicEngine_Bullet::TWorld& world);
};

#endif
