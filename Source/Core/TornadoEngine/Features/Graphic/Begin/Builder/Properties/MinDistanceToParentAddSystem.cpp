/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/MinDistanceToParentAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TMinDistanceToParentAddSystem::Reactive(nsECSFramework::TEntityID eid, const TMinDistanceToParentComponent* pMinDistanceToParentComponent)
{
    auto pUnit = pMinDistanceToParentComponent->pOwner;

    pUnit->SetTopMinDistance(pMinDistanceToParentComponent->top);
    pUnit->SetBottomMinDistance(pMinDistanceToParentComponent->bottom);
    pUnit->SetLeftMinDistance(pMinDistanceToParentComponent->left);
    pUnit->SetRightMinDistance(pMinDistanceToParentComponent->right);
}