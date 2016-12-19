/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShape_Ogre.h"

#include <Ogre.h>
#include <OgreManualObject.h>

#include "ShapeItem.h"
#include "GeomUtils.h"
//#include "ModuleLogic.h"
//#include "Components.h"

TBuilderShape_Ogre::TBuilderShape_Ogre()
{
  mShape = NULL;
}
//-----------------------------------------------------------------------------
TBuilderShape_Ogre::~TBuilderShape_Ogre()
{

}
//-----------------------------------------------------------------------------
Ogre::MeshPtr TBuilderShape_Ogre::Build(TShapeItem* pShape)
{
  mMeshPtr.setNull();
  mShape = pShape;
  // выбрать из списка шаблон
  switch(mShape->mPtrGeometry->type)
  {
    case nsParamBuilderShape::Plate:
      BuildPlate();
      break;
    case nsParamBuilderShape::PlateVarGeom:
      BuildPlateVarGeom();
      break;
    case nsParamBuilderShape::Sphere:
      BuildSphere();
      break;
    case nsParamBuilderShape::Cone:
      BuildCone();
      break;
    case nsParamBuilderShape::Trapezium:
      BuildTrapezium();
      break;
    case nsParamBuilderShape::TriangularPyramid:
      BuildTriangularPyramid();
      break;
    case nsParamBuilderShape::QuadrangularPyramid:
      BuildQuadrangularPyramid();
      break;
    case nsParamBuilderShape::Cylinder:
      BuildCylinder();
      break;
    case nsParamBuilderShape::TriangularPrism:
      BuildTriangularPrism();
      break;
  }
  return mMeshPtr;
}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildPlate()
{
  nsParamBuilderShape::TPlate* pPlate = (nsParamBuilderShape::TPlate*)mShape->mPtrGeometry.get();
  pPlate->length;
  pPlate->height;
  pPlate->width;

  //MeshPtr Ogre::MeshManager::createPlane(,,,,);
  //!!!
  // OgreSDK_vc9_v1-9-0\Samples\DeferredShading\src\GeomUtils.cpp
  //!!!

  //TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager()->MaterialManager

  // материал создается как фантом - не надо его сохранять
  //Ogre::MaterialPtr mMaterialPtr = Ogre::MaterialManager::create("","");
  
  // сохранение происходит только в редакторе
  //Ogre::MaterialSerializer matSer;
  //matSer.exportMaterial(mMaterialPtr, "file");
  //Ogre::MeshSerializer meshSer;
  //meshSer.exportMesh()
  //Ogre::PatchMesh


  // взять геометрическую форму
  const float size = 60;
  Ogre::ManualObject mo("");

  mo.begin(mShape->mNameMaterial, Ogre::RenderOperation::OT_TRIANGLE_LIST);

  mo.position(-size, -size, -size);
  mo.textureCoord(0, 0);

  mo.position(-size, size, -size);
  mo.textureCoord(1, 0);

  mo.position(size, size, -size);
  mo.textureCoord(1, 1);

  mo.position(size, -size, -size);
  mo.textureCoord(0, 1);
  //-----------------------------------  
  mo.position(-size, -size, size);
  mo.textureCoord(1, 0);

  mo.position(-size, size, size);
  mo.textureCoord(0, 0);

  mo.position(size, size, size);
  mo.textureCoord(1, 1);

  mo.position(size, -size, size);
  mo.textureCoord(0, 1);

  mo.triangle(0,1,2);
  mo.triangle(0,2,3);

  mo.triangle(0,4,5);
  mo.triangle(0,5,1);

  mo.triangle(3,2,6);
  mo.triangle(3,6,7);

  mo.triangle(0,7,4);
  mo.triangle(0,3,7);

  mo.triangle(1,5,6);
  mo.triangle(1,6,2);

  mo.triangle(4,6,5);
  mo.triangle(4,7,6);
  mo.end();

  mMeshPtr = mo.convertToMesh(mShape->mName);
}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildPlateVarGeom()
{

}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildSphere()
{
  nsParamBuilderShape::TSphere* pSphere = (nsParamBuilderShape::TSphere*)mShape->mPtrGeometry.get();

  Ogre::String strName = mShape->mName;
  float radius = pSphere->radius_max;
  int nRings = pSphere->cnt_points_per_circle; 
  int nSegments = pSphere->cnt_points_per_circle; 
  bool bNormals = true;
  bool bTexCoords = true;
  GeomUtils::createSphere(strName, radius, nRings, nSegments, bNormals, bTexCoords);
}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildCone()
{

}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildTrapezium()
{

}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildTriangularPyramid()
{

}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildQuadrangularPyramid()
{

}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildCylinder()
{

}
//-----------------------------------------------------------------------------
void TBuilderShape_Ogre::BuildTriangularPrism()
{

}
//-----------------------------------------------------------------------------
