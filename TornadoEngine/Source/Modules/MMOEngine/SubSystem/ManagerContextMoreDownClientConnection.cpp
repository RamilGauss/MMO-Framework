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
bool TManagerContextMoreDownClientConnection::FindSessionByClientKey( unsigned int clientID, unsigned int &sessionID )
{
  TMapUintUintIt fit = mMapKeySession.find( clientID );
  if( fit == mMapKeySession.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextMoreDownClientConnection::FindSessionByClientKey(key=%u) not found.\n", clientID );
    return false;
  }
  sessionID = fit->second;
  return true;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::FindContextByClientKey( unsigned int clientID )
{
  TMapUintPtrIt fit = mMapKeyContext.find( clientID );
  if( fit == mMapKeyContext.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextMoreDownClientConnection::FindContextByClientKey(key=%u) not found.\n", clientID );
    return nullptr;
  }
  return fit->second;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::AddContext( unsigned int clientID, unsigned int sessionID )
{
  BL_ASSERT( sessionID != INVALID_HANDLE_SESSION );

  TContainerContextSc* pC = FindContextByClientKey( clientID );
  if( pC == nullptr )
  {
    pC = AddContainer();

    mMapKeyContext.insert( TMapUintPtr::value_type( clientID, pC ) );
    mMapKeySession.insert( TMapUintUint::value_type( clientID, sessionID ) );

    pC->SetSessionID( sessionID );
  }
  return pC;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::DeleteByKey( unsigned int key )
{
  TContainerContextSc* pC = FindContextByClientKey( key );
  if( pC == nullptr )
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
bool TManagerContextMoreDownClientConnection::SetSessionByClientKey( unsigned int clientID, unsigned int sessionID )
{
  TMapUintUintIt fit = mMapKeySession.find( clientID );
  if( fit == mMapKeySession.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerContextMoreDownClientConnection::SetSessionByClientKey(key=%u) not found.\n", clientID );
    return false;
  }
  fit->second = sessionID;
  // изменить номер сессии для всех контекстов
  TContainerContextSc* pC = FindContextByClientKey( clientID );
  if( pC )
    pC->SetSessionID( sessionID );

  return true;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::EntrustContext( unsigned int clientID, unsigned int sessionID, TContainerContextSc* pContext )
{
  BL_ASSERT( sessionID != INVALID_HANDLE_SESSION );

  mMapKeyContext.insert( TMapUintPtr::value_type( clientID, pContext ) );
  mMapKeySession.insert( TMapUintUint::value_type( clientID, sessionID ) );

  pContext->SetSessionID( sessionID );
}
//-------------------------------------------------------------------------
