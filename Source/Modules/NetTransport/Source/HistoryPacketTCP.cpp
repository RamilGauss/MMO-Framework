/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/GlobalEventHub.h"

#include "NetTransport/Include/HistoryPacketTCP.h"
#include "NetTransport/Include/HeaderTCP.h"

#include "MMOEngine/Include/INetTransport.h"
#include "MMOEngine/Include/EnumMMO.h"

THistoryPacketTCP::THistoryPacketTCP()
{
    Clear();
}
//------------------------------------------------------------------------
void THistoryPacketTCP::Clear()
{
    mState = eStatePacket::eSearchSize;
    mSizePacket = 0;
    flgNewPacket = true;
}
//------------------------------------------------------------------------
void THistoryPacketTCP::PackForSend(TBreakPacket& bp)
{
    int size = bp.GetSize();
    // добавить заголовки в начало
    THeaderTCP header;
    memcpy(header.size, &size, sizeof(THeaderTCP));
    bp.PushFront((char*)&header, sizeof(header));
}
//------------------------------------------------------------------------
void THistoryPacketTCP::Analiz(int& beginPos, TResult& res, int readSize, char* buffer)
{
    switch (mState) {
    case eStatePacket::eSearchSize:
        beginPos += SearchSize(readSize, buffer, res, beginPos);
        break;
    case eStatePacket::eSearchData:
        beginPos += SearchData(readSize, buffer, res, beginPos);
        break;
    }
}
//----------------------------------------------------------------------------------
int THistoryPacketTCP::SearchSize(int readSize, char* buffer, TResult& res, int beginPos)
{
    return flgNewPacket ?
        BeginSearchSize(readSize, buffer, res, beginPos) :
        ContinueSearchSize(readSize, buffer, res, beginPos);
}
//----------------------------------------------------------------------------------
int THistoryPacketTCP::BeginSearchSize(int readSize, char* buffer, TResult& res, int beginPos)
{
    int size = readSize - beginPos;
    if (size >= sizeof(THeaderTCP)) {
        size = sizeof(THeaderTCP);
        THeaderTCP* pHeader = (THeaderTCP*)&buffer[beginPos];
        mState = THistoryPacketTCP::eStatePacket::eSearchData;

        mSizePacket = 0;
        memcpy(&mSizePacket, pHeader->size, sizeof(THeaderTCP));
        CheckSize(res);
    }

    mCollectorPacket.Clear();
    mCollectorPacket.Append(size, &buffer[beginPos]);
    flgNewPacket = false;
    return size;
}
//----------------------------------------------------------------------------------
int THistoryPacketTCP::ContinueSearchSize(int readSize, char* buffer, TResult& res, int beginPos)
{
    int sizeNewData = readSize - beginPos;// размер новых данных
    int sizeFound = sizeNewData + mCollectorPacket.GetSize();
    if (sizeFound < sizeof(THeaderTCP)) {
        mCollectorPacket.Append(sizeNewData, &buffer[beginPos]);
        return sizeNewData;
    }

    int needCopy = sizeof(THeaderTCP) - mCollectorPacket.GetSize();
    mCollectorPacket.Append(needCopy, &buffer[beginPos]);

    THeaderTCP* pHeader = (THeaderTCP*)mCollectorPacket.GetPtr();
    mState = THistoryPacketTCP::eStatePacket::eSearchData;

    mSizePacket = 0;
    memcpy(&mSizePacket, pHeader->size, sizeof(THeaderTCP));

    CheckSize(res);
    return needCopy;// вернуть сколько истратили
}
//----------------------------------------------------------------------------------
int THistoryPacketTCP::SearchData(int readSize, char* buffer, TResult& res, int beginPos)
{
    int sizeNewData = readSize - beginPos;

    int mustSize = mSizePacket + sizeof(THeaderTCP);// предполагаемый размер
    // не хватает до полного размера
    if (mustSize > sizeNewData + mCollectorPacket.GetSize()/*остаток внутри истории*/) {
        // скопировать внутрь и выйти
        mCollectorPacket.Append(sizeNewData, &buffer[beginPos]);
        return sizeNewData;
    }

    // пакет собран
    int packetRest = mustSize - mCollectorPacket.GetSize();// остаток пакета
    mCollectorPacket.Append(packetRest, &buffer[beginPos]);

    res.Set(sizeof(THeaderTCP) + mCollectorPacket.GetPtr(), mSizePacket);
    Clear();
    return packetRest;
}
//----------------------------------------------------------------------------------
void THistoryPacketTCP::CheckSize(TResult& res)
{
    // проверка корректности предполагаемого размера пакета
    if (mSizePacket > eMaxSize) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("THistoryPacketTCP::SearchSize expect very large size of packet.");
        // сдвиг на 1 байт и поиск дальше, но фактически обмен нарушен
        // канал скоро умрет, админ, проверяя логи, забанит "хака".
        // ну, по крайней мере так должно быть.
        res.parse_error = true;
    }
}
//----------------------------------------------------------------------------------
