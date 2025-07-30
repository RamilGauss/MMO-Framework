/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Window.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/WindowMakerSystem.h"

using namespace nsGraphicWrapper;

void TWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto pWindow = new nsImGuiWidgets::TWindow();
    pWindowComponent->value = pWindow;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pWindow);
}
