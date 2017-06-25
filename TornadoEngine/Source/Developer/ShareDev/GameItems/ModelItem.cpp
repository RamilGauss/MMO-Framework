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
TModelItem::TLocation::TLocation(const TLocation& c)
{
  nameBase    = c.nameBase;
  nameBranch  = c.nameBranch;
  position    = c.position;
  orientation = c.orientation;
  listLink    = c.listLink;
}
//--------------------------------------------------------------------------------
TModelItem::TLocation& TModelItem::TLocation::operator = (const TLocation& c)
{
  TLocation* pC = (TLocation*)&c;

  pC->nameBase    = nameBase;
  pC->nameBranch  = nameBranch;
  pC->position    = position;
  pC->orientation = orientation;
  pC->listLink    = listLink;

  return *this;
}
//--------------------------------------------------------------------------------
TModelItem::TLink::TLink(const TLink& c)
{
  nameJointBase   = c.nameJointBase;
  nameJointBranch = c.nameJointBranch;

  TLink* pLink = (TLink*)&c;
  mPtrConstraint = pLink->mPtrConstraint;
}
//--------------------------------------------------------------------------------
TModelItem::TLink& TModelItem::TLink::operator = (const TLink& c)
{
  TLink* pC = (TLink*)&c;

  pC->nameJointBase   = nameJointBase;
  pC->nameJointBranch = nameJointBranch;

  pC->mPtrConstraint = mPtrConstraint;
  return *this;
}
//--------------------------------------------------------------------------------
