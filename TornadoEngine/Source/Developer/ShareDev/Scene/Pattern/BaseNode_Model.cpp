/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>

#include "BaseNode_Model.h"

TBaseNode_Model::TBaseNode_Model()
{

}
//---------------------------------------------------------------
TBaseNode_Model::~TBaseNode_Model()
{

}
//---------------------------------------------------------------
void TBaseNode_Model::CalcGlobal(TLocation& globalParent)
{
	// позиция нода рассчитываются как сумма позиции родителя и рассчитанной локальной позиции нода с учетом
	// вращения родителя
	nsMathTools::TQuaternion qPoint;
	qPoint.x = mLocal.mPos.x;
	qPoint.y = mLocal.mPos.y;
	qPoint.z = mLocal.mPos.z;
	qPoint.w = 0;

	nsMathTools::TQuaternion qResult = qPoint*globalParent.mOrient;

	nsMathTools::TVector3 vResult(0,0,0);
	float AngleResult = 0;
	SetQuaternionToAxisAngle(&qResult, &vResult, &AngleResult);

	mGlobal.mPos    = globalParent.mPos    + vResult;
	mGlobal.mOrient = globalParent.mOrient * mLocal.mOrient;//???
}
//---------------------------------------------------------------------------
