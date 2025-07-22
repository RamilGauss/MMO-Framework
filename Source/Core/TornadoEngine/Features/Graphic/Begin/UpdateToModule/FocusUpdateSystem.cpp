/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FocusUpdateSystem.h"

#include "ImGuiWidgets/Include/Window.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TFocusUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TFocusComponent* pFocusComponent)
{
    auto pUnit = pFocusComponent->pOwner;
    pUnit->SetFocused(pFocusComponent->value);
}