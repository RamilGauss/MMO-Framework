/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MinSizeUpdateSystem.h"

#include "ImGuiWidgets/Include/Window.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TMinSizeUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMinSizeComponent* pMinSizeComponent)
{
    auto pUnit = pMinSizeComponent->pOwner;
    pUnit->SetMinSize({ (float)pMinSizeComponent->x, (float)pMinSizeComponent->y });
}