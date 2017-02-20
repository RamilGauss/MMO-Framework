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
	mCntQuad = 0;
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

	for( int i = 0 ; i < mCntQuad ; i++)
	{
		unsigned int index = i*4;
		mo.triangle(index,index+1,index+2);// обход против часовой стрелки
		mo.triangle(index,index+2,index+3);
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
	if( mPSh->cnt_points_per_circle < 2 )
	{
		return;
	}
	Ogre::Real x_0 = 0;
	Ogre::Real z_0 = mPSh->radius_max;
	Ogre::Real u_0 = 0;
	Ogre::Real v_0 = 0;
	Ogre::Real v_1 = 1.0;
	Ogre::Real perimetr = Ogre::Math::TWO_PI*mPSh->radius_max;
	for( int i = 0 ; i <= mPSh->cnt_points_per_circle ; i++ )
	{
		Ogre::Real angle = (Ogre::Math::TWO_PI*i)/(mPSh->cnt_points_per_circle);
		Ogre::Real x_1 = mPSh->radius_max*sin(angle);
		Ogre::Real z_1 = mPSh->radius_max*cos(angle);

		Ogre::Real u_1 = perimetr*(i+1)/mPSh->cnt_points_per_circle;
		u_1 /= mPtrMaterialVariant->width;

		Ogre::Real ceil_u_0;
		Ogre::Real frac_u_0 = modf(u_0, &ceil_u_0);
		Ogre::Real ceil_u_1;
		Ogre::Real frac_u_1 = modf(u_1, &ceil_u_1);

		int cntBreakQuad_U = ceil_u_1 - ceil_u_0 + 1;
		if( ceil_u_1==u_1)
			cntBreakQuad_U--;
		Ogre::Real param_0 = 0;
		Ogre::Real delta_u = u_1 - u_0;
		for( int iBreakQuad_U = 0 ; iBreakQuad_U < cntBreakQuad_U ; iBreakQuad_U++ )
		{
			Ogre::Real param_1;
			if(iBreakQuad_U==cntBreakQuad_U-1)
				param_1 = 1.0;
			else
				param_1 = (ceil_u_0 + iBreakQuad_U + 1 - u_0)/delta_u;
			Ogre::Real x_min = x_0 + param_0*(x_1 - x_0);
			Ogre::Real x_max = x_0 + param_1*(x_1 - x_0);
			Ogre::Real y_min = 0;
			Ogre::Real y_max = mPSh->length;
			Ogre::Real z_min = z_0 + param_0*(z_1 - z_0);
			Ogre::Real z_max = z_0 + param_1*(z_1 - z_0);
			Ogre::Real u_min = u_0 + param_0*(u_1 - u_0);
			u_min = u_min - int(u_min);
			Ogre::Real u_max = u_0 + param_1*(u_1 - u_0);
			u_max = u_max - int(u_max);
			if( u_max==0 )// не может быть равно нулю
				u_max = 1.0;
			Ogre::Real v_min = 0;  //const
			Ogre::Real v_max = 1.0;//const
			CreateQuad(x_min, x_max, y_min, y_max, z_min, z_max, 
				u_min, u_max, v_min, v_max);
			param_0 = param_1;
		}
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

}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetDown_Cut()
{

}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetUp()
{

}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateCircleSheetDown()
{

}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateQuad( Ogre::Real x_0, Ogre::Real x_1, 
																						 Ogre::Real y_0, Ogre::Real y_1,
																						 Ogre::Real z_0, Ogre::Real z_1,
																						 Ogre::Real u_0, Ogre::Real u_1,
																						 Ogre::Real v_0, Ogre::Real v_1)
{
	mPtrMO->position(x_0, y_0, z_0);
	mPtrMO->textureCoord(u_0, v_0);
	//mPtrMO->normal(normal);

	mPtrMO->position(x_1, y_0, z_1);
	mPtrMO->textureCoord(u_1, v_0);
	//mPtrMO->normal(normal);

	mPtrMO->position(x_1, y_1, z_1);
	mPtrMO->textureCoord(u_1, v_1);
	//mPtrMO->normal(normal);

	mPtrMO->position(x_0, y_1, z_0);
	mPtrMO->textureCoord(u_0, v_1);
	//mPtrMO->normal(normal);
	mCntQuad++;
}
//-----------------------------------------------------------------------------
