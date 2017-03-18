/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderShapePlate_BulletH
#define BuilderShapePlate_BulletH

#include "TypeDef.h"

#include "ParamBuilderShape.h"
#include "MaterialItem.h"
#include "BuilderShapeBase_Bullet.h"

struct TShapeItem;
class btRigidBody;

class DllExport TBuilderShapePlate_Bullet : public TBuilderShapeBase_Bullet
{
public:
	TBuilderShapePlate_Bullet();
	virtual ~TBuilderShapePlate_Bullet();

	// Bullet thread only
	virtual btRigidBody* CreateRigidBody();
protected:
};

#endif
