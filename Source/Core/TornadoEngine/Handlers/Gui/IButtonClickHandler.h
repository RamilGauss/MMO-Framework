/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITargetHandler.h"

#include <ECS/include/Config.h>
#include "ButtonComponent.h"

namespace nsGuiWrapper
{
    class DllExport IButtonClickHandler : public nsTornadoEngine::ITargetHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) = 0;
    };
}