/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/
#define _USE_MATH_DEFINES

#include <cmath>
#include <boost/foreach.hpp>

#include "Builder_Model_Logic.h"
#include "Pattern_Model.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"
#include "ShapeItem.h"
#include "ShapeNode_Model.h"
#include "ModelNode_Model.h"

TBuilder_Model_Logic::TBuilder_Model_Logic()
{
	mFBP = NULL;
	mFGI = NULL;
	mModelItem = NULL;
}
//--------------------------------------------------------------------
TBuilder_Model_Logic::~TBuilder_Model_Logic()
{

}
//--------------------------------------------------------------------
void TBuilder_Model_Logic::Build()
{
	//###
	nsMathTools::TQuaternion qRot;
	nsMathTools::TVector3 v(0,1,0);
	float angle = float(M_PI/4);

	SetQuaternionRotationAxis(&qRot, &v, angle*2);

	nsMathTools::TQuaternion qPoint(1,0,0,0);

	nsMathTools::TQuaternion qResult;
	nsMathTools::TVector3 vResult;
	float angleResult;

	qResult = qPoint*qRot;// OK
	SetQuaternionToAxisAngle(&qResult, &vResult, &angleResult);
	//###

	mFBP = TModuleLogic::Get()->GetFBP();
	mFGI = TModuleLogic::Get()->GetFGI();

	// найти имя модели
	std::string nameGameItem = mPatternModel->GetNameGameItem();
	mModelItem = (TModelItem*)mFGI->Get(TFactoryGameItem::Model, nameGameItem);
	if( mModelItem==NULL )
		return;

	mPatternModel->SetTypeContent(mModelItem->mTypeCollection);

	SetupCollectionNode();
	LinkHierarchy();
	SetupHierarchyLocation();

	// расчет глобальных позиций и ориентаций нодов и их крючков
	TryCalcGlobal();
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupCollectionNode()
{
	// наполнить менеджер узлов данными (но не выделять память под физический и графический объекты)
	BOOST_FOREACH( TModelItem::TMapStrPartVT& vtPart, mModelItem->mMapNamePart )
	{
		std::string namePart = vtPart.first;
		BOOST_FOREACH( TModelItem::TVariant& variant, vtPart.second.vecVariant )
		{
			TBaseNode_Model* pNode = NULL;
			if( mPatternModel->GetTypeContent()==TModelItem::eModel )
				pNode = BuildModels(variant);
			else
				pNode = BuildShapes(variant);
			if( pNode==NULL )
				continue;
			pNode->namePart    = namePart;
			pNode->nameVariant = variant.name;
			mPatternModel->mMngNode_Collection.Add(pNode);// полная коллекция
		}
		// по-умолчанию берём первый вариант
		std::string nameVariant = mPatternModel->mMngNode_Collection.GetNameVariant(namePart, 0);
		TBaseNode_Model* p = mPatternModel->mMngNode_Collection.Get(namePart,nameVariant);
		if( p )
		{
			mPatternModel->mHierarchy.Add(p);// коллекция-схема
			mPatternModel->mMngNodeLocation.Add(p->namePart);// зеркало коллекции-схемы, данные позиционирования
		}
	}
}
//---------------------------------------------------------------------------
TBaseNode_Model* TBuilder_Model_Logic::BuildModels(TModelItem::TVariant& variant)
{
  TModelItem* pModel = (TModelItem*)mFGI->Get( TFactoryGameItem::Model, variant.nameItem);
  if( pModel==NULL )
    return NULL;
  TBehaviourPattern* pPattern = mFBP->GetPatternByName(pModel->mNamePattern);
  if( pPattern==NULL )
    return NULL;

  TModelNode_Model* pModelNode = new TModelNode_Model;
	pModelNode->mPtrModel        = (TPattern_Model*)pPattern;
	pModelNode->mPtrModel->SetNameGameItem(variant.nameItem);
	// выставить что не является игровым объектом, то есть является составной частью
	pModelNode->mPtrModel->SetIsGameObject(false);
	// дальше по итерации пока не попадётся Shape
	pModelNode->mPtrModel->BuildByModule_Logic();
	return pModelNode;
}
//---------------------------------------------------------------------------
TBaseNode_Model* TBuilder_Model_Logic::BuildShapes(TModelItem::TVariant& variant)
{
	// передача данных от Логики к Физике и Графике для каждого потока ( создание формы )
	TShapeItem* pShapeItem = (TShapeItem*)mFGI->Get( TFactoryGameItem::Shape, variant.nameItem);
	if( pShapeItem==NULL )
		return NULL;

	TShapeNode_Model* pShapeNode = new TShapeNode_Model;
	pShapeNode->nameShapeItem    = variant.nameItem;
	if( variant.redefinitionMaterial.length() )
		pShapeNode->nameMaterial = variant.redefinitionMaterial;
	else
		pShapeNode->nameMaterial = pShapeItem->mNameMaterial;
	// наполнить менеджер узлов данными (но не выделять память под физический и графический объекты)
	return pShapeNode;
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupHierarchyLocation()
{
	SetupInnerJoint();
	SetupExternalJoint();
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupNodeLocation(TBaseNode_Model* pNode, 
																						 TNodeLocation_Model* pNodeLocation)
{
	pNodeLocation->RemoveAllJoint();
	if( mPatternModel->GetTypeContent()==TModelItem::eModel )
	{
		TModelNode_Model* pModel = (TModelNode_Model*)pNode;
		std::string nameModelItem = pModel->mPtrModel->GetNameGameItem();
		TModelItem* pModelItem = (TModelItem*)mFGI->Get(TFactoryGameItem::Model,nameModelItem);
		if( pModelItem==NULL )
		{
			BL_FIX_BUG();
			return;
		}
		// набор всех крючков брать из паттерна
		int cntJoint = pModel->mPtrModel->GetCountExternalJoint();
		for( int i = 0 ; i < cntJoint ; i++ )
		{
			TPattern_Model::TExternalJoint* pExternalJoint = pModel->mPtrModel->GetExternalJoint(i);
			if( pExternalJoint==NULL )
				continue;
			pNodeLocation->AddJoint(pExternalJoint->name);
			TNodeLocation_Model::TJoint* pJoint = pNodeLocation->GetJoint(i);
			if( pJoint==NULL )
				continue;
			pJoint->mLocalRelativeNode.mPos    = pExternalJoint->pos;
			pJoint->mLocalRelativeNode.mOrient = pExternalJoint->orient;
		}
	}
	else
	{
		// набор всех крючков брать из ShapeItem
		TShapeNode_Model* pShape = (TShapeNode_Model*)pNode;
		TShapeItem* pShapeItem = (TShapeItem*)mFGI->Get(TFactoryGameItem::Shape, pShape->nameShapeItem);
		if( pShapeItem==NULL )
			return;
		BOOST_FOREACH( TShapeItem::TMapStrJointVT& vtJoint, pShapeItem->mMapNameJoint )
		{
			std::string nameJoint = vtJoint.first;
			pNodeLocation->AddJoint(nameJoint);
			TNodeLocation_Model::TJoint* pJoint = pNodeLocation->GetJoint(nameJoint);
			if( pJoint==NULL )
				continue;
			pJoint->mLocalRelativeNode.mPos    = vtJoint.second.position;
			pJoint->mLocalRelativeNode.mOrient = vtJoint.second.orientation;
		}
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::LinkHierarchy()
{
	mPatternModel->mHierarchy.SetRoot(mModelItem->mNameRoot);
	BOOST_FOREACH( TModelItem::TMMapStrLocationVT& vtLocation, mModelItem->mMapNameBranchLocation )
	{
		mPatternModel->mHierarchy.Link(vtLocation.second.nameBranch,vtLocation.second.nameBase);// схема

		TNodeLocation_Model* pChild  = mPatternModel->mMngNodeLocation.Get(vtLocation.second.nameBranch);
		TNodeLocation_Model* pParent = mPatternModel->mMngNodeLocation.Get(vtLocation.second.nameBase);

		if( pChild==NULL || pParent==NULL )
		{
			BL_FIX_BUG();
			continue;
		}
		// наполнить данными для последующего расчёта
		pChild->nameMyJointToParent = vtLocation.second.nameJointBranch;
		pChild->nameJointParent     = vtLocation.second.nameJointBase;
		pChild->mLocalRelativeJointToJointParent.mPos    = vtLocation.second.position;
		pChild->mLocalRelativeJointToJointParent.mOrient = vtLocation.second.orientation;
		// как соединить
		pChild->ClearListLink();
		BOOST_FOREACH( TModelItem::TLink& linkModelItem, vtLocation.second.listLink)
		{
			TNodeLocation_Model::TLink* pLink = new TNodeLocation_Model::TLink;
			pLink->nameJointParent     = linkModelItem.nameJointBase;
			pLink->nameMyJointToParent = linkModelItem.nameJointBranch;
			pLink->SetConstraint(linkModelItem.mPtrConstraint.get());
			pChild->mListLink.push_back(pLink);
		}
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupInnerJoint()
{
	int cnt = mPatternModel->mHierarchy.GetCount();
	for( int i = 0 ; i < cnt ; i++ )
	{
		TBaseNode_Model* pNode = mPatternModel->mHierarchy.Get(i);
		if( pNode==NULL )
			continue;
		// взять из набора локализованных узлов
		TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(pNode->namePart);
		if( pNodeLocation==NULL )
			continue;
		SetupNodeLocation(pNode, pNodeLocation);
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupExternalJoint()
{
	// для тех, кто пользуется паттерном
	BOOST_FOREACH( TModelItem::TMapExternalJointVT& vtExternalJoint, mModelItem->mMapExternalJoint )
	{
		std::string nameExternalJoint = vtExternalJoint.first;
		mPatternModel->AddExternalJoint(nameExternalJoint);
		// после добавления берём для настройки
		TPattern_Model::TExternalJoint* pExtrenalJoint = mPatternModel->GetExternalJoint(nameExternalJoint);
		if( pExtrenalJoint==NULL )
			continue;
		// ищем часть, на которую ссылается externalJoint
		TNodeLocation_Model* pNodeLocation = 
			mPatternModel->mMngNodeLocation.Get(vtExternalJoint.second.namePart);
		if( pNodeLocation==NULL )
			continue;
		TNodeLocation_Model::TJoint* pJoint = pNodeLocation->GetJoint(vtExternalJoint.second.nameInternalJoint);
		if( pJoint==NULL )
			continue;
		pExtrenalJoint->pos    = pJoint->mLocalRelativeNode.mPos;
		pExtrenalJoint->orient = pJoint->mLocalRelativeNode.mOrient;
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::TryCalcGlobal()
{
	if( mPatternModel->IsGameObject()==false )
		return;

	// здесь только для игровой модели, которая точно знает своё глобальное положение
	TBaseNode_Model* pRoot = mPatternModel->mHierarchy.GetRoot();
	if( pRoot==NULL )
	{
		BL_FIX_BUG();
		return;
	}
	TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(pRoot->namePart);
	if( pNodeLocation==NULL )
	{
		BL_FIX_BUG();
		return;
	}
	mPatternModel->GetPosition(pNodeLocation->mGlobal.mPos);
	mPatternModel->GetOrientation(pNodeLocation->mGlobal.mOrient);
	CalcGlobal(pRoot);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::CalcGlobal(TBaseNode_Model* pNode)
{
	TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(pNode->namePart);
	if( pNodeLocation==NULL )
	{
		BL_FIX_BUG();
		return;
	}
	TBaseNode_Model* pNodeParent = mPatternModel->mHierarchy.GetParent(pNode->namePart);
	TNodeLocation_Model* pNodeLocationParent = NULL;
	if( pNodeParent )
	{
		pNodeLocationParent = mPatternModel->mMngNodeLocation.Get(pNodeLocation->name);
		if( pNodeLocationParent==NULL )
		{
			BL_FIX_BUG();
			return;
		}
	}
	if( mPatternModel->GetTypeContent()==TModelItem::eModel )
	{
		TModelNode_Model* pModelNode = (TModelNode_Model*)pNode;
		if( pNodeParent==NULL )
		{
			pModelNode->mPtrModel->SetPosition(pNodeLocation->mGlobal.mPos);
			pModelNode->mPtrModel->SetOrientation(pNodeLocation->mGlobal.mOrient);
		}
		else
		{
			pNodeLocation->CalcGlobal(pNodeLocationParent);
		}
		pModelNode->mPtrModel->CalcGlobal();
	}
	else// eShape
	{
		if( pNodeParent==NULL )
		{// Root
			mPatternModel->GetPosition(   pNodeLocation->mGlobal.mPos);
			mPatternModel->GetOrientation(pNodeLocation->mGlobal.mOrient);
		}
		else
		{
			// расчёт
			pNodeLocation->CalcGlobal(pNodeLocationParent);
		}
		pNodeLocation->CalcGlobalJoint();
	}

	// пробежка по детям
	int cntChild = mPatternModel->mHierarchy.GetCountChild(pNode->namePart);
	for( int i = 0 ; i < cntChild ; i++ )
	{
		TBaseNode_Model* pChild = mPatternModel->mHierarchy.GetChild(pNode->namePart,i);
		if( pChild==NULL )
			continue;
		CalcGlobal(pChild);
	}
}
//---------------------------------------------------------------------------
