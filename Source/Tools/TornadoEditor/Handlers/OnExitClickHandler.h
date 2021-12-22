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

namespace nsTornadoEditor
{
    class DllExport TOnExitClickHandler : public nsGuiWrapper::IMenuNodeClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC) override
        {
            auto stopAccessor = nsTornadoEngine::Modules()->StopAccessor();
            stopAccessor->SetStop();
        }
    };
}