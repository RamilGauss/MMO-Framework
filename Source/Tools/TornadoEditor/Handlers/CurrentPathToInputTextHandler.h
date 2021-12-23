/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <filesystem>

#include "IObjectInstanceEndHandler.h"

#include "Modules.h"
#include "StopAccessor.h"
#include "PrefabManager.h"

#include "InputTextValueComponent.h"
#include "TitleComponent.h"

namespace nsTornadoEditor
{
    class DllExport TCurrentPathToInputTextHandler : public nsLogicWrapper::IObjectInstanceEndHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid) override
        {
            auto entMng = nsTornadoEngine::Modules()->EntMng();

            auto inputTextComponent = entMng->ViewComponent<nsGuiWrapper::TInputTextValueComponent>(eid);
            auto copyInputTextComponent = *inputTextComponent;
            copyInputTextComponent.value = std::filesystem::current_path().string();

            entMng->SetComponent(eid, copyInputTextComponent);
        }
    };
}