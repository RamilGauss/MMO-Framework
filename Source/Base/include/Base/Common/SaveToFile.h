/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <stdio.h>
#include <vector>

#include "Base/Common/TypeDef.h"
#include "Base/Common/ContainerTypes.h"
#include "Base/Common/ListPtr.h"
#include "Base/Common/InfoFile.h"

/*
  Сохранение файла.
  Вывод в консоль.
  Буферизация при отсутствии открытого файла.
*/

class DllExport TSaveToFile : public InfoFile
{
    bool flgPrintf;
    bool flgEnable;
    bool flgBuffer;

    using TListContainer = TListPtr<TContainer>;

    TListContainer mListBuffer;

    const size_t MAX_NUMBER_FOR_BUFFERIZATION = 5000;

public:
    TSaveToFile(char* path = nullptr);
    virtual ~TSaveToFile();

    // в случае append==false - стирает содержимое файла
    virtual bool ReOpen(char* path, bool append = false);

    void Write(void* buffer, int size);
    // форматированная строка, по типу printf(...)
    template<typename ... Args>
    void WriteF(const char* format, Args && ... args);
    template<typename ... Args>
    void WriteF_time(const char* format, Args && ... args);

    void SetPrintf(bool val);
    bool GetPrintf();
    void SetEnable(bool val);
    bool GetEnable();
    void SetBufferization(bool val);
    bool GetBufferization();
protected:
    void Write_Time();

    void ClearBuffer();
    void FlushBuffer();
    void FlushInBuffer(char* buffer, int size);
};
//--------------------------------------------------------------------------------
template<typename ... Args>
void TSaveToFile::WriteF(const char* format, Args && ... args)
{
    if (flgEnable == false) {
        return;
    }

    char s[10000];
    sprintf(s, format, std::forward<Args>(args)...);
    if (flgPrintf) {
        printf(s);
    }
    Write(s, strlen(s));
}
//--------------------------------------------------------------------------------
template<typename ... Args>
void TSaveToFile::WriteF_time(const char* format, Args && ... args)
{
    if (flgEnable == false) {
        return;
    }

    Write_Time();
    WriteF(format, std::forward<Args>(args)...);
}
//--------------------------------------------------------------------------------
