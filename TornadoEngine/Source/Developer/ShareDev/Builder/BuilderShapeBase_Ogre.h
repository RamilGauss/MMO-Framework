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
#include "StructBuilder_Ogre.h"

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

	struct TTriangle
	{
		TTriangle(){}
		TTriangle( int begin )
		{
			_0 = begin+0;
			_1 = begin+1;
			_2 = begin+2;
		}
		int _0;
		int _1;
		int _2;
	};
	struct TQuad
	{
		TQuad(){}
		TQuad(int begin)
		{
			_0 = begin+0;
			_1 = begin+1;
			_2 = begin+2;
			_3 = begin+3;
		}
		int _0;
		int _1;
		int _2;
		int _3;
	};

	Ogre::ManualObject* mPtrMO;
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
	void CreateMaterial();

	void ApplyQuad(TQuad& quad);
	void ApplyTriangle(TTriangle& triangle);
public:
	void CreateTriangle(nsStructBuilder_Ogre::TTriVertex& tVertex);
	void CreateQuad(nsStructBuilder_Ogre::TQuadVertex& qVertex);

	void AddPosition( nsStructBuilder_Ogre::TVertex* p, int cnt);
};

#endif
