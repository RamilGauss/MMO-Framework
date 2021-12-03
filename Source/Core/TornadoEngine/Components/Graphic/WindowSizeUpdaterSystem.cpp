/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowSizeUpdaterSystem.h"
#include "WindowComponent.h"
#include "SizeComponent.h"

using namespace nsGraphicWrapper;

void TWindowSizeUpdaterSystem::Execute()
{
    auto hasWindow = GetEntMng()->GetByHasCopy<nsGuiWrapper::TWindowComponent>();
    for (auto& eid : hasWindow) {
        auto pWindow = GetEntMng()->ViewComponent<nsGuiWrapper::TWindowComponent>(eid)->value;

        auto pPos = pWindow->GetPos();
        nsGuiWrapper::TSizeComponent sizeComponent;

        sizeComponent.x = pPos.x;
        sizeComponent.y = pPos.y;

        GetEntMng()->SetComponent(eid, sizeComponent, false);
    }
}