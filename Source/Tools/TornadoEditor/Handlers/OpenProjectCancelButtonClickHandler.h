/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IButtonClickHandler.h"

#include "Modules.h"
#include "StopAccessor.h"
#include "SceneManager.h"

#include "SceneInstanceGuidComponent.h"

#include "SceneObjectReferenceComponent.h"
#include "PrefabReferenceComponent.h"

namespace nsTornadoEditor
{
    class DllExport TOpenProjectCancelButtonClickHandler : public nsGuiWrapper::IButtonClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) override
        {
            auto sceneMng = nsTornadoEngine::Modules()->SceneMng();
            auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
            auto stopAccessor = nsTornadoEngine::Modules()->StopAccessor();
            auto entMng = nsTornadoEngine::Modules()->EntMng();

            //sceneMng->Destroy(eid);
            //sceneMng->Unload("first scene");
            //stopAccessor->SetStop();

            //auto prefabRef = entMng->ViewComponent<nsLogicWrapper::TPrefabReferenceComponent>(eid);
            //auto sceneInstanceGuid = entMng->ViewComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid);
            //auto objectRef = entMng->ViewComponent<nsLogicWrapper::TSceneObjectReferenceComponent>(eid);

            //prefabMng->InstantiateByGuid(prefabRef->prefabGuid, sceneInstanceGuid->value);// , objectRef->objectGuid);
        }
    };
}