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
  class TSessionManager
  {
    enum
    {
      eDefTimeLive               = 5*1000,// мс
      eSleepForWaitUp            = 40,  // мс
      eLimitWaitTimeAnswerFromUp = 2000,// мс
    };

    unsigned int mTimeLiveSession;
    unsigned int mLastID_Session;
   
    // должен быть как указатель, что бы контролировать порядок уничтожения объектов
    TSessionNavigator  *mNavigateSession;
    TTransportManager *mMngTransport;
    bool flgStart;

    bool flgUseCryptTCP;
    TCryptoContextManager mMngCtxCrypto;

    // один менеджер - одно верхнее соединение
    bool flgNeedAnswerFromUp;
    bool flgGetAnswerFromUp;
    TIP_Port mIP_PortUp;

    TBreakPacket mEncryptBP;

    TCallBackRegistrator1<int>               mCallBackDiconnect;
    TCallBackRegistrator1<TDescRecvSession*> mCallBackRecv;

    TMutex mMutexAccessMapSession;
    void lockAccessSession(){mMutexAccessMapSession.lock();}
    void unlockAccessSession(){mMutexAccessMapSession.unlock();}

    // запрет на попытку соединиться наверх более чем один раз
    TMutex mMutexConnectUp;
    void lockConnectUp(){mMutexConnectUp.lock();}
    void unlockConnectUp(){mMutexConnectUp.unlock();}
  public:
    TSessionManager();
    ~TSessionManager();
    // для поддержания работы
    void SetMakerTransport(IMakerTransport* pMakerTransport);

    TCallBackRegistrator1<TDescRecvSession*>* GetCallbackRecv(){return &mCallBackRecv;}
    TCallBackRegistrator1<int>* GetCallbackDisconnect(){return &mCallBackDiconnect;}
    
    bool Start(TDescOpen* pDesc, int count = 1);
    void Work();
    // для работы с сетью
    unsigned int Connect(unsigned int ip, unsigned short port, TBreakPacket& bp, unsigned char subNet, bool check = true);// только если не установлено соединение
    void Send(unsigned int id_session, TBreakPacket& bp, bool check = true);
    unsigned int GetSessionID(unsigned int ip, unsigned short port);
    bool GetInfo(unsigned int id_session, TIP_Port& ip_port_out);
    void CloseSession(unsigned int id_session);
    bool IsExist(unsigned int id_session);
    // настройка
    void SetTimeLiveSession(unsigned int time_ms);

    bool GetRSAPublicKeyForUp(TContainer& cRSA);
    bool GetRSAPublicKey(unsigned int id_session, TContainer& cRSA);

  protected:
    friend class TReciverTransport;

    bool StartTransport(unsigned short port, unsigned char subNet);
    void Recv( INetTransport::TDescRecv* pDescRecv, INetTransport* pTransport);
    void Disconnect(TIP_Port* ip_port);

    TSession* NewSession(TIP_Port& ip_port, INetTransport* pTransport);

    void RecvPacket(TDescRecvSession& descRecvSession, TSession* pSession);
    void RecvKeyRSA(TDescRecvSession& descRecvSession, TSession* pSession);
    void RecvKeyAES(TDescRecvSession& descRecvSession);

    bool WaitAnswerFromUp();
    void SetupFlagsForWaitUp();
    void CleanFlagsForWaitUp();
    void SendKeyRSA_Up(TSession* pSession);

    void Send(TSession* pSession, TBreakPacket& bp, bool check);

    void FixHack(char* sMsg);

    // использовать шифрование для передачи TCP
    void SetUseCryptTCP(bool v);
  public:
    bool GetUseCryptTCP();
  protected:
  };
}

#endif