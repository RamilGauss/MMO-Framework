/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/FocusAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TFocusAddSystem::Reactive(nsECSFramework::TEntityID eid, const TFocusComponent* pFocusComponent)
{
    auto pUnit = pFocusComponent->pOwner;
    pUnit->SetFocused(pFocusComponent->value);
}