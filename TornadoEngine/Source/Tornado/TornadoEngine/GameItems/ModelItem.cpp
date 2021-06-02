/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModelItem.h"

TModelItem::TModelItem(std::string& name):
TBaseItem(name, TFactoryGameItem::Model)
{

}
//--------------------------------------------------------------------------------
TModelItem::TLocation::TLocation(const TLocation& c)
{
  nameBase        = c.nameBase;
  nameJointBase   = c.nameJointBase;
  nameBranch      = c.nameBranch;
  nameJointBranch = c.nameJointBranch;
  distance        = c.distance;
  orientation     = c.orientation;
  listLink        = c.listLink;
}
//--------------------------------------------------------------------------------
TModelItem::TLocation& TModelItem::TLocation::operator = (const TLocation& c)
{
  TLocation* pC = (TLocation*)&c;

  pC->nameBase        = nameBase;
  pC->nameJointBase   = nameJointBase;
  pC->nameBranch      = nameBranch;
  pC->nameJointBranch = nameJointBranch;
  pC->distance        = distance;
  pC->orientation     = orientation;
  pC->listLink        = listLink;

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
