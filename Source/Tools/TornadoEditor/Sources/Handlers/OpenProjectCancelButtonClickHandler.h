/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/Handlers/Gui/IButtonClickHandler.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"
#include "TornadoEngine/Modules/Resources/Scene/SceneManager.h"

#include "TornadoEngine/Components/Meta/SceneInstanceGuidComponent.h"
#include "TornadoEngine/Components/Logic/SceneObjectReferenceComponent.h"
#include "TornadoEngine/Components/Logic/PrefabReferenceComponent.h"

namespace nsTornadoEditor
{
    class DllExport TOpenProjectCancelButtonClickHandler : public nsGuiWrapper::IButtonClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) override
        {
            auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
            prefabMng->Destroy(eid);// Close
        }
    };
}
