/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "HandlerMMO.h"
#include "MMOEngine/include/BaseEvent.h"
#include "MMOEngine/include/Client.h"
#include "MMOEngine/include/Slave.h"
#include "MMOEngine/include/Events.h"
#include <boost/asio/ip/impl/address_v4.ipp>
#include "CommonParam.h"
#include "ResolverSelf_IP_v4.h"
#include <iostream>
#include <iomanip>
#include "BL_Debug.h"
#include "Logger.h"

static THandlerMMO::TMapUIntPtr g_ID_MMO_HandlerPtr;

static THandlerMMO::TMapTypeMMOSetUInt g_Type_IDMap;// тип сервера - множество серверов

static THandlerMMO::TMapUIntSetUInt g_ID_ConnectionMap;
static THandlerMMO::TMapUIntSetUInt g_ID_DisconnectionMap;

static THandlerMMO::TSetUInt g_ClientKeySet;

static THandlerMMO::TSetUInt g_Client2Master_TryConnectSet;

static unsigned int g_LastID = 0;

THandlerMMO::THandlerMMO( nsMMOEngine::TBase* pBase, TypeMMO type )
{
  mBase = pBase;

  mID = ++g_LastID;
  mType = type;

  g_ID_MMO_HandlerPtr.insert( TMapUIntPtr::value_type( mID, this ) );

  g_ID_ConnectionMap.insert( TMapUIntSetUInt::value_type( mID, TSetUInt() ) );
  g_ID_DisconnectionMap.insert( TMapUIntSetUInt::value_type( mID, TSetUInt() ) );

  auto fit = g_Type_IDMap.find( mType );
  if( fit == g_Type_IDMap.end() )
  {
    g_Type_IDMap.insert( TMapTypeMMOSetUInt::value_type( mType, TSetUInt() ) );
    fit = g_Type_IDMap.find( mType );
  }
  fit->second.insert( mID );
}
//-----------------------------------------------------------------------------------
void THandlerMMO::Work()
{
  int count = 0;

  nsEvent::TEvent* pEvent = GetEvent();
  while( pEvent )
  {
    // обработать событие
    HandleFromMMOEngine( pEvent );
    delete pEvent;
    pEvent = GetEvent();

    count++;
  }

  WorkInherit();
}
//-----------------------------------------------------------------------------------
int THandlerMMO::GetCountConnection( TypeMMO type )
{
  auto fit = g_Type_IDMap.find( type );
  if( fit == g_Type_IDMap.end() )
    return 0;
  int count = 0;
  auto idSet = fit->second;
  for( auto id : idSet )
  {
    auto connSet = g_ID_ConnectionMap[id];
    count += connSet.size();
  }
  return count;
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::RemoveConnection( unsigned int sessionID )
{
  // сбор статистики дисконнектов
  auto& disconnectSet = g_ID_DisconnectionMap[mID];
  auto disconnectIt = disconnectSet.find( sessionID );
  BL_ASSERT( disconnectIt == disconnectSet.end() );
  disconnectSet.insert( sessionID );

  // удалить соединение из статистики
  auto& connectSet = g_ID_ConnectionMap[mID];
  auto connectIt = connectSet.find( sessionID );
  BL_ASSERT( connectIt != connectSet.end() );
  connectSet.erase( sessionID );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::AddConnection( unsigned int sessionID )
{// добавить соединение в статистику
  auto& set = g_ID_ConnectionMap[mID];
  auto fit = set.find( sessionID );
  BL_ASSERT( fit == set.end() );
  set.insert( sessionID );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::PrintCC( const char* loggerName )
{
  char append[1000];
  std::string s = "CC = ";
  int iType = 0;
  int typeCount = g_Type_IDMap.size();
  int connectionSumma = 0;
  for( auto pairType_ID : g_Type_IDMap )
  {
    auto type = pairType_ID.first;
    auto id = pairType_ID.second;
    int connectionCount = GetCountConnection( type );
    connectionSumma += connectionCount;
    if( type == eSlave )
    {
      s += ToString( type ) + "{";
      auto slaveID_Set = g_Type_IDMap[type];
      int iSlave = 0;
      int slaveCount = slaveID_Set.size();
      for( auto slaveID : slaveID_Set )
      {
        auto pHandler = g_ID_MMO_HandlerPtr[slaveID];
        auto pSlave = (nsMMOEngine::TSlave*)(pHandler->GetBase());
        std::list<unsigned int> sessionID_List;
        pSlave->GetDescDown( sessionID_List );
        if( iSlave == slaveCount - 1 )
          sprintf( append, "%d", sessionID_List.size() );
        else
          sprintf( append, "%d, ", sessionID_List.size() );
        s += append;
        iSlave++;
      }
      sprintf( append, "}(%u)", connectionCount );
      s += append;
    }
    else
    {
      sprintf( append, "%s(%u)", ToString( type ).data(), connectionCount );
      s += append;
    }
    if( iType != typeCount - 1 )
      s += " + ";
    else
    {
      sprintf( append, " = %d", connectionSumma );
      s += append;
    }
    iType++;
  }
  int clientCount = g_ClientKeySet.size();
  sprintf( append, ", clients = %d", clientCount );
  s += append;

  int tryConnectSize = g_Client2Master_TryConnectSet.size();
  sprintf( append, ", try client = %d", tryConnectSize );
  s += append;

  s += "\n";

  GetLogger( loggerName )->WriteF( s.data() );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::AddClient( unsigned int clientKey )
{
  auto fit = g_ClientKeySet.find( clientKey );
  BL_ASSERT( fit == g_ClientKeySet.end() );
  g_ClientKeySet.insert( clientKey );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::RemoveClient( unsigned int clientKey )
{
  auto fit = g_ClientKeySet.find( clientKey );
  BL_ASSERT( fit != g_ClientKeySet.end() );
  g_ClientKeySet.erase( clientKey );
}
//---------------------------------------------------------------------------------------------
void THandlerMMO::AddTryConnectClientToMaster( unsigned int sessionID )
{
  auto fit = g_Client2Master_TryConnectSet.find( sessionID );
  BL_ASSERT( fit == g_Client2Master_TryConnectSet.end() );
  g_Client2Master_TryConnectSet.insert( sessionID );
}
//---------------------------------------------------------------------------------------------
std::string THandlerMMO::ToString( TypeMMO type )
{
  auto s = "";
  switch( type )
  {
    case eClient:
      s = "C";
      break;
    case eSlave:
      s = "S";
      break;
    case eMaster:
      s = "M";
      break;
    case eSuperServer:
      s = "SS";
      break;
  }
  return s;
}
//---------------------------------------------------------------------------------------------
nsMMOEngine::TBase* THandlerMMO::GetBase()
{
  return mBase;
}
//---------------------------------------------------------------------------------------------
THandlerMMO::TSetUInt* THandlerMMO::GetClientKeySet()
{
  return &g_ClientKeySet;
}
//-----------------------------------------------------------------------------------
