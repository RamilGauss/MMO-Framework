/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Window.h"

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/TitleUpdateSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TTitleUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTitleComponent* pTitleComponent)
{
    auto pUnit = pTitleComponent->pOwner;
    pUnit->SetTitle(pTitleComponent->value);
}