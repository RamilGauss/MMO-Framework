/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>

#include "NodeLocation_Model.h"
#include <boost/foreach.hpp>
#include "BL_Debug.h"

TNodeLocation_Model::TNodeLocation_Model()
{

}
//---------------------------------------------------------------------------------
TNodeLocation_Model::~TNodeLocation_Model()
{
	ClearListLink();
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::AddJoint(std::string nameJoint)
{
	TJoint joint;
	joint.name = nameJoint;
	mMapNameJoint.insert(TMapStrJointVT(nameJoint,joint));
}
//---------------------------------------------------------------------------------
int TNodeLocation_Model::GetCountJoint()
{
	return mMapNameJoint.size();
}
//---------------------------------------------------------------------------------
TNodeLocation_Model::TJoint* TNodeLocation_Model::GetJoint(int index)
{
	if( index < 0 || 
		  index >= GetCountJoint() )
		return NULL;
	TMapStrJointIt bit = mMapNameJoint.begin();
	for(int i = 0 ; i < index ; i++ )
		bit++;
	return &(bit->second);
}
//---------------------------------------------------------------------------------
TNodeLocation_Model::TJoint* TNodeLocation_Model::GetJoint(std::string nameJoint)
{
	TMapStrJointIt fit = mMapNameJoint.find(nameJoint);
	if( fit==mMapNameJoint.end() )
		return NULL;
	return &(fit->second);
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::RemoveJoint(std::string nameJoint)
{
	mMapNameJoint.erase(nameJoint);
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::RemoveAllJoint()
{
	mMapNameJoint.clear();
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::ClearListLink()
{
	BOOST_FOREACH(TLink*& pLink, mListLink)
		delete pLink;
	mListLink.clear();
}
//---------------------------------------------------------------------------------
void TNodeLocation_Model::CalcGlobalJoint()
{
	BOOST_FOREACH( TMapStrJointVT& vtNameJoint, mMapNameJoint )
	{
		TJoint* pJoint = &(vtNameJoint.second);
		// позиция нода рассчитывается с учётом крючков своих и родителя
		nsMathTools::TQuaternion qPoint;
		qPoint.x = pJoint->mLocalRelativeNode.mPos.x;
		qPoint.y = pJoint->mLocalRelativeNode.mPos.y;
		qPoint.z = pJoint->mLocalRelativeNode.mPos.z;
		qPoint.w = 0;

		nsMathTools::TQuaternion qResult = qPoint*mGlobal.mOrient;

		nsMathTools::TVector3 vResult(0,0,0);
		float AngleResult = 0;
		SetQuaternionToAxisAngle(&qResult, &vResult, &AngleResult);

		pJoint->mGlobal.mPos    = mGlobal.mPos    + vResult;
		pJoint->mGlobal.mOrient = mGlobal.mOrient * pJoint->mLocalRelativeNode.mOrient;
	}
}
//---------------------------------------------------------------------------------
// по правилам математики поворот против часовой стрелки - положительный
void TNodeLocation_Model::CalcGlobal(TNodeLocation_Model* pNodeLocationParent)
{
	TJoint* pJointParent = pNodeLocationParent->GetJoint(nameJointParent);
	TJoint* pMyJoint     = GetJoint(nameMyJointToParent);
	if( pJointParent==NULL || pMyJoint==NULL )
	{
		BL_FIX_BUG();
		return;
	}

	// вращение крючка родителя с учетом параметров соединения
	nsMathTools::TQuaternion qJointParentConnection = 
		pJointParent->mGlobal.mOrient * mOrientRelativeJointToJointParent;
	
	nsMathTools::TQuaternion qUp_JointParent(0,1,0,0), qForward_JointParent(1,0,0,0);

	nsMathTools::TQuaternion qUpGlobal      = qUp_JointParent      * qJointParentConnection;
	nsMathTools::TQuaternion qForwardGlobal = qForward_JointParent * qJointParentConnection;

	nsMathTools::TVector3 vUpRelativeJointParent(0,0,0);// локальные координаты вектора Вверх с учётом вращения
	float angleTemp = 0;
	SetQuaternionToAxisAngle(&qUpGlobal, &vUpRelativeJointParent, &angleTemp);

	nsMathTools::TVector3 vForwardRelativeJointParent(0,0,0);// локальные координаты вектора Вперед с учётом вращения
	SetQuaternionToAxisAngle(&qForwardGlobal, &vForwardRelativeJointParent, &angleTemp);
	
	vForwardRelativeJointParent *= mDistanceRelativeJointToJointParent;// растягиваем до расстояния между крючками

	nsMathTools::TVector3 globalPosJointChild = 
		pJointParent->mGlobal.mPos + vForwardRelativeJointParent;

	nsMathTools::TQuaternion rotAboutUp;
	SetQuaternionRotationAxis( &rotAboutUp, &vUpRelativeJointParent, float(M_PI*2));
	nsMathTools::TQuaternion qJointChild = qJointParentConnection*rotAboutUp;

	mGlobal.mOrient = qJointChild*pMyJoint->mLocalRelativeNode.mOrient;

	nsMathTools::TQuaternion qMyJointRelativeChild;
	qMyJointRelativeChild.x = -pMyJoint->mLocalRelativeNode.mPos.x;// обратный сдвиг порождает знак минуса
	qMyJointRelativeChild.y = -pMyJoint->mLocalRelativeNode.mPos.y;// во всех осях
	qMyJointRelativeChild.z = -pMyJoint->mLocalRelativeNode.mPos.z;// 
	qMyJointRelativeChild.w = 0;

	nsMathTools::TQuaternion qMyJointGlobal = qMyJointRelativeChild*mGlobal.mOrient;

	nsMathTools::TVector3 posChildRelativeJoint;
	SetQuaternionToAxisAngle( &qMyJointGlobal, &posChildRelativeJoint, &angleTemp);
	mGlobal.mPos = globalPosJointChild + posChildRelativeJoint;
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
#if 0
void Test()
{	// разбор конкретного случая
	TNodeLocation_Model parent, child;
	parent.name            = "Parent";
	parent.mGlobal.mPos    = nsMathTools::TVector3(0,0,0);
	parent.mGlobal.mOrient = nsMathTools::TQuaternion(0,0,0,-1);
	parent.AddJoint("0");
	TNodeLocation_Model::TJoint* pJointParent = parent.GetJoint("0");
	pJointParent->mLocalRelativeNode.mPos    = nsMathTools::TVector3(1,0,0);
	pJointParent->mLocalRelativeNode.mOrient = nsMathTools::TQuaternion(0,0,0,1);

	parent.CalcGlobalJoint();

	child.name                = "Child";
	child.nameMyJointToParent = "0";
	child.nameJointParent     = "0";
	child.mDistanceRelativeJointToJointParent = 3;
	child.mOrientRelativeJointToJointParent   = nsMathTools::TQuaternion(0,0,0,1);

	child.AddJoint("0");
	TNodeLocation_Model::TJoint* pJointChild = child.GetJoint("0");
	pJointChild->mLocalRelativeNode.mPos    = nsMathTools::TVector3(1,0,0);
	pJointChild->mLocalRelativeNode.mOrient = nsMathTools::TQuaternion(0,0,0,1);

	child.CalcGlobal(&parent);
	child.CalcGlobalJoint();
}
#endif
//--------------------------------------------------------------------
