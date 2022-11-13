/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>

#include "ContainerRise.h"
#include "ShareMisc.h"
#include "BreakPacket.h"

class DllExport THistoryPacketTCP
{
public:
    struct TResult
    {
        void Set(char* b, int s)
        {
            buffer = b;
            size = s;
            complete = true;
        }
        bool complete = false;
        char* buffer = nullptr;
        int size = 0;

        bool parse_error = false;// обнаружена ошибка, при парсинге пакета
    };
protected:
    enum class eStatePacket
    {
        eSearchSize,
        eSearchData,
    };

    int mSizePacket;// предполагаемый размер пакета
    TContainerRise mCollectorPacket;
    eStatePacket   mState;
    bool flgNewPacket;// начало нового пакета
public:
    THistoryPacketTCP();
    void Clear();
    static void PackForSend(TBreakPacket& bp);

    void Analiz(int& beginPos, TResult& res, int readSize, char* buffer);
protected:

    int SearchSize(int readSize, char* buffer, TResult& res, int beginPos);

    int BeginSearchSize(int readSize, char* buffer, TResult& res, int beginPos);
    int ContinueSearchSize(int readSize, char* buffer, TResult& res, int beginPos);

    int SearchData(int readSize, char* buffer, TResult& res, int beginPos);

    void CheckSize(TResult& res);

    enum
    {
        eMaxSize = 0xFFFF, // пакета большего размера быть не может
    };
};
