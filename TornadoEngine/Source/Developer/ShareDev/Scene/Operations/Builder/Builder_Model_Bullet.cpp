/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
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
  mWorld = TModuleLogic::Get()->GetC()->pPhysicEngine->GetPE()->GetWorld(mPatternModel->GetPhysicWorld());
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
        pModelNode->mPtrModel->BuildByModule_Physic();// RANK
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
  TShapeItem* pShapeItem = (TShapeItem*)mFGI->Get(TFactoryGameItem::Shape,pShapeNode->nameShapeItem);
  if( pShapeItem==NULL )
    return;

  btRigidBody* pRB = GetShapeMaker()->Build( mPatternModel->GetPhysicWorld(), pShapeItem );
  pShapeNode->mPtrRigidBody = pRB;
}
//---------------------------------------------------------------------------
void TBuilder_Model_Bullet::PostBuild()
{
  if( mPatternModel->GetTypeContent()==TModelItem::eShape )
    PostBuild_Shape();
  else
    PostBuild_Model();
}
//---------------------------------------------------------------------------
void TBuilder_Model_Bullet::PostBuild_Shape()
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
void TBuilder_Model_Bullet::SetLocation_Shape(TShapeNode_Model* pNode)
{
  mWorld->addRigidBody(pNode->mPtrRigidBody);
  TNodeLocation_Model* pNodeLocation = mPatternModel->mMngNodeLocation.Get(pNode->namePart);

  // позиционирование
  btTransform& trans = pNode->mPtrRigidBody->getWorldTransform();
  btVector3& posBullet = trans.getOrigin();
  posBullet.setX(pNodeLocation->mGlobal.mPos.x);
  posBullet.setY(pNodeLocation->mGlobal.mPos.y);
  posBullet.setZ(pNodeLocation->mGlobal.mPos.z);

  // по непонятным мне причинам Bullet и Ogre умножают угол вращения кватерниона на 2. Why?
  nsMathTools::TMatrix16* m = &(pNodeLocation->mGlobal.mOrient);
  btMatrix3x3 btM3x3;
  //btM3x3.setValue(
  //  m->m[0][0], m->m[0][1], m->m[0][2], 
  //  m->m[1][0], m->m[1][1], m->m[1][2],
  //  m->m[2][0], m->m[2][1], m->m[2][2]);
  btM3x3.setValue(
    m->m(0,0), m->m(1,0), m->m(2,0), 
    m->m(0,1), m->m(1,1), m->m(2,1),
    m->m(0,2), m->m(1,2), m->m(2,2));
  trans.setBasis(btM3x3);

  pNode->mPtrRigidBody->setWorldTransform(trans);

  //### future features
  //pShapeNode->mPtrRigidBody->setLinearVelocity(btVector3(0,0,0)); 
  //pShapeDesc->pRigidBody->setAngularVelocity(btVector3(0,10,0));
  //### future features

  // соединить части через крючки через constraint
  int cntPart = mPatternModel->mHierarchy.GetCountChild(pNode->namePart);
  for( int iPart = 0 ; iPart < cntPart ; iPart++ )
  {
    TShapeNode_Model* pNodeChild = 
      (TShapeNode_Model*)mPatternModel->mHierarchy.GetChild(pNode->namePart,iPart);
    if( pNodeChild==NULL )
      continue;
    SetLocation_Shape(pNodeChild);

    // установить констрейнты между телами
    //SetConstraint(pNode->mPtrRigidBody,pNodeChild->mPtrRigidBody);
  }
}
//---------------------------------------------------------------------------
void TBuilder_Model_Bullet::PostBuild_Model()
{
  TModelNode_Model* pRoot = (TModelNode_Model*)mPatternModel->mHierarchy.GetRoot();
  if( pRoot==NULL )
  {
    BL_FIX_BUG();
    return;
  }
  // соединить части через крючки через constraint

}
//---------------------------------------------------------------------------