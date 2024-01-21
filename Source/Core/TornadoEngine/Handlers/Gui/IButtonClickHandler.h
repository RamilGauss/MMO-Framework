/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Config.h>

#include "Handlers/Common/ILocalHandler.h"

#include "Components/Gui/Widgets/ButtonComponent.h"

namespace nsGuiWrapper
{
    class DllExport IButtonClickHandler : public nsTornadoEngine::ILocalHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pC) = 0;
    };
}
