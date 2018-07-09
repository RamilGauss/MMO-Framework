/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MMOEngineSessionManagerH
#define MMOEngineSessionManagerH

#include <map>

#include "ShareMisc.h"
#include "Session.h"
#include "Mutex.h"
#include "SessionNavigator.h"
#include "CallBackRegistrator.h"
#include "DescRecvSession.h"
#include "TransportManager.h"
#include "CryptoContextManager.h"
#include "Structs.h"

namespace nsMMOEngine
{
  struct TTryConnectDown
  {
    int sessionID;
    TContainer loginHash;

    void Assign( TTryConnectDown* from )
    {
      sessionID = from->sessionID;
      loginHash = from->loginHash;
    }
  };

  class TSessionManager
  {
    enum
    {
      eDefTimeLive = 5 * 1000,// мс
      eSleepForWaitUp = 40,  // мс
      eLimitWaitTimeAnswerFromUp = 10000,// мс
    };

    unsigned int mTimeLiveSession = eDefTimeLive;
    unsigned int mLastID_Session = 0;

    // должен быть как указатель, что бы контролировать порядок уничтожения объектов
    TSessionNavigator* mNavigateSession;
    TTransportManager* mMngTransport;
    bool flgStart = false;

    int mKeyForEvent = 0;

    // один менеджер - одно верхнее соединение
    volatile bool flgNeedAnswerFromUp = false;
    volatile bool flgReceiveAnswerFromUp = false;
    unsigned int mBeinWaitConnectUpTime;

    TIP_Port mIP_PortUp;

    TBreakPacket mEncryptBP;

    TCallBackRegistrator1<int>               mCallBackDiconnect;
    //TCallBackRegistrator1<TDescConnectUp*>   mCallBackConnectUp;
    TCallBackRegistrator1<TDescRecvSession*> mCallBackRecv;
    TCallBackRegistrator1<TTryConnectDown*>  mCallBackTryConnectDown;

    TMutex mMutexAccessMapSession;
    void lockAccessSession()  { mMutexAccessMapSession.lock(); }
    void unlockAccessSession(){ mMutexAccessMapSession.unlock(); }

    // запрет на попытку соединиться наверх более чем один раз
    TMutex mMutexConnectUp;
    void lockConnectUp(){ mMutexConnectUp.lock(); }
    void unlockConnectUp(){ mMutexConnectUp.unlock(); }
  public:
    TSessionManager();
    ~TSessionManager();
    // для поддержания работы
    void SetMakerTransport( IMakerTransport* pMakerTransport );

    TCallBackRegistrator1<TDescRecvSession*>* GetCallbackRecv()          { return &mCallBackRecv; }
    TCallBackRegistrator1<int>*               GetCallbackDisconnect()    { return &mCallBackDiconnect; }
    //TCallBackRegistrator1<TDescConnectUp*>*   GetCallbackConnectUp()     { return &mCallBackConnectUp; }
    TCallBackRegistrator1<TTryConnectDown*>*  GetCallbackTryConnectDown(){ return &mCallBackTryConnectDown; }

    bool Start( TDescOpen* pDesc, int count = 1 );
    void Work();

    // для работы с сетью
    using ConnectResultCallback = std::function<void(int sessionID)>;
    // onResult вызовется в том же потоке что и Work
    void ConnectAsync( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet, ConnectResultCallback onResult );

    void Send( unsigned int sessionID, TBreakPacket& bp, bool check = true );
    unsigned int GetSessionID( unsigned int ip, unsigned short port );
    bool GetInfo( unsigned int sessionID, TIP_Port& ip_port_out );
    void CloseSession( unsigned int sessionID );
    bool IsExist( unsigned int sessionID );
    // настройка
    void SetTimeLiveSession( unsigned int time_ms );

    void Accept( unsigned int sessionID, std::string& password );
    void Reject( unsigned int sessionID );

  protected:
    friend class TReceiverTransport;

    bool StartTransport( unsigned short port, unsigned char subNet );
    void Recv( INetTransport::TDescRecv* pDescRecv, INetTransport* pTransport );
    void Disconnect( TIP_Port* ip_port );
    void ConnectFrom( TIP_Port* ip_port, INetTransport* pTransport );

    TSession* NewSession( TIP_Port& ip_port, INetTransport* pTransport, bool connectTo_elseFrom );

    void RecvData( TDescRecvSession& descRecvSession, TSession* pSession );
    void RecvLogin( TDescRecvSession& descRecvSession, TSession* pSession );
    void RecvKeyAES( TDescRecvSession& descRecvSession, TSession* pSession );
    void RecvIDconfirmation( TDescRecvSession& descRecvSession, TSession* pSession );

    void BeginWaitConnectUp();
    void CleanWaitConnectUp();

    void Send( TSession* pSession, TBreakPacket& bp, bool check );

    void FixHack( char* sMsg );

  protected:

    ConnectResultCallback mConnectResult;
    int mSessionID_UP = INVALID_HANDLE_SESSION;
  };
}

#endif