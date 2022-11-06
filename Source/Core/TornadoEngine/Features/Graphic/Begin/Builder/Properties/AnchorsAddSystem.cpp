/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "AnchorsAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TAnchorsAddSystem::Reactive(nsECSFramework::TEntityID eid, const TAnchorsComponent* pAnchorsComponent)
{
    auto pUnit = pAnchorsComponent->pOwner;

    pUnit->SetTopAnchor({ pAnchorsComponent->topIsUsed, pAnchorsComponent->topOffset });
    pUnit->SetBottomAnchor({ pAnchorsComponent->bottomIsUsed, pAnchorsComponent->bottomOffset });
    pUnit->SetLeftAnchor({ pAnchorsComponent->leftIsUsed, pAnchorsComponent->leftOffset });
    pUnit->SetRightAnchor({ pAnchorsComponent->rightIsUsed, pAnchorsComponent->rightOffset });
}