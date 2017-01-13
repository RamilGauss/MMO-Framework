/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Plane_test.h"
#include "ModuleLogic.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleGraphicEngine.h"

#include "BL_Debug.h"

TPlane_Test::TPlane_Test()
{
	mPtrSceneMng = NULL;
	mNameMesh     = "NameMesh";
	mNameMaterial = "NameMaterial";
	mNameTexture  = "NameTexture";
}
//-------------------------------------------------------------------------
void TPlane_Test::ShowPlane(int widthNumPoints, int heightNumPoints, 
	int widthPxTexture, int heightPxTexture,
	int width,          int height)
{
	mPtrSceneMng = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();

	SetupLight();
	CreateMaterial(widthPxTexture, heightPxTexture, width, height);
	CreateMesh(widthNumPoints, heightNumPoints);
	SetupEntity();
	SetupCamera();
}
//-------------------------------------------------------------------------
void TPlane_Test::SetupEntity()
{
	Ogre::Entity* pEntity = mPtrSceneMng->createEntity("PlaneEntity", mMeshPtr);
	pEntity->setCastShadows(false);
	Ogre::SceneNode* pNode = mPtrSceneMng->getRootSceneNode()->createChildSceneNode();
	pNode->attachObject(pEntity);

	Ogre::Vector3 vPos(0,0,0);
	pNode->setPosition(vPos);
}
//-------------------------------------------------------------------------
void TPlane_Test::SetupLight()
{
	Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
	pSM->setAmbientLight(Ogre::ColourValue(1, 1, 1));

	// light
	Ogre::String nameLight = "mainLight";
	Ogre::Light* pLight = NULL;
	if( pSM->hasLight(nameLight) )
		pLight = pSM->getLight(nameLight);
	else
		pLight = pSM->createLight(nameLight);

	pLight->setType(Ogre::Light::LT_SPOTLIGHT);
	pLight->setCastShadows(false);
	pLight->setVisible(true);
	Ogre::Vector3 posLight(0,0,0);
	pLight->setPosition(posLight);
	Ogre::Vector3 dirLight(1,0,0);
	dirLight.normalise();
	pLight->setDirection(dirLight);

	pLight->setDiffuseColour(1.0f, 1.0f, 1.0f);

	pLight->setDiffuseColour(1.0f, 1.0f, 1.0f);
	pLight->setSpecularColour(1.0f, 1.0f, 1.0f);	
	// light
}
//-----------------------------------------------------------------------------
void TPlane_Test::CreateMaterial(int widthPxTexture, int heightPxTexture, int width, int height)
{
	Ogre::TexturePtr texturePtr = 
		Ogre::TextureManager::getSingletonPtr()->createManual(
		mNameTexture, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
		Ogre::TEX_TYPE_2D, 
		widthPxTexture, heightPxTexture, 
		Ogre::MIP_DEFAULT, Ogre::PF_A8R8G8B8 );

	Ogre::ConstImagePtrList imageList;
	Ogre::Image image;
	int sizeBuffer = widthPxTexture*heightPxTexture*sizeof(unsigned int);
	Ogre::uchar* data = new Ogre::uchar[sizeBuffer];
	//memset(data, 0x10, sizeBuffer);
	for( int i = 0 ; i < sizeBuffer ; i += 4 )
	{
		data[i+0] = 0;// b
		data[i+1] = 0;// g
		data[i+2] = 0xff;// r
		data[i+3] = 0;// alpha
	}
	image.loadDynamicImage(data, widthPxTexture, heightPxTexture,	Ogre::PF_A8R8G8B8);

	imageList.push_back(&image);
	texturePtr->_loadImages( imageList );

	mMaterialPtr = Ogre::MaterialManager::getSingletonPtr()->
			create(mNameMaterial, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	Ogre::Technique* pTech = mMaterialPtr->getTechnique(0);
	Ogre::Pass* pPass = pTech->getPass(0);
	Ogre::TextureUnitState* pTexUS = pPass->createTextureUnitState( mNameTexture	);
}
//-----------------------------------------------------------------------------
void TPlane_Test::CreateMesh(int widthNumPoints, int heightNumPoints)
{
	// взять геометрическую форму
	const float size = 60;
	Ogre::ManualObject mo("");

	mo.begin(mNameMaterial, Ogre::RenderOperation::OT_TRIANGLE_LIST);

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
void TPlane_Test::SetupCamera()
{
	Ogre::Camera* pCamera = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetCamera();
	pCamera->setPosition(160,160,160);
	pCamera->lookAt(0,0,0);
}
//-----------------------------------------------------------------------------
