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
void TBuilderShapeCylinder_Ogre::CreateMaterial()
{
	// загрузка текстуры
	Ogre::TexturePtr texturePtr = 
		Ogre::TextureManager::getSingletonPtr()->
		load(mPtrMaterialVariant->color, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	// получить материал от Огра
	mMaterialPtr = Ogre::MaterialManager::getSingletonPtr()->
		getByName(mPtrMaterialVariant->ogreMaterial, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	// настройка 
	Ogre::Technique* pTech = mMaterialPtr->getTechnique(0);
	Ogre::Pass* pPass = pTech->getPass(0);
	Ogre::TextureUnitState* pTexUS = pPass->createTextureUnitState();
	pTexUS->setTexture(texturePtr);
}
//-----------------------------------------------------------------------------
void TBuilderShapeCylinder_Ogre::CreateMesh()
{
	mCntQuad = 0;
	// взять геометрическую форму
	Ogre::ManualObject mo("");
	mPtrMO = &mo;
	mo.begin(mPtrMaterialVariant->ogreMaterial, Ogre::RenderOperation::OT_TRIANGLE_LIST);
	if( mPSh->radius_min > 0 )
	{
		CreateInternalTube();// внутренняя труба
		// крышка и дно делать с прорезью
		CreateCircleSheetUp_Cut();
		CreateCircleSheetDown_Cut();
	}
	else
	{
		// крышка и дно
		CreateCircleSheetUp();
		CreateCircleSheetDown();
	}
	CreateExternalTube();// внешняя труба

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
	//mPtrMO->position(pos);
	//mPtrMO->textureCoord(u_min, v_min);
	//mPtrMO->normal(normal);

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
