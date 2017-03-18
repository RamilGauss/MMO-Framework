/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShape_Bullet.h"

#include "ShapeItem.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

// классы для создания форм
#include "BuilderShapePlate_Bullet.h"
#include "BuilderShapeCylinder_Bullet.h"

#include <boost/lexical_cast.hpp>

TBuilderShape_Bullet::TBuilderShape_Bullet()
{
	mShape    = NULL;
	mMaterial = NULL;
	mCntShape = 0;

	SetupBuilderMap();
}
//-----------------------------------------------------------------------------
TBuilderShape_Bullet::~TBuilderShape_Bullet()
{

}
//-----------------------------------------------------------------------------
btRigidBody* TBuilderShape_Bullet::Build(int id_world, TShapeItem* pShape)
{
	mShape = pShape;
	FindMaterialByShape();

	TMapTypePtrIt fit = mMapTypeBuilder.find(mShape->mPtrGeometry->type);
	if( fit==mMapTypeBuilder.end() )
		return NULL;
	TBuilderShapeBase_Bullet* pBuilder = (TBuilderShapeBase_Bullet*)fit->second;
	if( pBuilder==NULL )
		return NULL;

	pBuilder->Setup(id_world, mShape, mMaterial);
	return pBuilder->CreateRigidBody();
}
//-----------------------------------------------------------------------------
void TBuilderShape_Bullet::FindMaterialByShape()
{
	mMaterial = (TMaterialItem*)TModuleLogic::Get()->GetFGI()->
		Get( TFactoryGameItem::Material, mShape->mNameMaterial );
}
//-----------------------------------------------------------------------------
void TBuilderShape_Bullet::SetupBuilderMap()
{
	using namespace nsParamBuilderShape;
	mMapTypeBuilder.insert(TMapTypePtrVT(Plate,               new TBuilderShapePlate_Bullet));
	mMapTypeBuilder.insert(TMapTypePtrVT(PlateVarGeom, 		    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Sphere, 					    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Cone,   					    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Trapezium,    		    NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPyramid,   NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(QuadrangularPyramid, NULL));
	mMapTypeBuilder.insert(TMapTypePtrVT(Cylinder,        		new TBuilderShapeCylinder_Bullet));
	mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPrism, 		NULL));
}
//-----------------------------------------------------------------------------
