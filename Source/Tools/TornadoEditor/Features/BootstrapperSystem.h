/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/InitSystem.h>

namespace nsTornadoEditor
{
    class DllExport TBootstrapperSystem : public nsECSFramework::TInitSystem
    {
    public:
        void Init() override;
    };
}