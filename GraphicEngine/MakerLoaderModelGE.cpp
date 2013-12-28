/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerLoaderModelGE.h"
#ifdef WIN32
  #include "LoaderModelDX.h"
  MACRO_MAKER_CPP_USE_P_SAME(LoaderModelGE, LoaderModelDX, void* parameter, parameter)
#else
#endif
