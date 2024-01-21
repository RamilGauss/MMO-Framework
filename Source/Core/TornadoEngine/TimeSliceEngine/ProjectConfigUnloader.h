/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#pragma once

#include "Base/Common/TypeDef.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"

namespace nsTornadoEngine
{
    class DllExport TProjectConfigUnloader
    {
    public:
        static bool Unload(TProjectConfigContainer* pcc);
    private:
    };
}