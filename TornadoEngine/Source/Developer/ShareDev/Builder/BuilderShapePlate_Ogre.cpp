/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <math.h>
#include "OgreMath.h"

#include "BuilderShapePlate_Ogre.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "BL_Debug.h"
#include "MaterialItem.h"
#include "ShapeItem.h"
#include "ParamBuilderShape.h"
#include <boost/lexical_cast.hpp>

TBuilderShapePlate_Ogre::TBuilderShapePlate_Ogre()
{
}
//-------------------------------------------------------------------------
std::string TBuilderShapePlate_Ogre::GetNameType()
{
	return "Plate";
}
//-------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::SetNameMesh()
{
	mNameMesh = GetNameType();
	mNameMesh += "_";
	mNameMesh += boost::lexical_cast<std::string>(mPSh->width);
	mNameMesh += "_";
	mNameMesh += boost::lexical_cast<std::string>(mPSh->height);
	mNameMesh += "_";
	mNameMesh += boost::lexical_cast<std::string>(mPSh->length);
}
//-------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::SetParamShape( nsParamBuilderShape::TBaseParam* pShape )
{
	mPSh = (nsParamBuilderShape::TPlate*)pShape;
}
//-------------------------------------------------------------------------
Ogre::Entity* TBuilderShapePlate_Ogre::CreateEntity(std::string& nameEntity)
{
	mMeshPtr.setNull();
	mNameEntity = nameEntity;

	CreateMaterial();
	CreateMesh();
	SetupEntity();
	return mPtrEntity;
}
//-------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::SetupEntity()
{
	mPtrEntity = mPtrSceneMng->createEntity(mNameEntity, mMeshPtr);
	Ogre::SceneNode* pNode = mPtrSceneMng->getRootSceneNode()->createChildSceneNode();
	pNode->attachObject(mPtrEntity);
}
//-------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateMesh()
{
	// взять геометрическую форму
	Ogre::ManualObject mo("");
	mPtrMO = &mo;
	mo.begin(mPtrMaterialVariant->ogreMaterial, Ogre::RenderOperation::OT_TRIANGLE_LIST);
	CreateSheetY( mPSh->width, 0,  	        mPSh->length, 0,            0);//основание/bottom
	CreateSheetZ( 0,           mPSh->width, 0,            mPSh->height, mPSh->length);// бок, фронт/front
	CreateSheetZ( mPSh->width, 0,           0, 		  			mPSh->height, 0);//бок, зад/back
	CreateSheetX( mPSh->height,0,           0, 		  			mPSh->length, 0);//бок, лево/left
	CreateSheetX( 0,           mPSh->height,0, 		  			mPSh->length, mPSh->width);//бок, право/right
	CreateSheetY( mPSh->width, 0,           0, 		  			mPSh->length, mPSh->height);//крыша/top
	//------------------------------------------------
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
void TBuilderShapePlate_Ogre::CreateSheetY(Ogre::Real x_min, Ogre::Real x_max, 
									Ogre::Real z_min, Ogre::Real z_max, 
									Ogre::Real y )
{
	CreateSheet(x_min, x_max, z_min, z_max, useX, useZ, y);
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateSheetZ(Ogre::Real x_min, Ogre::Real x_max, 
									Ogre::Real y_min, Ogre::Real y_max, 
									Ogre::Real z )
{
	CreateSheet(x_min, x_max, y_min, y_max, useX, useY, z);
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateSheetX(Ogre::Real y_min, Ogre::Real y_max, 
									Ogre::Real z_min, Ogre::Real z_max, 
									Ogre::Real x )
{
	CreateSheet(y_min, y_max, z_min, z_max, useY, useZ, x);
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::SetVector3ByUse(Ogre::Vector3& pos, Ogre::Real v, eUseAxe use)
{
	switch(use)
	{
		case useX:
			pos.x = v;
			break;
		case useY:
			pos.y = v;
			break;
		case useZ:
			pos.z = v;
			break;
	}
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateSheet(Ogre::Real a_min, Ogre::Real a_max, 
															Ogre::Real b_min, Ogre::Real b_max,
															eUseAxe useA, eUseAxe useB,
															Ogre::Real unuse)
{
	Ogre::Real absA = abs(a_max-a_min);
	Ogre::Real absB = abs(b_max-b_min);
	Ogre::Real u_max = absA/mPtrMaterialVariant->width;
	Ogre::Real v_max = absB/mPtrMaterialVariant->length;
	CreateQuad(a_min, a_max, b_min, b_max,
		useA, useB, unuse, 0, u_max, 0, v_max);
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateQuad(Ogre::Real a_min, Ogre::Real a_max, 
								Ogre::Real b_min, Ogre::Real b_max,
								eUseAxe useA, eUseAxe useB,
								Ogre::Real unuse,
								Ogre::Real u_min, Ogre::Real u_max, 
								Ogre::Real v_min, Ogre::Real v_max)
{
	nsStructBuilder_Ogre::TQuadVertex qVertex;
	Ogre::Vector3 pos(unuse,unuse,unuse);

	SetVector3ByUse(pos, a_min, useA);
	SetVector3ByUse(pos, b_min, useB);
	qVertex.p[0].x = pos.x; qVertex.p[0].y = pos.y; qVertex.p[0].z = pos.z;
	qVertex.p[0].u = u_min; qVertex.p[0].v = v_min;

	SetVector3ByUse(pos, a_max, useA);
	SetVector3ByUse(pos, b_min, useB);
	qVertex.p[1].x = pos.x; qVertex.p[1].y = pos.y; qVertex.p[1].z = pos.z;
	qVertex.p[1].u = u_max; qVertex.p[1].v = v_min;

	SetVector3ByUse(pos, a_max, useA);
	SetVector3ByUse(pos, b_max, useB);
	qVertex.p[2].x = pos.x; qVertex.p[2].y = pos.y; qVertex.p[2].z = pos.z;
	qVertex.p[2].u = u_max; qVertex.p[2].v = v_max;

	SetVector3ByUse(pos, a_min, useA);
	SetVector3ByUse(pos, b_max, useB);
	qVertex.p[3].x = pos.x; qVertex.p[3].y = pos.y; qVertex.p[3].z = pos.z;
	qVertex.p[3].u = u_min; qVertex.p[3].v = v_max;

	TBuilderShapeBase_Ogre::CreateQuad(qVertex);
}
//-----------------------------------------------------------------------------
