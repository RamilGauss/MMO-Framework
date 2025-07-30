/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Button.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/WindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/DialogComponent.h"

#include "TornadoEngine/Features/Graphic/Begin/Terminator/Units/ButtonTerminatorSystem.h"
#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

using namespace nsGraphicWrapper;

void TButtonTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    TUnitBuilderHelper::UnlinkParent(GetEntMng(), eid, pButtonComponent->value);

    delete pButtonComponent->value;
    pButtonComponent->value = nullptr;
}
