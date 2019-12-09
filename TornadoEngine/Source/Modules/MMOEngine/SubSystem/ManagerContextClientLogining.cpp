/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
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
bool TManagerContextClientLogining::FindSessionByClientKey( unsigned int clientKey, unsigned int& sessionID )
{
  const bmUintUint::right_iterator fit = mMapSessionKey.right.find( clientKey );
  if( fit == mMapSessionKey.right.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextClientLogining::FindSessionByClientKey(clientKey=%u) not found.\n", clientKey );
    return false;
  }
  sessionID = fit->second;
  return true;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindClientKeyBySession( unsigned int sessionID, unsigned int& clientKey )
{
  const bmUintUint::left_iterator fit = mMapSessionKey.left.find( sessionID );
  if( fit == mMapSessionKey.left.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextClientLogining::FindClientKeyBySession(session=%u) not found.\n", sessionID );
    return false;
  }
  clientKey = fit->second;
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
bool TManagerContextClientLogining::AddKeyBySession( unsigned int sessionID, unsigned int clientKey )
{
  if( FindContextBySession( sessionID ) == nullptr )
  {
    BL_FIX_BUG();
    return false;
  }

  mMapSessionKey.insert( bmUintUint::value_type( sessionID, clientKey ) );
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
