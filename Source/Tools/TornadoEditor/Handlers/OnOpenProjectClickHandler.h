/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IMenuNodeClickHandler.h"

#include "Modules.h"
#include "StopAccessor.h"
#include "PrefabManager.h"

#include "SceneInstanceGuidComponent.h"

#include "SceneObjectReferenceComponent.h"
#include "PrefabReferenceComponent.h"

namespace nsTornadoEditor
{
    class DllExport TOnOpenProjectClickHandler : public nsGuiWrapper::IMenuNodeClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC) override
        {
            auto sceneMng = nsTornadoEngine::Modules()->SceneMng();
            auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
            auto stopAccessor = nsTornadoEngine::Modules()->StopAccessor();
            auto entMng = nsTornadoEngine::Modules()->EntMng();

            auto prefabRef = entMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid);
            auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid);

            prefabMng->InstantiateByGuid(prefabRef->prefabGuid, sceneInstanceGuid->value);
        }
    };
}