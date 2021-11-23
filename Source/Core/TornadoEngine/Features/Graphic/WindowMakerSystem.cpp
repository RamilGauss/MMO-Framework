/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowMakerSystem.h"

#include <ImGuiWidgets/include/Window.h>

using namespace nsGraphicWrapper;

void TWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC)
{
    auto pWindowComponent = (nsGuiWrapper::TWindowComponent*) pC;
    pWindowComponent->value = new nsImGuiWidgets::TWindow();
}
