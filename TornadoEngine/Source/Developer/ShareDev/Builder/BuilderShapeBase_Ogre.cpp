/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BuilderShapeBase_Ogre.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"
#include "ShapeItem.h"

//-------------------------------------------------------------------------------
TBuilderShapeBase_Ogre::TBuilderShapeBase_Ogre()
{
	mPtrMO              = NULL;
	mPtrShape    				= NULL;
	mPtrMaterial 				= NULL;
	mPtrMaterialVariant = NULL;
	mPtrSceneMng 				= NULL;
	mPtrEntity   				= NULL;

	mMeshPtr.setNull();
	mMaterialPtr.setNull();
}
//-------------------------------------------------------------------------------
TBuilderShapeBase_Ogre::~TBuilderShapeBase_Ogre()
{

}
//-------------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::Setup(TShapeItem* pShape, TMaterialItem* pMaterial)
{
	mPtrShape    = pShape;
	mPtrMaterial = pMaterial;

	mPtrSceneMng = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();

	SetRandomVariant();
	SetParamShape(pShape->mPtrGeometry.get());
	SetNameMesh();
}
//-------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::SetRandomVariant()
{
	int randomIndexGraphic = rand()%mPtrMaterial->mGraphic.size();
	mPtrMaterialVariant = &(mPtrMaterial->mGraphic[randomIndexGraphic]);
}
//-------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::CreateMaterial()
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
	if( pTech==NULL )
		return;
	Ogre::Pass* pPass = pTech->getPass(0);
	if( pPass==NULL )
		return;

	if( pPass->getNumTextureUnitStates()==0 )
	{
		Ogre::TextureUnitState* pTexUS = pPass->createTextureUnitState();
		pTexUS->setTexture(texturePtr);
	}
}
//-----------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::ApplyQuad(TQuad& quad)
{
  mPtrMO->quad(quad._0, quad._1, quad._2, quad._3);
}
//-----------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::ApplyTriangle(TTriangle& triangle)
{
  mPtrMO->triangle(triangle._0, triangle._1, triangle._2);
}
//-----------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::CreateTriangle(nsStructBuilder_Ogre::TTriVertex& tVertex)
{
	TTriangle triangle(mPtrMO->getCurrentVertexCount());
	AddPosition(&(tVertex.p[0]), 3);
	ApplyTriangle(triangle);
}
//-----------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::CreateQuad(nsStructBuilder_Ogre::TQuadVertex& qVertex)
{
	TQuad quad(mPtrMO->getCurrentVertexCount());
	AddPosition(&(qVertex.p[0]), 4);
	ApplyQuad(quad);
}
//-----------------------------------------------------------------------------
void TBuilderShapeBase_Ogre::AddPosition( nsStructBuilder_Ogre::TVertex* p, int cnt)
{
	for( int i = 0 ; i < cnt ; i++ )
	{
		mPtrMO->position(p[i].x, p[i].y, p[i].z);
		mPtrMO->textureCoord(p[i].u, p[i].v);
		//### TODO расчет нормалей, а вот надо ли это для затенения по Фонгу?
		//mPtrMO->normal(normal);
	}
}
//-----------------------------------------------------------------------------
