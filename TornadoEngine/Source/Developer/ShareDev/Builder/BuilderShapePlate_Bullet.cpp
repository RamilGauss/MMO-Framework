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

	btVector3 geom(pPlate->width/2,pPlate->height/2,pPlate->length/2);

	btCollisionShape* shape = new btBoxShape(geom);

	// Create Dynamic Objects
	btTransform startTransform;
	startTransform.setIdentity();

	float volume = pPlate->height*pPlate->length*pPlate->width;
	
	btScalar mass;//(100.f);// calculate!
	mass = volume*10000;//7810;

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

	body->setCcdMotionThreshold(300);//100

	float maxSize = std::max( pPlate->height, pPlate->length );
	maxSize = std::max(maxSize, pPlate->width);
	body->setCcdSweptSphereRadius(maxSize);
	return body;
}
//-------------------------------------------------------------------
