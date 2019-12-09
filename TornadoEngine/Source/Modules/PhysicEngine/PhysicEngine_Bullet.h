/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef PhysicEngine_BulletH
#define PhysicEngine_BulletH

#include "TypeDef.h"

#include <btBulletDynamicsCommon.h>
#include <map>

#define STR_NAME_PHYSIC_ENGINE "PE"

class DllExport TPhysicEngine_Bullet
{
public:
  typedef enum
  {
    eStatePause, 
    eStateRealTime, 
    eStateControlTime,
  } eStateWorld;
private:
  struct TWorld
  {
    btDiscreteDynamicsWorld*             pWorld;
    btBroadphaseInterface*               pBroadphase;
    btCollisionDispatcher*               pDispatcher;
    btSequentialImpulseConstraintSolver* pSolver;
    btDefaultCollisionConfiguration*     pCollisionConfiguration;

    eStateWorld state;
    eStateWorld prevState;
    
    float ratioRealTimeToControl;//  ratio > 1 - ускорение времени, ratio < 1 - замедление

    unsigned int prevTimeWork;
    
    TWorld()
    {
      pWorld = NULL;
      pBroadphase = NULL;
      pDispatcher = NULL;
      pSolver = NULL;
      pCollisionConfiguration = NULL;
      state     = eStatePause;
      prevState = eStatePause;
      prevTimeWork = 0;
      ratioRealTimeToControl = 1.0f;
    }
    ~TWorld()
    {
      delete pWorld;
      delete pBroadphase;
      delete pDispatcher;
      delete pSolver;
      delete pCollisionConfiguration;
    }
  };

  typedef std::map<int,TWorld*> TMapIntPtrWorld;
  typedef TMapIntPtrWorld::iterator   TMapIntPtrWorldIt;
  typedef TMapIntPtrWorld::value_type TMapIntPtrWorldVT;
  
  TMapIntPtrWorld mMapIDWorld;

  int mLastID;
  
public:
  TPhysicEngine_Bullet();
  virtual ~TPhysicEngine_Bullet();

  void Work();
  void Setup(int id_world, eStateWorld state = eStateRealTime, 
             float ratioRealTimeToControl = 1.0f);

  int AddWorld();
  void DeleteWorld(int id_world);

  btDiscreteDynamicsWorld* GetWorld(int id_world);
  btBroadphaseInterface* GetBroadphase(int id_world);
  btCollisionDispatcher* GetDispatcher(int id_world);
  btSequentialImpulseConstraintSolver* GetSolver(int id_world);
  btDefaultCollisionConfiguration* GetCollisionConfiguration(int id_world);

private:

  TPhysicEngine_Bullet::TWorld* GetByID(int id_world);
};

#endif
