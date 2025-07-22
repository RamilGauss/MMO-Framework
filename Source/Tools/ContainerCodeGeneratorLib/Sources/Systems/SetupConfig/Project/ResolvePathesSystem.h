/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/ExecuteSystem.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    class DllExport TResolvePathesSystem : public nsECSFramework::TExecuteSystem
    {
    public:
        void Execute() override;
    private:
        void ResolvePath(std::string& path);
    };
}