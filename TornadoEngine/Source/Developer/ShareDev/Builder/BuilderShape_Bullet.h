/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#ifndef BuilderShape_BulletH
#define BuilderShape_BulletH

#include "TypeDef.h"

#include <map>
#include "ParamBuilderShape.h"

struct TShapeItem;
struct TMaterialItem;
class TBuilderShapeBase_Bullet;
class btRigidBody;

class DllExport TBuilderShape_Bullet
{
	TShapeItem*    mShape;
	TMaterialItem* mMaterial;

	std::string mNameEntity;

	int mCntShape;

	typedef std::map<nsParamBuilderShape::eType,TBuilderShapeBase_Bullet*> TMapTypePtr;
	typedef TMapTypePtr::iterator   					 TMapTypePtrIt;
	typedef TMapTypePtr::value_type 					 TMapTypePtrVT;

	TMapTypePtr mMapTypeBuilder;
public:
	TBuilderShape_Bullet();
	~TBuilderShape_Bullet();

	btRigidBody* Build(int id_world, TShapeItem* pShape);
protected:
	void FindMaterialByShape();
	void SetupBuilderMap();
};

#endif
