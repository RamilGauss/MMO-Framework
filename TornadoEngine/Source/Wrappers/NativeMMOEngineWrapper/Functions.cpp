/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Functions.h"
#include "EventPool.h"

#include "MakerNetTransport.h"
#include "Client.h"
#include "EnumMMO.h"
#include "Logger.h"
#include "Slave.h"
#include "Master.h"
#include "SuperServer.h"

#pragma region Private
namespace nsImplimentation
{
  typedef enum{Client,Slave,Master,SuperServer}Type;
}

struct TDesc
{
  nsImplimentation::Type implType;
  nsMMOEngine::TBase* pBase;
  TEventPool mEventPool;
  TDesc()
  {
    pBase = NULL;
  }
  ~TDesc()
  {
    delete pBase;
  }
};

typedef std::map<int,TDesc*>   TMapIntPtr;
typedef TMapIntPtr::iterator   TMapIntPtrIt;
typedef TMapIntPtr::value_type TMapIntPtrVT;

typedef std::list<unsigned int> TListUint;
typedef TListUint::iterator TListUintIt;

static bool                g_NeedInit = true;
static TMapIntPtr          g_ID_ptrBase;
static int                 g_LastID = 1;
static TMakerNetTransport* g_MakerNetTransport = NULL;
static TDstEvent           g_DstEvent;

int Make( nsImplimentation::Type type )
{
  TDesc* pDesc = new TDesc();
  pDesc->implType = type;
  nsMMOEngine::TBase* pBase = NULL;
  switch(type)
  {
    case nsImplimentation::Client:
      pBase = new nsMMOEngine::TClient();
      break;
    case nsImplimentation::Slave:
      pBase = new nsMMOEngine::TSlave();
      break;
    case nsImplimentation::Master:
      pBase = new nsMMOEngine::TMaster();
      break;
    case nsImplimentation::SuperServer:
      pBase = new nsMMOEngine::TSuperServer();
      break;
  }
  pBase->SetDstObject(&g_DstEvent);
  pBase->SetSelfID(g_LastID);

  pDesc->pBase = pBase;
  g_ID_ptrBase.insert( TMapIntPtrVT(g_LastID, pDesc));
  return g_LastID++;
}
//--------------------------------------------------------------------
template <typename T>
T* Get( int implID )
{
  if(g_ID_ptrBase.find( implID ) == g_ID_ptrBase.end() )
    return NULL;
  return (T*)(g_ID_ptrBase[implID]->pBase);
}
#pragma endregion 
//--------------------------------------------------------------------
#pragma region LibraryFunc
void InitLib( char* logName )
{
  if( g_NeedInit == false )
    return;

  GetLogger()->Register(STR_NAME_MMO_ENGINE);
  GetLogger()->Register(STR_NAME_NET_TRANSPORT);
  GetLogger()->Init( logName );
  GetLogger()->SetPrintf(false);
  GetLogger()->SetEnable(false);

  g_MakerNetTransport = new TMakerNetTransport();

  g_NeedInit = false;
}
//--------------------------------------------------------------------
void DoneLib()
{
  if( g_NeedInit == false )
    return;

  delete g_MakerNetTransport;
  g_MakerNetTransport = NULL;
  
  g_NeedInit = true;

  TMapIntPtrIt bit = g_ID_ptrBase.begin();
  TMapIntPtrIt eit = g_ID_ptrBase.end();
  while( bit != eit )
  {
    delete bit->second;
    bit++;
  }
  g_ID_ptrBase.clear();
}
#pragma endregion 
//--------------------------------------------------------------------
#pragma region Make
int MakeClient() 
{
  return Make( nsImplimentation::Client );
}
//--------------------------------------------------------------------
int MakeSlave()
{
  return Make( nsImplimentation::Slave );
}
//--------------------------------------------------------------------
int MakeMaster()
{
  return Make( nsImplimentation::Master );
}
//--------------------------------------------------------------------
int MakeSuperServer()
{
  return Make( nsImplimentation::SuperServer );
}
//--------------------------------------------------------------------
void Destroy( int implID )
{
  delete g_ID_ptrBase[implID];
  g_ID_ptrBase.erase(implID);
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region Event
//###
void* GetEvent( int& type, int& size )
{
  type = 0;
  size = 0;
  return NULL;
}
//###
//--------------------------------------------------------------------
void* GetEvent( int implID, int& size )
{
  return NULL;
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region Base
void Init( int implID )
{
  Get<nsMMOEngine::TBase>( implID )->Init( g_MakerNetTransport );
}
//--------------------------------------------------------------------
bool Open( int implID, unsigned short port, unsigned char subNet )
{
  nsMMOEngine::TDescOpen descOpen;
  descOpen.port = port;
  descOpen.subNet = subNet;
  bool result = Get<nsMMOEngine::TBase>( implID )->Open( &descOpen, 1);
  return result;
}
//--------------------------------------------------------------------
void DisconnectUp( int implID )
{
  Get<nsMMOEngine::TBase>( implID )->DisconnectUp();
}
//--------------------------------------------------------------------
void SendUp( int implID, char* p, int size, bool check )
{
  Get<nsMMOEngine::TBase>( implID )->SendUp( p, size, check );
}
//--------------------------------------------------------------------
void Work( int implID )
{
  Get<nsMMOEngine::TBase>( implID )->Work();
}
//--------------------------------------------------------------------
bool IsConnectUp( int implID )
{
  return Get<nsMMOEngine::TBase>( implID )->IsConnectUp();
}
//--------------------------------------------------------------------
bool IsConnect( int implID, unsigned int id )
{
  return Get<nsMMOEngine::TBase>( implID )->IsConnect( id );
}
//--------------------------------------------------------------------
void SetLoad( int implID, int procent )
{
  Get<nsMMOEngine::TBase>( implID )->SetLoad( procent );
}
//--------------------------------------------------------------------
void SetTimeLiveSession( int implID, unsigned int time_ms )
{
  Get<nsMMOEngine::TBase>( implID )->SetTimeLiveSession( time_ms );
}
//--------------------------------------------------------------------
bool GetInfoSession( int implID, unsigned int id_session, unsigned int& ip, unsigned short& port )
{
  TIP_Port ip_port;
  bool result = Get<nsMMOEngine::TBase>( implID )->GetInfoSession( id_session, ip_port);
  if( result==false )
    return false;
  ip = ip_port.ip;
  port = ip_port.port;
  return true;
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region Client
void Login(int implID, unsigned int ip, unsigned short port, 
  void* pLogin, int sizeLogin, void* pPassword, int sizePassword)
{
  Get<nsMMOEngine::TClient>( implID )->Login( ip, port, pLogin, sizeLogin, pPassword, sizePassword);
}
//--------------------------------------------------------------------
void LeaveQueue( int implID )
{
  Get<nsMMOEngine::TClient>( implID )->LeaveQueue();
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region BaseServer
bool IsSessionSecurity(int implID, unsigned int id_session, void* crypt, int size_crypt, 
                       void* pLogin, int sizeLogin, void* pPassword, int sizePassword)
{
  return Get<nsMMOEngine::TBaseServer>( implID )->IsSessionSecurity( id_session, crypt, size_crypt, 
    pLogin, sizeLogin, pPassword, sizePassword);
}
//--------------------------------------------------------------------
void SendByClientKey(int implID, unsigned int* id_client, int count_client, char* p, int size )
{
  TListUint id_client_list;
  for( int i = 0 ; i < count_client ; i++ )
    id_client_list.push_back(id_client[i]);

  Get<nsMMOEngine::TBaseServer>( implID )->SendByClientKey( id_client_list, p, size );
}
//--------------------------------------------------------------------
void SendDown(int implID, unsigned int id_session, char* p, int size, bool check )
{
  Get<nsMMOEngine::TBaseServer>( implID )->SendDown(id_session, p, size, check);
}
//--------------------------------------------------------------------
int  GetCountDown(int implID)
{
  return Get<nsMMOEngine::TBaseServer>( implID )->GetCountDown();
}
//--------------------------------------------------------------------
bool GetDescDown(int implID, int index, void* pDesc, int& sizeDesc)
{
  return Get<nsMMOEngine::TBaseServer>( implID )->GetDescDown( index, pDesc, sizeDesc);
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region ActiveServer
void ConnectUp(int implID, unsigned int ip, unsigned short port,  
                           void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
                           unsigned char subNet )
{
  Get<nsMMOEngine::TActiveServer>( implID )->ConnectUp(ip, port,  
    pLogin, sizeLogin, pPassword, sizePassword, subNet);
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region Slave
void SaveContext(int implID, unsigned int id_session, void* data, int size)
{
  Get<nsMMOEngine::TSlave>( implID )->SaveContext(id_session, data, size);
}
//--------------------------------------------------------------------
bool FindClientKeyBySession(int implID, unsigned int id_session, unsigned int &id)
{
  return Get<nsMMOEngine::TSlave>( implID )->FindClientKeyBySession(id_session, id);
}
//--------------------------------------------------------------------
bool FindSessionByClientKey(int implID, unsigned int id, unsigned int& id_session)
{
  return Get<nsMMOEngine::TSlave>( implID )->FindSessionByClientKey(id, id_session);
}
#pragma endregion
//--------------------------------------------------------------------
#pragma region Master
bool TryCreateGroup(int implID, unsigned int* l_id_client, int count_id_client, unsigned int& id_group)
{
  TListUint id_client_list;
  for( int i = 0 ; i < count_id_client ; i++ )
    id_client_list.push_back(l_id_client[i]);

  return Get<nsMMOEngine::TMaster>( implID )->TryCreateGroup(id_client_list, id_group);
}
//--------------------------------------------------------------------
void DestroyGroup(int implID, unsigned int id_group)
{
  Get<nsMMOEngine::TMaster>( implID )->DestroyGroup(id_group);
}
//--------------------------------------------------------------------
void LeaveGroup(int implID, unsigned int id_client)
{
  Get<nsMMOEngine::TMaster>( implID )->LeaveGroup(id_client);
}
//--------------------------------------------------------------------
static TListUint g_ListForGroup;
int GetCountForGroup(int implID, unsigned int id_group)
{
  g_ListForGroup.clear();
  Get<nsMMOEngine::TMaster>( implID )->GetListForGroup(id_group, g_ListForGroup);
  return g_ListForGroup.size();
}
//--------------------------------------------------------------------
void GetListForGroup(int implID, unsigned int id_group, unsigned int* gc_arr, int& count)
{
  count = g_ListForGroup.size();
  int i = 0;
  TListUintIt bit = g_ListForGroup.begin();
  TListUintIt eit = g_ListForGroup.end();
  while( bit != eit )
  {
    gc_arr[i] = *bit;
    bit++;
    i++;
  }
}
//--------------------------------------------------------------------
void SetResultLogin(int implID, bool res, unsigned int id_session, 
                    unsigned int id_client, void* resForClient, int sizeResClient)
{
  Get<nsMMOEngine::TMaster>( implID )->SetResultLogin( res, id_session, 
    id_client, resForClient, sizeResClient);
}
//--------------------------------------------------------------------
bool FindSlaveSessionByGroup(int implID, unsigned int id_group, unsigned int& id_session)
{
  return Get<nsMMOEngine::TMaster>( implID )->FindSlaveSessionByGroup( id_group, id_session );
}
#pragma endregion
//--------------------------------------------------------------------
