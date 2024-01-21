/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IWindowCloseEventHandler.h"

#include "Modules/Common/Modules.h"
#include "StopAccessor.h"

namespace nsTornadoEditor
{
    class DllExport TOnCloseWindowHandler : public nsGuiWrapper::IWindowCloseEventHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pC) override
        {
            nsTornadoEngine::Modules()->StopAccessor()->SetStop();
        }
    };
}