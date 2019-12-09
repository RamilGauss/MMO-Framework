/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Synchronizer_Model_Bullet.h"
#include "Pattern_Model.h"
#include "ShapeNode_Model.h"
#include "ModelNode_Model.h"
#include "ModuleGraphicEngine.h"

TSynchronizer_Model_Bullet::TSynchronizer_Model_Bullet()
{

}
//-----------------------------------------------------------------------------
void TSynchronizer_Model_Bullet::Synchro()
{
  // проверка на изменение позиции и ориентации
  int cntPart = mPatternModel->mHierarchy.GetCount();
  for( int iPart = 0 ; iPart < cntPart ; iPart++ )
  {
    TBaseNode_Model* pNode = mPatternModel->mHierarchy.Get(iPart);
    if( pNode==NULL )
      continue;
    if( pNode->type==TModelItem::eShape )
    {
      TShapeNode_Model* pShapeNode = (TShapeNode_Model*)pNode;

      const btVector3& velocity = pShapeNode->mPtrRigidBody->getLinearVelocity();
      float speed = velocity.length();
      if( speed > 15.0f )
      {
        int a = 0;
      }
    }
  }
}
//---------------------------------------------------------------------------
