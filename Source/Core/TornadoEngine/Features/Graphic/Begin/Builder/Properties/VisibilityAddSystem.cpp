/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "VisibilityAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TVisibilityAddSystem::Reactive(nsECSFramework::TEntityID eid, const TVisibilityComponent* pVisibilityComponent)
{
    auto pUnit = pVisibilityComponent->pOwner;

    if (pVisibilityComponent->value) {
        pUnit->Show();
    } else {
        pUnit->Hide();
    }
}