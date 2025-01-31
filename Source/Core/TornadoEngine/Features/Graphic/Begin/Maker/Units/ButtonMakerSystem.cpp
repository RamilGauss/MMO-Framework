/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonMakerSystem.h"

#include <ImGuiWidgets/include/Button.h>

#include <Modules/Common/Modules.h>
#include <Modules/PropertyManager/PropertyManager.h>

using namespace nsGraphicWrapper;

void TButtonMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    auto pButton = new nsImGuiWidgets::TButton();
    pButtonComponent->value = pButton;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pButton);
}
