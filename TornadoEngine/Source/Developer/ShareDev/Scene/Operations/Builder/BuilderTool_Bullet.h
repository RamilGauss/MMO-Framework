/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTool_BulletH
#define BuilderTool_BulletH

#include "TypeDef.h"
#include "ParamBuilderShape.h"
#include "MaterialItem.h"

#include <CollisionDispatch/btCollisionObjectWrapper.h>

class btRigidBody;
class btCollisionShape;

class DllExport TBuilderTool_Bullet 
{
protected:
  int      mID_PhysicWorld;
	btScalar mDefaultContactProcessingThreshold;
public:
  TBuilderTool_Bullet();
  virtual ~TBuilderTool_Bullet();

  void SetID_PhysicWorld(int id);
  int GetID_PhysicWorld();

public:
	btRigidBody* localCreateRigidBody(float mass, 
		const btTransform& startTransform, btCollisionShape* shape);
};

#endif

