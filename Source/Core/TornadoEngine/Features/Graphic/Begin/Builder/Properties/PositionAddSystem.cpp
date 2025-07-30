/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/PositionAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TPositionAddSystem::Reactive(nsECSFramework::TEntityID eid, const TPositionComponent* pPositionComponent)
{
    auto pUnit = pPositionComponent->pOwner;
    pUnit->SetPosition({ (float)pPositionComponent->x, (float)pPositionComponent->y });
}