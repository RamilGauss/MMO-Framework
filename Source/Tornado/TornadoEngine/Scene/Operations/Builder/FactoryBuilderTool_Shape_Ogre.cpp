/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FactoryBuilderTool_Shape_Ogre.h"

#include "ShapeItem.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

// классы для создания форм
#include "BuilderTool_ShapePlate_Ogre.h"
#include "BuilderTool_ShapeCylinder_Ogre.h"

#include <boost/lexical_cast.hpp>

class TFactoryBuilderTool_Shape_Ogre_Private : public TFactoryBuilderTool_Shape_Ogre
{
public:
  TFactoryBuilderTool_Shape_Ogre_Private(){}
  virtual ~TFactoryBuilderTool_Shape_Ogre_Private(){}
};
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Ogre_Private g_FactoryBuilderTool_Shape_Ogre_Private;
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Ogre* TFactoryBuilderTool_Shape_Ogre::Get()
{
  return &g_FactoryBuilderTool_Shape_Ogre_Private;
}
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Ogre::TFactoryBuilderTool_Shape_Ogre()
{
  mShape    = NULL;
  mMaterial = NULL;
  mCntShape = 0;

  SetupBuilderMap();
}
//-----------------------------------------------------------------------------
TFactoryBuilderTool_Shape_Ogre::~TFactoryBuilderTool_Shape_Ogre()
{

}
//-----------------------------------------------------------------------------
Ogre::Entity* TFactoryBuilderTool_Shape_Ogre::Build(TShapeItem* pShape)
{
  mPtrEntity = NULL;
  mShape = pShape;
  FindMaterialByShape();

  TMapTypePtrIt fit = mMapTypeBuilder.find(mShape->mPtrGeometry->type);
  if( fit==mMapTypeBuilder.end() )
    return NULL;
  TBuilderTool_ShapeBase_Ogre* pBuilder = fit->second;
  if( pBuilder==NULL )
    return NULL;

  mNameEntity  = pBuilder->GetNameType();
  mNameEntity += "_";
  mNameEntity += boost::lexical_cast<std::string>(mCntShape);
  mCntShape++;

  pBuilder->Setup(mShape, mMaterial);
  mPtrEntity = pBuilder->CreateEntity(mNameEntity);

  return mPtrEntity;
}
//-----------------------------------------------------------------------------
void TFactoryBuilderTool_Shape_Ogre::FindMaterialByShape()
{
  mMaterial = (TMaterialItem*)TModuleLogic::Get()->GetFGI()->
    Get( TFactoryGameItem::Material, mShape->mNameMaterial );
}
//-----------------------------------------------------------------------------
void TFactoryBuilderTool_Shape_Ogre::SetupBuilderMap()
{
  using namespace nsParamBuilderShape;
  mMapTypeBuilder.insert(TMapTypePtrVT(Plate,               new TBuilderTool_ShapePlate_Ogre));
  mMapTypeBuilder.insert(TMapTypePtrVT(PlateVarGeom,         NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Sphere,               NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Cone,                 NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Trapezium,            NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPyramid,   NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(QuadrangularPyramid, NULL));
  mMapTypeBuilder.insert(TMapTypePtrVT(Cylinder,            new TBuilderTool_ShapeCylinder_Ogre));
  mMapTypeBuilder.insert(TMapTypePtrVT(TriangularPrism,     NULL));
}
//-----------------------------------------------------------------------------
