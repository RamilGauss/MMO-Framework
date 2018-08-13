/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <math.h>
#include "OgreMath.h"

#include "BuilderTool_ShapeCylinder_Ogre.h"
#include "ModuleLogic.h"
#include "GraphicEngine/GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "BL_Debug.h"
#include "MaterialItem.h"
#include "ShapeItem.h"
#include "ParamBuilderShape.h"

#include <boost/lexical_cast.hpp>
#include "StructBuilderTool_Ogre.h"

TBuilderTool_ShapeCylinder_Ogre::TBuilderTool_ShapeCylinder_Ogre()
{
  mPSh = nullptr;
}
//-------------------------------------------------------------------------
std::string TBuilderTool_ShapeCylinder_Ogre::GetNameType()
{
  return "Cylinder";
}
//-------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::SetNameMesh()
{
  mNameMesh = GetNameType();
  mNameMesh += "_";
  mNameMesh += boost::lexical_cast<std::string>(mPSh->length);
  mNameMesh += "_";
  mNameMesh += boost::lexical_cast<std::string>(mPSh->radius_max);
  mNameMesh += "_";
  mNameMesh += boost::lexical_cast<std::string>(mPSh->radius_min);
  mNameMesh += "_";
  mNameMesh += boost::lexical_cast<std::string>(mPSh->cnt_points_per_circle);
}
//-------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::SetParamShape( nsParamBuilderShape::TBaseParam* pShape )
{
  mPSh = (nsParamBuilderShape::TCylinder*)pShape;
}
//-------------------------------------------------------------------------
Ogre::Entity* TBuilderTool_ShapeCylinder_Ogre::CreateEntity(std::string& nameEntity)
{
  mMeshPtr.setNull();
  mNameEntity = nameEntity;

  CreateMaterial();
  CreateMesh();
  SetupEntity();
  return mPtrEntity;
}
//-------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::SetupEntity()
{
  mPtrEntity = mPtrSceneMng->createEntity(mNameEntity, mMeshPtr);
  Ogre::SceneNode* pNode = mPtrSceneMng->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(mPtrEntity);
}
//-------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateMesh()
{
  // взять геометрическую форму
  Ogre::ManualObject mo("");
  mPtrMO = &mo;
  mo.begin(mPtrMaterialVariant->ogreMaterial, Ogre::RenderOperation::OT_TRIANGLE_LIST);
  CreateExternalTube();// внешняя труба
  if( mPSh->radius_min > 0 )
  {
    CreateInternalTube();// внутренняя труба
    // крышка и дно, делать с прорезью
    CreateCircleSheetUp_Cut();
    CreateCircleSheetDown_Cut();
  }
  else
  {
    // крышка и дно
    CreateCircleSheetUp();
    CreateCircleSheetDown();
  }
  mo.end();

  mMeshPtr = mo.convertToMesh(mNameMesh);
  int cntSubMesh = mMeshPtr->getNumSubMeshes();
  if( cntSubMesh!=1 )
  {
    BL_FIX_BUG();
    return;
  }
  Ogre::SubMesh* pSubMesh = mMeshPtr->getSubMesh(0);
  pSubMesh->setMaterialName(mPtrMaterialVariant->ogreMaterial);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateExternalTube()
{
  CreateTube( mPSh->radius_max, true);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateTube(Ogre::Real radius, bool x_y)
{
  if( mPSh->cnt_points_per_circle < 3 )
    return;

  Ogre::Real mul = 1.0;
  if( x_y==false )
    mul = -1.0;

  Ogre::Real u_0 = 0;
  Ogre::Real u_1 = 0;
  Ogre::Real v_0 = 0;
  Ogre::Real v_1 = mPSh->length/mPtrMaterialVariant->width;

  Ogre::Real x_0 = 0;
  Ogre::Real y_0 = -mPSh->length/2;
  Ogre::Real y_1 = +mPSh->length/2;
  Ogre::Real z_0 = radius;
  Ogre::Real perimetr = Ogre::Math::TWO_PI*radius;
  for( int i = 0 ; i < mPSh->cnt_points_per_circle ; i++ )
  {
    Ogre::Real angle = (Ogre::Math::TWO_PI*(i+1))/(mPSh->cnt_points_per_circle);
    angle *= mul;
    Ogre::Real x_1 = radius*sin(angle);
    Ogre::Real z_1 = radius*cos(angle);

    Ogre::Real u_1 = perimetr*(i+1)/mPSh->cnt_points_per_circle;
    u_1 /= mPtrMaterialVariant->width;

    CreateQuad(x_0, x_1, y_0, y_1, z_0, z_1, 
        u_0, u_1, v_0, v_1);

    x_0 = x_1;
    z_0 = z_1;
    u_0 = u_1;
  }
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateInternalTube()// внутренняя труба
{
  CreateTube( mPSh->radius_min, false);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateCircleSheetUp_Cut()
{
  Ogre::Real y = mPSh->length/2;
  CreateCircleSheet_Cut( y, true);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateCircleSheetDown_Cut()
{
  Ogre::Real y = -mPSh->length/2;
  CreateCircleSheet_Cut(y, false);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateCircleSheetUp()
{
  Ogre::Real y = mPSh->length/2;
  CreateCircleSheet(y, true);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateCircleSheetDown()
{
  Ogre::Real y = -mPSh->length/2;
  CreateCircleSheet(y, false);
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateCircleSheet(Ogre::Real y, bool x_y)
{
  Ogre::Real mul = 1.0;
  if( x_y==false )
    mul = -1.0;

  Ogre::Real sizeU = mPSh->radius_max*2/mPtrMaterialVariant->width;
  Ogre::Real sizeV = mPSh->radius_max*2/mPtrMaterialVariant->length;

  nsStructBuilderTool_Ogre::TTriVertex tVertex;
  tVertex.p[2].y = tVertex.p[1].y = tVertex.p[0].y = y;
  tVertex.p[2].x = 0;
  tVertex.p[2].z = 0;
  tVertex.p[2].u = sizeU/2;
  tVertex.p[2].v = sizeV/2;

  tVertex.p[0].x = 0;
  tVertex.p[0].z = mPSh->radius_max;
  tVertex.p[0].u = sizeU/2;
  tVertex.p[0].v = 0.0;
  for( int i = 0 ; i < mPSh->cnt_points_per_circle ; i++ )
  {
    Ogre::Real angle = (Ogre::Math::TWO_PI*(i+1))/(mPSh->cnt_points_per_circle);
    angle *= mul;
    tVertex.p[1].x = mPSh->radius_max*sin(angle);
    tVertex.p[1].z = mPSh->radius_max*cos(angle);
    tVertex.p[1].u = sizeU/2*(1 - sin(angle));
    tVertex.p[1].v = sizeV/2*(1 - cos(angle));
    CreateTriangle(tVertex);
    tVertex.p[0] = tVertex.p[1];
  }
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateCircleSheet_Cut(Ogre::Real y, bool x_y)
{
  Ogre::Real mul = 1.0;
  if( x_y==false )
    mul = -1.0;

  nsStructBuilderTool_Ogre::TQuadVertex qVertex;
  qVertex.p[1].y = y;
  qVertex.p[2].y = y;

  qVertex.p[0].x = 0;
  qVertex.p[0].y = y;
  qVertex.p[0].z = mPSh->radius_max;
  qVertex.p[0].u = 0;
  qVertex.p[0].v = mPSh->radius_max/mPtrMaterialVariant->length;

  qVertex.p[3].x = 0;
  qVertex.p[3].y = y;
  qVertex.p[3].z = mPSh->radius_min;
  qVertex.p[3].u = 0;
  qVertex.p[3].v = mPSh->radius_min/mPtrMaterialVariant->length;
  for( int i = 0 ; i < mPSh->cnt_points_per_circle ; i++ )
  {
    Ogre::Real angle = (Ogre::Math::TWO_PI*(i+1))/(mPSh->cnt_points_per_circle);
    angle *= mul;
    Ogre::Real sinA = sin(angle);
    Ogre::Real cosA = cos(angle);
    qVertex.p[1].x = mPSh->radius_max*sinA;
    qVertex.p[1].z = mPSh->radius_max*cosA;
    qVertex.p[1].u = qVertex.p[1].x/mPtrMaterialVariant->width;
    qVertex.p[1].v = qVertex.p[1].z/mPtrMaterialVariant->length;
    
    qVertex.p[2].x = mPSh->radius_min*sinA;
    qVertex.p[2].z = mPSh->radius_min*cosA;
    qVertex.p[2].u = qVertex.p[2].x/mPtrMaterialVariant->width;
    qVertex.p[2].v = qVertex.p[2].z/mPtrMaterialVariant->length;
    TBuilderTool_ShapeBase_Ogre::CreateQuad(qVertex);
    qVertex.p[0] = qVertex.p[1];
    qVertex.p[3] = qVertex.p[2];
  }
}
//-----------------------------------------------------------------------------
void TBuilderTool_ShapeCylinder_Ogre::CreateQuad( Ogre::Real x_0, Ogre::Real x_1, 
                                                  Ogre::Real y_0, Ogre::Real y_1,
                                                  Ogre::Real z_0, Ogre::Real z_1,
                                                  Ogre::Real u_0, Ogre::Real u_1,
                                                  Ogre::Real v_0, Ogre::Real v_1)
{
  nsStructBuilderTool_Ogre::TQuadVertex qVertex;
  qVertex.p[0].x = x_0;  qVertex.p[0].y = y_0; qVertex.p[0].z = z_0;
  qVertex.p[0].u = u_0;  qVertex.p[0].v = v_0;
  
  qVertex.p[1].x = x_1;  qVertex.p[1].y = y_0; qVertex.p[1].z = z_1;
  qVertex.p[1].u = u_1;  qVertex.p[1].v = v_0;
  
  qVertex.p[2].x = x_1;  qVertex.p[2].y = y_1;  qVertex.p[2].z = z_1;
  qVertex.p[2].u = u_1;  qVertex.p[2].v = v_1;
  
  qVertex.p[3].x = x_0;  qVertex.p[3].y = y_1;  qVertex.p[3].z = z_0;
  qVertex.p[3].u = u_0;  qVertex.p[3].v = v_1;
  TBuilderTool_ShapeBase_Ogre::CreateQuad(qVertex);
}
//-----------------------------------------------------------------------------
