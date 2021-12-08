/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IButtonClickHandler.h"

#include "Modules.h"
#include "PrefabManager.h"

namespace nsTornadoEditor
{
    class DllExport TDeleteOnButtonClickHandler : public nsGuiWrapper::IButtonClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) override
        {
            nsTornadoEngine::Modules()->PrefabMng()->Destroy(eid);
        }
    };
}