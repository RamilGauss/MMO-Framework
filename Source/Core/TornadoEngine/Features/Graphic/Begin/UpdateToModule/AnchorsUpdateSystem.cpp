/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Window.h"

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/AnchorsUpdateSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TAnchorsUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TAnchorsComponent* pAnchorsComponent)
{
    auto pUnit = pAnchorsComponent->pOwner;

    pUnit->SetTopAnchor({ pAnchorsComponent->topIsUsed, pAnchorsComponent->topOffset });
    pUnit->SetBottomAnchor({ pAnchorsComponent->bottomIsUsed, pAnchorsComponent->bottomOffset });
    pUnit->SetLeftAnchor({ pAnchorsComponent->leftIsUsed, pAnchorsComponent->leftOffset });
    pUnit->SetRightAnchor({ pAnchorsComponent->rightIsUsed, pAnchorsComponent->rightOffset });
}
