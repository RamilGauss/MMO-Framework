/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderShapeBase_OgreH
#define BuilderShapeBase_OgreH

#include "TypeDef.h"
#include <Ogre.h>

#include "ParamBuilderShape.h"
#include "MaterialItem.h"

struct TShapeItem;

class DllExport TBuilderShapeBase_Ogre
{
protected:
	TShapeItem*    mPtrShape;
	TMaterialItem* mPtrMaterial;

	TMaterialItem::TVariant* mPtrMaterialVariant;
	Ogre::SceneManager*      mPtrSceneMng;
	Ogre::Entity*            mPtrEntity;

	Ogre::MeshPtr     mMeshPtr;
	Ogre::MaterialPtr mMaterialPtr;

	Ogre::String mNameMesh;
	Ogre::String mNameEntity;
public:
	TBuilderShapeBase_Ogre();
	virtual ~TBuilderShapeBase_Ogre();

	// Ogre thread only
	virtual void Setup(TShapeItem* pShape, TMaterialItem* pMaterial);
	// Ogre thread only
	virtual Ogre::Entity* CreateEntity(std::string& nameEntity) = 0;
	virtual std::string GetNameType() = 0;
protected:
	virtual void SetNameMesh() = 0;
	virtual void SetParamShape( nsParamBuilderShape::TBaseParam* pShape) = 0;
protected:
	void SetRandomVariant();
};

#endif
