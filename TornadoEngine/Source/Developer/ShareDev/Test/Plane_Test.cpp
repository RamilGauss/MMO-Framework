/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <math.h>
#include "OgreMath.h"

#include "Plane_test.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "BL_Debug.h"

TPlane_Test::TPlane_Test()
{
	mPtrSceneMng  	 = NULL;
	mPtrEntity       = NULL;
}
//-------------------------------------------------------------------------
void TPlane_Test::Setup(Ogre::Real width, Ogre::Real height, Ogre::Real depth, 
												Ogre::String& nameMaterial, Ogre::String& nameFileTexture, 
												Ogre::Real widthTexture, Ogre::Real lenghtTexture)
{
	mWidth  				 = width;
	mHeight 				 = height;
	mDepth  				 = depth;
	mWidthTexture    = widthTexture;
	mLenghtTexture   = lenghtTexture;
	mNameMaterial 	 = nameMaterial;
	mNameFileTexture = nameFileTexture;

	char s[400];
	sprintf(s, "PlaneMesh_%f_%f_%f", mWidth, mHeight, mDepth);
	mNameMesh = s;
}
//-------------------------------------------------------------------------
Ogre::Entity* TPlane_Test::CreateEntity(Ogre::String& nameEntity)
{
	mMeshPtr.setNull();
	mNameEntity = nameEntity;
	mPtrSceneMng = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();

	CreateMaterial();
	CreateMesh();
	SetupEntity();
	return mPtrEntity;
}
//-------------------------------------------------------------------------
void TPlane_Test::SetupEntity()
{
	mPtrEntity = mPtrSceneMng->createEntity(mNameEntity, mMeshPtr);
	Ogre::SceneNode* pNode = mPtrSceneMng->getRootSceneNode()->createChildSceneNode();
	pNode->attachObject(mPtrEntity);
}
//-------------------------------------------------------------------------
void TPlane_Test::CreateMaterial()
{
	// загрузка текстуры
	Ogre::TexturePtr texturePtr = 
		Ogre::TextureManager::getSingletonPtr()->
		load(mNameFileTexture, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	
	// получить материал от Огра
	mMaterialPtr = Ogre::MaterialManager::getSingletonPtr()->
		getByName(mNameMaterial, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	// настройка 
	Ogre::Technique* pTech = mMaterialPtr->getTechnique(0);
	Ogre::Pass* pPass = pTech->getPass(0);
	Ogre::TextureUnitState* pTexUS = pPass->createTextureUnitState();
	pTexUS->setTexture(texturePtr);
}
//-----------------------------------------------------------------------------
void TPlane_Test::CreateMesh()
{
	mCntQuad = 0;
	// взять геометрическую форму
	Ogre::ManualObject mo("");
	mPtrMO = &mo;
	mo.begin(mNameMaterial, Ogre::RenderOperation::OT_TRIANGLE_LIST);
	CreateSheetY( mWidth,  0,       mDepth, 0,       0);      // основание / bottom, 0-3
	CreateSheetZ( 0,       mWidth,  0,      mHeight, mDepth); // бок, фронт / front, 4-7
	CreateSheetZ( mWidth,  0,       0, 		  mHeight, 0);		  // бок, зад / back, 8-11
	CreateSheetX( mHeight, 0,       0, 		  mDepth,  0);		  // бок, лево / left, 12-15
	CreateSheetX( 0,       mHeight, 0, 		  mDepth,  mWidth); // бок, право / right, 16-19
	CreateSheetY( mWidth,  0,       0, 		  mDepth,  mHeight);// крыша / top, 20-23
	//------------------------------------------------
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
	pSubMesh->setMaterialName(mNameMaterial);
}
//-----------------------------------------------------------------------------
void TPlane_Test::CreateSheetY(Ogre::Real x_min, Ogre::Real x_max, 
									Ogre::Real z_min, Ogre::Real z_max, 
									Ogre::Real y )
{
	Ogre::Vector3 normal( 0, 0, 0);
	normal.y = ( x_min < x_max ) ? -1 : 1;
	CreateSheet(x_min, x_max, z_min, z_max, useX, useZ, y, normal);
}
//-----------------------------------------------------------------------------
void TPlane_Test::CreateSheetZ(Ogre::Real x_min, Ogre::Real x_max, 
									Ogre::Real y_min, Ogre::Real y_max, 
									Ogre::Real z )
{
	Ogre::Vector3 normal( 0, 0, 0);
	normal.z = ( x_min < x_max ) ? -1 : 1;
	CreateSheet(x_min, x_max, y_min, y_max, useX, useY, z, normal);
}
//-----------------------------------------------------------------------------
void TPlane_Test::CreateSheetX(Ogre::Real y_min, Ogre::Real y_max, 
									Ogre::Real z_min, Ogre::Real z_max, 
									Ogre::Real x )
{
	Ogre::Vector3 normal( 0, 0, 0);
	normal.x = ( y_min < y_max ) ? -1 : 1;
	CreateSheet(y_min, y_max, z_min, z_max, useY, useZ, x, normal);
}
//-----------------------------------------------------------------------------
void TPlane_Test::SetVector3ByUse(Ogre::Vector3& pos, Ogre::Real v, eUseAxe use)
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
void TPlane_Test::CreateSheet(Ogre::Real a_min, Ogre::Real a_max, 
															Ogre::Real b_min, Ogre::Real b_max,
															eUseAxe useA, eUseAxe useB,
															Ogre::Real unuse, Ogre::Vector3& normal)
{
	bool flgA_rise = bool(a_max - a_min > 0);
	bool flgB_rise = bool(b_max - b_min > 0);
	Ogre::Real absA = abs(a_max-a_min);
	Ogre::Real absB = abs(b_max-b_min);

	int cntA = int(absA/mWidthTexture);
	if(cntA*mWidthTexture < absA)
		cntA++;
	int cntB = int(absB/mLenghtTexture);
	if(cntB*mLenghtTexture < absB)
		cntB++;
	Ogre::Real a_begin = a_min, a_end, b_begin,	b_end;
	Ogre::Real stepA = flgA_rise ? mWidthTexture  : -mWidthTexture;
	Ogre::Real stepB = flgB_rise ? mLenghtTexture : -mLenghtTexture;
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
void TPlane_Test::CreateQuad(Ogre::Real a_min, Ogre::Real a_max, 
								Ogre::Real b_min, Ogre::Real b_max,
								eUseAxe useA, eUseAxe useB,
								Ogre::Real unuse, Ogre::Vector3& normal,
								Ogre::Real u_min, Ogre::Real u_max, 
								Ogre::Real v_min, Ogre::Real v_max)
{
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

	mCntQuad++;
}
//-----------------------------------------------------------------------------
