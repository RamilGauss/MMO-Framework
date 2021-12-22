/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowPositionUpdaterSystem.h"
#include "WindowComponent.h"
#include "PositionComponent.h"

using namespace nsGraphicWrapper;

void TWindowPositionUpdaterSystem::Execute()
{
    auto hasWindow = GetEntMng()->GetByHasCopy<nsGuiWrapper::TWindowComponent>();
    for (auto& eid : hasWindow) {
        auto pWindow = GetEntMng()->ViewComponent<nsGuiWrapper::TWindowComponent>(eid)->value;

        auto pPos = pWindow->GetPos();
        nsGuiWrapper::TPositionComponent posComponent;

        posComponent.x = pPos.x;
        posComponent.y = pPos.y;

        GetEntMng()->SetComponent(eid, posComponent, false);
    }
}