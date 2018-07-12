/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HandlerMMO.h"
#include "BaseEvent.h"
#include "Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "ResolverSelf_IP_v4.h"
#include "Client.h"
#include <iostream>
#include <iomanip>
#include "BL_Debug.h"
#include <unordered_set>
#include <unordered_map>
#include "Logger.h"

typedef std::set<unsigned int> TSetUInt;

typedef std::unordered_map<THandlerMMO::TypeMMO, TSetUInt> TMapIntSetUInt;

static TMapIntSetUInt mID_ConnectionMap;
static TMapIntSetUInt mID_DisconnectionMap;

static TSetUInt mClientIDSet;

static TSetUInt mClient2Master_TryConnectSet;

THandlerMMO::THandlerMMO( TypeMMO type )
{
  mType = type;
  mID_ConnectionMap.insert( TMapIntSetUInt::value_type( mType, TSetUInt() ) );
  mID_DisconnectionMap.insert( TMapIntSetUInt::value_type( mType, TSetUInt() ) );
}
//-----------------------------------------------------------------------------------
void THandlerMMO::Work()
{
  nsEvent::TEvent* pEvent = GetEvent();
  while( pEvent )
  {
    // обработать событие
    HandleFromMMOEngine( pEvent );
    delete pEvent;
    pEvent = GetEvent();
  }
}
//-----------------------------------------------------------------------------------
auto THandlerMMO::GetCountConnection()
{
  return mID_ConnectionMap[mType].size();
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::RemoveConnection( unsigned int sessionID )
{
  // сбор статистики дисконнектов
  auto& disconnectSet = mID_DisconnectionMap[mType];
  auto disconnectIt = disconnectSet.find( sessionID );
  BL_ASSERT( disconnectIt == disconnectSet.end() );
  disconnectSet.insert( sessionID );

  // удалить соединение из статистики
  auto& connectSet = mID_ConnectionMap[mType];
  auto connectIt = connectSet.find( sessionID );
  BL_ASSERT( connectIt != connectSet.end() );
  connectSet.erase( sessionID );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::AddConnection( unsigned int sessionID )
{// добавить соединение в статистику
  auto& set = mID_ConnectionMap[mType];
  auto fit = set.find( sessionID );
  BL_ASSERT( fit == set.end() );
  set.insert( sessionID );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::PrintCC( const char* loggerName )
{
  char append[1000];
  std::string s = "CC = ";
  int i = 0;
  int lastIndex = mID_ConnectionMap.size() - 1;
  int summa = 0;
  for( auto& pair : mID_ConnectionMap )
  {
    summa += pair.second.size();
    sprintf( append, "%u", pair.second.size() );
    s += append;
    if( i != lastIndex )
      s += " + ";
    else
    {
      sprintf( append, " = %d", summa );
      s += append;
    }
    i++;
  }
  int clientCount = mClientIDSet.size();
  sprintf( append, ", clients = %d", clientCount );
  s += append;

  int tryConnectSize = mClient2Master_TryConnectSet.size();
  sprintf( append, ", try client = %d", tryConnectSize );
  s += append;

  s += "\n";

  GetLogger( loggerName )->WriteF( s.data() );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::AddClient( unsigned int clientID )
{
  auto fit = mClientIDSet.find( clientID );
  BL_ASSERT( fit == mClientIDSet.end() );
  mClientIDSet.insert( clientID );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::RemoveClient( unsigned int clientID )
{
  auto fit = mClientIDSet.find( clientID );
  BL_ASSERT( fit != mClientIDSet.end() );
  mClientIDSet.erase( clientID );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::AddTryConnectClientToMaster( unsigned int sessionID )
{
  auto fit = mClient2Master_TryConnectSet.find( sessionID );
  BL_ASSERT( fit == mClient2Master_TryConnectSet.end() );
  mClient2Master_TryConnectSet.insert( sessionID );
}
//---------------------------------------------------------------------------------------------
