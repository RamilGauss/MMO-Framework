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
