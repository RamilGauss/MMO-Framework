/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModelItem.h"

TModelItem::TModelItem(std::string& name):
TBaseItem(name, TFactoryGameItem::Model)
{

}
//--------------------------------------------------------------------------------
TModelItem::TBranch::TBranch()
{

}
//--------------------------------------------------------------------------------
TModelItem::TBranch::TBranch(const TBranch& c)
{
  joint0 = c.joint0;
  joint1 = c.joint1;
  position = c.position;
  rotation = c.rotation;

  TBranch* pB = (TBranch*)&c;
  mPtrConstraint = pB->mPtrConstraint;
 }
//--------------------------------------------------------------------------------
TModelItem::TBranch::~TBranch()
{

}
//--------------------------------------------------------------------------------

