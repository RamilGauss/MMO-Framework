/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>

#include "Base/Common/TypeDef.h"
#include "Base/Common/ILoaderDLL.h"

extern DllExport std::shared_ptr<ILoaderDLL> MakeLoaderDLL();
