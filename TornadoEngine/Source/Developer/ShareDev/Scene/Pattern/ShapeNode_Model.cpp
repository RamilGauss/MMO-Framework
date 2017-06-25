/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ShapeNode_Model.h"

TShapeNode_Model::TShapeNode_Model()
{
	type = TModelItem::eShape;
	mPtrEntity    = NULL;
	mPtrRigidBody = NULL;
}
//---------------------------------------------------------------
TShapeNode_Model::~TShapeNode_Model()
{

}
//---------------------------------------------------------------
