/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NodeLocation_Model.h"
#include <boost/foreach.hpp>

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
void TNodeLocation_Model::CalcGlobal(TNodeLocation_Model* pNodeLocationParent)
{

}
//---------------------------------------------------------------------------------
