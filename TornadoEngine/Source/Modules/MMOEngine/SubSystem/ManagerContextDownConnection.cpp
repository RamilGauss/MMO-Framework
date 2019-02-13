/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextDownConnection.h"

#include "Logger.h"
#include "ContainerContextSc.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;

TManagerContextDownConnection::TManagerContextDownConnection( TBase* pBase ) :
  TDelegateManagerContextSc( pBase )
{

}
//-----------------------------------------------------------------------------------
TManagerContextDownConnection::~TManagerContextDownConnection()
{
  Clear();
}
//-----------------------------------------------------------------------------------
TContainerContextSc* TManagerContextDownConnection::FindContextBySession( unsigned int sessionID )
{
  TMapUintPtrIt fit = mMapSessionContext.find( sessionID );
  if( fit == mMapSessionContext.end() )
  {
    //GetLogger( STR_NAME_MMO_ENGINE )->
    //  WriteF_time( "TManagerContextDownConnection::FindContextBySession(sessionID=%u) not found.\n", sessionID );
    return nullptr;
  }
  return fit->second;
}
//-----------------------------------------------------------------------------------
int TManagerContextDownConnection::GetCountSession()
{
  return mMapSessionContext.size();
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::GetSessionByIndex( int index, unsigned int& sessionID )
{
  if( GetCountSession() <= index )
    return false;
  TMapUintPtrIt it = mMapSessionContext.begin();
  for( int i = 0; i < index; i++ )
    it++;
  sessionID = it->first;
  return true;
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::GetCountClientKey( unsigned int sessionID, int &count )
{
  TMapUintSetUintIt fit = mMapSessionKey.find( sessionID );
  if( fit == mMapSessionKey.end() )
    return false;
  count = fit->second.size();
  return true;
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::GetClientKeyByIndex( unsigned int sessionID, int index, unsigned int& clientID )
{
  TMapUintSetUintIt fit = mMapSessionKey.find( sessionID );
  if( fit == mMapSessionKey.end() )
    return false;

  TSetUintIt it = fit->second.begin();
  int count;
  if( GetCountClientKey( sessionID, count ) == false )
    return false;
  if( count <= index )
    return false;
  for( int i = 0; i < index; i++ )
    it++;
  clientID = *it;
  return true;
}
//-----------------------------------------------------------------------------------
TContainerContextSc* TManagerContextDownConnection::AddContext( unsigned int sessionID )
{
  BL_ASSERT( sessionID != INVALID_HANDLE_SESSION );

  TContainerContextSc* pC = FindContextBySession( sessionID );
  if( pC == NULL )
  {
    pC = AddContainer();
    mMapSessionContext.insert( TMapUintPtr::value_type( sessionID, pC ) );
    mMapSessionKey.insert( TMapUintSetUint::value_type( sessionID, TSetUint() ) );

    AddSessionEvent( sessionID );
  }
  return pC;
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::AddClientKey( unsigned int sessionID, unsigned int clientID )
{
  // проверка на существование такого мастера
  TContainerContextSc* pC = FindContextBySession( sessionID );
  if( pC == NULL )
    return false;

  TMapUintSetUintIt fit = mMapSessionKey.find( sessionID );
  // создать
  if( fit == mMapSessionKey.end() )
  {
    //mMapSessionKey.insert(TMapUintSetUint::value_type(sessionID,TSetUint()));
    //fit = mMapSessionKey.find(sessionID);
    BL_FIX_BUG();
  }

  fit->second.insert( TSetUint::value_type( clientID ) );
  return true;
}
//-----------------------------------------------------------------------------------
void TManagerContextDownConnection::DeleteByClientKey( unsigned int sessionID, unsigned int clientID )
{
  TMapUintSetUintIt fit = mMapSessionKey.find( sessionID );
  if( fit == mMapSessionKey.end() )
    return;
  fit->second.erase( clientID );
}
//-----------------------------------------------------------------------------------
void TManagerContextDownConnection::DeleteContextBySession( unsigned int sessionID )
{
  TContainerContextSc* pC = FindContextBySession( sessionID );
  if( pC == NULL )
    return;

  DeleteContainer( pC );
  mMapSessionContext.erase( sessionID );
  mMapSessionKey.erase( sessionID );

  DeleteSessionEvent( sessionID );
}
//-----------------------------------------------------------------------------------
void TManagerContextDownConnection::Clear()
{
  for( auto& it : mMapSessionContext )
    DeleteContainer( it.second );

  mMapSessionKey.clear();
  mMapSessionContext.clear();
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::FindSessionByClientKey( unsigned int clientID, unsigned int &id_session_slave )
{
  for( auto& it : mMapSessionKey )
  {
    TSetUintIt fit = it.second.find( clientID );
    if( fit != it.second.end() )
    {
      id_session_slave = it.first;
      return true;
    }
  }
  return false;
}
//-----------------------------------------------------------------------------------
