/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "BreakPacket.h"
#include "INetTransport.h"
#include "CryptoAES_Impl.h"
#include "SHA256.h"
#include "CRC8.h"

namespace nsMMOEngine
{
  class TSession
  {
  protected:
    friend class TSessionManager;

    enum PacketType
    {
      eLogin          = 'l',// от клиента запрос на авторизацию
      eKeyAES         = 'k',// ответ от сервера с ключом
      eIDconfirmation = 'c',// клиент должен подтвердить что понял пакет от сервера
      eData           = 'd',// обмен данными
      eEcho           = 'e',// эхо для проверки соединения на физические разрывы
    };
  public:
    enum State
    {
      eConnectTo,       // ждем окончания соединения к кому-то (в данной реализации транспорта этот этап длится несколько мкс)
      eConnectFrom,     // ждем вызова Accept или Reject - принимает ли сервер входящий запрос на соединение
      eWaitKeyAES,      // ждем ключ
      eWaitConirmation, // ждем подтверждения от клиента, что он нас понял
      eWork,            // обмен данными
    };
  private:
    unsigned int mTimeLive;// мс
    unsigned int mID;
    TIP_Port mIP_Port;
    unsigned int mLastTimeActive;
    INetTransport* mTransport;

    TBreakPacket mBP;

    //TBreakPacket mBP;
    //TBreakPacket mBP;

    State mState;
    unsigned int mStateChangeTime = 0;

    std::string mLogin;
    std::string mPassword;

    TSHA256 mSHA256;
    TContainer mLoginHash;
    TContainer mPasswordHash;

    TCryptoAES_Impl mPasswordAES;
    
    TCryptoAES_Impl mRecvAES;
    TCryptoAES_Impl mSendAES;

    TCRC8 mCalcCRC8;
    TContainerRise mBuffer;

    TContainerRise mEncrypt;
    TContainerRise mDecrypt;
#if defined( WIN32 )
#pragma pack(push, 1)
#endif
    struct THeader
    {
      unsigned char type;
      THeader( unsigned char t = eData )
      {
        type = t;
      }
    }_PACKED;
#if defined( WIN32 )
#pragma pack(pop)
#endif

    TContainerRise mRecvDataContainer;

  public:
    enum Wait
    {
      WaitConnectFrom = 10000,
      WaitConfirmation = 10000,
      WaitKeyAES = 10000,
    };

    TSession( State state, unsigned int time_live_ms );
    ~TSession();

    void Work();
    void Send( TBreakPacket& bp, bool check = true );
    void SetTransport( INetTransport* pTransport );
    void GetInfo( TIP_Port& pDesc );
    void SetInfo( TIP_Port& pDesc );
    void UpdateLastTime();
    
    bool RecvData( void* data, int dataSize, TContainerPtr& result );
    bool RecvKeyAES( void* pKey, int keySize );
    bool RecvIDconfirmation( void* pConfirm, int confirmSize );
    unsigned int GetID() const{ return mID; }
    void SetID( unsigned int id ){ mID = id; }
    void Close();

    void SendLogin();
    void SendKeyAES();
    void SendIDconfirmation();

    void SetState(State state);
    State GetState();

    unsigned int GetStateChangeTime();

    void SetKeyAES( void* p, int size );

  protected:
    void SendEcho();
    void RefreshLastTime();
    void SendData( char type, TBreakPacket& bp, bool check = true );

    void SetLogin( std::string& login );
    void SetLoginHash( char* loginHash, int loginHashSize );
    std::string GetLoginHashStr();

    void SetPassword( std::string& password );

  };
}