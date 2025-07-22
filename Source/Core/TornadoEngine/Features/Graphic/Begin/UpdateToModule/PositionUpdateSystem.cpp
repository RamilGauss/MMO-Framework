/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PositionUpdateSystem.h"

#include "ImGuiWidgets/Include/Window.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TPositionUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TPositionComponent* pPositionComponent)
{
    auto pUnit = pPositionComponent->pOwner;
    pUnit->SetPosition({ (float)pPositionComponent->x, (float)pPositionComponent->y });
}