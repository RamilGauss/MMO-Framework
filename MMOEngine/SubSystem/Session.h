/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SESSION_H
#define SESSION_H

#include "BreakPacket.h"
#include "INetTransport.h"

namespace nsMMOEngine
{
  class TSession
  {
    // для предотвращения подсовывания пакетов внутри серверных каналов 
    unsigned int mCounterIn;
    unsigned int mCounterOut;
    //----------------------------------------------------------------
    // Recv
    // if(packet->cIn <= mCounterIn)
      //return; // ignore packet
    // mCounterIn = packet->cIn;
    //----------------------------------------------------------------
    // Send
    // mCounterOut++;
    // Send(...);

    unsigned int mTimeLive;// мс
    unsigned int mID;
    TIP_Port mIP_Port;
    unsigned int mLastTimeActive;
    INetTransport* mTransport;
  protected:
    friend class TManagerSession;

    enum{
      eEcho   = 'e',
      ePacket = 'p',
      // для процедуры обмена ключами шифрования
      eKeyRSA = 'r',
      eKeyAES = 'a',
    };
#if defined( WIN32 )
#pragma pack(push, 1)
#endif
    struct THeader
    {
      unsigned char type      : 7;
      unsigned char use_crypt : 1;
      THeader(unsigned char t = ePacket)
      {
        type      = t;
        use_crypt = 0;
      }
    };
#if defined( WIN32 )
#pragma pack(pop)
#endif

  public:
    TSession(unsigned int time_live_ms);
    ~TSession();
    
    void Work();
    void Send(TBreakPacket bp, bool check = true, bool use_crypt = false);
    void SetTransport(INetTransport* pTransport);
    void GetInfo(TIP_Port& pDesc);
    void SetInfo(TIP_Port& pDesc);
    void Recv();
    unsigned int GetID(){return mID;}
    void SetID(unsigned int id){mID=id;}
    void Close();

    void SendKeyRSA(TContainer& c_keyRSA);
    void SendKeyAES(TContainer& c_keyAES);

    void SendEncrypt(TBreakPacket bp);

    unsigned int GetCounterIn();

    unsigned int GetCounterOut();
    void IncrementCounterOut(); 
  protected:
    void SendEcho();
    void RefreshLastTime();
    void SendData(char type, TBreakPacket& bp, bool check = true, bool use_crypt = false);
  };
}

#endif