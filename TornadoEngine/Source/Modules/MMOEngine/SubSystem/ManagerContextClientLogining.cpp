/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextClientLogining.h"

#include "Logger.h"
#include "ContainerContextSc.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;

TManagerContextClientLogining::TManagerContextClientLogining( TBase* pBase ) :
  TDelegateManagerContextSc( pBase )
{

}
//-------------------------------------------------------------------------------------------
TManagerContextClientLogining::~TManagerContextClientLogining()
{
  Clear();
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindSessionByClientKey( unsigned int clientID, unsigned int& sessionID )
{
  const bmUintUint::right_iterator fit = mMapSessionKey.right.find( clientID );
  if( fit == mMapSessionKey.right.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextClientLogining::FindSessionByClientKey(clientID=%u) not found.\n", clientID );
    return false;
  }
  sessionID = fit->second;
  return true;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindClientKeyBySession( unsigned int sessionID, unsigned int& clientID )
{
  const bmUintUint::left_iterator fit = mMapSessionKey.left.find( sessionID );
  if( fit == mMapSessionKey.left.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextClientLogining::FindClientKeyBySession(session=%u) not found.\n", sessionID );
    return false;
  }
  clientID = fit->second;
  return true;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TManagerContextClientLogining::FindContextBySession( unsigned int sessionID )
{
  TMapUintPtrIt fit = mMapSessionContext.find( sessionID );
  if( fit == mMapSessionContext.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextClientLogining::FindContextBySession(session=%u) not found.\n", sessionID );
    return nullptr;
  }
  return fit->second;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TManagerContextClientLogining::AddContext( unsigned int sessionID )
{
  BL_ASSERT( sessionID != INVALID_HANDLE_SESSION );

  TContainerContextSc* pC = FindContextBySession( sessionID );
  if( pC == nullptr )
  {
    pC = AddContainer();
    mMapSessionContext.insert( TMapUintPtr::value_type( sessionID, pC ) );
  }
  return pC;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::AddKeyBySession( unsigned int sessionID, unsigned int clientID )
{
  if( FindContextBySession( sessionID ) == nullptr )
  {
    BL_FIX_BUG();
    return false;
  }

  mMapSessionKey.insert( bmUintUint::value_type( sessionID, clientID ) );
  return true;
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::DeleteBySession( unsigned int sessionID )
{
  TContainerContextSc* pC = FindContextBySession( sessionID );
  if( pC == nullptr )
    return;

  DeleteContainer( pC );
  mMapSessionContext.erase( sessionID );
  mMapSessionKey.left.erase( sessionID );
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::Clear()
{
  for( auto& bit : mMapSessionContext )
    DeleteContainer( bit.second );

  mMapSessionContext.clear();
  mMapSessionKey.clear();
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::UnlinkContextBySession( unsigned int sessionID )
{
  TContainerContextSc* pC = FindContextBySession( sessionID );
  if( pC == nullptr )
    return;

  mMapSessionContext.erase( sessionID );
  mMapSessionKey.left.erase( sessionID );
}
//-------------------------------------------------------------------------------------------
