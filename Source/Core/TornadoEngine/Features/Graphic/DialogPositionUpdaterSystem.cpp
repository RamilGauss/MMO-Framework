/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogPositionUpdaterSystem.h"
#include "DialogComponent.h"
#include "PositionComponent.h"

using namespace nsGraphicWrapper;

void TDialogPositionUpdaterSystem::Execute()
{
    auto hasDialog = GetEntMng()->GetByHasCopy<nsGuiWrapper::TDialogComponent>();
    for (auto& eid : hasDialog) {
        auto pDialog = GetEntMng()->ViewComponent<nsGuiWrapper::TDialogComponent>(eid)->value;

        auto pPos = pDialog->GetPos();
        nsGuiWrapper::TPositionComponent posComponent;

        posComponent.x = pPos.x;
        posComponent.y = pPos.y;

        GetEntMng()->SetComponent(eid, posComponent, false);
    }
}