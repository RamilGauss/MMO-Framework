/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HorizontalAlignAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void THorizontalAlignAddSystem::Reactive(nsECSFramework::TEntityID eid, const THorizontalAlignComponent* pHorizontalAlignComponent)
{
    auto pUnit = pHorizontalAlignComponent->pOwner;

    pUnit->SetHorizontalAlign((nsImGuiWidgets::THorizontalAlign::Type)pHorizontalAlignComponent->value);
}