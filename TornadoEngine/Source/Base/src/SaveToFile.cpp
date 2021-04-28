/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SaveToFile.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include <sys/timeb.h>
#include <algorithm>

#include "BL_Debug.h"
#include "HiTimer.h"

using namespace std;

TSaveToFile::TSaveToFile(char* path)
{
    ReOpen(path);

    flgPrintf = false;
    flgEnable = true;
    flgBuffer = true;
}
//---------------------------------------------------------------
TSaveToFile::~TSaveToFile()
{
    ClearBuffer();
}
//---------------------------------------------------------------
bool TSaveToFile::ReOpen(char* path, bool append)
{
    Close();

    if (path != nullptr) {
        sPath = path;
    }

    if (sPath.length() == 0) {
        return false;
    }

    const char* sMode = (append) ? "ab" : "wb";
    pFile = fopen(sPath.data(), sMode);
    if (pFile != nullptr) {
        FlushBuffer();
        return true;
    }

    char sErr[1000];
    sprintf(sErr, "fopen Error: %s path=\"%s\"", strerror(errno), path);
    BL_MessageBug(sErr);

    return false;
}
//---------------------------------------------------------------
void TSaveToFile::Write(void* buffer, int size)
{
    if (flgEnable == false)
        return;

    if (pFile) {
        fwrite(buffer, size, 1, pFile);
        fflush(pFile);
    } else {
        if (flgBuffer) {
            FlushInBuffer((char*) buffer, size);
        }
    }
}
//---------------------------------------------------------------
void TSaveToFile::Write_Time()
{
    auto str_time = ht_GetTimeStr();
    Write((char*) str_time.data(), str_time.length());
}
//---------------------------------------------------------------
void TSaveToFile::FlushBuffer()
{
    TListContainer::T::iterator bit = mListBuffer->begin();
    TListContainer::T::iterator eit = mListBuffer->end();
    while (bit != eit) {
        TContainer* v = *bit;
        Write(v->GetPtr(), v->GetSize());
        delete v;
        bit++;
    }
    mListBuffer->clear();
}
//---------------------------------------------------------------
void TSaveToFile::ClearBuffer()
{
    mListBuffer.Clear();
}
//---------------------------------------------------------------
void TSaveToFile::FlushInBuffer(char* buffer, int size)
{
    TContainer* v = new TContainer;
    v->SetDataByCount(buffer, size);

    mListBuffer->push_back(v);

    BL_ASSERT(mListBuffer->size() <= eMaxNumberForBufferization);
}
//---------------------------------------------------------------
void TSaveToFile::SetPrintf(bool val)
{
    flgPrintf = val;
}// все что записывается - дублируется в вывод на консоль
//---------------------------------------------------------------
bool TSaveToFile::GetPrintf()
{
    return flgPrintf;
}     // но только для форматированной строки
//---------------------------------------------------------------
void TSaveToFile::SetEnable(bool val)
{
    flgEnable = val;
}// отмена применения в Write, WriteF, WriteF_time
//---------------------------------------------------------------
bool TSaveToFile::GetEnable()
{
    return flgEnable;
}
//---------------------------------------------------------------
void TSaveToFile::SetBufferization(bool val)
{
    flgBuffer = val;
}// буферизация, без открытого файла все складируется в памяти
//---------------------------------------------------------------
bool TSaveToFile::GetBufferization()
{
    return flgBuffer;
}
//---------------------------------------------------------------
