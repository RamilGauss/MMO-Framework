/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "IConveyerPart.h"
#include "GlobalAccess.h"

namespace nsECSFramework
{
  class DllExport TConveyerPartWithGlobalAccess : public IConveyerPart, public TGlobalAccess { };
}
