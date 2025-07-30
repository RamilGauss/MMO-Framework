/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/HorizontalAlignUpdateSystem.h"

#include "ImGuiWidgets/Include/Window.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void THorizontalAlignUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::THorizontalAlignComponent* pHorizontalAlignComponent)
{
    auto pUnit = pHorizontalAlignComponent->pOwner;
    pUnit->SetHorizontalAlign((nsImGuiWidgets::THorizontalAlign::Type)pHorizontalAlignComponent->value);
}