/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderShapeBase_BulletH
#define BuilderShapeBase_BulletH

#include "TypeDef.h"

#include "ParamBuilderShape.h"
#include "MaterialItem.h"

#include <CollisionDispatch/btCollisionObjectWrapper.h>

struct TShapeItem;
class btRigidBody;
class btCollisionShape;

class DllExport TBuilderShapeBase_Bullet
{
  btScalar m_defaultContactProcessingThreshold;

	int mID_world;
protected:
	TShapeItem* mShape;
	TMaterialItem* mMaterial;
public:
	TBuilderShapeBase_Bullet();
	virtual ~TBuilderShapeBase_Bullet();

	virtual void Setup(int id_world, TShapeItem* pShape, TMaterialItem* pMaterial);
	virtual btRigidBody* CreateRigidBody() = 0;
protected:
	btRigidBody* localCreateRigidBody(float mass, 
		const btTransform& startTransform, btCollisionShape* shape);
};

#endif
