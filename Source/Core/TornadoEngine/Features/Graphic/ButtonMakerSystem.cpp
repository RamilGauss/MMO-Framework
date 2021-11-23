/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ButtonMakerSystem.h"

#include <ImGuiWidgets/include/Button.h>

using namespace nsGraphicWrapper;

void TButtonMakerSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    auto pButtonComponent = (nsGuiWrapper::TButtonComponent*) pC;
    pButtonComponent->value = new nsImGuiWidgets::TButton();
}
