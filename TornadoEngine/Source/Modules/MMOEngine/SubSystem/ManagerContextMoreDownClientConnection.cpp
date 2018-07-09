/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextMoreDownClientConnection.h"

#include "Logger.h"
#include "ContainerContextSc.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;
using namespace std;

TManagerContextMoreDownClientConnection::TManagerContextMoreDownClientConnection( TBase* pBase ) :
  TDelegateManagerContextSc( pBase )
{

}
//-------------------------------------------------------------------------
TManagerContextMoreDownClientConnection::~TManagerContextMoreDownClientConnection()
{
  Clear();
}
//-------------------------------------------------------------------------
bool TManagerContextMoreDownClientConnection::FindSessionByClientKey( unsigned int id_client,
  unsigned int &sessionID )
{
  TMapUintUintIt fit = mMapKeySession.find( id_client );
  if( fit == mMapKeySession.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextMoreDownClientConnection::FindSessionByClientKey(key=%u) not found.\n", id_client );
    return false;
  }
  sessionID = fit->second;
  return true;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::FindContextByClientKey( unsigned int id_client )
{
  TMapUintPtrIt fit = mMapKeyContext.find( id_client );
  if( fit == mMapKeyContext.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextMoreDownClientConnection::FindContextByClientKey(key=%u) not found.\n", id_client );
    return NULL;
  }
  return fit->second;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::AddContext( unsigned int id_client,
  unsigned int sessionID )
{
  BL_ASSERT( sessionID != INVALID_HANDLE_SESSION );

  TContainerContextSc* pC = FindContextByClientKey( id_client );
  if( pC == NULL )
  {
    pC = AddContainer();

    mMapKeyContext.insert( TMapUintPtr::value_type( id_client, pC ) );
    mMapKeySession.insert( TMapUintUint::value_type( id_client, sessionID ) );

    pC->SetSessionID( sessionID );
  }
  return pC;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::DeleteByKey( unsigned int key )
{
  TContainerContextSc* pC = FindContextByClientKey( key );
  if( pC == NULL )
    return;

  DeleteContainer( pC );
  mMapKeyContext.erase( key );
  mMapKeySession.erase( key );
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::Clear()
{
  for( auto& bit : mMapKeyContext )
    DeleteContainer( bit.second );

  mMapKeyContext.clear();
  mMapKeySession.clear();
}
//-------------------------------------------------------------------------
bool TManagerContextMoreDownClientConnection::SetSessionByClientKey( unsigned int id_client,
  unsigned int sessionID )
{
  TMapUintUintIt fit = mMapKeySession.find( id_client );
  if( fit == mMapKeySession.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextMoreDownClientConnection::SetSessionByClientKey(key=%u) not found.\n", id_client );
    return false;
  }
  fit->second = sessionID;
  // изменить номер сессии для всех контекстов
  TContainerContextSc* pC = FindContextByClientKey( id_client );
  if( pC )
    pC->SetSessionID( sessionID );

  return true;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::EntrustContext( unsigned int id_client,
  unsigned int sessionID,
  TContainerContextSc* pContext )
{
  BL_ASSERT( sessionID != INVALID_HANDLE_SESSION );

  mMapKeyContext.insert( TMapUintPtr::value_type( id_client, pContext ) );
  mMapKeySession.insert( TMapUintUint::value_type( id_client, sessionID ) );

  pContext->SetSessionID( sessionID );
}
//-------------------------------------------------------------------------
