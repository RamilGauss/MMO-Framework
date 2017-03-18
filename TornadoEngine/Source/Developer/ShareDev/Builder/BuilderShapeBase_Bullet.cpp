/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShapeBase_Bullet.h"
#include "PhysicEngine_Bullet.h"
#include "ModuleLogic.h"
#include "ShapeItem.h"
#include "ModulePhysicEngine.h"

//-------------------------------------------------------------------------------
TBuilderShapeBase_Bullet::TBuilderShapeBase_Bullet()
{
	m_defaultContactProcessingThreshold = BT_LARGE_FLOAT;
	mID_world = -1;
	mShape    = NULL;
	mMaterial = NULL;
}
//-------------------------------------------------------------------------------
TBuilderShapeBase_Bullet::~TBuilderShapeBase_Bullet()
{

}
//-------------------------------------------------------------------------------
void TBuilderShapeBase_Bullet::Setup(int id_world, TShapeItem* pShape, TMaterialItem* pMaterial)
{
	mID_world = id_world;
	mShape    = pShape;
	mMaterial = pMaterial;
}
//-------------------------------------------------------------------------
btRigidBody* TBuilderShapeBase_Bullet::localCreateRigidBody(float mass, 
								const btTransform& startTransform, btCollisionShape* shape)
{
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
	body->setContactProcessingThreshold(m_defaultContactProcessingThreshold);

	btDiscreteDynamicsWorld* pWorld = 
		TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(mID_world);
	pWorld->addRigidBody(body);

	return body;
}
//-------------------------------------------------------------------
