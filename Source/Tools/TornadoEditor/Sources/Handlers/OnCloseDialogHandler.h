/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IDialogCloseEventHandler.h"

#include "Modules.h"
#include "PrefabManager.h"

namespace nsTornadoEditor
{
    class DllExport TOnCloseDialogHandler : public nsGuiWrapper::IDialogCloseEventHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pC) override
        {
            auto prefabMng = nsTornadoEngine::Modules()->PrefabMng();
            prefabMng->Destroy(eid);
        }
    };
}