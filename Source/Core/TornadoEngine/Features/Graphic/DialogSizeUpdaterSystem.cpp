/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogSizeUpdaterSystem.h"
#include "DialogComponent.h"
#include "SizeComponent.h"

using namespace nsGraphicWrapper;

void TDialogSizeUpdaterSystem::Execute()
{
    auto hasDialog = GetEntMng()->GetByHasCopy<nsGuiWrapper::TDialogComponent>();
    for (auto& eid : hasDialog) {
        auto pDialog = GetEntMng()->ViewComponent<nsGuiWrapper::TDialogComponent>(eid)->value;

        auto pSize = pDialog->GetSize();
        nsGuiWrapper::TSizeComponent sizeComponent;

        sizeComponent.x = pSize.x;
        sizeComponent.y = pSize.y;

        GetEntMng()->SetComponent(eid, sizeComponent, false);
    }
}