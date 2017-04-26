/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderTool_ShapePlate_Bullet.h"

#include <btBulletDynamicsCommon.h>

#include "ParamBuilderShape.h"
#include "ShapeItem.h"

TBuilderTool_ShapePlate_Bullet::TBuilderTool_ShapePlate_Bullet()
{

}
//-------------------------------------------------------------------
TBuilderTool_ShapePlate_Bullet::~TBuilderTool_ShapePlate_Bullet()
{

}
//-------------------------------------------------------------------
btRigidBody* TBuilderTool_ShapePlate_Bullet::CreateRigidBody()
{
	nsParamBuilderShape::TPlate* pPlate = (nsParamBuilderShape::TPlate*)mShape->mPtrGeometry.get();
	btVector3 geom(pPlate->width/2,pPlate->height/2,pPlate->length/2);
	btCollisionShape* shape = new btBoxShape(geom);

	// Create Dynamic Objects
	btTransform startTransform;
	startTransform.setIdentity();

	float volume = pPlate->height*pPlate->length*pPlate->width;
	
	btScalar mass;//(100.f);// calculate!
	mass = volume*7810;

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
	body->setFriction(0.5f);// from material

	body->setCcdMotionThreshold(40.0f);

	float h_l_sqr = pPlate->height*pPlate->height/4 + pPlate->length*pPlate->length/4;
	float maxSize = sqrt(h_l_sqr + pPlate->width*pPlate->width/4);
	maxSize *= 1.1f;

	body->setCcdSweptSphereRadius(maxSize);
	return body;
}
//-------------------------------------------------------------------
