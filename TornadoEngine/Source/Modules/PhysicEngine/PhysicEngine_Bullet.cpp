/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PhysicEngine_Bullet.h"
#include <boost/foreach.hpp>
#include "HiTimer.h"


TPhysicEngine_Bullet::TPhysicEngine_Bullet()
{
  mLastID = 0;
}
//----------------------------------------------------------------------------------------------
TPhysicEngine_Bullet::~TPhysicEngine_Bullet()
{
  BOOST_FOREACH(TMapIntPtrWorldVT& ID_World, mMapIDWorld)
    delete ID_World.second;
  mMapIDWorld.clear();
}
//----------------------------------------------------------------------------------------------
int TPhysicEngine_Bullet::AddWorld()
{
  mLastID++;
  TWorld* pWorld = new TWorld;

  pWorld->pBroadphase = new btDbvtBroadphase;
  pWorld->pCollisionConfiguration = new btDefaultCollisionConfiguration;
  pWorld->pDispatcher = new btCollisionDispatcher(pWorld->pCollisionConfiguration);
  pWorld->pSolver = new btSequentialImpulseConstraintSolver;
  pWorld->pWorld = new btDiscreteDynamicsWorld(pWorld->pDispatcher, pWorld->pBroadphase, 
    pWorld->pSolver, pWorld->pCollisionConfiguration);

  mMapIDWorld.insert(TMapIntPtrWorldVT(mLastID, pWorld));
  return mLastID;
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::DeleteWorld(int id_world)
{
  TWorld* pWorld = GetByID(id_world);
  delete pWorld;
  mMapIDWorld.erase(id_world);
}
//----------------------------------------------------------------------------------------------
btDiscreteDynamicsWorld* TPhysicEngine_Bullet::GetWorld(int id_world)
{
  TWorld* pWorld = GetByID(id_world);
  if(pWorld)
    return pWorld->pWorld;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btBroadphaseInterface* TPhysicEngine_Bullet::GetBroadphase(int id_world)
{
  TWorld* pWorld = GetByID(id_world);
  if(pWorld)
    return pWorld->pBroadphase;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btCollisionDispatcher* TPhysicEngine_Bullet::GetDispatcher(int id_world)
{
  TWorld* pWorld = GetByID(id_world);
  if(pWorld)
    return pWorld->pDispatcher;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btSequentialImpulseConstraintSolver* TPhysicEngine_Bullet::GetSolver(int id_world)
{
  TWorld* pWorld = GetByID(id_world);
  if(pWorld)
    return pWorld->pSolver;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btDefaultCollisionConfiguration* TPhysicEngine_Bullet::GetCollisionConfiguration(int id_world)
{
  TWorld* pWorld = GetByID(id_world);
  if(pWorld)
    return pWorld->pCollisionConfiguration;

  return NULL;
}
//----------------------------------------------------------------------------------------------
TPhysicEngine_Bullet::TWorld* TPhysicEngine_Bullet::GetByID(int id_world)
{
  TMapIntPtrWorldIt fit = mMapIDWorld.find(id_world);
  if(fit==mMapIDWorld.end())
    return NULL;

  return fit->second;
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::Work()
{
  // делать замеры времени самостоятельно
  BOOST_FOREACH(TMapIntPtrWorldVT& ID_World, mMapIDWorld)
  {
    TWorld* pWorld = ID_World.second;
    if( pWorld->state==eStateRealTime || pWorld->state==eStateControlTime )
    {
      unsigned int now_ms = ht_GetMSCount();
      unsigned int dt = now_ms - pWorld->prevTimeWork;

      float dt_sec = dt/1000.0f;
      
      if( pWorld->state==eStateControlTime )
        dt_sec /= pWorld->ratioRealTimeToControl;

      pWorld->pWorld->stepSimulation(dt_sec, 1, dt_sec);
      
      pWorld->prevTimeWork = now_ms;
    }
  }
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::Setup(int id_world, eStateWorld state, 
                                 float ratioRealTimeToControl)
{
  TWorld* pWorld = GetByID(id_world);
  if(pWorld==NULL)
    return;

  pWorld->prevState              = pWorld->state;
	pWorld->state                  = state;
	pWorld->ratioRealTimeToControl = ratioRealTimeToControl;

	if( pWorld->prevState==eStatePause  )
	if( pWorld->state==eStateRealTime || pWorld->state==eStateControlTime )
		pWorld->prevTimeWork = ht_GetMSCount();
}
//----------------------------------------------------------------------------------------------
