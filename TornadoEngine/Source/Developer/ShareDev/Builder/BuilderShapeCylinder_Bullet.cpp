/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShapeCylinder_Bullet.h"

#include <btBulletDynamicsCommon.h>
#include "ParamBuilderShape.h"
#include "ShapeItem.h"

TBuilderShapeCylinder_Bullet::TBuilderShapeCylinder_Bullet()
{

}
//------------------------------------------------------------------------
btRigidBody* TBuilderShapeCylinder_Bullet::CreateRigidBody()
{
	nsParamBuilderShape::TCylinder* pCylinder = (nsParamBuilderShape::TCylinder*)mShape->mPtrGeometry.get();

  //btCylinderShape* shape = new btCylinderShape(btVector3(radius,height*0.5,radius));
	btVector3 geom(pCylinder->radius_max, pCylinder->length*0.5, pCylinder->radius_max);
	btCollisionShape* shape = new btCylinderShape(geom);

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
	body->setFriction(0.5);// from material

	body->setCcdMotionThreshold(1);
	body->setCcdSweptSphereRadius(0.9f);
	return body;
}
//------------------------------------------------------------------------
