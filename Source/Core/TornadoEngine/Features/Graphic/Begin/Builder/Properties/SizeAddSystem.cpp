/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/SizeAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TSizeAddSystem::Reactive(nsECSFramework::TEntityID eid, const TSizeComponent* pSizeComponent)
{
    auto pUnit = pSizeComponent->pOwner;
    pUnit->SetSize({ (float)pSizeComponent->x, (float)pSizeComponent->y });
}