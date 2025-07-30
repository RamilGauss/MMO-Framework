/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/VerticalAlignAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TVerticalAlignAddSystem::Reactive(nsECSFramework::TEntityID eid, const TVerticalAlignComponent* pVerticalAlignComponent)
{
    auto pUnit = pVerticalAlignComponent->pOwner;
    pUnit->SetVerticalAlign((nsImGuiWidgets::TVerticalAlign::Type)pVerticalAlignComponent->value);
}