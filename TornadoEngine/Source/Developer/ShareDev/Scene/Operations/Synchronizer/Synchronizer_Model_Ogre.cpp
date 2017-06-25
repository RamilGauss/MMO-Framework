/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Synchronizer_Model_Ogre.h"
#include "Pattern_Model.h"
#include "ShapeNode_Model.h"
#include "ModelNode_Model.h"
#include "ModuleGraphicEngine.h"

TSynchronizer_Model_Ogre::TSynchronizer_Model_Ogre()
{

}
//-----------------------------------------------------------------------------
void TSynchronizer_Model_Ogre::Synchro()
{
	// синхронизируем всё!
	int cntPart = mPatternModel->mHierarchy.GetCount();
	for( int iPart = 0 ; iPart < cntPart ; iPart++ )
	{
		TBaseNode_Model* pNode = mPatternModel->mHierarchy.Get(iPart);
		if( pNode==NULL )
			continue;
		if( pNode->type==TModelItem::eModel )
		{
			TModelNode_Model* pModelNode = (TModelNode_Model*)pNode;
			pModelNode->mPtrModel->SynchroByModule_Graphic();
		}
		else
		{
			TShapeNode_Model* pShapeNode = (TShapeNode_Model*)pNode;

			btTransform& trans = pShapeNode->mPtrRigidBody->getWorldTransform();//###
			btVector3& posBullet = trans.getOrigin();

			Ogre::Entity* pEntity = pShapeNode->mPtrEntity;

			Ogre::Vector3 posOgre;
			posOgre.x = posBullet.x();
			posOgre.y = posBullet.y();
			posOgre.z = posBullet.z();
			pEntity->getParentSceneNode()->setPosition(posOgre);

			btQuaternion quat = trans.getRotation();
			Ogre::Real w = quat.w(); 
			Ogre::Real x = quat.x(); 
			Ogre::Real y = quat.y();
			Ogre::Real z = quat.z();
			pEntity->getParentSceneNode()->setOrientation( w, x, y, z);
		}
	}
}
//---------------------------------------------------------------------------
