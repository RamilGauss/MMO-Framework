/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Model_Bullet.h"
#include "FactoryBuilderTool_Shape_Bullet.h"

#include "Pattern_Model.h"
#include "ModelItem.h"
#include "ShapeNode_Model.h"
#include "ModelNode_Model.h"
#include "ModuleLogic.h"
#include "FactoryGameItem.h"

TBuilder_Model_Bullet::TBuilder_Model_Bullet()
{

}
//--------------------------------------------------------------------
TBuilder_Model_Bullet::~TBuilder_Model_Bullet()
{

}
//--------------------------------------------------------------------
TFactoryBuilderTool_Shape_Bullet* TBuilder_Model_Bullet::GetShapeMaker()
{
	return TFactoryBuilderTool_Shape_Bullet::Get();
}
//--------------------------------------------------------------------
void TBuilder_Model_Bullet::Build()
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
				pModelNode->mPtrModel->BuildByModule_Physic();
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
void TBuilder_Model_Bullet::BuildShape(TShapeNode_Model* pShapeNode)
{
	TFactoryGameItem* pFGI = TModuleLogic::Get()->GetFGI();
	TShapeItem* pShapeItem = (TShapeItem*)pFGI->Get(TFactoryGameItem::Shape,pShapeNode->nameShapeItem);
	if( pShapeItem==NULL )
		return;

	int id_world = mPatternModel->GetPhysicWorld();

	btRigidBody* pRB = GetShapeMaker()->Build( id_world, pShapeItem );
	pShapeNode->mPtrRigidBody = pRB;
#if 0
	//### TODO убрать, всё позиционирование производится после загрузки всех форм (PostLoad)
	// сделано временно для визуализации (отладка)
	nsMathTools::TVector3 pos;
	GetPosition(pos);
	btTransform& trans = pShapeNode->mPtrRigidBody->getWorldTransform();
	btVector3& posBullet = trans.getOrigin();
	posBullet.setX(pos.x);
	posBullet.setY(pos.y);
	posBullet.setZ(pos.z);

	nsMathTools::TQuaternion orient;
	GetOrientation(orient);
	btQuaternion quat;
	quat.setX(orient.x);
	quat.setY(orient.y);
	quat.setZ(orient.z);
	quat.setW(orient.w);
	trans.setRotation(quat);

	pShapeNode->mPtrRigidBody->setWorldTransform(trans);

	//###
	pShapeNode->mPtrRigidBody->setLinearVelocity(btVector3(0,0,0));
	//pShapeDesc->pRigidBody->setAngularVelocity(btVector3(0,10,0));

	//btDiscreteDynamicsWorld* pWorld = 
	// TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(id_world);
	//###
#endif
}
//---------------------------------------------------------------------------
void TBuilder_Model_Bullet::PostBuild()
{
	// расположить части в соответствии с описанием внутри ModelItem
	TShapeNode_Model* pShapeNode = (TShapeNode_Model*)mPatternModel->mHierarchy.GetRoot();
	nsMathTools::TVector3 pos;
	mPatternModel->GetPosition(pos);
	btTransform& trans = pShapeNode->mPtrRigidBody->getWorldTransform();
	btVector3& posBullet = trans.getOrigin();
	posBullet.setX(pos.x);
	posBullet.setY(pos.y);
	posBullet.setZ(pos.z);

	nsMathTools::TQuaternion orient;
	mPatternModel->GetOrientation(orient);
	btQuaternion quat;
	quat.setX(orient.x);
	quat.setY(orient.y);
	quat.setZ(orient.z);
	quat.setW(orient.w);
	trans.setRotation(quat);

	pShapeNode->mPtrRigidBody->setWorldTransform(trans);

	btDiscreteDynamicsWorld* pWorld = 
		TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(mPatternModel->GetPhysicWorld());
	if( pWorld==NULL )
		return;
	if( pShapeNode->mPtrRigidBody->isInWorld() )
		pWorld->removeRigidBody(pShapeNode->mPtrRigidBody);


	// соединить части через крючки через constraint
}
//---------------------------------------------------------------------------