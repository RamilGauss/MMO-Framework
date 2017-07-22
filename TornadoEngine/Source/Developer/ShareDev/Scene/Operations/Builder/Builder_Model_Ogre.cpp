/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Model_Ogre.h"
#include "Pattern_Model.h"
#include "FactoryBuilderTool_Shape_Ogre.h"
#include "ModuleGraphicEngine.h"
#include "ShapeNode_Model.h"
#include "ModelNode_Model.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

TBuilder_Model_Ogre::TBuilder_Model_Ogre()
{

}
//--------------------------------------------------------------------
TBuilder_Model_Ogre::~TBuilder_Model_Ogre()
{

}
//--------------------------------------------------------------------
TFactoryBuilderTool_Shape_Ogre* TBuilder_Model_Ogre::GetShapeMaker()
{
	return TFactoryBuilderTool_Shape_Ogre::Get();
}
//------------------------------------------------------------------------
void TBuilder_Model_Ogre::Build()
{
	int cntPart = mPatternModel->mMngNode_Collection.GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		std::string namePart = mPatternModel->mMngNode_Collection.GetNamePart(iPart);
		int cntVariant = mPatternModel->mMngNode_Collection.GetCountVariant(namePart);
		for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
		{
			std::string nameVariant = mPatternModel->mMngNode_Collection.GetNameVariant(namePart, iVariant);
			TBaseNode_Model* pNode = mPatternModel->mMngNode_Collection.Get(namePart, nameVariant);
			if( pNode==NULL )
				continue;
			if( pNode->type==TModelItem::eModel )
			{
				TModelNode_Model* pModelNode = (TModelNode_Model*)pNode;
				pModelNode->mPtrModel->BuildByModule_Graphic();
			}
			else
			{
				TShapeNode_Model* pShapeNode = (TShapeNode_Model*)pNode;
				BuildShape(pShapeNode);
			}
		}
	}
	PostBuild();
}
//---------------------------------------------------------------------------
void TBuilder_Model_Ogre::BuildShape(TShapeNode_Model* pShapeNode)
{
	TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
	TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get(TFactoryGameItem::Shape,pShapeNode->nameShapeItem);
	if( pShapeItem==NULL )
		return;

	Ogre::Entity* pEntity = GetShapeMaker()->Build( pShapeItem );
	pShapeNode->mPtrEntity = pEntity;
	// каждый вариант части будет виден в PostBuild
	pShapeNode->mPtrEntity->setVisible(false);

	//### TODO убрать, всё позиционирование производится после загрузки всех форм (PostLoad)
	// сделано временно для визуализации (отладка)
	nsMathTools::TVector3 pos;
	mPatternModel->GetPosition(pos);
	Ogre::Vector3 vPos(pos.x, pos.y, pos.z);
	pEntity->getParentSceneNode()->setPosition(vPos);
	pEntity->setCastShadows(true);

	nsMathTools::TQuaternion orient;
	mPatternModel->GetOrientation(orient);
	pEntity->getParentSceneNode()->setOrientation(orient.w, orient.x, orient.y, orient.z);
	//###
}
//---------------------------------------------------------------------------
void TBuilder_Model_Ogre::PostBuild()
{
	//// каждый вариант части будет виден в PostBuild
	//pShapeNode->mPtrEntity->setVisible(false);

	////### TODO убрать, всё позиционирование производится после загрузки всех форм (PostLoad)
	//// сделано временно для визуализации (отладка)
	//nsMathTools::TVector3 pos;
	//mPatternModel->GetPosition(pos);
	//Ogre::Vector3 vPos(pos.x, pos.y, pos.z);
	//pEntity->getParentSceneNode()->setPosition(vPos);
	//pEntity->setCastShadows(true);

	//nsMathTools::TQuaternion orient;
	//mPatternModel->GetOrientation(orient);
	//pEntity->getParentSceneNode()->setOrientation(orient.w, orient.x, orient.y, orient.z);
	//###
}
//---------------------------------------------------------------------------
