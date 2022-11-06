/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FocusAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TFocusAddSystem::Reactive(nsECSFramework::TEntityID eid, const TFocusComponent* pFocusComponent)
{
    auto pUnit = pFocusComponent->pOwner;
    pUnit->SetIsFocused(pFocusComponent->value);
}