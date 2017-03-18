/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShapePlate_Bullet.h"

#include <btBulletDynamicsCommon.h>

#include "ParamBuilderShape.h"
#include "ShapeItem.h"

TBuilderShapePlate_Bullet::TBuilderShapePlate_Bullet()
{

}
//-------------------------------------------------------------------
TBuilderShapePlate_Bullet::~TBuilderShapePlate_Bullet()
{

}
//-------------------------------------------------------------------
btRigidBody* TBuilderShapePlate_Bullet::CreateRigidBody()
{
	nsParamBuilderShape::TPlate* pPlate = (nsParamBuilderShape::TPlate*)mShape->mPtrGeometry.get();

	btVector3 geom(pPlate->length,pPlate->height,pPlate->width);

	btCollisionShape* shape = new btBoxShape(geom);

	// Create Dynamic Objects
	btTransform startTransform;
	startTransform.setIdentity();

	btScalar mass(100.f);// calculate!

	btVector3 localInertia(0,0,0);
	shape->calculateLocalInertia(mass, localInertia);

	btTransform trans;
	trans.setIdentity();

	btVector3 pos(0,0,0);
	trans.setOrigin(pos);
	//trans.setRotation(

	btRigidBody* body = localCreateRigidBody(mass,trans,shape);
	body->setAnisotropicFriction(shape->getAnisotropicRollingFrictionDirection(),
		btCollisionObject::CF_ANISOTROPIC_ROLLING_FRICTION);
	//body->setFriction(0.5f);// from material

	//body->setCcdMotionThreshold(1);
	//body->setCcdSweptSphereRadius(0.9f);
	return body;
}
//-------------------------------------------------------------------
