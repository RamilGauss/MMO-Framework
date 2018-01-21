/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperFunctionsH
#define NativeMMOEngineWrapperFunctionsH

#include "TypeDef.h"
#include "Structs.h"//###

// 
DllExport_C void InitLib( char* logName );
DllExport_C void DoneLib();

// make/destroy implementation
DllExport_C int MakeClient();
DllExport_C int MakeSlave();
DllExport_C int MakeMaster();
DllExport_C int MakeSuperServer();
DllExport_C void Destroy( int implID );

// Event
DllExport_C void* GetEvent( int& type, int& size );

// Base
DllExport_C void Init( int implID );
DllExport_C bool Open( int implID, unsigned short port, unsigned char subNet );
DllExport_C void DisconnectUp( int implID );
DllExport_C void SendUp( int implID, char* p, int size, bool check );
DllExport_C void Work( int implID );
DllExport_C bool IsConnectUp( int implID );
DllExport_C bool IsConnect( int implID, unsigned int id );
DllExport_C void SetLoad( int implID, int procent );
DllExport_C void SetTimeLiveSession( int implID, unsigned int time_ms );
DllExport_C bool GetInfoSession( int implID, unsigned int id_session, unsigned int& ip, unsigned short& port );

// Client
DllExport_C void Login(int implID, unsigned int ip, unsigned short port, 
           void* pLogin, int sizeLogin, void* pPassword, int sizePassword);
DllExport_C void LeaveQueue( int implID );

// BaseServer
DllExport_C bool IsSessionSecurity(int implID, unsigned int id_session, void* crypt, int size_crypt, 
                       void* pLogin, int sizeLogin, void* pPassword, int sizePassword);
DllExport_C void SendByClientKey(int implID, unsigned int* id_client, int count_client, char* p, int size );
DllExport_C void SendDown(int implID, unsigned int id_session, char* p, int size, bool check );
DllExport_C int  GetCountDown(int implID);
DllExport_C bool GetDescDown(int implID, int index, void* pDesc, int& sizeDesc);

// SuperServer
// empty!
// ActiveServer
DllExport_C void ConnectUp(int implID, unsigned int ip, unsigned short port,  
               void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
               unsigned char subNet );
// Slave
DllExport_C void SaveContext(int implID, unsigned int id_session, void* data, int size);
DllExport_C bool FindClientKeyBySession(int implID, unsigned int id_session, unsigned int &id);
DllExport_C bool FindSessionByClientKey(int implID, unsigned int id, unsigned int& id_session);

// Master
DllExport_C bool TryCreateGroup(int implID, unsigned int* l_id_client, int count_id_client, unsigned int& id_group);
DllExport_C void DestroyGroup(int implID, unsigned int id_group);
DllExport_C void LeaveGroup(int implID, unsigned int id_client);
DllExport_C int GetCountForGroup(int implID, unsigned int id_group);
DllExport_C void GetListForGroup(int implID, unsigned int* gc_arr, int& count);
DllExport_C void SetResultLogin(int implID, bool res, unsigned int id_session, 
                            unsigned int id_client, void* resForClient, int sizeResClient);
DllExport_C bool FindSlaveSessionByGroup(int implID, unsigned int id_group, unsigned int& id_session);

#endif
