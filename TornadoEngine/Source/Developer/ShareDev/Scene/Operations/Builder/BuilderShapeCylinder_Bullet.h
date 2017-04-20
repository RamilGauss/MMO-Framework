/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderShapeCylinder_BulletH
#define BuilderShapeCylinder_BulletH

#include "TypeDef.h"
#include "BuilderShapeBase_Bullet.h"

struct TShapeItem;

class DllExport TBuilderShapeCylinder_Bullet : public TBuilderShapeBase_Bullet
{
public:
	TBuilderShapeCylinder_Bullet();

	virtual btRigidBody* CreateRigidBody();
protected:

};

#endif
