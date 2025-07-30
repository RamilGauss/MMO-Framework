/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#pragma once

#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/Logger.h"
#include "Base/Common/TextFile.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/TimeSliceEngine/TimeSliceEngine.h"
#include "TornadoEngine/GeneratedFiles/TornadoEngineJsonSerializer.h"

namespace nsTornadoEngine
{
    class DllExport TProjectConfigLoader
    {
        static TProjectConfigContainer* mPcc;
    public:
        static bool Load(TProjectConfigContainer* pcc);
    private:
        static bool LoadProjectConfig();
        static bool LoadConveyor();
        static bool LoadBinary();
        static bool LoadResources();
    };
}
