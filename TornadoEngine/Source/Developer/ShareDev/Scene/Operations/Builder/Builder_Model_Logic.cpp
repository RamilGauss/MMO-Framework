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
#if 0
	//###
	{
		//nsMathTools::TQuaternion q;
		//nsMathTools::TMatrix16 m;
		//btMatrix3x3 btM;
		//btVector3 row = btM.getRow(0);
		//m.m[0][0] = row.x();
		//m.m[0][1] = row.y();
		//m.m[0][2] = row.z();
		//row = btM.getRow(1);
		//m.m[1][0] = row.x();
		//m.m[1][1] = row.y();
		//m.m[1][2] = row.z();
		//row = btM.getRow(2);
		//m.m[2][0] = row.x();
		//m.m[2][1] = row.y();
		//m.m[2][2] = row.z();
		//SetMatrixToQuaternion(&m, &q);

		//btQuaternion quat;
		//btM.getRotation(quat);
		
		int asdasd = 0;
	}
	TestNodeLocation();
	nsMathTools::TMatrix16 m16;
	nsMathTools::TVector3 axis;
	
	float x = rand()/64000.0f;
	float y = rand()/64000.0f;
	float z = rand()/64000.0f;

	axis = nsMathTools::TVector3(x,y,z);//0.9178219f,-0.562612f,0.63631f);
	SetVec3Normalize(&axis, &axis);
	SetMatrixRotationAxis(&m16, &axis, float(M_PI-0.002));// подготовка

	nsMathTools::TVector3 searchAxis;
	float searchAngle;
	SetMatrixToAxisAngle(&m16, &searchAxis, &searchAngle);
	SetVec3Normalize(&searchAxis,&searchAxis);

	nsMathTools::TVector3 point(1,0,0);
	nsMathTools::TVector3 pointResult;
	SetVec3TransformCoord(&pointResult, &point, &m16);

	int a = 0;
	//###
#endif
}
//--------------------------------------------------------------------
TBuilder_Model_Logic::~TBuilder_Model_Logic()
{

}
//--------------------------------------------------------------------
bool TBuilder_Model_Logic::Init()
{
	mFBP = TModuleLogic::Get()->GetFBP();
	mFGI = TModuleLogic::Get()->GetFGI();

	if( mFBP==NULL || mFGI==NULL )
		return false;

	// найти имя модели
	std::string nameGameItem = mPatternModel->GetNameGameItem();
	mModelItem = (TModelItem*)mFGI->Get(TFactoryGameItem::Model, nameGameItem);
	if( mModelItem==NULL )
		return false;

	mPatternModel->SetTypeContent(mModelItem->mTypeCollection);
	return true;
}
//--------------------------------------------------------------------
void TBuilder_Model_Logic::Build()
{ 
	if( Init()==false )
		return;
	// создание и инициализация нодов схемы, набора и локализованных нодов (без итеративного прохода)
	SetupCollectionNode();
	// соединить части только внутри данной модели
	LinkHierarchy();
	// настройка крючков, для модели неполная, для форм - полная
	SetupJoint();
	// 
	CalcLocation();
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
	// физ. мир наследуется
	pModelNode->mPtrModel->SetNameMapItem(mPatternModel->GetNameMapItem());
	pModelNode->mPtrModel->SetPhysicWorld(mPatternModel->GetPhysicWorld());
	// какие настройки брать должен определять сам паттерн
	mPatternModel->Event_AddModelNode(pModelNode);
	pModelNode->mPtrModel->SetNameGameItem(variant.nameItem);
	// выставить, что не является игровым объектом, то есть является составной частью
	pModelNode->mPtrModel->SetIsGameObject(false);
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
void TBuilder_Model_Logic::LinkHierarchy()
{
	mPatternModel->mHierarchy.SetRoot(mModelItem->mNameRoot);
	BOOST_FOREACH( TModelItem::TMMapStrLocationVT& vtLocation, mModelItem->mMapNameBranchLocation )
	{
		mPatternModel->mHierarchy.Link(vtLocation.second.nameBranch,vtLocation.second.nameBase);// схема
		// настройка локализованных нодов
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
		pChild->mDistanceRelativeJointToJointParent   = vtLocation.second.distance;
		pChild->mOrientRelativeJointToJointParent     = vtLocation.second.orientation;
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
void TBuilder_Model_Logic::SetupJoint()
{
	// нет зависимости от варианта, потому во всех вариантах набор крючков должен быть одинаковым
	// перебор только по частям
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
		SetupJointForNode(pNode, pNodeLocation);
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupJointForNode(TBaseNode_Model* pNode, 
																						 TNodeLocation_Model* pNodeLocation)
{
	pNodeLocation->RemoveAllJoint();
	if( mPatternModel->GetTypeContent()==TModelItem::eModel )
		SetupJointForNode_Model((TModelNode_Model*)pNode, pNodeLocation);
	else
		SetupJointForNode_Shape((TShapeNode_Model*)pNode, pNodeLocation);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupJointForNode_Model(TModelNode_Model* pModelNode, 
																									TNodeLocation_Model* pNodeLocation)
{
	std::string nameModelItem = pModelNode->mPtrModel->GetNameGameItem();
	TModelItem* pModelItem = (TModelItem*)mFGI->Get(TFactoryGameItem::Model,nameModelItem);
	if( pModelItem==NULL )
		return;
	// просто добавить все крючки
	BOOST_FOREACH( TModelItem::TMapExternalJointVT& vtEJ, pModelItem->mMapExternalJoint )
		pNodeLocation->AddJoint(vtEJ.first);// пока только добавить, настроить полностью потом
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::SetupJointForNode_Shape(TShapeNode_Model* pShapeNode, 
																												TNodeLocation_Model* pNodeLocation)
{
	// набор всех крючков брать из ShapeItem
	TShapeItem* pShapeItem = (TShapeItem*)mFGI->Get(TFactoryGameItem::Shape, pShapeNode->nameShapeItem);
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
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::CalcLocation()
{
	CalcLocalLocation();
	if( mPatternModel->IsGameObject()==false )
		return;
	// здесь только для игровой модели, которая точно знает своё глобальное положение
	// расчет глобальных позиций и ориентаций нодов и их крючков
	CalcGlobalLocation();
	// коррекция с учётом рассчитанного глобального позиционирования
	RankGlobalLocationCorrection();
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::CalcLocalLocation()
{
	if( mPatternModel->GetTypeContent()==TModelItem::eModel )
	{
		RankBuildVariant();
		// поиск локального позиционирования для крючков нода
		DefineLocalLocationJoint();
	}
	// предположить что корень расположен в начале координат и никак не ориентирован (упрощение)
	// позиция (0,0,0) и ориентация (0,0,0,1)
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
	pNodeLocation->mGlobal.mPos    = nsMathTools::TVector3(0,0,0);
	SetMatrixIdentity(&(pNodeLocation->mGlobal.mOrient));// не вращать
	// рассчитать глобальное позиционирование детей и как побочный продукт
	// глобальное позиционирование крючка относительно корня для каждого нода
	CalcGlobalNode(pNodeLocation);
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::CalcGlobalNode(TNodeLocation_Model* pNodeLocation)
{
	// рассчитать свои крючки
	pNodeLocation->CalcGlobalJoint();
	// пробежка по детям
	int cntChild = mPatternModel->mHierarchy.GetCountChild(pNodeLocation->name);
	for( int i = 0 ; i < cntChild ; i++ )
	{
		TBaseNode_Model* pNodeChild = mPatternModel->mHierarchy.GetChild(pNodeLocation->name,i);
		if( pNodeChild==NULL )
			continue;

		TNodeLocation_Model* pNodeLocationChild = mPatternModel->mMngNodeLocation.Get(pNodeChild->namePart);
		if( pNodeLocationChild==NULL )
			continue;

		pNodeLocationChild->CalcGlobal(pNodeLocation);
		CalcGlobalNode(pNodeLocationChild);
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::RankBuildVariant()
{
	// расчеты проводить для всех вариантов, но использовать только те, что соединены
	// иначе у неиспользуемых вариантов не будут созданы физ, граф и звук компоненты
	int cntPart = mPatternModel->mMngNode_Collection.GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		std::string namePart = mPatternModel->mMngNode_Collection.GetNamePart(iPart);
		int cntVariant = mPatternModel->mMngNode_Collection.GetCountVariant(namePart);
		for( int iVariant = 0 ; iVariant < cntVariant ; iVariant++ )
		{
			std::string nameVariant = mPatternModel->mMngNode_Collection.GetNameVariant(namePart,iVariant);
			TModelNode_Model* pNode = (TModelNode_Model*)mPatternModel->mMngNode_Collection.Get(namePart,nameVariant);
			if( pNode==NULL )
				continue;
			// нет данных для расчета, поэтому дать квант для расчета внутри и потом забрать результат
			pNode->mPtrModel->BuildByModule_Logic();// RANK ранговая итерация
		}
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::DefineLocalLocationJoint()
{
	// пробежка по всем частям
	int cntPart = mPatternModel->mMngNode_Collection.GetCountPart();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(iPart);
		TModelNode_Model* pNodeModel = (TModelNode_Model*)mPatternModel->mHierarchy.Get(pNodeLocation->name);

		// поиск внутри части, поэтому вместо mPatternModel нужно использовать pNodeModel->mPtrModel
		std::string nameModelItem = pNodeModel->mPtrModel->GetNameGameItem();
		TModelItem* pModelItem = (TModelItem*)mFGI->Get(TFactoryGameItem::Model,nameModelItem);
		if( pModelItem==NULL )
			return;
		BOOST_FOREACH( TNodeLocation_Model::TMapStrJointVT& vtJoint, pNodeLocation->mMapNameJoint )
		{
			TNodeLocation_Model::TJoint* pJoint = &(vtJoint.second);
			TModelItem::TMapExternalJointIt fit = pModelItem->mMapExternalJoint.find(pJoint->name);
			if( fit==pModelItem->mMapExternalJoint.end() )
				continue;
			TNodeLocation_Model* pNodeOwnerJoint = pNodeModel->mPtrModel->mMngNodeLocation.Get(fit->second.namePart);
			if( pNodeOwnerJoint==NULL )
			{
				BL_FIX_BUG();
				continue;
			}
			TNodeLocation_Model::TJoint* pInternalJoint = pNodeOwnerJoint->GetJoint(fit->second.nameInternalJoint);
			if( pInternalJoint==NULL )
			{
				BL_FIX_BUG();
				continue;
			}
			// глобальное позиционирование внутреннего крючка - это локальное позиционирование внешнего крючка
			pJoint->mLocalRelativeNode = pInternalJoint->mGlobal;
		}
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::RankGlobalLocationCorrection()
{
	if( mPatternModel->GetTypeContent()==TModelItem::eShape)
		return;// не требует корректировки

	int cntPart = mPatternModel->mHierarchy.GetCount();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		TModelNode_Model* pModelNode = (TModelNode_Model*)mPatternModel->mHierarchy.Get(iPart);
		if( pModelNode==NULL )
			continue;
		TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(pModelNode->namePart);
		if( pNodeLocation==NULL )
			continue;

		pModelNode->mPtrModel->SetPosition(pNodeLocation->mGlobal.mPos);
		pModelNode->mPtrModel->SetOrientation(pNodeLocation->mGlobal.mOrient);
		pModelNode->mPtrModel->CalcGlobalLocation_Parts();
		// и скорректировать дальше
		pModelNode->mPtrModel->RankGlobalLocationCorrection();
	}
}
//---------------------------------------------------------------------------
void TBuilder_Model_Logic::CalcGlobalLocation()
{
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
	CalcGlobalNode(pNodeLocation);
}
//---------------------------------------------------------------------------
