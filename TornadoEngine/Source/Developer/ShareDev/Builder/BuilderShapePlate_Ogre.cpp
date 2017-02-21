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
	Ogre::Vector3 normal( 0, 0, 0);
	normal.y = ( x_min < x_max ) ? -1 : 1;
	CreateSheet(x_min, x_max, z_min, z_max, useX, useZ, y, normal);
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateSheetZ(Ogre::Real x_min, Ogre::Real x_max, 
									Ogre::Real y_min, Ogre::Real y_max, 
									Ogre::Real z )
{
	Ogre::Vector3 normal( 0, 0, 0);
	normal.z = ( x_min < x_max ) ? -1 : 1;
	CreateSheet(x_min, x_max, y_min, y_max, useX, useY, z, normal);
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateSheetX(Ogre::Real y_min, Ogre::Real y_max, 
									Ogre::Real z_min, Ogre::Real z_max, 
									Ogre::Real x )
{
	Ogre::Vector3 normal( 0, 0, 0);
	normal.x = ( y_min < y_max ) ? -1 : 1;
	CreateSheet(y_min, y_max, z_min, z_max, useY, useZ, x, normal);
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
															Ogre::Real unuse, Ogre::Vector3& normal)
{
	bool flgA_rise = bool(a_max - a_min > 0);
	bool flgB_rise = bool(b_max - b_min > 0);
	Ogre::Real absA = abs(a_max-a_min);
	Ogre::Real absB = abs(b_max-b_min);

	int cntA = int(absA/mPtrMaterialVariant->width);
	if(cntA*mPtrMaterialVariant->width < absA)
		cntA++;
	int cntB = int(absB/mPtrMaterialVariant->length);
	if(cntB*mPtrMaterialVariant->length < absB)
		cntB++;
	Ogre::Real a_begin = a_min, a_end, b_begin,	b_end;
	Ogre::Real stepA = flgA_rise ? mPtrMaterialVariant->width  : -mPtrMaterialVariant->width;
	Ogre::Real stepB = flgB_rise ? mPtrMaterialVariant->length : -mPtrMaterialVariant->length;
	for( int iA = 0 ; iA < cntA ; iA++ )
	{
		b_begin = b_min;
		a_end = a_begin + stepA;
		if( flgA_rise )
			a_end = std::min(a_end,a_max);
		else
			a_end = std::max(a_end,a_max);
		Ogre::Real u_max = (a_end - a_begin)/stepA;
		if( u_max==0 )
			u_max = 1.0;
		for( int iB = 0 ; iB < cntB ; iB++ )
		{
			b_end = b_begin + stepB;
			if( flgB_rise )
				b_end = std::min(b_end, b_max);
			else
				b_end = std::max(b_end, b_max);
			Ogre::Real v_max = (b_end - b_begin)/stepB;
			if( v_max==0 )
				v_max = 1.0;
			CreateQuad(a_begin, a_end, b_begin, b_end,
				useA, useB, unuse, normal,
				0, u_max, 0, v_max);
			b_begin += stepB;
		}
		a_begin += stepA;
	}
}
//-----------------------------------------------------------------------------
void TBuilderShapePlate_Ogre::CreateQuad(Ogre::Real a_min, Ogre::Real a_max, 
								Ogre::Real b_min, Ogre::Real b_max,
								eUseAxe useA, eUseAxe useB,
								Ogre::Real unuse, Ogre::Vector3& normal,
								Ogre::Real u_min, Ogre::Real u_max, 
								Ogre::Real v_min, Ogre::Real v_max)
{
	TQuad quad(mPtrMO->getCurrentVertexCount());

	Ogre::Vector3 pos(unuse,unuse,unuse);

	SetVector3ByUse(pos, a_min, useA);
	SetVector3ByUse(pos, b_min, useB);
	mPtrMO->position(pos);
	mPtrMO->textureCoord(u_min, v_min);
	mPtrMO->normal(normal);

	SetVector3ByUse(pos, a_max, useA);
	SetVector3ByUse(pos, b_min, useB);
	mPtrMO->position(pos);
	mPtrMO->textureCoord(u_max, v_min);
	mPtrMO->normal(normal);

	SetVector3ByUse(pos, a_max, useA);
	SetVector3ByUse(pos, b_max, useB);
	mPtrMO->position(pos);
	mPtrMO->textureCoord(u_max, v_max);
	mPtrMO->normal(normal);

	SetVector3ByUse(pos, a_min, useA);
	SetVector3ByUse(pos, b_max, useB);
	mPtrMO->position(pos);
	mPtrMO->textureCoord(u_min, v_max);
	mPtrMO->normal(normal);

	ApplyQuad(quad);
}
//-----------------------------------------------------------------------------
