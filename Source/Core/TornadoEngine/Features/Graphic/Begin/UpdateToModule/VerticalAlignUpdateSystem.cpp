/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "VerticalAlignUpdateSystem.h"

#include <ImGuiWidgets/include/Window.h>

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TVerticalAlignUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TVerticalAlignComponent* pVerticalAlignComponent)
{
    auto pUnit = pVerticalAlignComponent->pOwner;
    pUnit->SetVerticalAlign((nsImGuiWidgets::TVerticalAlign::Type)pVerticalAlignComponent->value);
}