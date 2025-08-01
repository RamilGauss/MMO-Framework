/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/MinSizeAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TMinSizeAddSystem::Reactive(nsECSFramework::TEntityID eid, const TMinSizeComponent* pMinSizeComponent)
{
    auto pUnit = pMinSizeComponent->pOwner;
    pUnit->SetMinSize({ (float)pMinSizeComponent->x, (float)pMinSizeComponent->y });
}