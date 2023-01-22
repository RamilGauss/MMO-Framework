/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Session.h"
#include "HiTimer.h"

#include <time.h>
#include "ContainerTypes.h"
#include "BL_Debug.h"

using namespace nsMMOEngine;

/* Схема шифрования:
   Отправка:
      Расчет CRC8, зашифровка AES блока данных вместе с CRC8.
   Приём:
      Дешифровка, сравнение с последним байтом суммы данных.
*/

TSession::TSession(State state, unsigned int time_live_ms)
{
    mTimeLive = time_live_ms;

    mLastTimeActive = ht_GetMSCount();
    mTransport = nullptr;

    SetState(state);
}
//---------------------------------------------------------------------
TSession::~TSession()
{
    Close();
}
//---------------------------------------------------------------------
bool TSession::Work()
{
    unsigned int now_ms = ht_GetMSCount();
    bool result = true;
    switch (mState) {
    case TSession::StateWaitConnectTo:
        if (GetStateChangeTime() + TimeWaitConnectTo < now_ms) {
            PrintError();//###
            result = false;
        }
        break;
    case TSession::StateWaitLogin:
        if (GetStateChangeTime() + TimeWaitLogin < now_ms) {
            PrintError();//###
            result = false;
        }
        break;
    case TSession::StateWaitDeveloper:
        if (GetStateChangeTime() + TimeWaitDeveloper < now_ms) {
            PrintError();//###
            result = false;
        }
        break;
    case TSession::StateWaitKeyAES:
        if (GetStateChangeTime() + TimeWaitKeyAES < now_ms) {
            PrintError();//###
            result = false;
        }
        break;
    case TSession::StateWaitConfirmation:
        if (GetStateChangeTime() + TimeWaitConfirmation < now_ms) {
            PrintError();//###
            result = false;
        }
        break;
    case TSession::StateWork:
        if (mLastTimeActive + mTimeLive < now_ms) {
            SendEcho();
            RefreshLastTime();
        }
        break;
    }
    return result;
}
//---------------------------------------------------------------------
void TSession::Send(TBreakPacket& bp, bool check)
{
    if (check) {
        // Data + crc8(Data) => Encrypt
        bp.CopyInBuffer(mBuffer);
        unsigned char crc8;
        mCalcCRC8.Calc(mBuffer.GetPtr(), mBuffer.GetSize(), crc8);

        bp.PushBack((char*)&crc8, sizeof(crc8));
        bp.CopyInBuffer(mBuffer);

        mSendAES.Encrypt(mBuffer.GetPtr(), mBuffer.GetSize(), mEncrypt);
        bp.Reset();
        bp.PushBack((char*)mEncrypt.GetPtr(), mEncrypt.GetSize());
    }

    SendData(eData, bp, check);
    // гарантия того что пакет дойдет
    // иначе сессия на той стороне не освежит время
    if (check) {
        RefreshLastTime();
    }
}
//---------------------------------------------------------------------
void TSession::SetTransport(INetTransport* pTransport)
{
    mTransport = pTransport;
}
//---------------------------------------------------------------------
void TSession::GetInfo(TIP_Port& pDesc)
{
    pDesc = mIP_Port;
}
//---------------------------------------------------------------------
void TSession::SetInfo(TIP_Port& pDesc)
{
    mIP_Port = pDesc;
}
//---------------------------------------------------------------------
bool TSession::RecvData(void* data, int dataSize, TContainerPtr& result)
{
    // Encrypt => Data + crc8(Data)
    mRecvAES.Decrypt(data, dataSize, mRecvDataContainer);
    auto p = (unsigned char*)mRecvDataContainer.GetPtr();
    auto size = mRecvDataContainer.GetSize();
    auto indexCRC8 = size - sizeof(unsigned char);
    auto sizeWithoutCRC8 = indexCRC8;

    unsigned char recvCRC8 = p[indexCRC8];// последний байт - crc8

    unsigned char crc8;
    mCalcCRC8.Calc(p, sizeWithoutCRC8, crc8);
    if (crc8 != recvCRC8) {
        return false;
    }

    result.SetData(mRecvDataContainer.GetPtr(), sizeWithoutCRC8);

    RefreshLastTime();
    return true;
}
//---------------------------------------------------------------------
void TSession::RecvKeyAES(void* pKey, int keySize)// Client
{
    mPasswordAES.Decrypt(pKey, keySize, mDecrypt);

    // запомнить пароль для работы
    SetKeyAES(mDecrypt.GetPtr(), mDecrypt.GetSize());
}
//---------------------------------------------------------------------
unsigned int TSession::GetID() const
{
    return mID;
}
//---------------------------------------------------------------------
void TSession::SetID(unsigned int id)
{
    mID = id;
}
//---------------------------------------------------------------------
bool TSession::RecvIDconfirmation(void* pConfirm, int confirmSize)// Server
{
    if (mRecvAES.Decrypt(pConfirm, confirmSize, mDecrypt) == false) {
        return false;
    }

    auto dataSize = mDecrypt.GetSize() - sizeof(unsigned char);

    unsigned char crc8;
    mCalcCRC8.Calc(mDecrypt.GetPtr(), dataSize, crc8);

    unsigned char recvCRC8 = ((unsigned char*)mDecrypt.GetPtr())[dataSize];
    if (crc8 != recvCRC8) {
        return false;
    }

    return true;
}
//---------------------------------------------------------------------
void TSession::SendEcho()
{
    mBP.Reset();
    SendData(eEcho, mBP);
}
//---------------------------------------------------------------------
void TSession::RefreshLastTime()
{
    mLastTimeActive = ht_GetMSCount();
}
//---------------------------------------------------------------------
void TSession::SendData(char type, TBreakPacket& bp, bool check)
{
    THeader h(type);
    bp.PushFront((char*)&h, sizeof(THeader));
    mTransport->Send(mIP_Port.ip, mIP_Port.port, bp, check);
}
//---------------------------------------------------------------------
void TSession::Close()
{
    mTransport->Close(mIP_Port.ip, mIP_Port.port);
}
//---------------------------------------------------------------------
void TSession::SetState(State state)
{
    mState = state;
    mStateChangeTime = ht_GetMSCount();
}
//---------------------------------------------------------------------
TSession::State TSession::GetState()
{
    return mState;
}
//---------------------------------------------------------------------
unsigned int TSession::GetStateChangeTime()
{
    return mStateChangeTime;
}
//---------------------------------------------------------------------
void TSession::SendLogin()// Client
{
    mBP.Reset();
    mBP.PushFront(mLoginHash.GetPtr(), mLoginHash.GetSize());
    SendData(eLogin, mBP, true);
}
//---------------------------------------------------------------------
void TSession::SendIDconfirmation()// Client
{
    mPasswordAES.GetKey(mBuffer);
    unsigned char crc8;
    mCalcCRC8.Calc(mBuffer.GetPtr(), mBuffer.GetSize(), crc8);

    mBP.Reset();// склейка CRC8 и ключа
    mBP.PushBack((char*)mBuffer.GetPtr(), mBuffer.GetSize());
    mBP.PushBack((char*)&crc8, sizeof(crc8));

    mBP.CopyInBuffer(mBuffer);
    mSendAES.Encrypt(mBuffer.GetPtr(), mBuffer.GetSize(), mEncrypt);

    mBP.Reset();
    mBP.PushBack((char*)mEncrypt.GetPtr(), mEncrypt.GetSize());

    SendData(eIDconfirmation, mBP, true);
}
//---------------------------------------------------------------------
void TSession::SendKeyAES()// Server
{
    // генерация пароля
    mSendAES.GenerateKey();
    mSendAES.GetKey(mBuffer);
    mRecvAES.SetKey(mBuffer.GetPtr(), mBuffer.GetSize());

    // шифрование
    mPasswordAES.Encrypt(mBuffer.GetPtr(), mBuffer.GetSize(), mEncrypt);// шифруем рабочий ключ паролем 

    mBP.Reset();
    mBP.PushBack((char*)mEncrypt.GetPtr(), mEncrypt.GetSize());

    SendData(eKeyAES, mBP, true);
}
//---------------------------------------------------------------------
void TSession::SetLogin(const std::string& login)
{
    mLogin = login;
    mSHA256.FastCalc((char*)mLogin.data(), mLogin.size(), mLoginHash);
}
//---------------------------------------------------------------------
void TSession::SetLoginHash(char* loginHash, int loginHashSize)
{
    mLoginHash.SetData(loginHash, loginHashSize);
}
//---------------------------------------------------------------------
std::string TSession::GetLoginHashStr()
{
    std::string hash;
    int size = mLoginHash.GetSize();
    auto p = (unsigned char*)mLoginHash.GetPtr();
    for (int i = 0; i < size; i++) {
        char append[100];
        sprintf(append, "0x%02X", p[i]);
        hash += append;
        if (i != size - 1)
            hash += ",";
    }
    return hash;
}
//---------------------------------------------------------------------
void TSession::SetPassword(const std::string& password)
{
    mPassword = password;
    mSHA256.FastCalc((char*)mPassword.data(), mPassword.size(), mPasswordHash);
    mPasswordAES.SetKey(mPasswordHash.GetPtr(), mPasswordHash.GetSize());
}
//---------------------------------------------------------------------
void TSession::SetKeyAES(void* p, int size)
{
    mSendAES.SetKey(p, size);
    mRecvAES.SetKey(p, size);
}
//---------------------------------------------------------------------
void TSession::PrintError()
{
    printf("Session FAIL at state = %d, ip:port = %s\n", mState, mIP_Port.ToString());
}
//---------------------------------------------------------------------
