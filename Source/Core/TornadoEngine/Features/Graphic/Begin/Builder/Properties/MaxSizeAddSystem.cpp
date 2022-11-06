/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MaxSizeAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TMaxSizeAddSystem::Reactive(nsECSFramework::TEntityID eid, const TMaxSizeComponent* pMaxSizeComponent)
{
    auto pUnit = pMaxSizeComponent->pOwner;
    pUnit->SetMaxSize({ (float)pMaxSizeComponent->x, (float)pMaxSizeComponent->y});
}