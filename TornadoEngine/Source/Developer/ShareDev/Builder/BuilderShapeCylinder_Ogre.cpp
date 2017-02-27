/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <math.h>
#include "OgreMath.h"

#include "BuilderShapeCylinder_Ogre.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "BL_Debug.h"
#include "MaterialItem.h"
#include "ShapeItem.h"
#include "ParamBuilderShape.h"

#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

TBuilderShapeCylinder_Ogre::TBuilderShapeCylinder_Ogre()
{
}
//-------------------------------------------------------------------------
std::string TBuilderShapeCylinder_Ogre::GetNameType()
{
	return "Cylinder";
}
//-------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::SetNameMesh()
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
void TBuilderShapeCylinder_Ogre::SetParamShape( nsParamBuilderShape::TBaseParam* pShape )
{
	mPSh = (nsParamBuilderShape::TCylinder*)pShape;
}
//-------------------------------------------------------------------------
Ogre::Entity* TBuilderShapeCylinder_Ogre::CreateEntity(std::string& nameEntity)
{
	mMeshPtr.setNull();
	mNameEntity = nameEntity;

	CreateMaterial();
	CreateMesh();
	SetupEntity();
	return mPtrEntity;
}
//-------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::SetupEntity()
{
	mPtrEntity = mPtrSceneMng->createEntity(mNameEntity, mMeshPtr);
	Ogre::SceneNode* pNode = mPtrSceneMng->getRootSceneNode()->createChildSceneNode();
	pNode->attachObject(mPtrEntity);
}
//-------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateMesh()
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
void TBuilderShapeCylinder_Ogre::CreateExternalTube()
{
	if( mPSh->cnt_points_per_circle < 3 )
		return;

	Ogre::Real u_0 = 0;
	Ogre::Real u_1 = 0;
	Ogre::Real v_0 = 0;
	Ogre::Real v_1 = mPSh->length/mPtrMaterialVariant->width;

	Ogre::Real x_0 = 0;
	Ogre::Real y_0 = 0;
	Ogre::Real y_1 = mPSh->length;
	Ogre::Real z_0 = mPSh->radius_max;
	Ogre::Real perimetr = Ogre::Math::TWO_PI*mPSh->radius_max;
	for( int i = 0 ; i <= mPSh->cnt_points_per_circle ; i++ )
	{
		Ogre::Real angle = (Ogre::Math::TWO_PI*(i+1))/(mPSh->cnt_points_per_circle);
		Ogre::Real x_1 = mPSh->radius_max*sin(angle);
		Ogre::Real z_1 = mPSh->radius_max*cos(angle);

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
void TBuilderShapeCylinder_Ogre::CreateInternalTube()// внутренняя труба
{
	
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetUp_Cut()
{
	Ogre::Real y = mPSh->length;
	CreateCircleSheet_Cut( y, true);
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetDown_Cut()
{
	Ogre::Real y = 0;
	CreateCircleSheet_Cut(y, false);
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetUp()
{
	Ogre::Real y = mPSh->length;
	CreateCircleSheet(y, true);
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetDown()
{
	Ogre::Real y = 0;
	CreateCircleSheet(y, false);
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheet(Ogre::Real y, bool x_y)
{
	//int i_0 = 0;
	//int i_1 = 1;
	//if( x_y==false )
	//{
	//	i_0 = 1;
	//	i_1 = 0;
	//}

	Ogre::Real sizeU = mPSh->radius_max*2/mPtrMaterialVariant->width;
	Ogre::Real sizeV = mPSh->radius_max*2/mPtrMaterialVariant->length;

	nsStructBuilder_Ogre::TTriVertex tVertex;
	tVertex.p[2].y = tVertex.p[1].y = tVertex.p[0].y = y;
	tVertex.p[2].x = 0;
	tVertex.p[2].z = 0;
	tVertex.p[2].u = sizeU/2;
	tVertex.p[2].v = sizeV/2;

	tVertex.p[0].x = 0;
	tVertex.p[0].z = mPSh->radius_max;
	tVertex.p[0].u = sizeU/2;
	tVertex.p[0].v = 0.0;
	for( int i = 0 ; i <= mPSh->cnt_points_per_circle ; i++ )
	{
		Ogre::Real angle = (Ogre::Math::TWO_PI*(i+1))/(mPSh->cnt_points_per_circle);
		tVertex.p[1].x = mPSh->radius_max*sin(angle);
		tVertex.p[1].z = mPSh->radius_max*cos(angle);
		tVertex.p[1].u = sizeU/2*(1 - sin(angle));
		tVertex.p[1].v = sizeV/2*(1 - cos(angle));
		CreateTriangle(tVertex);
		tVertex.p[0] = tVertex.p[1];
	}
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheet_Cut(Ogre::Real y, bool x_y)
{
	Ogre::Real dRadius = mPSh->radius_max - mPSh->radius_min;
	Ogre::Real sizeU = dRadius/mPtrMaterialVariant->width;
	Ogre::Real sizeV = dRadius/mPtrMaterialVariant->length;
	Ogre::Real ratioRadius = mPSh->radius_min/mPSh->radius_max;

	nsStructBuilder_Ogre::TQuadVertex qVertex;
	qVertex.p[1].y = y;
	qVertex.p[2].y = y;

	qVertex.p[0].x = 0;
	qVertex.p[0].y = y;
	qVertex.p[0].z = mPSh->radius_max;
	qVertex.p[0].u = sizeU/2;
	qVertex.p[0].v = 0;

	qVertex.p[3].x = 0;
	qVertex.p[3].y = y;
	qVertex.p[3].z = mPSh->radius_min;
	qVertex.p[3].u = sizeU/2;
	qVertex.p[3].v = sizeV/2*(1 - ratioRadius);
	for( int i = 0 ; i <= mPSh->cnt_points_per_circle ; i++ )
	{
		Ogre::Real angle = (Ogre::Math::TWO_PI*(i+1))/(mPSh->cnt_points_per_circle);
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
		TBuilderShapeBase_Ogre::CreateQuad(qVertex);
		qVertex.p[0] = qVertex.p[1];
		qVertex.p[3] = qVertex.p[2];
	}
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateQuad( Ogre::Real x_0, Ogre::Real x_1, 
																						 Ogre::Real y_0, Ogre::Real y_1,
																						 Ogre::Real z_0, Ogre::Real z_1,
																						 Ogre::Real u_0, Ogre::Real u_1,
																						 Ogre::Real v_0, Ogre::Real v_1)
{
	nsStructBuilder_Ogre::TQuadVertex qVertex;
	qVertex.p[0].x = x_0;	qVertex.p[0].y = y_0; qVertex.p[0].z = z_0;
	qVertex.p[0].u = u_0;	qVertex.p[0].v = v_0;
	
	qVertex.p[1].x = x_1;	qVertex.p[1].y = y_0; qVertex.p[1].z = z_1;
	qVertex.p[1].u = u_1;	qVertex.p[1].v = v_0;
	
	qVertex.p[2].x = x_1;	qVertex.p[2].y = y_1;	qVertex.p[2].z = z_1;
	qVertex.p[2].u = u_1;	qVertex.p[2].v = v_1;
	
	qVertex.p[3].x = x_0;	qVertex.p[3].y = y_1;	qVertex.p[3].z = z_0;
	qVertex.p[3].u = u_0;	qVertex.p[3].v = v_1;
	TBuilderShapeBase_Ogre::CreateQuad(qVertex);
}
//-----------------------------------------------------------------------------
