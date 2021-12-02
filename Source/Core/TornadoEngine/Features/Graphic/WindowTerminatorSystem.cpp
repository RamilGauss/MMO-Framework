/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowTerminatorSystem.h"
#include "Modules.h"
#include "GraphicEngineModule.h"

#include <ImGuiWidgets/include/Window.h>

using namespace nsGraphicWrapper;

void TWindowTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    nsTornadoEngine::Modules()->G()->GetGE()->RemoveRender(pWindowComponent->value);

    delete pWindowComponent->value;
    pWindowComponent->value = nullptr;
}
