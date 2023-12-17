/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "LoaderDLLFactory.h"

#include "LoaderDLL_Win32.h"
#include "LoaderDLL_Unix.h"

std::shared_ptr<ILoaderDLL> MakeLoaderDLL()
{
    return std::make_shared <
#ifdef WIN32
TLoaderDLL_Win32
#else
TLoaderDLL_Unix
#endif
>();
}

