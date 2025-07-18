/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/LoaderDLLFactory.h"

#include "Base/Common/LoaderDLL_Win32.h"
#include "Base/Common/LoaderDLL_Unix.h"

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

