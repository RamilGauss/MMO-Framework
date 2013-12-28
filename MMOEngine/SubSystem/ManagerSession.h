/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_SESSION_H
#define MANAGER_SESSION_H

#include <map>

#include "ShareMisc.h"
#include "Session.h"
#include "GCS.h"
#include "NavigateSession.h"
#include "CallBackRegistrator.h"
#include "DescRecvSession.h"
#include "ManagerTransport.h"
#include "ManagerContextCrypto.h"

namespace nsMMOEngine
{
  class TManagerSession
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
		TNavigateSession  *mNavigateSession;
    TManagerTransport *mMngTransport;
    bool flgStart;

    bool flgUseCryptTCP;
    TManagerContextCrypto mMngCtxCrypto;

    // один менеджер - одно верхнее соединение
    bool flgNeedAnswerFromUp;
    bool flgGetAnswerFromUp;
    TIP_Port mIP_PortUp;

    TCallBackRegistrator1<int>               mCallBackDiconnect;
    TCallBackRegistrator1<TDescRecvSession*> mCallBackRecv;

    GCS mMutexAccessMapSession;
    void lockAccessSession(){mMutexAccessMapSession.lock();}
    void unlockAccessSession(){mMutexAccessMapSession.unlock();}

    // запрет на попытку соединиться наверх более чем один раз
    GCS mMutexConnectUp;
    void lockConnectUp(){mMutexConnectUp.lock();}
    void unlockConnectUp(){mMutexConnectUp.unlock();}
  public:
    TManagerSession();
    ~TManagerSession();
		// для поддержания работы
    void SetMakerTransport(IMakerTransport* pMakerTransport);

    TCallBackRegistrator1<TDescRecvSession*>* GetCallbackRecv(){return &mCallBackRecv;}
    TCallBackRegistrator1<int>* GetCallbackDisconnect(){return &mCallBackDiconnect;}
    
		bool Start(TDescOpen* pDesc, int count = 1);
    void Work();
		// для работы с сетью
    unsigned int Send(unsigned int ip, unsigned short port, TBreakPacket bp, unsigned char subNet, bool check = true);// только если не установлено соединение
		void Send(unsigned int id_session, TBreakPacket bp, bool check = true);
    unsigned int GetSessionID(unsigned int ip, unsigned short port);
    bool GetInfo(unsigned int id_session, TIP_Port& ip_port_out);
    void CloseSession(unsigned int id_session);
    bool IsExist(unsigned int id_session);
    // настройка
    void SetTimeLiveSession(unsigned int time_ms);

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

    void Send(TSession* pSession, TBreakPacket bp, bool check);

    void FixHack(char* sMsg);

    // использовать шифрование для передачи TCP
    void SetUseCryptTCP(bool v);
    bool GetUseCryptTCP();
  };
}

#endif