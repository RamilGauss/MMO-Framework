/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SetOrderElement.h"
#include "BL_Debug.h"

#include <algorithm>
#include <search.h>

using namespace std;

//-------------------------------------------------------------------------------------
void TSetOrderElement::PushBack( unsigned int key, ContentType type )
{
  mNextAddInnerID++;
  switch ( type )
  {
    case TSetOrderElement::InGroup:
      mInGroup.PushBack( key, mNextAddInnerID );
      break;
    case TSetOrderElement::Simple:
      mSimple.PushBack( key, mNextAddInnerID );
      break;
  }
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::RemoveFirst()
{
  auto p = GetFirstViaID();
  if ( p == nullptr )
    return;
  p->RemoveFirst();
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::RemoveByKey( unsigned int key )
{
  mSimple.RemoveByKey( key );
  mInGroup.RemoveByKey( key );
}
//-------------------------------------------------------------------------------------
bool TSetOrderElement::GetFirst( unsigned int& key, ContentType type )
{
  switch ( type )
  {
    case TSetOrderElement::InGroup:
      return mInGroup.GetFirst( key );
    case TSetOrderElement::Simple:
      return mSimple.GetFirst( key );
  }
  return false;
}
//-------------------------------------------------------------------------------------
bool TSetOrderElement::GetIndex( unsigned int key, int& index )
{
  if ( mSimple.GetIndex( key, index ) == false )
    return mInGroup.GetIndex( key, index );
  return true;
}
//-------------------------------------------------------------------------------------
void TSetOrderElement::MoveToSimple( unsigned int key )
{
  unsigned int ID;
  if ( mInGroup.FindIDByKey( key, ID ) == false )
    return;
  mInGroup.RemoveByKey( key );
  mSimple.Insert( key, ID );
}
//-------------------------------------------------------------------------------------
TSortedVecWithKeyMap* TSetOrderElement::GetFirstViaID()
{
  auto simpleCount = mSimple.GetSize();
  auto inGroupCount = mInGroup.GetSize();

  if ( simpleCount == 0 &&
    inGroupCount == 0 )
    return nullptr;

  if ( simpleCount == 0 )
    return &mInGroup;
  if ( inGroupCount == 0 )
    return &mSimple;

  auto inGroupID = mInGroup.GetFirstID();
  auto simpleID = mSimple.GetFirstID();
  if ( inGroupID > simpleID )
    return &mSimple;
  return &mInGroup;
}
//-------------------------------------------------------------------------------------
