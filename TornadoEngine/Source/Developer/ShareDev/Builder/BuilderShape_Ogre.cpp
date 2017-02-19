/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShape_Ogre.h"

#include "ShapeItem.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

// классы для создания форм
#include "BuilderShapePlate_Ogre.h"
#include "BuilderShapeCylinder_Ogre.h"

TBuilderShape_Ogre::TBuilderShape_Ogre()
{
  mShape    = NULL;
	mMaterial = NULL;
	mCntShape = 0;

	SetupBuilderMap();
}
//-----------------------------------------------------------------------------
TBuilderShape_Ogre::~TBuilderShape_Ogre()
{

}
//-----------------------------------------------------------------------------
Ogre::Entity* TBuilderShape_Ogre::Build(TShapeItem* pShape)
{
	mPtrEntity = NULL;
  mShape = pShape;
	FindMaterialByShape();

	TMapTypePtrIt fit = mMapTypeBuilder.find(mShape->mPtrGeometry->type);
	if( fit==mMapTypeBuilder.end() )
		return NULL;
	TBuilderShapeBase_Ogre* pBuilder = (TBuilderShapeBase_Ogre*)fit->second;
	if( pBuilder==NULL )
		return NULL;

	char s[400];
	sprintf(s, "_%d", mCntShape);
	mNameEntity = pBuilder->GetNameType() + s;
	mCntShape++;

	pBuilder->Setup(mShape, mMaterial);
	mPtrEntity = pBuilder->CreateEntity(mNameEntity);

  return mPtrEntity;
}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::FindMaterialByShape()
{
	mMaterial = (TMaterialItem*)TModuleLogic::Get()->GetFGI()->
		Get( TFactoryGameItem::Material, mShape->mNameMaterial );
}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::SetupBuilderMap()
{
	using namespace nsParamBuilderShape;
	mMapTypeBuilder.insert(TMapTypePtrVT(Plate,               new TBuilderShapePlate_Ogre));
	mMapTypeBuilder.insert(TMapTypePtrVT(PlateVarGeom, 		    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Sphere, 					    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Cone,   					    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Trapezium,    		    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPyramid,   NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(QuadrangularPyramid, NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Cylinder,        		new TBuilderShapeCylinder_Ogre));
	mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPrism, 		NULL));
}
//-----------------------------------------------------------------------------
