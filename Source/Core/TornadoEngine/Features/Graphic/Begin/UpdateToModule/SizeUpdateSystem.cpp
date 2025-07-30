/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Window.h"

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/SizeUpdateSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TSizeUpdateSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TSizeComponent* pSizeComponent)
{
    auto pUnit = pSizeComponent->pOwner;
    pUnit->SetSize({ (float)pSizeComponent->x, (float)pSizeComponent->y });
}