/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <filesystem>

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"
#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Components/Gui/Properties/InputTextValueComponent.h"
#include "TornadoEngine/Handlers/Logic/IObjectInstantiationCompletionHandler.h"

namespace nsTornadoEditor
{
    class DllExport TCurrentPathToInputTextHandler : public nsLogicWrapper::IObjectInstantiationCompletionHandler
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