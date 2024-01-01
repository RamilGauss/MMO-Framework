/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/BreakPacket.h"
#include "INetTransport.h"
#include "Base/Common/CryptoAES_Impl.h"
#include "Base/Common/SHA256.h"
#include "Base/Common/CRC8.h"

namespace nsMMOEngine
{
    class TSession
    {
    protected:
        friend class TSessionManager;

        enum PacketType
        {
            eLogin = 'l',// от клиента запрос на авторизацию
            eKeyAES = 'k',// ответ от сервера с ключом
            eIDconfirmation = 'c',// клиент должен подтвердить что понял пакет от сервера
            eData = 'd',// обмен данными
            eEcho = 'e',// эхо для проверки соединения на физические разрывы
        };
        enum Wait
        {
            TimeWaitConnectTo = 100000,
            TimeWaitLogin = 100000,
            TimeWaitDeveloper = 100000,
            TimeWaitConfirmation = 100000,
            TimeWaitKeyAES = 100000,
        };
    public:
        enum State
        {
            StateWaitConnectTo,   // ждем окончания соединения к кому-то (в данной реализации транспорта этот этап длится несколько мкс)
            StateWaitLogin,       // 
            StateWaitDeveloper,   // ждем вызова Accept или Reject - принимает ли сервер входящий запрос на соединение
            StateWaitKeyAES,      // ждем ключ
            StateWaitConfirmation,// ждем подтверждения от клиента, что он нас понял
            StateWork,            // обмен данными
        };
    private:
        unsigned int mTimeLive;// мс
        unsigned int mID;
        TIP_Port mIP_Port;

        volatile unsigned int mLastTimeActive;

        INetTransport* mTransport;

        TBreakPacket mBP;

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
#pragma pack(push, 1)
        struct THeader
        {
            unsigned char type;
            THeader(unsigned char t = eData)
            {
                type = t;
            }
        };
#pragma pack(pop)

        TContainerRise mRecvDataContainer;

    public:
        TSession(State state, unsigned int time_live_ms);
        virtual ~TSession();

        bool Work();
        void Send(TBreakPacket& bp, bool check = true);
        void SetTransport(INetTransport* pTransport);
        void GetInfo(TIP_Port& pDesc);
        void SetInfo(TIP_Port& pDesc);

        bool RecvData(void* data, int dataSize, TContainerPtr& result);
        void RecvKeyAES(void* pKey, int keySize);
        bool RecvIDconfirmation(void* pConfirm, int confirmSize);
        unsigned int GetID() const;
        void SetID(unsigned int id);
        void Close();

        void SendLogin();
        void SendKeyAES();
        void SendIDconfirmation();

        void SetState(State state);
        State GetState();

        unsigned int GetStateChangeTime();

        void SetKeyAES(void* p, int size);

        void RefreshLastTime();
    protected:
        void SendEcho();
        void SendData(char type, TBreakPacket& bp, bool check = true);

        void SetLogin(const std::string& login);
        void SetLoginHash(char* loginHash, int loginHashSize);
        std::string GetLoginHashStr();

        void SetPassword(const std::string& password);

    private:
        void PrintError();
    };
}