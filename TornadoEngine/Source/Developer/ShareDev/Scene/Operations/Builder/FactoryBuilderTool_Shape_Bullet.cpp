/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FactoryBuilderTool_Shape_Bullet.h"

#include "ShapeItem.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

// классы для создания форм
#include "BuilderTool_ShapePlate_Bullet.h"
#include "BuilderTool_ShapeCylinder_Bullet.h"

#include <boost/lexical_cast.hpp>

class TFactoryBuilderTool_Shape_Bullet_Private : 
  public TFactoryBuilderTool_Shape_Bullet
{
public:
  TFactoryBuilderTool_Shape_Bullet_Private(){}
  virtual ~TFactoryBuilderTool_Shape_Bullet_Private(){}
};
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Bullet_Private g_FactoryBuilderTool_Shape_Bullet_Private;
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Bullet* TFactoryBuilderTool_Shape_Bullet::Get()
{
  return &g_FactoryBuilderTool_Shape_Bullet_Private;
}
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Bullet::TFactoryBuilderTool_Shape_Bullet()
{
  mShape    = NULL;
  mMaterial = NULL;

  SetupBuilderMap();
}
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Bullet::~TFactoryBuilderTool_Shape_Bullet()
{

}
//-----------------------------------------------------------------------------
btRigidBody* TFactoryBuilderTool_Shape_Bullet::Build(int id_world, TShapeItem* pShape)
{
  mShape = pShape;
  FindMaterialByShape();

  TMapTypePtrIt fit = mMapTypeBuilder.find(mShape->mPtrGeometry->type);
  if( fit==mMapTypeBuilder.end() )
    return NULL;
  TBuilderTool_ShapeBase_Bullet* pBuilder = fit->second;
  if( pBuilder==NULL )
    return NULL;

  pBuilder->SetID_PhysicWorld(id_world);
  pBuilder->SetShape(mShape);
  pBuilder->SetMaterial(mMaterial);
  return pBuilder->CreateRigidBody();
}
//-----------------------------------------------------------------------------
void TFactoryBuilderTool_Shape_Bullet::FindMaterialByShape()
{
  mMaterial = (TMaterialItem*)TModuleLogic::Get()->GetFGI()->
    Get( TFactoryGameItem::Material, mShape->mNameMaterial );
}
//-----------------------------------------------------------------------------
void TFactoryBuilderTool_Shape_Bullet::SetupBuilderMap()
{
  using namespace nsParamBuilderShape;
  mMapTypeBuilder.insert(TMapTypePtrVT(Plate,               new TBuilderTool_ShapePlate_Bullet));
  mMapTypeBuilder.insert(TMapTypePtrVT(PlateVarGeom,         NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Sphere,               NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Cone,                 NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Trapezium,            NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPyramid,   NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(QuadrangularPyramid, NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Cylinder,            new TBuilderTool_ShapeCylinder_Bullet));
  mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPrism,     NULL));
}
//-----------------------------------------------------------------------------
