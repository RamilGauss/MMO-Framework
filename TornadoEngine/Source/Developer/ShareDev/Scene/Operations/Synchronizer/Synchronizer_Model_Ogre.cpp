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

			nsMathTools::TQuaternion q;
			nsMathTools::TMatrix16 m;
			btMatrix3x3 btM = trans.getBasis();
			btVector3 row = btM.getRow(0);
			m.m[0][0] = row.x();
			m.m[0][1] = row.y();
			m.m[0][2] = row.z();
			row = btM.getRow(1);
			m.m[1][0] = row.x();
			m.m[1][1] = row.y();
			m.m[1][2] = row.z();
			row = btM.getRow(2);
			m.m[2][0] = row.x();
			m.m[2][1] = row.y();
			m.m[2][2] = row.z();
			SetMatrixToQuaternion(&m, &q);

			btQuaternion quat;
			btM.getRotation(quat);

			Ogre::Entity* pEntity = pShapeNode->mPtrEntity;

			Ogre::Vector3 posOgre;
			posOgre.x = posBullet.x();
			posOgre.y = posBullet.y();
			posOgre.z = posBullet.z();
			pEntity->getParentSceneNode()->setPosition(posOgre);

			//btQuaternion quat = trans.getRotation();
			Ogre::Real w = -q.w; 
			Ogre::Real x = q.x; 
			Ogre::Real y = q.y;
			Ogre::Real z = q.z;
			pEntity->getParentSceneNode()->setOrientation( w, x, y, z);
		}
	}
}
//---------------------------------------------------------------------------
