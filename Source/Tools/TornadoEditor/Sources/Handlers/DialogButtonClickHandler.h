/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Prefab/PrefabManager.h"
#include "TornadoEngine/Modules/Resources/Prefab/InstantiatePrefabParams.h"

#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"

#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Logic/SceneObjectReferenceComponent.h"
#include "TornadoEngine/Components/Logic/PrefabReferenceComponent.h"

#include "TornadoEngine/Handlers/Gui/IButtonClickHandler.h"

namespace nsTornadoEditor
{
    class DllExport TDialogButtonClickHandler : public nsGuiWrapper::IButtonClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) override
        {
            auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
            auto entMng = nsTornadoEngine::Modules()->EntMng();

            //auto objectRef = entMng->ViewComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid);
            auto prefabRef = entMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid);

            auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid);

            prefabMng->Instantiate({ prefabRef->prefabGuid, sceneInstanceGuid->value });
        }
    };
}
