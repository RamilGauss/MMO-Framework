/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderTool_Bullet.h"

#include "ModulePhysicEngine.h"
#include "ModuleLogic.h"

TBuilderTool_Bullet::TBuilderTool_Bullet()
{
	mDefaultContactProcessingThreshold = BT_LARGE_FLOAT;
	mID_PhysicWorld = -1;
}
//---------------------------------------------------------------------------------
TBuilderTool_Bullet::~TBuilderTool_Bullet()
{

}
//---------------------------------------------------------------------------------
void TBuilderTool_Bullet::SetID_PhysicWorld( int id )
{
  mID_PhysicWorld = id;
}
//---------------------------------------------------------------------------------
int TBuilderTool_Bullet::GetID_PhysicWorld()
{
  return mID_PhysicWorld;
}
//---------------------------------------------------------------------------------
btRigidBody* TBuilderTool_Bullet::localCreateRigidBody(float mass, 
					const btTransform& startTransform, btCollisionShape* shape)
{
	btDiscreteDynamicsWorld* pWorld = 
		TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(mID_PhysicWorld);
	if( pWorld==NULL )
		return NULL;

	// rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0,0,0);
	if( isDynamic )
		shape->calculateLocalInertia(mass,localInertia);

	// using motionstate is recommended, it provides interpolation capabilities, 
	// and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo cInfo(mass,myMotionState,shape,localInertia);

	btRigidBody* body = new btRigidBody(cInfo);
	body->setContactProcessingThreshold(mDefaultContactProcessingThreshold);
	pWorld->addRigidBody(body);
	return body;
}
//-------------------------------------------------------------------

