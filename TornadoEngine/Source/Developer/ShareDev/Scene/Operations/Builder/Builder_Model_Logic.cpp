/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

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
	mFBP = TModuleLogic::Get()->GetFBP();
	mFGI = TModuleLogic::Get()->GetFGI();

	// найти имя модели
	std::string nameGameItem = mPatternModel->GetNameGameItem();
	TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();

	mModelItem = (TModelItem*)pFGI->Get(TFactoryGameItem::Model, nameGameItem);
	if( mModelItem==NULL )
		return;

	// задача: создать модели по имени. При синхронизации менять положение и ориентацию форм или моделей
	mPatternModel->SetTypeContent(mModelItem->mTypeCollection);
	Build_Private(mModelItem->mMapNamePart);

	mPatternModel->mHierarchy.SetRoot(mModelItem->mRoot.name);
	BOOST_FOREACH( TModelItem::TMMapStrLocationVT& vtLocation, mModelItem->mMapNameBranchLocation )
		mPatternModel->mHierarchy.Link(vtLocation.second.nameBranch,vtLocation.second.nameBase);

	CalcLocal();

	// расчет глобальных позиций и ориентаций
	TBaseNode_Model* pNodeRoot = mPatternModel->mHierarchy.GetRoot();
	CalcGlobal(pNodeRoot);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::Build_Private(TModelItem::TMapStrPart& mapNamePart)
{
	// создать другие модели и сохранить в контексте
	BOOST_FOREACH( TModelItem::TMapStrPartVT& vtPart, mapNamePart )
	{
		std::string namePart = vtPart.first;
		BOOST_FOREACH( TModelItem::TVariant& variant, vtPart.second.vecVariant )
		{
			if( mPatternModel->GetTypeContent()==TModelItem::eModel )
				BuildModels(namePart, variant);
			else
				BuildShapes(namePart, variant);
		}
		// по-умолчанию берём первый вариант
		std::string nameVariant = mPatternModel->mMngNode_Collection.GetNameVariant(namePart, 0);
		TBaseNode_Model* p = mPatternModel->mMngNode_Collection.Get(namePart,nameVariant);
		if( p )
			mPatternModel->mHierarchy.Add(p);
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::BuildModels(std::string& namePart, TModelItem::TVariant& variant)
{
  TModelItem* pModel = (TModelItem*)mFGI->Get( TFactoryGameItem::Model, variant.nameItem);
  if( pModel==NULL )
    return;
  TBehaviourPattern* pPattern = mFBP->GetPatternByName(pModel->mNamePattern);
  if( pPattern==NULL )
    return;

  TModelNode_Model* pModelNode = new TModelNode_Model;
	pModelNode->mPtrModel        = (TPattern_Model*)pPattern;
	pModelNode->namePart         = namePart;
	pModelNode->nameVariant      = variant.name;
	// наполнить менеджер узлов данными (но не выделять память под физический и графический объекты)
	mPatternModel->mMngNode_Collection.Add(pModelNode);
  pModelNode->mPtrModel->BuildByModule_Logic();// дальше по итерации
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::BuildShapes(std::string& namePart, TModelItem::TVariant& variant)
{
	// передача данных от Логики к Физике и Графике для каждого потока ( создание формы )
	TShapeItem* pShapeItem = (TShapeItem*)mFGI->Get( TFactoryGameItem::Shape, variant.nameItem);
	if( pShapeItem==NULL )
		return;

	TShapeNode_Model* pShapeNode = new TShapeNode_Model;
	pShapeNode->namePart         = namePart;
	pShapeNode->nameVariant      = variant.name;
	pShapeNode->nameShapeItem    = variant.nameItem;
	if( variant.redefinitionMaterial.length() )
		pShapeNode->nameMaterial = variant.redefinitionMaterial;
	else
		pShapeNode->nameMaterial = pShapeItem->mNameMaterial;
	// наполнить менеджер узлов данными (но не выделять память под физический и графический объекты)
	mPatternModel->mMngNode_Collection.Add(pShapeNode);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::CalcGlobal(TBaseNode_Model* pNode)
{
	TBaseNode_Model* pNodeParent = mPatternModel->mHierarchy.GetParent(pNode->namePart);
	if( pNodeParent==NULL )
	{// корень
		TBaseNode_Model::TLocation globalParent;
		mPatternModel->GetPosition(globalParent.mPos);
		mPatternModel->GetOrientation(globalParent.mOrient);
		// расчёт
		pNode->CalcGlobal(globalParent);
	}
	else
	{
		// расчёт
		pNode->CalcGlobal(pNodeParent->mGlobal);
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
void TBuilder_Model_Logic::CalcLocal()
{
	TBaseNode_Model* pRoot = mPatternModel->mHierarchy.GetRoot();
	if( pRoot==NULL )
	{
		BL_FIX_BUG();
		return;
	}
	pRoot->mLocal.mPos    = mModelItem->mRoot.position;
	pRoot->mLocal.mOrient = mModelItem->mRoot.orientation;

	int cnt = mPatternModel->mHierarchy.GetCount();
	for( int i = 0 ; i < cnt ; i++ )
	{
		TBaseNode_Model* pNode = mPatternModel->mHierarchy.Get(i);
		if( pNode==NULL )
			continue;
		if( pNode==pRoot )// хотя в mMapNameBranchLocation Root и не найдёт
			continue;
		TModelItem::TMMapStrLocationIt fit = mModelItem->mMapNameBranchLocation.find(pNode->namePart);
		if( fit==mModelItem->mMapNameBranchLocation.end() )
			continue;

		pNode->mLocal.mPos    = fit->second.position;
		pNode->mLocal.mOrient = fit->second.orientation;
	}
}
//---------------------------------------------------------------------------
