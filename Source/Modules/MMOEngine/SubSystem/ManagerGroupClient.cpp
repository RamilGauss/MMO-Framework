/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ManagerGroupClient.h"

#include "Logger.h"
#include "EnumMMO.h"
#include <list>

using namespace nsMMOEngine;
using namespace std;

TManagerGroupClient::TManagerGroupClient()
{
  mNextID_createGroup = 0;
}
//------------------------------------------------------------------------------------
TManagerGroupClient::~TManagerGroupClient()
{

}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::FindSessionByID( unsigned int groupID,
  unsigned int& sessionID )
{
  TMapUintUintIt fit = mMapID_SlaveSession.find( groupID );
  if( fit == mMapID_SlaveSession.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerGroupClient::FindSessionByID(groupID=%u) not found.\n", groupID );
    return false;
  }
  sessionID = fit->second;
  return true;
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::FindIDByClientKey( unsigned int clientKey, unsigned int& groupID )
{
  TMapUintUintIt fit = mMapClientKey_ID.find( clientKey );
  if( fit == mMapClientKey_ID.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerGroupClient::FindIDByClientKey(clientKey=%u) not found.\n", clientKey );
    return false;
  }
  groupID = fit->second;
  return true;
}
//------------------------------------------------------------------------------------
int TManagerGroupClient::GetCountID()
{
  return mMapID_SlaveSession.size();
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::GetIDByIndex( int index, unsigned int& groupID )
{
  if( GetCountID() <= index )
    return false;
  TMapUintUintIt it = mMapID_SlaveSession.begin();
  for( int i = 0; i < index; i++ )
    it++;
  groupID = it->first;
  return true;
}
//------------------------------------------------------------------------------------
int TManagerGroupClient::GetCountClientKey( unsigned int groupID )
{
  TMapUintSetUintIt fit = mMapID_ClientKey.find( groupID );
  if( fit == mMapID_ClientKey.end() )
    return 0;
  return fit->second.size();
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::GetClientKeyByIndex( unsigned int groupID, int index, unsigned int& clientKey )
{
  TMapUintSetUintIt fit = mMapID_ClientKey.find( groupID );
  if( fit == mMapID_ClientKey.end() )
    return false;

  TSetUintIt it = fit->second.begin();
  if( GetCountClientKey( groupID ) <= index )
    return false;
  for( int i = 0; i < index; i++ )
    it++;
  clientKey = *it;
  return true;
}
//------------------------------------------------------------------------------------
unsigned int TManagerGroupClient::AddGroup( unsigned int sessionID )
{
  mNextID_createGroup++;
  AddGroup( mNextID_createGroup, sessionID );
  return mNextID_createGroup;
}
//------------------------------------------------------------------------------------
void TManagerGroupClient::AddGroup( unsigned int groupID, unsigned int sessionID )
{
  mMapID_SlaveSession.insert( TMapUintUint::value_type( groupID, sessionID ) );
  mMapID_ClientKey.insert( TMapUintSetUint::value_type( groupID, TSetUint() ) );
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::AddClientKey( unsigned int groupID, unsigned int clientKey )
{
  TMapUintSetUintIt fit = mMapID_ClientKey.find( groupID );
  if( fit == mMapID_ClientKey.end() )
    return false;
  fit->second.insert( clientKey );

  mMapClientKey_ID.insert( TMapUintUint::value_type( clientKey, groupID ) );
  return true;
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::SetSessionByID( unsigned int groupID, unsigned int sessionID )
{
  TMapUintUintIt fit = mMapID_SlaveSession.find( groupID );
  if( fit == mMapID_SlaveSession.end() )
  {
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TManagerGroupClient::SetSessionByID(groupID=%u) not found.\n", groupID );
    return false;
  }
  fit->second = sessionID;
  return false;
}
//------------------------------------------------------------------------------------
void TManagerGroupClient::DeleteClientKey( unsigned int clientKey )
{
  unsigned int groupID;
  if( FindIDByClientKey( clientKey, groupID ) == false )
    return;
  TMapUintSetUintIt fit = mMapID_ClientKey.find( groupID );
  if( fit == mMapID_ClientKey.end() )
    return;
  // связка группа---множество клиентов
  fit->second.erase( clientKey );
  // связка клиента---группа
  mMapClientKey_ID.erase( clientKey );
}
//------------------------------------------------------------------------------------
void TManagerGroupClient::DeleteByID( unsigned int groupID )
{
  list<unsigned int> listClientOnErase;
  // поиск всех клиентов, связанных с данной группой
  int countClient = GetCountClientKey( groupID );
  // сформировать список ключей клиентов, которые содержаться в данной группе
  for( int i = 0; i < countClient; i++ )
  {
    unsigned int clientKey;
    GetClientKeyByIndex( groupID, i, clientKey );
    listClientOnErase.push_back( clientKey );
  }
  // удалить все упоминания о ключах
  for( unsigned int clientKey : listClientOnErase )
    DeleteClientKey( clientKey );
  // группа---сессия Slave
  mMapID_SlaveSession.erase( groupID );
}
//------------------------------------------------------------------------------------
