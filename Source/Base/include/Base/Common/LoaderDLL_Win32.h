/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#ifdef WIN32

#include "Base/Common/ILoaderDLL.h"

#include <windows.h>

class TLoaderDLL_Win32 : public ILoaderDLL
{
    HMODULE hModule;
public:
    TLoaderDLL_Win32();
    virtual ~TLoaderDLL_Win32();

    virtual bool Init(const char* sPath);
    virtual void* Get(const char* nameFunc);
    virtual void Done();
};

#endif
