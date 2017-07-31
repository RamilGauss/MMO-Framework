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
	mFGI = TModuleLogic::Get()->GetFGI();

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
			if( mPatternModel->GetTypeContent()==TModelItem::eModel )
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
	TShapeItem* pShapeItem = (TShapeItem*)mFGI->Get(TFactoryGameItem::Shape,pShapeNode->nameShapeItem);
	if( pShapeItem==NULL )
		return;

	Ogre::Entity* pEntity = GetShapeMaker()->Build( pShapeItem );
	pShapeNode->mPtrEntity = pEntity;
	// каждый вариант части будет виден в PostBuild
	pShapeNode->mPtrEntity->setVisible(false);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Ogre::PostBuild()
{
	if( mPatternModel->GetTypeContent()==TModelItem::eShape )
		PostBuild_Shape();
}
//---------------------------------------------------------------------------
void TBuilder_Model_Ogre::PostBuild_Shape()
{
	TShapeNode_Model* pRoot = (TShapeNode_Model*)mPatternModel->mHierarchy.GetRoot();
	if( pRoot==NULL )
	{
		BL_FIX_BUG();
		return;
	}
	SetLocation_Shape(pRoot);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Ogre::SetLocation_Shape(TShapeNode_Model* pNode)
{
	TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(pNode->namePart);

	// позиционирование
	// каждый вариант части будет виден в PostBuild
	pNode->mPtrEntity->setVisible(true);

	Ogre::Vector3 vPos(pNodeLocation->mGlobal.mPos.x,
		pNodeLocation->mGlobal.mPos.y, pNodeLocation->mGlobal.mPos.z);
	pNode->mPtrEntity->getParentSceneNode()->setPosition(vPos);
	pNode->mPtrEntity->setCastShadows(true);

	//=================================================================
	//### потом переделать на поиск своей функцией
	nsMathTools::TQuaternion q;
	SetMatrixToQuaternion(&(pNodeLocation->mGlobal.mOrient), &q);
	//nsMathTools::TMatrix16* m = &(pNodeLocation->mGlobal.mOrient);
	//btMatrix3x3 btM3x3;
	//btM3x3.setValue(
	//	m->m[0][0], m->m[0][1], m->m[0][2], 
	//	m->m[1][0], m->m[1][1], m->m[1][2],
	//	m->m[2][0], m->m[2][1], m->m[2][2]);
	////### потом переделать на поиск своей функцией
	//btQuaternion q;
	//btM3x3.getRotation(q);
	pNode->mPtrEntity->getParentSceneNode()->setOrientation(-q.w, q.x, q.y, q.z);
	//=================================================================

	// соединить части через крючки через constraint
	int cntPart = mPatternModel->mHierarchy.GetCountChild(pNode->namePart);
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		TShapeNode_Model* pNodeChild = 
			(TShapeNode_Model*)mPatternModel->mHierarchy.GetChild(pNode->namePart,iPart);
		if( pNodeChild==NULL )
			continue;
		SetLocation_Shape(pNodeChild);
	}
}
//---------------------------------------------------------------------------
