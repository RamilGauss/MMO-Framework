/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MakerLoaderDLL.h"
#include "LoaderDLL_Win32.h"
#include "LoaderDLL_Unix.h"

#ifdef WIN32
  MACRO_MAKER_CPP_USE_SAME(LoaderDLL,LoaderDLL_Win32)
#else
  MACRO_MAKER_CPP_USE_SAME(LoaderDLL,LoaderDLL_Unix)
#endif

