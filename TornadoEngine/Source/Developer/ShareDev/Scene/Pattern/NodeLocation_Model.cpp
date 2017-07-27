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
	/*BOOST_FOREACH( TMapStrJointVT& vtNameJoint, mMapNameJoint )
	{
		TJoint* pJoint = &(vtNameJoint.second);
		// позиция нода рассчитывается с учётом крючков своих и родителя
		nsMathTools::TVector3 vResult;
		SetRotatePoint(&mGlobal.mOrient, &pJoint->mLocalRelativeNode.mPos, &vResult);

		pJoint->mGlobal.mPos    = mGlobal.mPos    + vResult;
		pJoint->mGlobal.mOrient = mGlobal.mOrient * pJoint->mLocalRelativeNode.mOrient;
	}*/
	BOOST_FOREACH( TMapStrJointVT& vtNameJoint, mMapNameJoint )
	{
		TJoint* pJoint = &(vtNameJoint.second);
		// позиция нода рассчитывается с учётом крючков своих и родителя
		nsMathTools::TVector3 vResult;
		SetVec3TransformCoord(&vResult, &pJoint->mLocalRelativeNode.mPos, &mGlobal.mOrient);

		pJoint->mGlobal.mPos    = mGlobal.mPos + vResult;
		// домножить на вращение относительно родителя
		pJoint->mGlobal.mOrient *= pJoint->mLocalRelativeNode.mOrient;
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
	nsMathTools::TMatrix16 qJointParentConnection = 
		pJointParent->mGlobal.mOrient * mOrientRelativeJointToJointParent;

	nsMathTools::TVector3 Up_JointParent(0,1,0);
	nsMathTools::TVector3 vUpRelativeJointParent(0,0,0);// локальные координаты вектора Вверх с учётом вращения

	nsMathTools::TVector3 Forward_JointParent(1,0,0);
	nsMathTools::TVector3 vForwardRelativeJointParent(0,0,0);// локальные координаты вектора Вперед с учётом вращения

	SetVec3TransformCoord(&vUpRelativeJointParent,     &Up_JointParent,     &qJointParentConnection);
	SetVec3TransformCoord(&vForwardRelativeJointParent,&Forward_JointParent,&qJointParentConnection);

	vForwardRelativeJointParent *= mDistanceRelativeJointToJointParent;// растягиваем до расстояния между крючками
	
	nsMathTools::TVector3 globalPosJointChild = 
		pJointParent->mGlobal.mPos + vForwardRelativeJointParent;

	// повернуть направление на 180 градусов, потому что нужно ориентироваться
	// относительно родителя, т.к. крючки смотрят друг на друга
	nsMathTools::TMatrix16 rotAboutUp;
	SetMatrixRotationAxis( &rotAboutUp, &vUpRelativeJointParent, float(M_PI));
	
	nsMathTools::TMatrix16 qJointChild = qJointParentConnection*rotAboutUp;

	mGlobal.mOrient = qJointChild*pMyJoint->mLocalRelativeNode.mOrient;

	nsMathTools::TVector3 MyJointRelativeChild;
	MyJointRelativeChild.x = -pMyJoint->mLocalRelativeNode.mPos.x;// обратный сдвиг порождает знак минуса
	MyJointRelativeChild.y = -pMyJoint->mLocalRelativeNode.mPos.y;// во всех осях
	MyJointRelativeChild.z = -pMyJoint->mLocalRelativeNode.mPos.z;// 

	nsMathTools::TVector3 posChildRelativeJoint;
	SetVec3TransformCoord(&posChildRelativeJoint, &MyJointRelativeChild, &mGlobal.mOrient);

	mGlobal.mPos = globalPosJointChild + posChildRelativeJoint;
/*
	// вращение крючка родителя с учетом параметров соединения
	nsMathTools::TQuaternion qJointParentConnection = 
		pJointParent->mGlobal.mOrient * mOrientRelativeJointToJointParent;

	float angleTemp = 0;
	nsMathTools::TVector3 Up_JointParent(0,1,0);
	nsMathTools::TVector3 vUpRelativeJointParent(0,0,0);// локальные координаты вектора Вверх с учётом вращения

	nsMathTools::TVector3 Forward_JointParent(1,0,0);
	nsMathTools::TVector3 vForwardRelativeJointParent(0,0,0);// локальные координаты вектора Вперед с учётом вращения

	SetRotatePoint(&qJointParentConnection, &Up_JointParent,      &vUpRelativeJointParent);
	SetRotatePoint(&qJointParentConnection, &Forward_JointParent, &vForwardRelativeJointParent);

	vForwardRelativeJointParent *= mDistanceRelativeJointToJointParent;// растягиваем до расстояния между крючками

	nsMathTools::TVector3 globalPosJointChild = 
		pJointParent->mGlobal.mPos + vForwardRelativeJointParent;

	// повернуть направление на 180 градусов, потому что нужно ориентироваться
	// относительно родителя, т.к. крючки смотрят друг на друга
	nsMathTools::TQuaternion rotAboutUp;
	SetQuaternionRotationAxis( &rotAboutUp, &vUpRelativeJointParent, float(M_PI*2));
	nsMathTools::TQuaternion qJointChild = qJointParentConnection*rotAboutUp;

	mGlobal.mOrient = qJointChild*pMyJoint->mLocalRelativeNode.mOrient;

	nsMathTools::TVector3 MyJointRelativeChild;
	MyJointRelativeChild.x = -pMyJoint->mLocalRelativeNode.mPos.x;// обратный сдвиг порождает знак минуса
	MyJointRelativeChild.y = -pMyJoint->mLocalRelativeNode.mPos.y;// во всех осях
	MyJointRelativeChild.z = -pMyJoint->mLocalRelativeNode.mPos.z;// 

	nsMathTools::TVector3 posChildRelativeJoint;
	SetRotatePoint(&mGlobal.mOrient, &MyJointRelativeChild, &posChildRelativeJoint);

	mGlobal.mPos = globalPosJointChild + posChildRelativeJoint;*/
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
void TestNodeLocation()
{	
#if 1
	// разбор конкретного случая
	TNodeLocation_Model parent, child;
	parent.name            = "Parent";
	parent.mGlobal.mPos    = nsMathTools::TVector3(0,0,0);
	nsMathTools::TVector3 axis_Z(0,0,1);
	SetMatrixRotationAxis(&parent.mGlobal.mOrient, &axis_Z, float(M_PI));// подготовка

	parent.AddJoint("0");
	TNodeLocation_Model::TJoint* pJointParent = parent.GetJoint("0");
	pJointParent->mLocalRelativeNode.mPos    = nsMathTools::TVector3(1,0,0);
	SetMatrixRotationAxis(&pJointParent->mLocalRelativeNode.mOrient, &axis_Z, 0);// подготовка

	parent.CalcGlobalJoint();

	child.name                = "Child";
	child.nameMyJointToParent = "0";
	child.nameJointParent     = "0";
	child.mDistanceRelativeJointToJointParent = 3;
	SetMatrixRotationAxis(&child.mOrientRelativeJointToJointParent, &axis_Z, 0);// подготовка

	child.AddJoint("0");
	TNodeLocation_Model::TJoint* pJointChild = child.GetJoint("0");
	pJointChild->mLocalRelativeNode.mPos    = nsMathTools::TVector3(1,0,0);
	SetMatrixRotationAxis(&pJointChild->mLocalRelativeNode.mOrient, &axis_Z, 0);// подготовка

	child.CalcGlobal(&parent);
	child.CalcGlobalJoint();
#endif
}
//--------------------------------------------------------------------
